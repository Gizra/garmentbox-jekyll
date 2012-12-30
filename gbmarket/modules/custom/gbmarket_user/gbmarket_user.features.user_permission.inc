<?php
/**
 * @file
 * gbmarket_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function gbmarket_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: access checkout.
  $permissions['access checkout'] = array(
    'name' => 'access checkout',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: create commerce_customer_profile entities of bundle billing.
  $permissions['create commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'create commerce_customer_profile entities of bundle billing',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit own commerce_customer_profile entities of bundle billing.
  $permissions['edit own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'edit own commerce_customer_profile entities of bundle billing',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: use search_api_sorts.
  $permissions['use search_api_sorts'] = array(
    'name' => 'use search_api_sorts',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'search_api_sorts',
  );

  // Exported permission: view own commerce_customer_profile entities of bundle billing.
  $permissions['view own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'view own commerce_customer_profile entities of bundle billing',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'commerce_customer',
  );

  return $permissions;
}
