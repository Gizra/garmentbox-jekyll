<?php
/**
 * @file
 * gbmarket_add_ons.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function gbmarket_add_ons_taxonomy_default_vocabularies() {
  return array(
    'add_on_category' => array(
      'name' => 'Add-on category',
      'machine_name' => 'add_on_category',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
