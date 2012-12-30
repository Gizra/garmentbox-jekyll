<?php if ($breadcrumb): ?>
  <div id="breadcrumb" class="grid-<?php print $columns; ?>"><?php print $breadcrumb; ?></div>
<?php endif; ?>

<?php if ($messages): ?>
  <div id="messages">
    <div class="messages-wrapper">
      <?php print $messages; ?>
    </div>
  </div>
<?php endif; ?>

<?php if (isset($tabs)): ?>
  <div id="tabs"><?php print $tabs; ?></div>
<?php endif; ?>

<div class="content-wrapper clearfix">
  <?php if (!empty($action_links)): ?>
    <div class="action-links"><?php print render($action_links); ?></div>
  <?php endif; ?>
  <?php print $content; ?>
</div>
