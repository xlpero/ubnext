<?php
/**
 * @file
 * Displays a single spellcheck suggestion
 *
 * Available variables
 * - $suggestion
 *   - $suggestion->link
 *   - $suggestion->suggestion
 *   - $suggestion->original
 *   - $suggestion->url
 *
 * @ingroup themeable
 */
?>
<?php print t('Showing results for !link', array('!link' => $suggestion->link)); ?>
