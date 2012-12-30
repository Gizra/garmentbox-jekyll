<?php

/**
 * @file
 *   Populate distribution with some content.
 */

/**
 * Migrate page_element nodes.
 */
class gbmarketPageElements extends Migration {
  private $csvColumns = array(
    array('language', 'Language'),
    array('title', 'Title'),
    array('page_ids', 'Page IDs'),
    array('section_id', 'Section ID'),
    array('body', 'Body'),
    array('images', 'Images'),
  );

  public function __construct() {
    parent::__construct();
    $this->description = t('Import page elements from CSV file.');

    // Create a map object for tracking the relationships between source rows
    $key = array(
      'title' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap($this->machineName, $key, MigrateDestinationEntityAPI::getKeySchema('node'));

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'gbmarket_migrate') . '/csv/page_elements.csv', $this->csvColumns, array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('page_element', array('text_format' => 'full_html'));

    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_page_id', 'page_ids');
    $this->addFieldMapping('field_section_id', 'section_id');
    $this->addFieldMapping('body', 'body');

    $this->addFieldMapping('field_images', 'images');
    $this->addFieldMapping('field_images:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_images:source_dir')
      ->defaultValue(drupal_get_path('module', 'gbmarket_migrate') . '/images');
  }

  function prepareRow($row) {
    $row->uid = 1;

    if (!$row->images) {
      return;
    }

    $row->images = explode('; ', $row->images);
    // Replace @imageX tokens in the body with themed image tags.
    foreach ($row->images as $delta => $image_name) {
      $image = theme('image', array('path' => file_build_uri($image_name)));
      $row->body = str_replace("@image$delta", $image, $row->body);
    }
  }
}

/**
 * Migrate training_category nodes.
 */
class gbmarketTrainingCategories extends Migration {
  private $csvColumns = array(
    array('id', 'Unique ID'),
    array('language', 'Language'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('logo', 'Logo'),
    array('image', 'Image'),
    array('show_next_training', 'Show next training'),
  );

  public function __construct() {
    parent::__construct();
    $this->description = t('Import training categories from CSV file.');

    // Create a map object for tracking the relationships between source rows
    $key = array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap($this->machineName, $key, MigrateDestinationEntityAPI::getKeySchema('node'));

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'gbmarket_migrate') . '/csv/training_categories.csv', $this->csvColumns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationNode('training_category');

    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('field_show_next_training', 'show_next_training');

    $this->addFieldMapping('field_logo', 'logo');
    $this->addFieldMapping('field_logo:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_logo:source_dir')
      ->defaultValue(drupal_get_path('module', 'gbmarket_migrate') . '/images');

    $this->addFieldMapping('field_image', 'image');
    $this->addFieldMapping('field_image:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'gbmarket_migrate') . '/images');
  }

  function prepareRow($row) {
    $row->uid = 1;
  }

  function complete($entity, stdClass $source_row) {
    // Add the node to the sections nodequeue.
    $queue = nodequeue_load_queue_by_name('training_categories');
    $subqueue = reset(nodequeue_load_subqueues_by_queue($queue->qid));
    nodequeue_subqueue_add($queue, $subqueue, $entity->nid);
  }
}

/**
 * Migrate training_session nodes.
 */
class gbmarketTrainingSessions extends Migration {
  private $csvColumns = array(
    array('id', 'ID'),
    array('ref', 'ID reference'),
    array('language', 'Language'),
    array('title', 'Title'),
    array('description', 'Description'),
    array('audience', 'Audience'),
    array('date', 'Date'),
    array('price', 'Price'),
    array('location', 'Location'),
    array('link', 'Link'),
  );

  public function __construct() {
    parent::__construct();
    $this->description = t('Import training sessions from CSV file.');
    $this->dependencies = array('gbmarketTrainingCategories');

    // Create a map object for tracking the relationships between source rows
    $key = array(
      'id' => array(
        'type' => 'int',
        'length' => 10,
        'not null' => TRUE,
      ),
      'title' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap($this->machineName, $key, MigrateDestinationEntityAPI::getKeySchema('node'));

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'gbmarket_migrate') . '/csv/training_sessions.csv', $this->csvColumns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationNode('training_session');

    $this->addFieldMapping('field_training_category', 'ref')->sourceMigration('gbmarketTrainingCategories');

    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'description')
      ->arguments(array('format' => 'full_html'));
    $this->addFieldMapping('field_audience', 'audience');
    $this->addFieldMapping('field_date', 'date');
    $this->addFieldMapping('field_price', 'price');
    $this->addFieldMapping('field_location', 'location');
    $this->addFieldMapping('field_link', 'link')
      ->arguments(array('title' => 'Register on garment-box.com'));
  }

  function prepareRow($row) {
    $row->audience = explode('; ', $row->audience);

    $dates = explode('; ', $row->date);
    $row->date = drupal_json_encode(array(
      'from' => $dates[0],
      'to' => $dates[1],
    ));
    $row->uid = 1;
  }
}

