<?php

abstract class UBNDatabasesFeedsFetcherBase extends FeedsFetcher {

  protected function ubnDatabasesPDO($source) {
    $source_config = $source->getConfigFor($this);
    $pdo = new PDO(
      $source_config['source']
      //variable_get('ubn_databases_db_user', ''),
      //variable_get('ubn_databases_db_password', '')
    );
    return $pdo;
  }

  /**
   * Expose source form.
   */
  public function sourceForm($source_config) {
    $form = parent::sourceForm($source_config);
    //Database connection url?
    $form['source'] = array(
      '#type' => 'textfield',
      '#title' => t('PDO Data Source Name'),
      '#default_value' => !empty($source_config['source']) ?
        $source_config['source'] :
        'pgsql:host=<hostname>;port=<portnumber>;dbname=<databasename>',
      '#maxlength' => NULL,
      '#required' => TRUE,
    );

    /*
    $form['db_password'] = array(
      '#type' => 'textfield',
      '#title' => t('Database password'),
      '#default_value' => !empty($source_config['db_password']) ? $source_config['db_password'] : '',
      '#maxlength' => NULL,
      '#required' => TRUE,
    );
    $form['db_user'] = array(
      '#type' => 'textfield',
      '#title' => t('Database user'),
      '#default_value' => !empty($source_config['db_user']) ? $source_config['db_user'] : '',
      '#maxlength' => NULL,
      '#required' => TRUE,
    );
    */
    return $form;
  }
}

class UBNDatabasesFeedsFetcher extends UBNDatabasesFeedsFetcherBase {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $pdo = $this->UBNDatabasesPDO($source);
        /*
    $statement = $pdo->prepare('SELECT * FROM table');
    $statement->execute();
    //This is not really required for connection to close
    $statement->closeCursor();
    $statement = null;
    $pdo = null;
     */
    //Databases
    //
    $databases = array();
    foreach($pdo->query('SELECT id, libris_id, title FROM dbs', $pdo::FETCH_ASSOC) as $row) {
      $databases[$row['id']] = $row + array(
        'guid' => md5('ubn_databases:' . $row['id']), //Quick and dirty fix
        'alternate_titles' => array(),
        'publishers' => array(),
        'descriptions' => array(),
        'public_access' => NULL,
        'urls' => array(),
        'categories' => array(),
        'keywords' => array(),
        'prioritized_keywords' => array(),
      );
    }

    //Alternative titles
    foreach($pdo->query('SELECT db_id as id, title FROM alternate_titles', $pdo::FETCH_ASSOC) as $row) {
      $databases[$row['id']]['alternate_titles'][] = $row['title'];
    }

    //Publishers
    foreach($pdo->query('SELECT db_id as id, name FROM publishers', $pdo::FETCH_ASSOC) as $row) {
      $databases[$row['id']]['publishers'][] = $row['name'];
    }

    //Descriptions
    foreach($pdo->query('SELECT db_id as id, description FROM descriptions', $pdo::FETCH_ASSOC) as $row) {
      $databases[$row['id']]['descriptions'][] = $row['description'];
    }
    $database_public_access = NULL;
    //Urls
    foreach($pdo->query('SELECT db_id as id, url, info, description FROM urls', $pdo::FETCH_ASSOC) as $row) {
      $public_access = strpos($row['url'], '.ezproxy.') === FALSE;
      if(!isset($database_public_access)) {
        $database_public_access = $public_access;
      }
      $guid = md5('unb_databases_url:' . $row['url']);
      $per_language_access_descriptions = array_combine(array('sv', 'en'), array_map('trim', explode('/', $row['info'])));
      $databases[$row['id']]['urls'][] = array(
        'guid' => $guid,
        'url' => $row['url'],
        'access' => array(
          'guid' => md5('ubn_databases_access_info:' . trim($row['info'])),
          'description' => $per_language_access_descriptions,
        ),
        'public_access' => $public_access,
        'description' => $row['description'],
      );
    }
    $database['public_access'] = $database_public_access;
    /*
    $infos = array('sv' => array(), 'en' => array());
    foreach($databases as $item) {
      foreach(array_keys($infos) as $lang) {
        foreach($item['urls']['access']['description'][$lang] as $desc) {
          $infos[$lang][] = $desc;
        }
      }
    }
    foreach(array_keys($infos) as $lang) {
      $infos[$lang] = array_unique($infos[$lang]);
    }
    //dsm($infos);
    */

