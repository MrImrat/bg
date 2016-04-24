(function($) {
	Drupal.behaviors.custom = {
	  attach: function (context) {
		$(document).ready(function() {
			$('#site-info-list').mouseenter(function(){
				$('#site-info-list li').each(function(){
				  $th = $(this);
				  $text = $th.text().replace(/Total/i,'<span style="color:red">$&</span>');
				  $th.html($text);
				})  
			}); 

			$('#site-info-list').mouseleave(function(){
				$('#site-info-list li').each(function(){
				  $th = $(this);
				  $th.text($th.text());
				})  
			});   
		});
	  }
	};
})(jQuery);