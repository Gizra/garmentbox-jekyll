<?php

/**
 * @file template.php
 *
 * Contains theme override functions and preprocess functions for the theme.
 */

/**
 * Implements theme_preprocess_html().
 *
 * Add a CSS class based on the current page context.
 */
function gbmarkettheme_preprocess_html(&$variables) {
  if (drupal_is_front_page()) {
    return;
  }

  $context = str_replace('/', '--', drupal_get_path_alias());
  if (!empty($context)) {
    $variables['attributes_array']['class'][] = drupal_html_class($context);
  }

  // Add conditional stylesheets for IE
  drupal_add_css(path_to_theme() . '/css/gbmarkettheme-ie-lte-8.css', array('group' => CSS_THEME, 'weight' => 999, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'preprocess' => FALSE));
}

/**
 * Implements hook_process_region().
 */
function gbmarkettheme_process_region(&$variables) {
  if ($variables['elements']['#region'] == 'menu') {
    $variables['main_menu'] = NULL;
    $variables['secondary_menu'] =  NULL;
  }
}

/**
 * Implements hook_preprocess_zone();
 */
function gbmarkettheme_preprocess_zone(&$variables) {
  $item = menu_get_item();
  $theme = alpha_get_theme();

  if (strpos($item['path'], 'user/%') !== 0)  {
    return;
  }

  // Not all user pages have tabs (ie. orders).
  if (is_array($theme->page['tabs']['#primary'])) {
    foreach ($theme->page['tabs']['#primary'] as $item) {
      $items[] = l($item['#link']['title'], $item['#link']['href']);
    }

    $variables['tabs'] = theme('item_list', array(
      'items' => $items,
      'type' => 'ul',
    ));
  }

  // Add Action Links variable for content zone.
  if (is_array($theme->page['action_links'])) {
    foreach ($theme->page['action_links'] as $alink) {
      $alinks[] = l($alink['#link']['title'], $alink['#link']['href']);
    }

    if (!empty($alinks)) {
      $variables['action_links'] = theme('item_list', array(
        'items' => $alinks,
        'type' => 'ul',
      ));
    } else {
      $variables['action_links'] = '';
    }
  }
}

/**
 * Implements template_preprocess_section().
 */
function gbmarkettheme_preprocess_section(&$variables) {
  if ($variables['section'] != 'header') {
    return;
  }

  global $user;

  $variables['shopping_cart_detail'] = '';

  $order = commerce_cart_order_load($user->uid);

  if (!empty($order)) {
    $wrapper = entity_metadata_wrapper('commerce_order', $order->order_id);

    $total = array();

    foreach ($wrapper->commerce_line_items as $wrapper_line_item) {
      $value = $wrapper_line_item->commerce_product->commerce_price->value();
      $total[] = $value['amount'];
    }

    $variables['shopping_cart_detail'] = '<div class="cart">';
    $variables['shopping_cart_detail'] .= '<span class="items-number">';
    $variables['shopping_cart_detail'] .= l(format_plural(count($total), t('1 item'), t('@items items', array('@items' => count($total)))), 'cart');
    $variables['shopping_cart_detail'] .= '</span><span class="items-total">';
    $variables['shopping_cart_detail'] .= '$' . array_sum($total) / 100;
    $variables['shopping_cart_detail'] .= '</span>';
    $variables['shopping_cart_detail'] .= l(t('Checkout'), 'checkout', array('attributes' => array('class' => array('first'))));
    $variables['shopping_cart_detail'] .= '</div>';
  }
}

/**
 * Implements theme_preprocess_node().
 */
function gbmarkettheme_preprocess_node(&$variables) {
  if (!in_array($variables['type'], array('training_category', 'webform'))) {
    return;
  }

  $function = 'gbmarkettheme_preprocess_node_' . $variables['type'];

  if ($variables['view_mode'] != 'full') {
    $function .= '_' . $variables['view_mode'];
  }

  $function($variables);
}

/**
 * Implements template_preprocess_entity().
 *
 * Remove un-needed data from service details view mode of line-items.
 */
function gbmarkettheme_preprocess_entity(&$variables) {
  if ($variables['entity_type'] != 'commerce_line_item' || $variables['view_mode'] != 'service_details') {
    return;
  }

  unset($variables['content']['product:title']);
  unset($variables['content']['product:sku']);
  unset($variables['content']['product:commerce_price']);
  $variables['title'] = '';
}

/**
 * Custom callback for webform teaser preprocess.
 */
function gbmarkettheme_preprocess_node_webform_teaser(&$variables) {
  $variables['url'] = url('node/' . $variables['nid']);
  $variables['theme_hook_suggestions'][] = 'node__webform__teaser';
}
