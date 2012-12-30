/**
 * @file
 * jQuery handling for adding active on the bullets of the slide show.
 */
(function($) {
  Drupal.viewsSlideshowSlideCounter.transitionBegin = function (options) {
    $('.views_slideshow_slide_counter').removeClass('active');
    // Adding active class to the current slideshow and remove it from the others.
    $('#views_slideshow_slide_counter_' + options.slideshowID + ' .num-' + (options.slideNum + 1)).addClass('active');
  }
})(jQuery);
