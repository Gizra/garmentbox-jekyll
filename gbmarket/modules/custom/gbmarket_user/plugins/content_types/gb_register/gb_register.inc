<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('GBMarket register'),
  'description' => t('Display the registration form.'),
  'category' => t('gbmarket'),
);

/**
 * Render callback.
 */
function gbmarket_user_gb_register_content_type_render($subtype, $conf, $args, $context) {
  global $user;

  $block = new stdClass();
  $block->title = t('Start now, free');
  $block->module = 'gbmarket_user';
  $block->content = drupal_get_form('user_register_form');

  return $block;
}

/**
 * Form callback.
 */
function gbmarket_user_gb_register_content_type_edit_form($form, &$form_state) {
  return $form;
}
