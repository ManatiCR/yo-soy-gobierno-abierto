<?php

/**
 * @file
 * Provides the reCAPTCHA administration settings.
 */

/**
 * Form callback; administrative settings for reCaptcha.
 */
function recaptcha_admin_settings() {
  // Load the recaptcha library. Error if library does not load.
  if (!_recaptcha_load_library()) {
    drupal_set_message(t('Error loading recaptchalib.'), 'error');
    return FALSE;
  }

  $form = array();
  $form['recaptcha_public_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Public Key'),
    '#default_value' => variable_get('recaptcha_public_key', ''),
    '#maxlength' => 40,
    '#description' => t('The public key given to you when you <a href="@url" target="_blank">register for reCAPTCHA</a>.', array('@url' => url(recaptcha_get_signup_url($_SERVER['SERVER_NAME'], variable_get('site_name', ''))))),
    '#required' => TRUE,
  );
  $form['recaptcha_private_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Private Key'),
    '#default_value' => variable_get('recaptcha_private_key', ''),
    '#maxlength' => 40,
    '#description' => t('The private key given to you when you <a href="@url" target="_blank">register for reCAPTCHA</a>.', array('@url' => url(recaptcha_get_signup_url($_SERVER['SERVER_NAME'], variable_get('site_name', ''))))),
    '#required' => TRUE,
  );
  $form['recaptcha_server_status_check_interval'] = array(
    '#type' => 'textfield',
    '#title' => t('Captcha server check interval'),
    '#default_value' => variable_get('recaptcha_server_status_check_interval', 5),
    '#description' => t('Number of minutes to cache reCAPTCHA server status.'),
    '#size' => 10,
  );
  $form['recaptcha_ajax_api'] = array(
    '#type' => 'checkbox',
    '#title' => t('AJAX API'),
    '#default_value' => variable_get('recaptcha_ajax_api', FALSE),
    '#description' => t('Use the AJAX API to display reCAPTCHA.'),
  );
  $form['recaptcha_nocookies'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable Client-Side Cookies'),
    '#default_value' => variable_get('recaptcha_nocookies', FALSE),
    '#description' => t('Add flag to disable third-party cookies set by reCAPTCHA.'),
  );
  $form['recaptcha_theme_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Theme Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['recaptcha_theme_settings']['recaptcha_theme'] = array(
    '#type' => 'select',
    '#title' => t('Theme'),
    '#description' => t('Defines which theme to use for reCAPTCHA.'),
    '#options' => array(
      'red' => t('Red'),
      'white' => t('White'),
      'blackglass' => t('Black Glass'),
      'clean' => t('Clean'),
      'custom' => t('Custom'),
    ),
    '#default_value' => variable_get('recaptcha_theme', 'red'),
    '#required' => TRUE,
  );
  $form['recaptcha_theme_settings']['recaptcha_tabindex'] = array(
    '#type' => 'textfield',
    '#title' => t('Tab Index'),
    '#description' => t('Sets a <a href="@tabindex" target="_blank">tabindex</a> for the reCAPTCHA text box. If other elements in the form use a tabindex, this should be set so that navigation is easier for the user.', array('@tabindex' => 'http://www.w3.org/TR/html4/interact/forms.html#adef-tabindex')),
    '#default_value' => variable_get('recaptcha_tabindex', ''),
    '#size' => 4,
  );

  return system_settings_form($form);
}

/**
 * Validation function for recaptcha_admin_settings().
 *
 * @see recaptcha_admin_settings()
 */
function recaptcha_admin_settings_validate($form, &$form_state) {
  $tabindex = $form_state['values']['recaptcha_tabindex'];
  if (!empty($tabindex) && !is_numeric($tabindex)) {
    form_set_error('recaptcha_tabindex', t('The Tab Index must be an integer.'));
  }
}
