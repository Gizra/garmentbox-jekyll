<?php

/**
 * Callback function for the index service call.
 */
function services_search_api_index_resource_retrieve($index, $fields) {
  $property_info = array();
  // This will allow us to dynamically retrieve the remote index properties.
  if ($search_index = search_api_index_load($index)) {
    $property_info = $search_index->entityWrapper()->getPropertyInfo();
  }
  $options_list = array();
  if (!empty($fields)) {
    foreach ($fields as $field_name) {
      if (($field = field_info_field($field_name)) && $field['type'] == 'taxonomy_term_reference') {
        $options_list[$field_name] = taxonomy_allowed_values($field);
      }
    }
  }
  else {
    if (module_exists('search_api_facetapi')) {
      foreach (facetapi_get_enabled_facets('search_api@' . $index) as $key => $facet) {
        if (!isset($facet['field type'])) {
          continue;
        }
        if ($facet['field type'] == 'taxonomy_term') {
          $options_list[$key] = taxonomy_allowed_values(field_info_field($key));
        }
      }
    }
  }
  return array(
    'property info' => $property_info,
    'options list' => $options_list,
  );
}
