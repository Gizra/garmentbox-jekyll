<?php

/**
 * @file
 * Page preprocessing.
 */

/**
 * Preprocess page display.
 */
function gbmarkettheme_alpha_preprocess_page(&$vars) {
  $vars['title'] = '';
  unset($vars['page']['content']['content']['content']['#grid']);
}
