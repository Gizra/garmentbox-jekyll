<?php

function _services_entity_resource_access($op, $args) {
  if ($op == 'create') {
    list($entity_type) = $args;
    // Pass the entity to the access control.
    return entity_access($op, $entity_type);
  }
  else {
    // Delete, Update.
    list($entity_type, $entity_id) = $args;

    // Load the corresponding entity.
    $entities = entity_load($entity_type, array($entity_data));
    if (empty($entities)) {
      return FALSE;
    }
    $entity = reset($entities);

    // Pass the entity to the access control.
    return entity_access($op, $entity_type, $entity);
  }
}

function _services_entity_resource_access_view() {
  // The access control is done at the level of each entity.
  return TRUE;
}

function _services_entity_resource_retrieve($entity_type, $entity_key, $fields) {
  // Build an EFQ to retrieve the entity. This also satisfies access control.
  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', $entity_type)
      ->addTag('service_entity_resource')
      ->addMetaData('entity_type', $entity_type);

  // If there's no : in the entity key, we're looking for the id.
  if (strpos($entity_key, ':') == 0) {
    $query->entityCondition('entity_id', $entity_key);
  }
  else {
    // First split the property key and the value.
    list($key, $value) = explode(':', $entity_key);
    // We need to be sure that is a unique property to avoid multiple results
    // index option should be used instead.
    $info = entity_get_info($entity_type);
    $schema = drupal_get_schema($info['base table']);
    if (!empty($schema['unique keys'][$key])) {
      $query->propertyCondition($key, $value);
    }
    else {
      // If this is not a unique property, avoid doing the query.
      return services_error(t('Loading an entity using a non unique property is not allowed.'), 404);
    }
  }

  $entities = $query->execute();

  if (!empty($query->ordered_results)) {
    $result = _services_postprocess_entities($entities, $query->ordered_results, $fields);
    return reset($result);
  }
  else {
    return services_error(t('No entities retrieved.'), 404);
  }
}

function _services_entity_resource_index($entity_type, $page, $bundle, $fields, $page_size) {
  // Build an EFQ based on the arguments.
  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', $entity_type)
      ->range($page * $page_size, $page_size);

  if (!empty($bundle)) {
    $query->entityCondition('bundle', $bundle, '=');
  }

  $entities = $query->execute();

  if (empty($entities)) {
    return services_error(t('No entities found.'), 404);
  }

  return _services_postprocess_entities($entities, $query->ordered_results, $fields);
}

function _services_postprocess_entities($entities, $ordered_results, $fields) {
  // Prepare the fields.
  $fields = _services_entity_transform_fields($fields);

  // Load the full entities.
  foreach ($entities as $entity_type => &$entities_of_type) {
    $entities_of_type = entity_load($entity_type, array_keys($entities_of_type));

    // Allow other modules to modify the returned entities.
    drupal_alter('services_entity_postprocess', $entities_of_type, $entity_type);
  }

  // Now return the entities in the correct order.
  $result = array();
  foreach ($ordered_results as $partial_entity) {
    if (isset($entities[$partial_entity->entity_type][$partial_entity->entity_id])) {
      $entity = $entities[$partial_entity->entity_type][$partial_entity->entity_id];

      $wrapper = entity_metadata_wrapper($partial_entity->entity_type, $entity);
      $entity_result = (object) services_entity_prepare_structure($wrapper, $fields);
      if (!empty($entity_result)) {
        $entity_result->uri = services_resource_uri(array('entity_' . $partial_entity->entity_type, $partial_entity->entity_id));
      }

      $result[] = $entity_result;
    }
  }

  // Allow other modules to alter the returned result.
  drupal_alter('services_entity_postprocess_result', $result, $partial_entity->entity_type);

  return $result;
}

function _services_entity_resource_create($entity_type, $values) {
  return entity_create($entity_type, $values);
}

function _services_entity_resource_update($entity_type, $entity) {
  return entity_save($entity_type, $entity);
}

function _services_entity_resource_delete($entity_type, $entity_id) {
  return entity_delete($entity_type, $entity_id);
}

/**
 * Recursive function to get all fields and the children of those fields
 * noted by field_name:child_name.
 */
function _services_entity_transform_fields(array $fields) {
  $transformed_fields = array();
  foreach ($fields as $field) {
    if (!strpos($field, ':') == 0) {
      list($parent, $child) = explode(':', $field, 2);
      $value = _services_entity_transform_fields(array($child));
      $transformed_fields[$parent] = isset($transformed_fields[$parent]) ? array_merge_recursive($transformed_fields[$parent], $value) : $value;
    }
    else {
      $transformed_fields[$field] = $field;
    }
  }

  return $transformed_fields;
}
