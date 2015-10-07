<?php
/**
 * @file
 * rules_demo.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rules_demo_default_rules_configuration() {
  $items = array();
  $items['rules_rd_passing_data_form_view_to_event'] = entity_import('rules_config', '{ "rules_rd_passing_data_form_view_to_event" : {
      "LABEL" : "RD | Passing data form View to Event",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "userpoints_rules", "rules_demo" ],
      "ON" : { "rules_demo_event_points_manipulator" : [] },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "user" ],
            "points" : [ "points" ],
            "tid" : "0",
            "entity" : [ "" ],
            "operation" : "[description:value]",
            "display" : "1",
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  return $items;
}
