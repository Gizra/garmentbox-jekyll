<?php
/**
 * @file
 * gbmarket_user.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function gbmarket_user_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_checkout_redirect_anonymous';
  $strongarm->value = TRUE;
  $export['commerce_checkout_redirect_anonymous'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_customer_profile_billing_addressbook';
  $strongarm->value = TRUE;
  $export['commerce_customer_profile_billing_addressbook'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'contact_default_status';
  $strongarm->value = 0;
  $export['contact_default_status'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_immediate_login_on_register';
  $strongarm->value = 1;
  $export['logintoboggan_immediate_login_on_register'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_login_with_email';
  $strongarm->value = '1';
  $export['logintoboggan_login_with_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_no_approval_required_body';
  $strongarm->value = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>Untitled Document</title>
<style type="text/css">
<!--
body {
        font: 100%/1.4 Verdana, Arial, Helvetica, sans-serif;
        background-image:url(https://marketplace.garmentbox.com/profiles/gbmarket/themes/gbmarkettheme/images/mails/background.png);
        background: #4E5869;
        margin: 0;
        padding: 0;
        color: #000;
}

/* ~~ Element/tag selectors ~~ */
ul, ol, dl { /* Due to variations between browsers, it\'s best practices to zero padding and margin on lists. For consistency, you can either specify the amounts you want here, or on the list items (LI, DT, DD) they contain. Remember that what you do here will cascade to the .nav list unless you write a more specific selector. */
        padding: 0;
        margin: 0;
}
h1, h2, h4, h5, h6, p {
        margin-top: 0;   /* removing the top margin gets around an issue where margins can escape from their containing div. The remaining bottom margin will hold it away from any elements that follow. */
        color:#000000;
        padding-right: 15px;
        padding-left: 15px; /* adding the padding to the sides of the elements within the divs, instead of the divs themselves, gets rid of any box model math. A nested div with side padding can also be used as an alternate method. */
}

h3 {
        margin-top: 0;   /* removing the top margin gets around an issue where margins can escape from their containing div. The remaining bottom margin will hold it away from any elements that follow. */
        color:#fec017;
        padding-right: 15px;
        padding-left: 15px; /* adding the padding to the sides of the elements within the divs, instead of the divs themselves, gets rid of any box model math. A nested div with side padding can also be used as an alternate method. */
}
a img { /* this selector removes the default blue border displayed in some browsers around an image when it is surrounded by a link */
        border: none;
}

/* ~~ Styling for your site\'s links must remain in this order - including the group of selectors that create the hover effect. ~~ */
a:link {
        color:#414958;
        text-decoration: underline; /* unless you style your links to look extremely unique, it\'s best to provide underlines for quick visual identification */
}
a:visited {
        color: #4E5869;
        text-decoration: underline;
}
li {padding: 0px 20px 50px 0px; margin-left: 50px;}
li img {float:left; padding: 0 10px 0 0;}
a:hover, a:active, a:focus { /* this group of selectors will give a keyboard navigator the same hover experience as the person using a mouse. */
        text-decoration: none;
}

/* ~~ this container surrounds all other divs giving them their percentage-based width ~~ */
.container {
        width: 80%;
        max-width: 1260px;/* a max-width may be desirable to keep this layout from getting too wide on a large monitor. This keeps line length more readable. IE6 does not respect this declaration. */
        min-width: 780px;/* a min-width may be desirable to keep this layout from getting too narrow. This keeps line length more readable in the side columns. IE6 does not respect this declaration. */
        background: #FFF;
        margin: 0 auto; /* the auto value on the sides, coupled with the width, centers the layout. It is not needed if you set the .container\'s width to 100%. */
}

/* ~~the header is not given a width. It will extend the full width of your layout. It contains an image placeholder that should be replaced with your own linked logo~~ */
.header {
        background: #000000;
}
.content {
        padding: 10px 0;
}

