<div class="category-wrapper">
<div class="image"><?php print $image; ?></div>
<div class="details">
  <p><?php print $logo; ?></p>
  <h3><?php print $title; ?></h3>
  <?php print $body; ?>
  <a href="<?php print $sessions_url; ?>" class="more"><?php print t('Learn more'); ?></a>
</div>
<?php if ($next_training): ?>
<div class="extra-details">
  <div class="next-training"><?php print t('Next training'); ?></div>
  <div class="next-training-details">
    <p><span class="title"><?php print $next_training['title']; ?></span> <span class="em"><b>For</b> <?php print $next_training['audience']; ?></span></p>
    <p><?php print $next_training['description']; ?></p>
  </div>
  <a href="<?php print $sessions_url; ?>" class="more"><?php print t('View all'); ?></a>
</div>
<?php endif; ?>
</div>
