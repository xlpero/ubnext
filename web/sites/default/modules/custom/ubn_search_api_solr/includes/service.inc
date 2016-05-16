<?php
/**
 * Search service class using Solr server.
 */
class UBNSearchApiSolrService extends SearchApiSolrService  {
  /**
   * Implements SearchApiServiceInterface::__construct().
   *
   * The default implementation sets $this->server and $this->options.
   */
  public function __construct(SearchApiServer $server) {
    parent::__construct($server);
    $this->connection_class = 'UBNSearchApiSolrConnection';
  }
}