/* ~~ This grouped selector gives the lists in the .content area space ~~ */
.content ul, .content ol {
list-style-type: none;
        padding: 0 15px 15px 10px; /* this padding mirrors the right padding in the headings and paragraph rule above. Padding was placed on the bottom for space between other elements on the lists and on the left to create the indention. These may be adjusted as you wish. */
}

/* ~~ The footer ~~ */
.footer {
        padding: 10px 0;
        background: #000000;
}

/* ~~ miscellaneous float/clear classes ~~ */
.fltrt {  /* this class can be used to float an element right in your page. The floated element must precede the element it should be next to on the page. */
        float: right;
        margin-left: 8px;
}
.fltlft { /* this class can be used to float an element left in your page. The floated element must precede the element it should be next to on the page. */
        float: left;
        margin-right: 8px;
}
.clearfloat { /* this class can be placed on a <br /> or empty div as the final element following the last floated div (within the #container) if the #footer is removed or taken out of the #container */
        clear:both;
        height:0;
        font-size: 1px;
        line-height: 0px;
}
-->
</style></head>

<body>

<div class="container">
  <div class="header"><a href="#"><img src="https://marketplace.garmentbox.com/profiles/gbmarket/themes/gbmarkettheme/images/mails/header.png" alt="Commerce Marketplace" name="Commerce Marketplace" width="600" height="69" id="Insert_logo" style="background: #000000; display:block;" /></a>
    <!-- end .header --></div>
  <div class="content">

<p>[user:name],</p>
    <p>Thank you for registering at Commerce Marketplace. You may now log in by clicking this link or copying and pasting it to your browser:</p>
    <p>[user:one-time-login-url]</p>
    <p>This link can only be used once to log in and will lead you to a page where you can set your password.</p>
    <p><img src="https://marketplace.garmentbox.com/profiles/gbmarket/themes/gbmarkettheme/images/mails/now_what.png" width="200" height="42" /></p>
<p>As a new marketplace member, you are one of the first with access to the growing list enhancements for eCommerce sites. All of which offer services that integrate seemlessly with Drupal Commerce. You can also:<br />
<ul>
    <li><img src="https://marketplace.garmentbox.com/profiles/gbmarket/themes/gbmarkettheme/images/mails/Jirafe-logo.png" width="120" height="42" /> Claim Your free 30 days of Analytics Insights from Jirafe [link]</li>
    <li><img src="https://marketplace.garmentbox.com/profiles/gbmarket/themes/gbmarkettheme/images/mails/email-logo.png" width="120" height="42" /> Update us with your communications preferences and opt-in to our email list (if you haven\'t already).</li>
    <li><img src="https://marketplace.garmentbox.com/profiles/gbmarket/themes/gbmarkettheme/images/mails/support-logo.png" width="120" height="42" /> Take advantage of direct access to support options to solve problems and move head. [link]</li>
    <li> <img src="https://marketplace.garmentbox.com/profiles/gbmarket/themes/gbmarkettheme/images/mails/training-logo.png" width="120" height="42" />Browse a wide range of training options to broaden your understanding of Drupal Commerce and show you what\'s possible.
    </ul>
    <h3>Always Growing, Always evolving</h3>
    <p>We are excited to have you aboard with us at the ground level.  Commerce Marketplace will constantly grow as we find new ways to enhance your eCommerce site and satisfy unfulfilled needs.  It\'s a resource that grows with you: As your business succeeds, it\'s there to guide you forward.
    <p>-- Commerce Marketplace team</p>
    <!-- end .content --></div>
  <div class="footer">
    <img src="https://marketplace.garmentbox.com/profiles/gbmarket/themes/gbmarkettheme/images/mails/footer.png" width="600" height="60" />
<!-- end .footer --></div>
  <!-- end .container --></div>
</body>
</html>';
  $export['user_mail_register_no_approval_required_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_no_approval_required_subject';
  $strongarm->value = 'Account details for [user:name] at [site:name]';
  $export['user_mail_register_no_approval_required_subject'] = $strongarm;

  return $export;
}
