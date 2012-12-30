<?php
/**
 * @file
 * Alpha's theme implementation to display a block.
 */
?>
<div<?php print $attributes; ?>>
  <div class="block-inner clearfix">
    <?php print render($title_prefix); ?>
    <?php if ($block->subject): ?>
      <h2<?php print $title_attributes; ?>><?php print $block->subject; ?></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <div<?php print $content_attributes; ?>>
      <?php print $content ?>

      <?php if (!empty($show_commerce_platform_header)): ?>
        <div class="head clearfix">
          <div class="logo"><img src="<?php print $images_path; ?>/commerce-platform-logo.png" /></div>
          <div class="description">
            <p class="title"><?php print t('Drupal Commerce hosting<br/>by the people who know it best.'); ?></p>
            <p class="extra"><?php print t('It\'s more than just hosting: It\'s everything your eCommerce site needs for successful daily operation.'); ?></p>
          </div>
          <div class="buttons">
            <div class="soon"><img src="<?php print $images_path; ?>/coming-soon.png" /></div>
            <a class="button sign-up" href="user/register"><em><?php print t('Want a beta invite?'); ?></em> <?php print t('Sign up'); ?></a>
          </div>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>
