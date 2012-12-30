<?php

/**
 * Implementation of hook_services_resources().
 */
function services_entity_services_resources() {
  $resources = array();

  foreach (entity_get_info() as $entity_type => $info) {
    $resources["entity_$entity_type"]['retrieve'] = array(
      'file' => array('type' => 'inc', 'module' => 'services_entity', 'name' => 'services_entity.resources'),
      'callback' => '_services_entity_resource_retrieve',
      'args' => array(
        array(
          'name' => 'entity_type',
          'optional' => TRUE,
          'default value' => $entity_type,
          'type' => 'string',
          'description' => 'The type of the entity to get',
        ),
        array(
          'name' => 'entity_key',
          'optional' => FALSE,
          'source' => array('path' => 0),
          'type' => 'int',
          'description' => 'The ID of the entity to get or a unique property of the entity in the form property:value',
        ),
        array(
          'name' => 'fields',
          'optional' => TRUE,
          'type' => 'array',
          'description' => 'The fields to get, if fields are from a related entity, use field_relationship:field_name for getting a given field or field_relationship_* for getting the whole set of data',
          'default value' => array(),
          'source' => array('param' => 'fields'),
        ),
      ),
      'access callback' => '_services_entity_resource_access_view',
    );

    $resources["entity_$entity_type"]['index'] = array(
      'file' => array('type' => 'inc', 'module' => 'services_entity', 'name' => 'services_entity.resources'),
      'callback' => '_services_entity_resource_index',
      'args' => array(
        array(
          'name' => 'entity_type',
          'optional' => TRUE,
          'default value' => $entity_type,
          'type' => 'string',
          'description' => 'The type of the entity to get',
        ),
        array(
          'name' => 'page',
          'optional' => TRUE,
          'type' => 'int',
          'description' => 'The zero-based index of the page to get, defaults to 0.',
          'default value' => 0,
          'source' => array('param' => 'page'),
        ),
        array(
          'name' => 'bundle',
          'optional' => TRUE,
          'type' => 'string',
          'description' => 'Get all entities of a given bundle of the entity type',
          'default value' => '',
          'source' => array('param' => 'bundle'),
        ),
        array(
          'name' => 'fields',
          'optional' => TRUE,
          'type' => 'array',
          'description' => 'The fields to get.',
          'default value' => array(),
          'source' => array('param' => 'fields'),
        ),
        array(
          'name' => 'pagesize',
          'optional' => TRUE,
          'type' => 'int',
          'description' => 'Number of records to get per page.',
          'default value' => variable_get('services_entity_' . $entity_type . '_index_page_size', 20),
          'source' => array('param' => 'pagesize'),
        ),
      ),
      'access callback' => '_services_entity_resource_access_view',
    );

    if (module_exists('entity') && entity_type_supports($entity_type, 'create')) {
      $resources["entity_$entity_type"]['create'] = array(
        'file' => array('type' => 'inc', 'module' => 'services_entity', 'name' => 'services_entity.resources'),
        'callback' => '_services_entity_resource_create',
        'args' => array(
          array(
            'name' => 'entity_type',
            'optional' => TRUE,
            'default value' => $entity_type,
            'type' => 'string',
            'description' => 'The type of the entity to create',
          ),
          array(
            'name' => 'values',
            'optional' => FALSE,
            'source' => 'data',
            'description' => 'The values used to create the entity',
            'type' => 'struct',
          ),
        ),
        'access callback' => '_services_entity_resource_access',
        'access arguments' => array('create'),
        'access arguments append' => TRUE,
      );
    }

    if (module_exists('entity') && entity_type_supports($entity_type, 'save')) {
      $resources["entity_$entity_type"]['update'] = array(
        'file' => array('type' => 'inc', 'module' => 'services_entity', 'name' => 'services_entity.resources'),
        'callback' => '_services_entity_resource_update',
        'args' => array(
          array(
            'name' => 'entity_type',
            'optional' => TRUE,
            'default value' => $entity_type,
            'type' => 'string',
            'description' => 'The type of the entity to update',
          ),
          array(
            'name' => 'entity_id',
            'optional' => FALSE,
            'source' => array('path' => 0),
            'type' => 'int',
            'description' => 'The nid of the node to update',
          ),
          array(
            'name' => 'entity',
            'optional' => FALSE,
            'source' => 'data',
            'description' => 'The entity data to update',
            'type' => 'struct',
          ),
        ),
        'access callback' => '_services_entity_resource_access',
        'access arguments' => array('update'),
        'access arguments append' => TRUE,
      );
    }

    if (module_exists('entity') && entity_type_supports($entity_type, 'delete')) {
      $resources["entity_$entity_type"]['update'] = array(
        'file' => array('type' => 'inc', 'module' => 'services_entity', 'name' => 'services_entity.resources'),
        'callback' => '_services_entity_resource_delete',
        'args' => array(
          array(
            'name' => 'entity_type',
            'optional' => TRUE,
            'default value' => $entity_type,
            'type' => 'string',
            'description' => 'The type of the entity to delete',
          ),
          array(
            'name' => 'entity_id',
            'optional' => FALSE,
            'source' => array('path' => 0),
            'type' => 'int',
            'description' => 'The nid of the node to delete',
          ),
        ),
        'access callback' => '_services_entity_resource_access',
        'access arguments' => array('delete'),
        'access arguments append' => TRUE,
      );
    }
  }

  return $resources;
}
