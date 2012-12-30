<?php
/**
 * @file
 * gbmarket_content.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gbmarket_content_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'page_elements';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Page elements';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Page ID (field_page_id) */
  $handler->display->display_options['arguments']['field_page_id_value']['id'] = 'field_page_id_value';
  $handler->display->display_options['arguments']['field_page_id_value']['table'] = 'field_data_field_page_id';
  $handler->display->display_options['arguments']['field_page_id_value']['field'] = 'field_page_id_value';
  $handler->display->display_options['arguments']['field_page_id_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_page_id_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_page_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_page_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_page_id_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Section ID (field_section_id) */
  $handler->display->display_options['arguments']['field_section_id_value']['id'] = 'field_section_id_value';
  $handler->display->display_options['arguments']['field_section_id_value']['table'] = 'field_data_field_section_id';
  $handler->display->display_options['arguments']['field_section_id_value']['field'] = 'field_section_id_value';
  $handler->display->display_options['arguments']['field_section_id_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_section_id_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_section_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_section_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_section_id_value']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page_element' => 'page_element',
  );

  /* Display: Page elements */
  $handler = $view->new_display('panel_pane', 'Page elements', 'panel_page_elements');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'field_page_id_value' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Page ID',
    ),
    'field_section_id_value' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Section ID',
    ),
  );
  $translatables['page_elements'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('All'),
    t('Page elements'),
    t('View panes'),
  );
  $export['page_elements'] = $view;

  return $export;
}
