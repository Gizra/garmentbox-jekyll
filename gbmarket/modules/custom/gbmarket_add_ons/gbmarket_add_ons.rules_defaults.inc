<?php

/**
 * Implements hook_default_rules_configuration_alter().
 *
 * Disable add-to-cart message.
 */
function gbmarket_add_ons_default_rules_configuration_alter(&$configs) {
  if (isset($configs['commerce_cart_add_to_cart_message'])) {
    $configs['commerce_cart_add_to_cart_message']->active = FALSE;
  }
}
