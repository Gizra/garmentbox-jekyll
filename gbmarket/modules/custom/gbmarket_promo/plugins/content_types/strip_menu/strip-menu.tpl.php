<div<?php print $attributes; ?>>
  <?php if ($linked_logo_img): ?>
  <div class="branding-data clearfix">
    <div class="logo-img">
      <?php print $linked_logo_img; ?>
    </div>
  </div>
  <?php endif; ?>

  <?php if ($main_menu): ?>
    <nav>
      <?php print render($main_menu); ?>
    </nav>
  <?php endif; ?>
</div>
