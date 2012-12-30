core = 7.x
api = 2

; Modules
projects[addressfield][subdir] = "contrib"
projects[addressfield][version] = "1.0-beta3"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.2"

projects[commerce][subdir] = "contrib"
projects[commerce][version] = "1.3"
projects[commerce][patch][] = "http://drupal.org/files/1736850-checkout-redirect-1.patch"
projects[commerce][patch][] = "http://drupal.org/files/1588226-product-reference-node-types_0.patch"

projects[devel][subdir] = "contrib"
projects[devel][version] = "1.3"

projects[diff][subdir] = "contrib"
projects[diff][version] = "2.0"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.x-dev"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0"

projects[i18n][subdir] = "contrib"
projects[i18n][version] = "1.7"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.0"

projects[markdown][subdir] = "contrib"
projects[markdown][version] = "1.0"

projects[oauth][subdir] = "contrib"
projects[oauth][version] = "3.0"
projects[oauth][patch][] = "http://drupal.org/files/980340-d7.patch"
projects[oauth][patch][] = "http://drupal.org/files/1535764-fix-signatures.patch"
projects[oauth][patch][] = "http://drupal.org/files/oauth-1431642-consumer-deletion.patch"

projects[omega_tools][subdir] = "contrib"
projects[omega_tools][version] = "3.0-rc4"

projects[openid_provider][subdir] = "contrib"
projects[openid_provider][version] = "1.0-rc4"

projects[services][subdir] = "contrib"
; Currently not upgradeable to 3.1
projects[services][version] = "3.x-dev"

projects[rules][subdir] = "contrib"
projects[rules][version] = "2.2"

projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.3"

projects[search_api_db][subdir] = "contrib"
projects[search_api_db][version] = "1.0-beta4"

projects[search_api_solr][subdir] = "contrib"
projects[search_api_solr][version] = "1.0-rc2"

projects[search_api_sorts][subdir] = "contrib"
projects[search_api_sorts][version] = "1.2"

projects[facetapi][subdir] = "contrib"
projects[facetapi][version] = "1.1"
projects[facetapi][patch][] = "http://drupal.org/files/limit-active-items-1393928-33.patch"

libraries[SolrPhpClient][download][type] = "get"
libraries[SolrPhpClient][download][url] = "http://solr-php-client.googlecode.com/files/SolrPhpClient.r60.2011-05-04.tgz"
libraries[SolrPhpClient][directory_name] = "SolrPhpClient"
libraries[SolrPhpClient][destination] = "modules/contrib/search_api_solr"

projects[services_tools][subdir] = "contrib"
projects[services_tools][version] = "3.2"

projects[simpletest][subdir] = "contrib"
projects[simpletest][version] = "2.0"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[variable][subdir] = "contrib"
projects[variable][version] = "1.2"

projects[views][subdir] = "contrib"
projects[views][version] = "3.5"

projects[views_slideshow][subdir] = "contrib"
projects[views_slideshow][version] = "3.0"

projects[xrds_simple][subdir] = "contrib"
projects[xrds_simple][version] = "1.0"
projects[xrds_simple][patch][] = "http://drupal.org/files/xrds_simple-correct_syntax_for_drupal_add_html_head_in_hook_init-1732876-2.patch"

projects[panels][subdir] = "contrib"
projects[panels][version] = "3.3"

projects[field_collection][subdir] = "contrib"
projects[field_collection][version] = "1.0-beta4"

projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "3.0-rc3"

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "1.7"

projects[nodequeue][subdir] = "contrib"
projects[nodequeue][version] = "2.0-beta1"

projects[link][subdir] = "contrib"
; Unable to downgrade to 1.0.
projects[link][version] = "1.x-dev"

projects[migrate][version] = 2.4
projects[migrate][subdir] = "contrib"

projects[migrate_extras][version] = 2.4
projects[migrate_extras][subdir] = "contrib"

projects[commerce_migrate][version] = 1.x-dev
projects[commerce_migrate][subdir] = "contrib"

projects[entityreference][version] = "1.x-dev"
; Currently cannot downgrade to 7.x-1.0-rc3.
projects[entityreference][subdir] = "contrib"

projects[date][version] = "2.6"
projects[date][subdir] = "contrib"

projects[jirafe][version] = "1.0-beta4"
projects[jirafe][subdir] = "contrib"

projects[message][version] = "1.5"
projects[message][subdir] = "contrib"

projects[message_notify][version] = "2.x-dev"
projects[message_notify][subdir] = "contrib"

projects[token][version] = "1.2"
projects[token][subdir] = "contrib"

projects[mailsystem][version] = 2.34
projects[mailsystem][subdir] = "contrib"

projects[mimemail][version] = 1.0-alpha1
; Cannot upgrade to 1.0-alpha2.
projects[mimemail][subdir] = "contrib"
projects[mimemail][patch][] = "http://drupal.org/files/rules-1585546-1-moving_rules_actions.patch"
projects[mimemail][patch][] = "http://drupal.org/files/compress_install_missing_value.patch"

projects[email][version] = "1.2"
projects[email][subdir] = "contrib"

projects[webform][version] = "3.18"
projects[webform][subdir] = "contrib"

projects[pathauto][version] = "1.2"
projects[pathauto][subdir] = "contrib"

projects[r4032login][version] = "1.5"
projects[r4032login][subdir] = "contrib"

projects[logintoboggan][version] = "1.3"
projects[logintoboggan][subdir] = "contrib"

projects[commerce_addressbook][version] = "2.0-rc2"
projects[commerce_addressbook][subdir] = "contrib"

projects[google_analytics][version] = "1.2"
projects[google_analytics][subdir] = "contrib"

projects[views_bulk_operations][version] = "3.0"
projects[views_bulk_operations][subdir] = "contrib"

projects[hint][version] = "1.2"
projects[hint][subdir] = "contrib"

projects[fontyourface][version] = "2.6"
projects[fontyourface][subdir] = "contrib"

; No stable release yet.
projects[openid_sso_provider][version] = "1.x-dev"
projects[openid_sso_provider][subdir] = "contrib"

; Themes
projects[omega][subdir] = "contrib"
projects[omega][version] = "3.1"
