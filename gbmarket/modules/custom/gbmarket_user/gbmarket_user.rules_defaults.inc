<?php
/**
 * @file
 * gbmarket_user.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function gbmarket_user_default_rules_configuration() {
  $items = array();
  $items['rules_account_created'] = entity_import('rules_config', '{ "rules_account_created" : {
      "LABEL" : "Account created",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_insert" ],
      "DO" : [
        { "drupal_message" : { "message" : "Thanks for signing up on our Marketplace!" } }
      ]
    }
  }');
  return $items;
}
