<?php
/**
 * @file
 * ysga_ct_grupo_trabajo.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ysga_ct_grupo_trabajo_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-grupo_de_trabajo-body'
  $field_instances['node-grupo_de_trabajo-body'] = array(
    'bundle' => 'grupo_de_trabajo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-grupo_de_trabajo-field_consulta_fecha'
  $field_instances['node-grupo_de_trabajo-field_consulta_fecha'] = array(
    'bundle' => 'grupo_de_trabajo',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_consulta_fecha',
    'label' => 'Fecha de la consulta',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
      'wysiwyg_fields' => array(
        'settings' => array(
          'advanced' => array(
            'delete' => 1,
            'hide' => 1,
          ),
          'formatters' => array(),
          'icon' => '6f7621a02161e347e66d99d8ace540a3',
          'label' => 'Fecha de la consulta',
        ),
        'status' => 0,
      ),
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-grupo_de_trabajo-field_consulta_imagenes'
  $field_instances['node-grupo_de_trabajo-field_consulta_imagenes'] = array(
    'bundle' => 'grupo_de_trabajo',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_consulta_imagenes',
    'label' => 'Imágenes',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'imagenes/grupos',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
      'wysiwyg_fields' => array(
        'settings' => array(
          'advanced' => array(
            'delete' => 1,
            'hide' => 1,
          ),
          'formatters' => array(),
          'icon' => '6f7621a02161e347e66d99d8ace540a3',
          'label' => 'Imágenes',
        ),
        'status' => 0,
      ),
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Fecha de la consulta');
  t('Imágenes');

  return $field_instances;
}
