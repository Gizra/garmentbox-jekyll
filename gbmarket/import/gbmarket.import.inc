<?php

/**
 * @file
 */

/**
 * BatchAPI callback.
 *
 * Create gbmarket main-menu items.
 * @see gbmarket_import_data().
 */
function _gbmarket_create_main_menu() {
  // Build the main menu.
  $item = array(
    'link_path' => drupal_get_normal_path('garmentbox-platform/features'),
    'link_title' => 'Features',
    'weight' => 21,
    //'plid' => $mlid,
    'menu_name' => 'main-menu',
  );
   menu_link_save($item);

  $item = array(
    'link_path' => drupal_get_normal_path('garmentbox-platform/how-it-works'),
    'link_title' => 'How it works',
    'weight' => 22,
    //'plid' => $mlid,
    'menu_name' => 'main-menu',
  );
  menu_link_save($item);

  $item = array(
    'link_path' => drupal_get_normal_path('garmentbox-platform/hosting-plans'),
    'link_title' => 'Plans',
    'weight' => 23,
    //'plid' => $mlid,
    'menu_name' => 'main-menu',
  );
  menu_link_save($item);

  $item = array(
    'link_path' => 'add-ons',
    'link_title' => 'Add-ons',
    'weight' => 30,
    'menu_name' => 'main-menu',
    'customized' => 1,
  );
  menu_link_save($item);

  $item = array(
    'link_path' => 'services',
    'link_title' => 'Services',
    'weight' => 40,
    'menu_name' => 'main-menu',
    'customized' => 1,
  );
  menu_link_save($item);

  $item = array(
    'link_path' => drupal_get_normal_path('support'),
    'link_title' => 'Support',
    'weight' => 50,
    'menu_name' => 'main-menu',
  );
  menu_link_save($item);

  $item = array(
    'link_path' => 'training',
    'link_title' => 'Training',
    'weight' => 60,
    'menu_name' => 'main-menu',
    'customized' => 1,
  );
  menu_link_save($item);
}

/**
 * BatchAPI callback.
 *
 * Create gbmarket hosting sub-menu.
 * @see gbmarket_import_data().
 */
function _gbmarket_create_submenu_hosting() {
  $item = array(
    'link_path' => drupal_get_normal_path('garmentbox-platform/features'),
    'link_title' => 'Features',
    'weight' => 10,
    'menu_name' => 'menu-submenu-hosting',
  );
  menu_link_save($item);

  $item = array(
    'link_path' => drupal_get_normal_path('garmentbox-platform/how-it-works'),
    'link_title' => 'How it works',
    'weight' => 20,
    'menu_name' => 'menu-submenu-hosting',
  );
  menu_link_save($item);

  $item = array(
    'link_path' => drupal_get_normal_path('garmentbox-platform/hosting-plans'),
    'link_title' => 'Plans',
    'weight' => 30,
    'menu_name' => 'menu-submenu-hosting',
  );
  menu_link_save($item);
}

/**
 * BatchAPI callback.
 *
 * Update blocks settings.
 * @see gbmarket_import_data().
 */
function _gbmarket_update_blocks() {
  $block = array(
    'status' => BLOCK_CUSTOM_ENABLED,
    'weight' => 10,
    'region' => 'user_first',
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => 'garmentbox-platform*',
    'title' => '<none>',
  );
  db_update('block')
    ->fields($block)
    ->condition('module', 'panels_mini')
    ->condition('delta', 'commerce_platform_submenu')
    ->condition('theme', 'gbmarkettheme')
    ->execute();

  $block = array(
    'status' => BLOCK_CUSTOM_ENABLED,
    'weight' => 0,
    'region' => 'footer_first',
    'visibility' => BLOCK_VISIBILITY_NOTLISTED,
    'title' => '<none>',
  );
  db_update('block')
    ->fields($block)
    ->condition('module', 'panels_mini')
    ->condition('delta', 'footer')
    ->condition('theme', 'gbmarkettheme')
    ->execute();

  $block = array(
    'status' => BLOCK_CUSTOM_ENABLED,
    'weight' => 0,
    'region' => 'branding',
    'visibility' => BLOCK_VISIBILITY_NOTLISTED,
    'title' => '<none>',
  );
  db_update('block')
    ->fields($block)
    ->condition('module', 'system')
    ->condition('delta', 'main-menu')
    ->condition('theme', 'gbmarkettheme')
    ->execute();

  $block = array(
    'status' => BLOCK_CUSTOM_ENABLED,
    'weight' => 0,
    'region' => 'branding',
    'visibility' => BLOCK_VISIBILITY_NOTLISTED,
    'title' => '<none>',
  );
  db_update('block')
    ->fields($block)
    ->condition('module', 'system')
    ->condition('delta', 'user-menu')
    ->condition('theme', 'gbmarkettheme')
    ->execute();
}
