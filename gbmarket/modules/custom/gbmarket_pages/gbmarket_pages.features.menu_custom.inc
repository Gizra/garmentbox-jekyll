<?php
/**
 * @file
 * gbmarket_pages.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function gbmarket_pages_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-submenu-hosting.
  $menus['menu-submenu-hosting'] = array(
    'menu_name' => 'menu-submenu-hosting',
    'title' => 'Sub-menu - Hosting',
    'description' => 'Sub-menu for hosting related basic pages.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Sub-menu - Hosting');
  t('Sub-menu for hosting related basic pages.');


  return $menus;
}
