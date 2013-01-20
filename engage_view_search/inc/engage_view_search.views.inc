<?php
/**
* Implementation of hook_views_handlers() to register all of the basic handlers
* views uses.
*/
function engage_view_search_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'engage_view_search') . '/inc', // path to view files
    ),
    'handlers' => array(
      // register our custom filter, with the class/file name and parent class
      'engage_view_search_filter_multiple' => array(
        'parent' => 'views_handler_filter',
      )
    ),
  );
}

/*
 * Implementation of hook_views_data()
 */
function engage_view_search_views_data() {
  $data = array();
  // The flexible date filter.
  $data['node']['engage_view_search'] = array(
    'group' => t('Engage views'),
    'real field'  => 'engage_view_search',
    'title' => t('Private'),
    'help' => t('Filter Private content'),
    'filter' => array(
      'handler' => 'engage_view_search_filter_multiple'
    ),
  );

  return $data;
}
