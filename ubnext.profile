<?php
/**
 * @file
 */


/**
 * Implements hook_install().
 */
function ubnext_install() {
  theme_enable(array('ubnext'));
  theme_disable(array('bartik'));
}
