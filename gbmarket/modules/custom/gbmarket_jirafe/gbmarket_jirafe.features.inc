<?php
/**
 * @file
 * gbmarket_jirafe.features.inc
 */

/**
 * Implements hook_default_message_type().
 */
function gbmarket_jirafe_default_message_type() {
  $items = array();
  $items['jirafe_service_added'] = entity_import('message_type', '{
    "name" : "jirafe_service_added",
    "description" : "Jirafe service added",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type_email",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null
  }');
  return $items;
}
