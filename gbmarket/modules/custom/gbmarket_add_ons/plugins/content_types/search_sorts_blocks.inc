<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Search sorts."),
  // 'single' means not to be subtyped.
  'single' => TRUE,
  'description' => '',
  // Name of a function which will render the block.
  'render callback' => 'gbmarket_add_ons_sort_panels_manage_render',
  'category' => t('gbmarket'),
  'render last' => TRUE,
);


/**
 * Render the current search block.
 */
function gbmarket_add_ons_sort_panels_manage_render($subtype, $conf, $panel_args) {
  $block_current_search = module_invoke('search_api_sorts', 'block_view', 'search-sorts');
  $block = new stdClass();
  $block->title = t('Sort by');
  $block->content = $block_current_search['content'];
  return $block;
}
