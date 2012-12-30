<?php
/**
 * @file
 * gbmarket_trainings.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function gbmarket_trainings_taxonomy_default_vocabularies() {
  return array(
    'audience_types' => array(
      'name' => 'Audience types',
      'machine_name' => 'audience_types',
      'description' => NULL,
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
