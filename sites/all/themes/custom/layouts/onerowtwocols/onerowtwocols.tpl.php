<div class="panel-display panel-wrapp clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	<div class="callout large primary">
		<div class="row column">
			<?php print $content['top']; ?>
		</div>
	</div>  
  
	<div class="row panel-panel panel-row-content">
		<div class="small-12 columns"><?php print $content['content']; ?></div>
	</div>
</div>