<?php

/**
 * Implements hook_action_info().
 */
function rules_demo_action_info() {
  $default_description = 'Default description from Code';
  $default_number_points = 10;
  return array(
    'rules_demo_action_trigger_points_manipulator' => array(
      'type' => 'user',
      'label' => 'Rules Demo | Action | VBO | Perform manipulator',
      'configurable' => FALSE,
      'behavior' => array('views_property'),
      // this passes the entire views row to the $context array
      'pass rows' => TRUE,
      // you can also define some other parameters that are passed via the $context array
      'parameters' => array(
        'points' => $default_number_points,
        'description' => $default_description,
      ),
    ),
  );
}

function rules_demo_action_trigger_points_manipulator(&$user, $context) {
  $event_name = 'rules_demo_event_points_manipulator';
  $points = $context['points'];
  $description = $context['description'];
  $progress_index = $context['progress']['current'] - 1;
  if ($context['rows'][$progress_index]->users_userpoints_total__userpoints_total_points === NULL) {
    $points = 100;
  }
  // call event which will trigger the action on the user via Rules
  rules_invoke_event($event_name, $user, $points, $description);
}
