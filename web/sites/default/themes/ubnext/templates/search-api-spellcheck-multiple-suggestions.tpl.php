<?php
/**
 * @file
 * Displays a list of spellcheck suggestions
 *
 * - $suggestions: An array of $suggestion objects
 *   - $suggestion->link
 *   - $suggestion->text
 *   - $suggestion->submited_text
 *   - $suggestion->url
 *
 * @ingroup themeable
 */
//TODO: Showing for first link only
?>
<h3><?php print t('Showing results for:'); ?></h3>
<ul>
  <?php foreach ($suggestions as $suggestion): ?>
    <li><?php print $suggestion->link; ?></li>
  <?php endforeach; ?>
</ul>
