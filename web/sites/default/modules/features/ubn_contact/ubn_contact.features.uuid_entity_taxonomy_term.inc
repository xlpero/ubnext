<?php
/**
 * @file
 * ubn_contact.features.uuid_entity_taxonomy_term.inc
 */

/**
 * Implements hook_uuid_entity_default_taxonomy_term().
 */
function ubn_contact_uuid_entity_default_taxonomy_term() {
  $items = array();
  $items['20c74674-ae25-449b-becc-9d585f4c966e'] = entity_create('taxonomy_term', array(
    'name' => 'Biomedical Library - Learning Centre',
    'description' => '',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '20c74674-ae25-449b-becc-9d585f4c966e',
    'vocabulary_machine_name' => 'ttx_library',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Biomedical Library - Learning Centre',
          'format' => NULL,
          'safe_value' => 'Biomedical Library - Learning Centre',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Studietorget Hälsovetarbacken',
          'format' => NULL,
          'safe_value' => 'Studietorget Hälsovetarbacken',
        ),
      ),
    ),
    'field_value' => array(
      'und' => array(
        0 => array(
          'value' => 'Biomedical Library - Learning Centre',
          'format' => NULL,
          'safe_value' => 'Biomedical Library - Learning Centre',
        ),
      ),
    ),
    'translations' => array(
      'original' => 'sv',
      'data' => array(
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
        'en' => array(
          'language' => 'en',
          'source' => 'sv',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'name_original' => 'Studietorget Hälsovetarbacken',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'entity_translation_handler_id' => 'taxonomy_term-eid-630-0',
    'url_alias' => array(
      0 => array(
        'alias' => 'ttx-library/biomedical-library-learning-centre',
        'language' => 'en',
      ),
      1 => array(
        'alias' => 'ttx-library/studietorget-halsovetarbacken',
        'language' => 'sv',
      ),
    ),
  ));
  $items['44794526-92e9-4ce7-88aa-018dd0f22074'] = entity_create('taxonomy_term', array(
    'name' => 'Music and Drama Library',
    'description' => '',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '44794526-92e9-4ce7-88aa-018dd0f22074',
    'vocabulary_machine_name' => 'ttx_library',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Music and Drama Library',
          'format' => NULL,
          'safe_value' => 'Music and Drama Library',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Biblioteket för musik och dramatik',
          'format' => NULL,
          'safe_value' => 'Biblioteket för musik och dramatik',
        ),
      ),
    ),
    'field_value' => array(
      'und' => array(
        0 => array(
          'value' => 'Music and Drama Library',
          'format' => NULL,
          'safe_value' => 'Music and Drama Library',
        ),
      ),
    ),
    'translations' => array(
      'original' => 'sv',
      'data' => array(
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
        'en' => array(
          'language' => 'en',
          'source' => 'sv',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'name_original' => 'Biblioteket för musik och dramatik',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'entity_translation_handler_id' => 'taxonomy_term-eid-628-0',
    'url_alias' => array(
      0 => array(
        'alias' => 'ttx-library/music-and-drama-library',
        'language' => 'en',
      ),
      1 => array(
        'alias' => 'ttx-library/biblioteket-for-musik-och-dramatik',
        'language' => 'sv',
      ),
    ),
  ));
  $items['5a15e618-81c2-42e0-8fe6-75a8a94e5bfc'] = entity_create('taxonomy_term', array(
    'name' => 'Biomedical Library',
    'description' => '',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '5a15e618-81c2-42e0-8fe6-75a8a94e5bfc',
    'vocabulary_machine_name' => 'ttx_library',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Biomedical Library',
          'format' => NULL,
          'safe_value' => 'Biomedical Library',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Biomedicinska biblioteket',
          'format' => NULL,
          'safe_value' => 'Biomedicinska biblioteket',
        ),
      ),
    ),
    'field_value' => array(
      'und' => array(
        0 => array(
          'value' => 'Biomedical Library',
          'format' => NULL,
          'safe_value' => 'Biomedical Library',
        ),
      ),
    ),
    'translations' => array(
      'original' => 'sv',
      'data' => array(
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
        'en' => array(
          'language' => 'en',
          'source' => 'sv',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'name_original' => 'Biomedicinska biblioteket',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'entity_translation_handler_id' => 'taxonomy_term-eid-629-0',
    'url_alias' => array(
      0 => array(
        'alias' => 'ttx-library/biomedical-library',
        'language' => 'en',
      ),
      1 => array(
        'alias' => 'ttx-library/biomedicinska-biblioteket',
        'language' => 'sv',
      ),
    ),
  ));
  $items['6e8a5141-7679-4d3e-9e6c-89c7344e666e'] = entity_create('taxonomy_term', array(
    'name' => 'Konstbiblioteket',
    'description' => '',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '6e8a5141-7679-4d3e-9e6c-89c7344e666e',
    'vocabulary_machine_name' => 'ttx_library',
    'name_field' => array(
      'sv' => array(
        0 => array(
          'value' => 'Konstbiblioteket',
          'format' => NULL,
          'safe_value' => 'Konstbiblioteket',
        ),
      ),
    ),
    'field_value' => array(
      'und' => array(
        0 => array(
          'value' => 'Art Library',
          'format' => NULL,
          'safe_value' => 'Art Library',
        ),
      ),
    ),
    'translations' => array(
      'original' => 'sv',
      'data' => array(
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'name_original' => 'Konstbiblioteket',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'entity_translation_handler_id' => 'taxonomy_term-eid-634-0',
    'url_alias' => array(
      0 => array(
        'alias' => 'ttx-library/konstbiblioteket',
        'language' => 'sv',
      ),
    ),
  ));
  $items['70d93717-6e43-4445-9eab-222c27ae983d'] = entity_create('taxonomy_term', array(
    'name' => 'Humanities Library',
    'description' => '',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '70d93717-6e43-4445-9eab-222c27ae983d',
    'vocabulary_machine_name' => 'ttx_library',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Humanities Library',
          'format' => NULL,
          'safe_value' => 'Humanities Library',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Humanistiska biblioteket',
          'format' => NULL,
          'safe_value' => 'Humanistiska biblioteket',
        ),
      ),
    ),
    'field_value' => array(
      'und' => array(
        0 => array(
          'value' => 'Humanities Library',
          'format' => NULL,
          'safe_value' => 'Humanities Library',
        ),
      ),
    ),
    'translations' => array(
      'original' => 'sv',
      'data' => array(
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
        'en' => array(
          'language' => 'en',
          'source' => 'sv',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'name_original' => 'Humanistiska biblioteket',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'entity_translation_handler_id' => 'taxonomy_term-eid-631-0',
    'url_alias' => array(
      0 => array(
        'alias' => 'ttx-library/humanities-library',
        'language' => 'en',
      ),
      1 => array(
        'alias' => 'ttx-library/humanistiska-biblioteket',
        'language' => 'sv',
      ),
    ),
  ));
  $items['8879d243-b1a9-404e-9a19-24d606e0063b'] = entity_create('taxonomy_term', array(
    'name' => 'Social Sciences Library',
    'description' => '',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '8879d243-b1a9-404e-9a19-24d606e0063b',
    'vocabulary_machine_name' => 'ttx_library',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Social Sciences Library',
          'format' => NULL,
          'safe_value' => 'Social Sciences Library',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Samhällsvetenskapliga biblioteket',
          'format' => NULL,
          'safe_value' => 'Samhällsvetenskapliga biblioteket',
        ),
      ),
    ),
    'field_value' => array(
      'und' => array(
        0 => array(
          'value' => 'Social Sciences Library',
          'format' => NULL,
          'safe_value' => 'Social Sciences Library',
        ),
      ),
    ),
    'translations' => array(
      'original' => 'sv',
      'data' => array(
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
        'en' => array(
          'language' => 'en',
          'source' => 'sv',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'name_original' => 'Samhällsvetenskapliga biblioteket',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'entity_translation_handler_id' => 'taxonomy_term-eid-635-0',
    'url_alias' => array(
      0 => array(
        'alias' => 'ttx-library/social-sciences-library',
        'language' => 'en',
      ),
      1 => array(
        'alias' => 'ttx-library/samhallsvetenskapliga-biblioteket',
        'language' => 'sv',
      ),
    ),
  ));
  $items['9281b091-3083-4af4-90b3-de006a0b887b'] = entity_create('taxonomy_term', array(
    'name' => 'Campus Linne',
    'description' => '',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '9281b091-3083-4af4-90b3-de006a0b887b',
    'vocabulary_machine_name' => 'ttx_library',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Campus Linne',
          'format' => NULL,
          'safe_value' => 'Campus Linne',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Studietorget Campus Linne',
          'format' => NULL,
          'safe_value' => 'Studietorget Campus Linne',
        ),
      ),
    ),
    'field_value' => array(
      'und' => array(
        0 => array(
          'value' => 'Campus Linne',
          'format' => NULL,
          'safe_value' => 'Campus Linne',
        ),
      ),
    ),
    'translations' => array(
      'original' => 'sv',
      'data' => array(
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
        'en' => array(
          'language' => 'en',
          'source' => 'sv',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'name_original' => 'Studietorget Campus Linne',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'entity_translation_handler_id' => 'taxonomy_term-eid-637-0',
    'url_alias' => array(
      0 => array(
        'alias' => 'ttx-library/campus-linne',
        'language' => 'en',
      ),
      1 => array(
        'alias' => 'ttx-library/studietorget-campus-linne',
        'language' => 'sv',
      ),
    ),
  ));
  $items['9a3402f6-f516-4ddf-9b01-9bdbdaa0b853'] = entity_create('taxonomy_term', array(
    'name' => 'Pedagogiska biblioteke',
    'description' => '',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '9a3402f6-f516-4ddf-9b01-9bdbdaa0b853',
    'vocabulary_machine_name' => 'ttx_library',
    'name_field' => array(
      'sv' => array(
        0 => array(
          'value' => 'Pedagogiska biblioteke',
          'format' => NULL,
          'safe_value' => 'Pedagogiska biblioteke',
        ),
      ),
    ),
    'field_value' => array(
      'und' => array(
        0 => array(
          'value' => 'Education Library',
          'format' => NULL,
          'safe_value' => 'Education Library',
        ),
      ),
    ),
    'translations' => array(
      'original' => 'sv',
      'data' => array(
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'name_original' => 'Pedagogiska biblioteke',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'entity_translation_handler_id' => 'taxonomy_term-eid-636-0',
    'url_alias' => array(
      0 => array(
        'alias' => 'ttx-library/pedagogiska-biblioteke',
        'language' => 'sv',
      ),
    ),
  ));
  $items['e317540a-901f-4f49-8a74-7de5fcc53015'] = entity_create('taxonomy_term', array(
    'name' => 'Earth Sciences Library',
    'description' => '',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => 'e317540a-901f-4f49-8a74-7de5fcc53015',
    'vocabulary_machine_name' => 'ttx_library',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Earth Sciences Library',
          'format' => NULL,
          'safe_value' => 'Earth Sciences Library',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Geovetenskapliga biblioteket',
          'format' => NULL,
          'safe_value' => 'Geovetenskapliga biblioteket',
        ),
      ),
    ),
    'field_value' => array(
      'und' => array(
        0 => array(
          'value' => 'Earth Sciences Library',
          'format' => NULL,
          'safe_value' => 'Earth Sciences Library',
        ),
      ),
    ),
    'translations' => array(
      'original' => 'sv',
      'data' => array(
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
        'en' => array(
          'language' => 'en',
          'source' => 'sv',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'name_original' => 'Geovetenskapliga biblioteket',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'entity_translation_handler_id' => 'taxonomy_term-eid-633-0',
    'url_alias' => array(
      0 => array(
        'alias' => 'ttx-library/earth-sciences-library',
        'language' => 'en',
      ),
      1 => array(
        'alias' => 'ttx-library/geovetenskapliga-biblioteket',
        'language' => 'sv',
      ),
    ),
  ));
  $items['eef4521a-55c7-4a3d-b4c2-d2721aa94afa'] = entity_create('taxonomy_term', array(
    'name' => 'Economics Library',
    'description' => '',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => 'eef4521a-55c7-4a3d-b4c2-d2721aa94afa',
    'vocabulary_machine_name' => 'ttx_library',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Economics Library',
          'format' => NULL,
          'safe_value' => 'Economics Library',
        ),
      ),
      'sv' => array(
        0 => array(
          'value' => 'Ekonomiska biblioteket',
          'format' => NULL,
          'safe_value' => 'Ekonomiska biblioteket',
        ),
      ),
    ),
    'field_value' => array(
      'und' => array(
        0 => array(
          'value' => 'Economics Library',
          'format' => NULL,
          'safe_value' => 'Economics Library',
        ),
      ),
    ),
    'translations' => array(
      'original' => 'sv',
      'data' => array(
        'sv' => array(
          'language' => 'sv',
          'source' => '',
          'status' => 1,
          'translate' => 0,
        ),
        'en' => array(
          'language' => 'en',
          'source' => 'sv',
          'status' => 1,
          'translate' => 0,
        ),
      ),
    ),
    'name_original' => 'Ekonomiska biblioteket',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'skos:Concept',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'rdfs:label',
          1 => 'skos:prefLabel',
        ),
      ),
      'description' => array(
        'predicates' => array(
          0 => 'skos:definition',
        ),
      ),
      'vid' => array(
        'predicates' => array(
          0 => 'skos:inScheme',
        ),
        'type' => 'rel',
      ),
      'parent' => array(
        'predicates' => array(
          0 => 'skos:broader',
        ),
        'type' => 'rel',
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'entity_translation_handler_id' => 'taxonomy_term-eid-632-0',
    'url_alias' => array(
      0 => array(
        'alias' => 'ttx-library/economics-library',
        'language' => 'en',
      ),
      1 => array(
        'alias' => 'ttx-library/ekonomiska-biblioteket',
        'language' => 'sv',
      ),
    ),
  ));
  return $items;
}
