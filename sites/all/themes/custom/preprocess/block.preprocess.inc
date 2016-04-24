<?php

/**
 * @file
 * Contains a pre-process hook for 'block'.
 */

/**
 * Implements hook_preprocess_TEMPLATE().
 */
function custom_preprocess_block(&$variables) {
  $block = $variables['block'];
  if ($block->region == 'navigation' && _custom_is_menu_block($block)) {
    $variables['attributes_array']['class'][] = 'block--nav-bar';
  }
}
