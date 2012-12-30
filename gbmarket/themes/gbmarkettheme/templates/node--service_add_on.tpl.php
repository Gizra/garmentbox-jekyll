
<div class="left-column">
  <div class="column-wrapper">
    <?php if ($content['field_image']):?>
      <?php print render($content['field_image']);?>
    <?php endif;?>
    <?php if ($content['field_category']):?>
      <?php print render($content['field_category']);?>
    <?php endif;?>
    <?php if ($content['field_link']):?>
      <?php print render($content['field_link']);?>
    <?php endif;?>
    <?php if ($content['field_download_link']):?>
      <?php print render($content['field_download_link']);?>
    <?php endif;?>
  </div>
</div>
<div class="right-column">
  <div class="column-wrapper">
    <?php print render($content); ?>
  </div>
</div>
