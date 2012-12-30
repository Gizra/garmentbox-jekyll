<?php
/**
 * @file
 * gbmarket_add_ons.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function gbmarket_add_ons_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'current_search_add_ons';
  $item->label = 'Current Search add ons';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => 'Search found [facetapi_results:result-count] item',
        'plural' => 1,
        'text_plural' => 'Search found [facetapi_results:result-count] items',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 0,
        'element' => '0',
        'css' => 0,
        'classes' => '',
        'weight' => '-50',
      ),
      '_facetapi_active_active_value_' => array(
        'id' => 'active',
        'label' => '[facetapi_active:active-value]',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'css' => 0,
        'classes' => '',
        'nofollow' => 1,
        'weight' => '-49',
      ),
    ),
    'advanced' => array(
      'empty_searches' => 0,
    ),
  );
  $export['current_search_add_ons'] = $item;

  return $export;
}
