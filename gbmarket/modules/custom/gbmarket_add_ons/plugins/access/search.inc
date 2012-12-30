<?php

/**
 * @file
 * Plugin to provide access control based on the search (search_api) status.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Currently searching"),
  'description' => t('Control access by checking the current site.'),
  'callback' => 'gbmarket_add_on_ctools_access_check',

);

/**
 * Check for access.
 */
function gbmarket_add_on_ctools_access_check($conf, $context) {
  if (isset($_GET['f']) || isset($_GET['search_api_views_fulltext'])) {
    return FALSE;
  }
  return TRUE;
}
