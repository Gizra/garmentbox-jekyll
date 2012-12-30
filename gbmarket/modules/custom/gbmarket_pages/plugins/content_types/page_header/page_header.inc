<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Page header'),
  'description' => t('Present the menu on top of the slide show.'),
  'category' => t('gbmarket'),
  'hook theme' => 'gbmarket_pages_page_header_content_type_theme',
);

/**
 * Render callback.
 */
function gbmarket_pages_page_header_content_type_render($subtype, $conf, $args, $context) {
  global $user;

  // The title and subtitle will be extracted from a wrapper, which will either
  // be the viewed node or a page_title node retrieved from an entity query.
  $object = menu_get_object();

  if ($object) {
    $wrapper = entity_metadata_wrapper('node', $object);

    // If the viewed node is a training_session, set its category as the
    // subtitle.
    if ($object->type == 'training_session') {
      $subtitle = $wrapper->field_training_category->label();
    }
  }
  else {
    $item = menu_get_item();

    if ($item['path'] == 'training-sessions/%') {
      $wrapper = entity_metadata_wrapper('node', $item['map'][1]->data);
    }
    else {
      $query = new EntityFieldQuery();
      $result = $query
        ->entityCondition('entity_type', 'node')
        ->propertyCondition('type', 'page_title')
        ->fieldCondition('field_path', 'value', $item['path'])
        ->range(0, 1)
        ->execute();
      if (!$result) {
        return;
      }

      $nids = array_keys($result['node']);
      $wrapper = entity_metadata_wrapper('node', $nids[0]);
    }
  }

  $variables['title'] = $wrapper->label();
  if (isset($subtitle)) {
    $variables['subtitle'] = $subtitle;
  }
  else {
    $variables['subtitle'] = !empty($wrapper->field_subtitle) ? $wrapper->field_subtitle->value() : '';
  }

  $block = new stdClass();
  $block->module = 'gbmarket_promo';
  $block->content = theme('gbmarket_theme_page_header', $variables);
  $block->css_class = 'clearfix';

  return $block;
}

/**
 * Form callback.
 */
function gbmarket_pages_page_header_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function gbmarket_pages_page_header_content_type_theme(&$theme, $plugin) {
  $theme['gbmarket_theme_page_header'] = array(
    'variables' => array(
      'title' => NULL,
      'subtitle' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'page-header',
  );
}