/**
 * Migrate basic_page nodes.
 */
class gbPages extends Migration {
  private $csvColumns = array(
    array('language', 'Language'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('submenu', 'Sub-menu'),
    array('images', 'Images'),
    array('path', 'Path'),
    array('subtitle', 'Subtitle'),
    array('status', 'Status'),
  );

  public function __construct() {
    parent::__construct();
    $this->description = t('Import basic pages from CSV file.');

    // Create a map object for tracking the relationships between source rows
    $key = array(
      'title' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
      'path' => array(
        'type' => 'varchar',
        'length' => 255,
        'no null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap($this->machineName, $key, MigrateDestinationEntityAPI::getKeySchema('node'));

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'gbmarket_migrate') . '/csv/basic_pages.csv', $this->csvColumns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationNode('basic_page', array('text_format' => 'full_html'));

    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('status', 'status')
      ->defaultValue(NODE_PUBLISHED);
    $this->addFieldMapping('field_submenu', 'submenu');
    $this->addFieldMapping('field_subtitle', 'subtitle');

    $this->addFieldMapping('field_images', 'images');
    $this->addFieldMapping('field_images:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_images:source_dir')
      ->defaultValue(drupal_get_path('module', 'gbmarket_migrate') . '/images');
  }

  function prepareRow($row) {
    $row->uid = 1;

    // Load the body HTML file.
    $path = drupal_get_path('module', 'gbmarket_migrate') . '/html/' . $row->language . '/' . check_plain($row->body);
    if (file_exists($path)) {
      $row->body = file_get_contents($path);
    }

    $row->images = explode('; ', $row->images);
    // Replace @imageX tokens in the body with themed image tags.
    foreach ($row->images as $delta => $image_name) {
      $image = theme('image', array('path' => file_build_uri($image_name)));
      $row->body = str_replace("@image$delta", $image, $row->body);
    }
  }

  function complete($entity, stdClass $source_row) {
    // Set page path.
    $path = array(
      'source' => 'node/' . $entity->nid,
      'alias' => $source_row->path,
      'language' => $entity->language,
    );
    path_save($path);
  }
}

/**
 * Migrate page titles nodes.
 */
class gbmarketPageTitles extends Migration {
  private $csvColumns = array(
    array('id', 'ID'),
    array('path', 'Path'),
    array('language', 'Language'),
    array('title', 'Title'),
    array('subtitle', 'Subtitle'),
  );

  public function __construct() {
    parent::__construct();
    $this->description = t('Import basic pages from CSV file.');

    // Create a map object for tracking the relationships between source rows
    $key = array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap($this->machineName, $key, MigrateDestinationEntityAPI::getKeySchema('node'));

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'gbmarket_migrate') . '/csv/page_titles.csv', $this->csvColumns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationNode('page_title', array('text_format' => 'full_html'));

    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_subtitle', 'subtitle');
    $this->addFieldMapping('field_path', 'path');
  }

  function prepareRow($row) {
    $row->uid = 1;
  }
}

/**
 * Migrate homepage_section nodes.
 */
class gbmarketHomepageSections extends Migration {
  private $csvColumns = array(
    array('id', 'Unique ID'),
    array('language', 'Language'),
    array('title', 'Title'),
    array('subtitle', 'Subtitle'),
    array('body', 'Body'),
    array('more_link_title', 'More Title'),
    array('more_link_url', 'More URL'),
  );

  public function __construct() {
    parent::__construct();

    $this->description = t('Import homepage sections from CSV file.');

    // Create a map object for tracking the relationships between source rows
    $key = array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap($this->machineName, $key, MigrateDestinationEntityAPI::getKeySchema('node'));

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'gbmarket_migrate') . '/csv/homepage_sections.csv', $this->csvColumns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationNode('homepage_section');

    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_subtitle', 'subtitle');
    $this->addFieldMapping('body', 'body');

    $arguments = MigrateLinkFieldHandler::arguments(array('source_field' => 'more_link_title'));
    $this->addFieldMapping('field_link', 'more_link_url')->arguments($arguments);
  }

  function prepareRow($row) {
    $row->uid = 1;
  }

  function complete($entity, stdClass $source_row) {
    // Add the node to the sections nodequeue.
    $queue = nodequeue_load_queue_by_name('front_page_sections');
    $subqueue = reset(nodequeue_load_subqueues_by_queue($queue->qid));
    nodequeue_subqueue_add($queue, $subqueue, $entity->nid);
  }
}

/**
 * Migrate service_add_ons products.
 */
class gbmarketServiceAddOns extends Migration {
  private $csvColumns = array(
    array('title', 'Title'),
    array('sku', 'SKU'),
    array('price', 'Price'),
  );

  public function __construct() {
    parent::__construct();

    $this->description = t('Import service_add_ons products from CSV file.');

    // Create a map object for tracking the relationships between source rows
    $key = array(
      'sku' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap($this->machineName, $key, MigrateDestinationEntityAPI::getKeySchema('commerce_product'));

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'gbmarket_migrate') . '/csv/service_add_ons.csv', $this->csvColumns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationEntityAPI('commerce_product', 'service_add_on');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('sku', 'sku');
    $this->addFieldMapping('commerce_price', 'price');
  }

