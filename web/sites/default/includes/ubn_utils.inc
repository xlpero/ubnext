<?php

/**
 * @file
 * Custom utility functions for Gothenburg University Library site.
 */

/**
 * Generates a customized string representation for the given byte count.
 * It is based on the format_size function in includes/common.inc
 * Though in UBNext we don't want decimals for the file sizes.
 *
 * @param $size
 *   A size in bytes.
 * @param $langcode
 *   Optional language code to translate to a language other than what is used
 *   to display the page.
 *
 * @return
 *   A translated string representation of the size.
 */
function ubn_format_size($size, $langcode = NULL) {
  if ($size < DRUPAL_KILOBYTE) {
    return format_plural($size, '1 byte', '@count bytes', array(), array('langcode' => $langcode));
  }
  else {
    $size = $size / DRUPAL_KILOBYTE; // Convert bytes to kilobytes.
    $units = array(
      t('@size KB', array(), array('langcode' => $langcode)),
      t('@size MB', array(), array('langcode' => $langcode)),
      t('@size GB', array(), array('langcode' => $langcode)),
      t('@size TB', array(), array('langcode' => $langcode)),
      t('@size PB', array(), array('langcode' => $langcode)),
      t('@size EB', array(), array('langcode' => $langcode)),
      t('@size ZB', array(), array('langcode' => $langcode)),
      t('@size YB', array(), array('langcode' => $langcode)),
    );
    foreach ($units as $unit) {
      if (round($size, 2) >= DRUPAL_KILOBYTE) {
        $size = $size / DRUPAL_KILOBYTE;
      }
      else {
        break;
      }
    }
    return str_replace('@size', round($size, 2), $unit);
  }
}
