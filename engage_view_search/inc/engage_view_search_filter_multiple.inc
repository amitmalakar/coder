<?php
class engage_view_search_filter_multiple extends views_handler_filter {
  function value_form(&$form, &$form_state) {
    //parent::options_form($form, $form_state);
	// Step 1:
		//	Table Name : og
		//	Field NAme : og_private
		//	Private Group : 1 mean Active
		//	Private Group : 0 mean In-Active
	//	Since there are only 0/1 field therefore custom array created without using query
    $private_opt = array(1 => 'Yes', 0 => 'No');
    $show = array();
	foreach($private_opt as $key => $value) {
		$show[$key] = $value;
    }

    // Step 2: create a select field to choose Vocabulary options
    //   this allows you to choose which vocabulary to fetch terms for in the exposed filter
    $form['value'] = array(
      '#type' => 'select',
      '#title'  => t('Private Group Yes/No'),
      '#options'  => $show,
      '#default_value'  => $this->options['value']
    );
	return $form;
  }

  // the query method is responsible for actually running our exposed filter
  function query() {
	global $user;
	$user_id = $user->uid;

    // make sure our base table is included in the query.
    // base table for this is node so it may be redundent...
    $this->ensure_my_table();
    
    // make sure og table is joined in if needed
    $this->query->add_table('og');

    // make sure users table is joined in if needed
    $this->query->add_table('users');

    // get the value of the submitted filter
    $value = $this->value[0];

    $case = 'all';
    switch($case) {
      case 'all';
        $this->query->add_where($this->options['group'], "og.og_private = %d", $value);
        
        $this->query->add_where($this->options['group'], "users.uid = %d", $user_id);
        break;
    }
  }
}
