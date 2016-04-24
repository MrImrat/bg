<?php

// Plugin definition
$plugin = array(
  'title' => t('Custom layout'), 
  'category' => 'custom layout',
  'icon' => 'onerowtwocols.png',
  'theme' => 'onerowtwocols',
  'css' => 'onerowtwocols.css',
  'regions' => array(
    'top' => t('Top'),
    'content' => t('Content'), 
  ),
);