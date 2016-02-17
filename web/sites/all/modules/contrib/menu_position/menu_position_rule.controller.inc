<?php
/**
 * Controller class for menu position rules.
 *
 */

class MenuPositionRuleController extends EntityAPIController {

  protected function attachLoad(&$menu_links, $revision_id = FALSE) {
    foreach ($menu_links as $mlid => &$item) {
    }
    parent::attachLoad($menu_links, $revision_id);
  }

  /**
   * Overrides delete from EntityAPIController
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    foreach ($ids as $rid) {
      menu_position_rule_delete($rid);
    }
  }

  /**
   * Overrides save from EntityAPIController
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $rule = (array) $entity;
    $rid = menu_position_rule_save($rule);
    if (FALSE === $rid) {
      $transaction->rollback();
      throw new Exception('Could not save menu position rule');
    }
    $entity->rid = $rid;
  }

}