    foreach(array('en' => 'ind2:0'/*, 'sv' => 'ind2:4'*/) as $lang => $code) {
      //Categories
      $query = <<<EOD
      SELECT cz.db_id as id, c.hash_value as hash_value, c.category as name, c.id as category_id FROM categorizations cz
        JOIN categories c ON c.id = cz.category_id
        WHERE c.category_source_id in (SELECT id FROM category_sources where code = '$code')
EOD;

      foreach($pdo->query($query, $pdo::FETCH_ASSOC) as $delta => $row) {
        $guid = $row['hash_value'];
        $databases[$row['id']]['categories'][] = array(
          'guid' => $guid,
        );
      }
    }

    foreach(array('en' => 'ind2:0'/*, 'sv' => 'ind2:4'*/) as $lang => $code) {
      //Keywords
      $query = <<<EOD
        SELECT
          c.db_id as id,
          k.hash_value as hash_value,
          k.keyword as name,
          k.id as keyword_id,
          k.parent_id as keyword_parent_id
        FROM classifications c
          JOIN keywords k ON k.id = c.keyword_id
          WHERE k.keyword_source_id in (SELECT id FROM keyword_sources where code = '$code')
EOD;
      foreach($pdo->query($query, $pdo::FETCH_ASSOC) as $row) {
        $guid = $row['hash_value'];
        $databases[$row['id']]['keywords'][] = array(
          'guid' => $guid
        );
      }
    }

    foreach(array('en' => 'ind2:0'/*, 'sv' => 'ind2:4'*/) as $lang => $code) {
      //Prioritized keywords
      $query = <<<EOD
        SELECT
          c.db_id as id,
          k.hash_value as hash_value,
          k.keyword as name,
          k.id as keyword_id,
          k.parent_id as keyword_parent_id
        FROM classifications c
        JOIN keywords k ON k.id = c.keyword_id
        WHERE priority = 1
          AND k.keyword_source_id in (SELECT id FROM keyword_sources where code = '$code')
EOD;
      foreach($pdo->query($query, $pdo::FETCH_ASSOC) as $row) {
        $guid = $row['hash_value'];
        $databases[$row['id']]['prioritized_keywords'][] = array(
          'guid' => $guid,
        );
      }
    }
    $raw = drupal_json_encode(array_values($databases));
    //file_put_contents('/tmp/databases.json', $raw);
    $fetcher_result = new FeedsFetcherResult($raw);
    return $fetcher_result;
  }
}

class UBNDatabasesCategoriesFeedsFetcher extends UBNDatabasesFeedsFetcherBase {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $pdo = $this->UBNDatabasesPDO($source);
    $categories = array();
    foreach(array('en' => 'ind2:0', 'sv' => 'ind2:4') as $lang => $code) {
      //Categories
      $query = <<<EOD
        SELECT
          c.id as id,
          c.hash_value as hash_value,
          c.category as name
        FROM categories c
        WHERE c.category_source_id in (SELECT id FROM category_sources where code = '$code')
EOD;
      foreach($pdo->query($query, $pdo::FETCH_ASSOC) as $delta => $row) {
        if($lang == 'en') {
          //Delta matching does not work
          $categories[$delta] = array(
            'guid' => $row['hash_value'],
            'name' => array(),
          );
        }
        $categories[$delta]['name'][$lang] = $row['name'];
      }
    }
    $raw = drupal_json_encode(array_values($categories));
    $fetcher_result = new FeedsFetcherResult($raw);
    return $fetcher_result;
  }
}

class UBNDatabasesKeywordsFeedsFetcher extends UBNDatabasesFeedsFetcherBase {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $pdo = $this->UBNDatabasesPDO($source);
    $guids = array();
    //Keywords
    $keywords = array();
    foreach(array('en' => 'ind2:0'/*, 'sv' => 'ind2:4'*/) as $lang => $code) {
      $query = <<<EOD
        SELECT
          k.id as id,
          k.hash_value as hash_value,
          k.keyword as name,
          kp.hash_value as keyword_parent_hash_value
        FROM keywords k
        LEFT JOIN keywords kp
        ON k.parent_id = kp.id
        WHERE k.keyword_source_id in (SELECT id FROM keyword_sources where code = '$code')
        ORDER BY id DESC
EOD;
      foreach($pdo->query($query, $pdo::FETCH_ASSOC) as $delta => $row) {
        if($lang == 'en') {
          //Delta matching does not work
          $keywords[$delta] = array(
            'guid' => $row['hash_value'],
            'parent_guid' => $row['keyword_parent_hash_value'],
            'name' => array(),
          );
        }
        //TODO: GUID missing, possible to provide with same GUID for terms in
        //different languages?
        $keywords[$delta]['name'][$lang] = $row['name'];
      }
    }
    $raw = drupal_json_encode(array_values($keywords));
    $fetcher_result = new FeedsFetcherResult($raw);
    return $fetcher_result;
  }
}
