<?php
/**
 * @file
 * Template for a 3 rows panel layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="panel-display panel-2rows clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="panel-panel panel-col-top clearfix">
    <div class="container-12"><?php print $content['top']; ?></div>
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

  <div class="panel-panel panel-col-center4 clearfix">
      <div class="container-12"><?php print $content['center4']; ?></div>
  </div>

</div>
