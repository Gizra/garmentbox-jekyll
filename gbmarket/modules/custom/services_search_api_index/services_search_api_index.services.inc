<?php

/**
 * Implementation of hook_services_resources().
 */
function services_search_api_index_services_resources() {
  return array(
    'search_api_index' => array(
      'retrieve' => array(
        'file' => array('type' => 'inc', 'module' => 'services_search_api_index', 'name' => 'services_search_api_index.resources'),
        'callback' => 'services_search_api_index_resource_retrieve',
        'args' => array(
          array(
            'name' => 'index',
            'type' => 'string',
            'optional' => FALSE,
            'source' => array('path' => '0'),
            'description' => t('Search API index machine name to use.'),
          ),
          array(
            'name' => 'fields',
            'type' => 'array',
            'optional' => TRUE,
            'source' => array('param' => 'fields'),
            'default value' => '',
            'description' => t('Fields to retrieve the optionsList.'),
          ),
        ),
        'access arguments' => array('access content'),
        'access arguments append' => FALSE,
      ),
    ),
  );
}
