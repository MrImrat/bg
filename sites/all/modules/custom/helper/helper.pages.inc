<?php

//helper_menu page callback 
function _json_output(){
	$data = _get_facebook_share_data();
	
	$json = array();
	
	foreach($data as $id => $item){
		$json[] = array(
						'path' => $id,
						'shares' => (!isset($item['shares']) || empty($item['shares']))? 'none' : $item['shares']
						);
	}
	
	drupal_json_output($json);
}

//access block site info
function _access_block_site_info($access){
 global $user;
 //$access_message = t('You don’t have an access');
 switch($access){
    case 'all':
           return TRUE;
        break;
    case 'auth':
          $logged_in = (bool)$user->uid;
          return $logged_in;
        break;
    case 'admin':
            return in_array('administrator', $user->roles);
        break;
 }
}

//site_info_form page callback 
function site_info_form($form, &$form_state){
    $options = array(
        'all' => 'All users',
        'auth' => 'Auth users',
        'admin' => 'Admins'
    );
    
    $default_value = variable_get('site_info_page_radio');
    
    $form['radios'] = array(
        '#type' => 'radios',
        '#default_value' => $default_value,
        '#options' => $options
    );
    
    $form['save'] = array(
        '#type' => 'submit',
        '#value' => 'Save'
    );
    
    return $form;
}

//submit 
function site_info_form_submit(&$form, &$form_state){
    $value = $form_state['values']['radios'];
    variable_set('site_info_page_radio', $value);
}

//data facebook share
function _get_facebook_share_data(){
	$urls = array(
		'https://basegroup.ru/',
		'https://basegroup.ru/deductor/description',
		'http://yandex.ru',
		'https://basegroup.ru/service/introduction',
		'https://basegroup.ru/service/learning',
		'https://www.drupal.org/'
	);
	
	$ids = implode(',',$urls);
	
	$facebook_url = 'http://graph.facebook.com/?ids=' . $ids;
	
	$request = drupal_http_request($facebook_url);
	
	return drupal_json_decode($request->data);
}

//Counts items
function _count_items($type){
	switch ($type) {
		case 'comment':
			$query = db_select('comment');
			$query->addExpression('COUNT(*)');
			$count = $query->execute()->fetchField();
			
			return $count;
			
			break;
		case 'node':
			$query = db_select('node');
			$query->addExpression('COUNT(*)');
			$count = $query->execute()->fetchField();
			
			return $count;
			
			break;
		case 'user':
			$query = db_select('users');
			$query->addExpression('COUNT(*)');
			$count = $query->execute()->fetchField();
			
			return $count;
			
			break;
		case 'node_type':
			$query = db_select('node_type');
			$query->addExpression('COUNT(*)');
			$count = $query->execute()->fetchField();
			
			return $count;
			break;
		case 'fields':
			$query = db_select('field_config_instance', 'fci')->condition('fci.entity_type', 'node');
			$query->addExpression('COUNT(DISTINCT field_name)');
			$count = $query->execute()->fetchField();
			
			return $count;
			break;
	}
}