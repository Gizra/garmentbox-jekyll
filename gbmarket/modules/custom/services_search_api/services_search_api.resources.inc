<?php

/**
 * Callback function for the index service call.
 */
function _services_search_api_resource_retrieve($index, $filter, $sort, $limit, $offset, $fields) {
  $options = array(
    'parse mode' => 'terms',
    'limit' => $limit,
    'offset' => $offset,
  );

  // Initialize the query object.
  $query = search_api_query($index, $options);
  // Set the filters.
  if (!empty($filter)) {
    $query_filters = unserialize($filter);
    foreach ($query_filters as $query_filter) {
      list($field_name, $value, $operator) = $query_filter;
      $query->condition($field_name, $value, $operator);
    }
  }

  // Also set sorts.
  if (!empty($sort) && is_array($sort)) {
    foreach ($sort as $field => $mode) {
      $query->sort($field, $mode);
    }
  }

  $result = $query->execute();
  return _services_search_api_process_results($result, $query, $fields);
}

function _services_search_api_process_results($result, $query, $fields) {
  if (empty($result['results']) || !is_array($result['results'])) {
    return array();
  }
  $result += array(
    'search_api_facets' => array(),
  );

  module_load_include('inc', 'services_entity', 'services_entity.resources');
  $fields = _services_entity_transform_fields($fields);

  $entity_type = $query->getIndex()->item_type;
  $entities = entity_load($entity_type, array_keys($result['results']));

  // Allow other modules to alter the entities retrieved.
  drupal_alter('services_search_api_postprocess', $entities, $entity_type);

  foreach ($entities as $entity_id => $entity) {
    // Transform entities and add extra information to properties.
    $wrapper = entity_metadata_wrapper($entity_type, $entity);
    $entities[$entity_id] = (object) services_entity_prepare_structure($wrapper, $fields, $entity_type);
  }

  return array('results' => $entities, 'search_api_facets' => $result['search_api_facets']);
}
