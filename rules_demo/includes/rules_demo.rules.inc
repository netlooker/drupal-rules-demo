<?php

/**
 * Implementation of hook_rules_event_info().
 */
function rules_demo_rules_event_info() {
  return array(
    'rules_demo_event_points_manipulator' => array(
      'label' => t('Points manipulator special event'),
      'module' => 'rules_demo',
      'group' => 'Rules Demo',
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('User object')),
        'points' => array('type' => 'integer', 'label' => t('Number of points')),
        'description' => array('type' => 'text', 'label' => t('Description for points operation')),
      ),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function rules_demo_rules_condition_info() {
  return array(
    'rules_demo_condition_check_answers' => array(
      'label' => t('Check if answers in given test are correct'),
      'module' => 'rules_demo',
      'group' => 'Rules Demo' ,
      'parameter' => array(
        'ef_submission' => array(
          'type' => 'entityform',
          'label' => t('Entity form submission'),
        ),
      ),
      'callbacks' => array('execute' => '_rules_demo_condition_check_answers_callback'),
    ),
  );
}

/**
 * Custom condition callback
 * @param $ef_submission
 * @return bool
 */
function _rules_demo_condition_check_answers_callback($ef_submission) {
  $ef_wrapper = entity_metadata_wrapper('entityform', $ef_submission);
  //TODO here we should do something during the demo
  return TRUE;
}

/**
 * Implements hook_rules_action_info().
 */
function rules_demo_rules_action_info() {
  return array(
    'rules_demo_action_double_points' => array(
      'label' => t('Double points'),
      'parameter' => array(
        'points_in' => array(
          'type' => 'integer',
          'label' => t('Number of points'),
          'default mode' => 'input',
        ),
      ),
      'provides' => array(
        'points_out' => array(
          'type' => 'integer',
          'label' => t('Doubled number of points'),
        ),
      ),
      'group' => 'Rules Demo',
      'callbacks' => array('execute' => '_rules_demo_action_double_points_callback'),
    ),
  );
}

/**
 * Custom action callback
 * @param $points_in
 * @return array
 */
function _rules_demo_action_double_points_callback($points_in) {
  // Provide variable for Rules
  return array(
    'points_out' => $points_in * 2,
  );
}