<?php
/**
 * @file
 * gbmarket_marketplace_api.oauth.inc
 */

/**
 * Implements hook_default_oauth_common_context().
 */
function gbmarket_marketplace_api_default_oauth_common_context() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 1;
  $context->name = 'gbmarket_marketplace_api';
  $context->title = 'gbmarket Marketplace Context';
  $context->authorization_options = array(
    'access_token_lifetime' => NULL,
    'page_title' => NULL,
    'message' => NULL,
    'warning' => NULL,
    'deny_access_title' => NULL,
    'grant_access_title' => NULL,
    'disable_auth_level_selection' => NULL,
    'signature_methods' => array(
      0 => 'PLAINTEXT',
      1 => 'HMAC-SHA1',
      2 => 'HMAC-SHA256',
      3 => 'HMAC-SHA384',
      4 => 'HMAC-SHA512',
    ),
    'default_authorization_levels' => array(
      0 => 'read',
    ),
  );
  $context->authorization_levels = array(
    'read' => array(
      'name' => 'read',
      'title' => 'Read data',
      'default' => 1,
      'delete' => 0,
      'description' => 'Allows read only access to the data.',
    ),
  );
  $export['gbmarket_marketplace_api'] = $context;

  return $export;
}
