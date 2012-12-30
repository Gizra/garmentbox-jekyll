<article<?php print $attributes; ?>>
  <div class="session-wrapper">
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php elseif ($page && $title):?>
  <div class="page-title">
    <h2 class="pane-title"><?php print $title;?></h2>
    <p><?php print $content['field_training_category'][0]['#markup'];?></p>
  </div>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <h3 class="subtitle"><?php print render($content['field_date']);?> <?php print render($content['field_location']);?></h3>
  <?php if($page):?>
    <div class="price">
      <?php print render($content['field_price']);?>
    </div>
  <?php endif;?>
  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_training_category']);
      print render($content);
    ?>
  </div>
  </div>
  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>
</article>
