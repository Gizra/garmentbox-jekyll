<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Strip menu'),
  'description' => t('Present the menu on top of the slide show.'),
  'category' => t('gbmarket'),
  'hook theme' => 'gbmarket_promo_strip_menu_content_type_theme',
);

/**
 * Render callback.
 */
function gbmarket_promo_strip_menu_content_type_render($subtype, $conf, $args, $context) {
  global $user;

  $path = drupal_get_path('theme', 'gbmarkettheme') . '/images';

  $tree = menu_tree_all_data('main-menu');
  $variables['main_menu'] = menu_tree_output($tree);

  $variables['linked_logo_img'] = l(theme('image', array('path' => theme_get_setting('logo'))), '<front>', array('html' => TRUE));

  $block = new stdClass();
  $block->module = 'gbmarket_promo';
  $block->content = theme('gbmarket_theme_strip_menu', $variables);
  $block->css_class = 'clearfix';

  return $block;
}

/**
 * Form callback.
 */
function gbmarket_promo_strip_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
*/
function gbmarket_promo_strip_menu_content_type_theme(&$theme, $plugin) {
  $theme['gbmarket_theme_strip_menu'] = array(
    'variables' => array(
      'linked_logo_img' => NULL,
      'main_menu' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'strip-menu',
  );
}
