<div class="panel-display panel-2rows clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="panel-panel panel-col-top clearfix">
    <div class="container-wrapper">
      <div class="container-12">
        <?php print $content['top']; ?>
      </div>
    </div>
  </div>

  <div class="panel-panel panel-col-center clearfix">
    <div class="container-12"><?php print $content['center']; ?></div>
  </div>

  <div class="panel-panel panel-col-center2 clearfix">
    <div class="container-12"><?php print $content['center2']; ?></div>
  </div>

  <div class="panel-panel panel-col-center3 clearfix">
      <div class="container-12"><?php print $content['center3']; ?></div>
  </div>

</div>