  public function prepareRow($row) {
    $row->uid = 1;
  }
}

/**
 * Migrate service_add_ons products display.
 */
class gbmarketServiceAddOnsDisplay extends Migration {
  private $csvColumns = array(
    array('sku', 'SKU'),
    array('language', 'Language'),
    array('title', 'Title'),
    array('tos_page', 'TOS URL'),
    array('subtitle', 'Subtitle'),
    array('featured', 'Featured'),
    array('image', 'Image'),
    array('body', 'Body'),
    array('category', 'Category'),
    array('link_title', 'Link Title'),
    array('link_url', 'Link URL'),
  );

  public function __construct() {
    parent::__construct();

    $this->description = t('Import service_add_ons products\' display nodes from CSV file.');
    $this->dependencies = array('gbmarketServiceAddOns');

    // Create a map object for tracking the relationships between source rows
    $key = array(
      'title' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap($this->machineName, $key, MigrateDestinationEntityAPI::getKeySchema('node'));

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'gbmarket_migrate') . '/csv/service_add_ons_node.csv', $this->csvColumns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationNode('service_add_on', array('text_format' => 'full_html'));

    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_product', 'sku');
    $this->addFieldMapping('field_tos_page', 'tos_page');
    $this->addFieldMapping('field_subtitle', 'subtitle');
    $this->addFieldMapping('field_featured', 'featured');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('field_category', 'category');

    $this->addFieldMapping('field_image', 'image');
    $this->addFieldMapping('field_image:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'gbmarket_migrate') . '/images');

    $arguments = MigrateLinkFieldHandler::arguments(array('source_field' => 'link_title'));
    $this->addFieldMapping('field_link', 'link_url')->arguments($arguments);
  }

  public function prepareRow($row) {
    $row->uid = 1;

    $product = commerce_product_load_by_sku($row->sku);
    $row->sku = $product->product_id;
  }
}

/**
 * Destination class implementing migration into field_collection.
 */
class gbmarketMigrateDestinationFieldCollection extends MigrateDestinationEntity {
  /**
   * The type of entity hosting this collection field (e.g., node).
   *
   * @var string
   */
  protected $hostEntityType;

  static public function getKeySchema() {
    return array(
      'cid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'ID of field collection item',
      ),
    );
  }

  /**
   * Basic initialization.
   *
   * @param array $options
   *  Options applied to collections.
   */
  public function __construct($bundle, array $options = array()) {
    parent::__construct('field_collection_item', $bundle, $options);
    $this->hostEntityType = $options['host_entity_type'];
  }

  /**
   * Returns a list of fields available to be mapped for this collection (bundle).
   *
   * @return array
   *  Keys: machine names of the fields (to be passed to addFieldMapping).
   *  Values: Human-friendly descriptions of the fields.
   */
  public function fields() {
    $fields = migrate_handler_invoke_all('Entity', 'fields', $this->entityType, $this->bundle);
    $fields['host_entity_id'] = t('Field collection host ID');
    return $fields;
  }

  /**
   * Import a single term.
   *
   * @param $collection
   *  Collection object to build. Pre-filled with any fields mapped in the migration.
   * @param $row
   *  Raw source data object - passed through to prepare/complete handlers.
   *
   * @return array
   *  Array of key fields (item_id only in this case) of the collection that was saved if
   *  successful. FALSE on failure.
   */
  public function import(stdClass $collection, stdClass $row) {
    $entity = entity_create('field_collection_item', array('field_name' => $this->bundle));
    $updating = FALSE;
    // The host entity cannot be reset - we only set it on initial insert
    $host_entity = entity_load_single($this->hostEntityType, $collection->host_entity_id['destid1']);
    $entity->setHostEntity($this->hostEntityType, $host_entity);

    unset($collection->host_entity_id);

    foreach ((array) $collection as $field => $value) {
      $entity->{$field} = $value;
    }
    $this->prepare($entity, $row);
    migrate_instrument_start('field_collection_save');
    $status = entity_save('field_collection_item', $entity);
    migrate_instrument_stop('field_collection_save');

    if ($status) {
      $this->complete($entity, $row);
      if ($updating) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }
      return array($entity->item_id);
    }
    else {
      return FALSE;
    }
  }

  /**
   * Delete a migrated collection.
   *
   * @param $key
   *  Array of fields representing the key.
   */
  public function rollback(array $key) {
    $item_id = reset($key);

    $this->prepareRollback($item_id);
    $field_collection_item = field_collection_item_load($item_id);
    // If the collection wasn't imported we can't roll it back so check if the
    // loaded object matches the fieldcollection item class.
    if ($field_collection_item instanceof  FieldCollectionItemEntity) {
      $field_collection_item->delete();
    }

    $this->completeRollback($item_id);
    return TRUE;
  }
}

