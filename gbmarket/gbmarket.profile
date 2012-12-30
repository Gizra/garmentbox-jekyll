<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function gbmarket_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/**
 * Implements hook_install_tasks().
 */
function gbmarket_install_tasks() {
  $tasks = array();

  $tasks['gbmarket_import_data'] = array(
    'display_name' => st('Import content'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );
  return $tasks;
}

/**
 * Task callback: return a batch API array, for importing content and creating
 * menues.
 */
function gbmarket_import_data() {
  drupal_set_title(st('Import content'));

  // Fixes problems when the CSV files used for importing have been created
  // on a Mac, by forcing PHP to detect the appropriate line endings.
  ini_set('auto_detect_line_endings', TRUE);

  $migrations = migrate_migrations();

  $operations[] = array('_gbmarket_create_terms', array(t('Creating taxonomy terms.')));
  $operations[] = array('_gbmarket_create_main_menu', array(t('Building main menu.')));
  $operations[] = array('_gbmarket_create_submenu_hosting', array(t('Building hosting sub-menu.')));
  $operations[] = array('_gbmarket_update_blocks', array(t('Update blocks settings.')));

  $batch = array(
    'title' => t('Importing content'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'gbmarket') . '/import/gbmarket.import.inc',
  );

  return $batch;
}
