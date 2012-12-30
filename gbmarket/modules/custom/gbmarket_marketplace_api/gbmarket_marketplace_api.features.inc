<?php
/**
 * @file
 * gbmarket_marketplace_api.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gbmarket_marketplace_api_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "oauth_common" && $api == "oauth") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function gbmarket_marketplace_api_default_search_api_index() {
  $items = array();
  $items['products'] = entity_import('search_api_index', '{
    "name" : "products",
    "machine_name" : "products",
    "description" : "An index of products for marketplace search.",
    "server" : "database",
    "item_type" : "commerce_product",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : 50,
      "fields" : {
        "sku" : { "type" : "string" },
        "type" : { "type" : "string" },
        "title" : { "type" : "text" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "search_api_language" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function gbmarket_marketplace_api_default_search_api_server() {
  $items = array();
  $items['database'] = entity_import('search_api_server', '{
    "name" : "database",
    "machine_name" : "database",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "indexes" : {
        "products" : {
          "sku" : {
            "table" : "search_api_db_products_sku",
            "type" : "string",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_products_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_products_title",
            "type" : "text",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_products_created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_products_changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_products_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          }
        },
        "productdisplay" : {
          "title" : {
            "table" : "search_api_db_productdisplay_title",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_category" : {
            "table" : "search_api_db_productdisplay_field_category",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_productdisplay_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_productdisplay_body_value",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_product:type" : {
            "table" : "search_api_db_productdisplay_field_product_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_product:title" : {
            "table" : "search_api_db_productdisplay_field_product_title",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_product:status" : {
            "table" : "search_api_db_productdisplay_field_product_status",
            "type" : "boolean",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
