<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Sub-menu'),
  'description' => t('Dispaly a sub-menu for basic pages.'),
  'category' => t('gbmarket'),
  'required context' => new ctools_context_optional(t('Node'), 'node'),
);

/**
 * Render callback.
 */
function gbmarket_pages_submenu_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }

  $node = $context->data;
  $wrapper = entity_metadata_wrapper('node', $node);
  if (empty($wrapper->field_submenu)) {
    return;
  }

  $menu_name = $wrapper->field_submenu->value();
  $menu = menu_tree($menu_name);

  $block = new stdClass();
  $block->module = 'gbmarket_pages';
  $block->content = drupal_render($menu);
  return $block;
}

/**
 * Form callback.
 */
function gbmarket_pages_submenu_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  return $form;
}
