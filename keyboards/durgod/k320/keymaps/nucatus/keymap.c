#include QMK_KEYBOARD_H

enum _layers {
	_QWR_LAYER,
	_DV_LAYER,
	_DVP_LAYER,
    _FN,
    _NUM
};

enum _keycodes {
  QWRT = SAFE_RANGE,
  DVRK,
  DVRK_P
};

// Tap Dance declarations
enum {
    TD_CAPS,
    TD_Q,
    TD_A
};

void double_tap_q(tap_dance_state_t *state, void *user_data);

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_Q] = ACTION_TAP_DANCE_FN(double_tap_q)
};

#ifndef DEFAULT_LAYOUT
# define DEFAULT_LAYOUT _QWR_LAYER
#endif

#define ncts_ko_shift_num_dvp(kc_num)                                   \
  ((const key_override_t){                                              \
       .trigger_mods           = (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)), \
       .layers                 = (1 << _DVP_LAYER),                     \
       .suppressed_mods        = (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)), \
       .options                = (ko_options_default),                  \
       .trigger                = (kc_num),                              \
       .replacement            = (kc_num),                              \
       .enabled                = (NULL)                                 \
  })

#define ncts_ko_with_mods(kc_t, kc_r, tr_mods)                              \
  ((const key_override_t){                                                  \
       .trigger_mods           = (tr_mods),                                 \
       .layers                 = (1 << _DVP_LAYER),                         \
       .suppressed_mods        = (0),                                       \
       .options                = (ko_options_default | ko_option_one_mod),  \
       .trigger                = (kc_t),                                    \
       .replacement            = (kc_r),                                    \
       .enabled                = (NULL)                                     \
  })


/*
[_TRANSP_LAYER] = LAYOUT_tkl_ansi(
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______)
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWR_LAYER] = LAYOUT_tkl_ansi( /* Qwerty Layer */
    KC_ESC,                   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,
    KC_GRV,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
    KC_TAB,         KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
    LCTL_T(KC_ESC), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
    TD(TD_CAPS),    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                                KC_UP,
    KC_LCTL,        KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RGUI,  MO(_FN),  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

  [_DV_LAYER] = LAYOUT_tkl_ansi(
    KC_ESC,                   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,
    KC_GRV,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LBRC,  KC_RBRC,  KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
    KC_TAB,         KC_SCLN,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_D,     KC_SLSH,  KC_EQL,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
    LCTL_T(KC_ESC), KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_L,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,  KC_ENT,
    TD(TD_CAPS),    KC_QUOT,  TD(TD_Q), KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     KC_RSFT,                                KC_UP,
    KC_LCTL,        KC_LALT,  KC_LGUI,                                LT(_NUM, KC_SPC),                       KC_RGUI,  MO(_FN),  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

  [_DVP_LAYER] = LAYOUT_tkl_ansi(
    KC_ESC,                   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,
    KC_GRV,         KC_3,     KC_2,     KC_0,     KC_1,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_LBRC,  KC_RBRC,  KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
    KC_TAB,         KC_SCLN,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_D,     KC_SLSH,  KC_EQL,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
    LCTL_T(KC_ESC), KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_L,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,  KC_ENT,
    TD(TD_CAPS),    KC_QUOT,  TD(TD_Q), KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     KC_RSFT,                                KC_UP,
    KC_LCTL,        KC_LALT,  KC_LGUI,                                LT(_NUM, KC_SPC),                       KC_RGUI,  MO(_FN),  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

  [_FN] = LAYOUT_tkl_ansi(
    _______,                  KC_MPLY,  KC_MSTP,  KC_MPRV,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,        QWRT,     DVRK,     DVRK_P,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,
    _______,        _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______),


  [_NUM] = LAYOUT_tkl_ansi(
    _______,                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,        KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,        KC_3,     KC_2,     KC_0,     KC_1,     KC_4,     _______,  KC_DOT,   KC_COMM,  _______,  _______,  _______,  _______,
    _______,        _______,  _______,  _______,  KC_BSPC,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,
    _______,        _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______)
};

const key_override_t ko_grv = ko_make_with_layers_and_negmods(0, KC_GRV,  S(KC_4),    1 << _DVP_LAYER, ~0); // ` is $
const key_override_t ko_1   = ko_make_with_layers_and_negmods(0, KC_3,    S(KC_7),    1 << _DVP_LAYER, ~0); // 1 is &
const key_override_t ko_2   = ko_make_with_layers_and_negmods(0, KC_2,    S(KC_LBRC), 1 << _DVP_LAYER, ~0); // 2 is {
const key_override_t ko_3   = ko_make_with_layers_and_negmods(0, KC_0,    S(KC_9),    1 << _DVP_LAYER, ~0); // 3 is (
const key_override_t ko_4   = ko_make_with_layers_and_negmods(0, KC_1,    KC_LBRC,    1 << _DVP_LAYER, ~0); // 4 is [
const key_override_t ko_5   = ko_make_with_layers_and_negmods(0, KC_4,    KC_EQL,     1 << _DVP_LAYER, ~0); // 5 is =
const key_override_t ko_6   = ko_make_with_layers_and_negmods(0, KC_5,    S(KC_EQL),  1 << _DVP_LAYER, ~0); // 6 is +
const key_override_t ko_7   = ko_make_with_layers_and_negmods(0, KC_6,    KC_RBRC,    1 << _DVP_LAYER, ~0); // 7 is ]
const key_override_t ko_8   = ko_make_with_layers_and_negmods(0, KC_7,    S(KC_0),    1 << _DVP_LAYER, ~0); // 8 is }
const key_override_t ko_9   = ko_make_with_layers_and_negmods(0, KC_8,    S(KC_RBRC), 1 << _DVP_LAYER, ~0); // 9 is )
const key_override_t ko_0   = ko_make_with_layers_and_negmods(0, KC_9,    S(KC_8),    1 << _DVP_LAYER, ~0); // 0 is *
const key_override_t ko_lbr = ko_make_with_layers_and_negmods(0, KC_LBRC, S(KC_BSLS), 1 << _DVP_LAYER, ~0); // [ is |
const key_override_t ko_rbr = ko_make_with_layers_and_negmods(0, KC_RBRC, KC_GRV,     1 << _DVP_LAYER, ~0); // ] is `
const key_override_t ko_eql = ko_make_with_layers_and_negmods(0, KC_EQL,  S(KC_6),    1 << _DVP_LAYER, ~0); // = is ^

const key_override_t mod_ko_4   = ncts_ko_with_mods(KC_4,   KC_LBRC, ~MOD_MASK_SHIFT);
const key_override_t mod_ko_5   = ncts_ko_with_mods(KC_5,   KC_EQL,  ~MOD_MASK_SHIFT);
const key_override_t mod_ko_7   = ncts_ko_with_mods(KC_7,   KC_RBRC, ~MOD_MASK_SHIFT);
const key_override_t mod_ko_eql = ncts_ko_with_mods(KC_EQL, S(KC_6), ~MOD_MASK_SHIFT);

const key_override_t ko_sh_grv = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_GRV,  LSFT(KC_5),   1 << _DVP_LAYER, ~MOD_MASK_SHIFT); // shift + ` is %
const key_override_t ko_sh_lbr = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LBRC, LSFT(KC_GRV), 1 << _DVP_LAYER, ~MOD_MASK_SHIFT); // shift + [ is ~
const key_override_t ko_sh_rbr = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_RBRC, LSFT(KC_1),   1 << _DVP_LAYER, ~MOD_MASK_SHIFT); // shift + ] is !
const key_override_t ko_sh_eql = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_EQL,  LSFT(KC_2),   1 << _DVP_LAYER, ~MOD_MASK_SHIFT); // shift + = is @
const key_override_t ko_sh_bsl = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_BSLS, LSFT(KC_3),   1 << _DVP_LAYER, ~MOD_MASK_SHIFT); // shift + \ is #

const key_override_t ko_sh_1 = ncts_ko_shift_num_dvp( KC_1 );     // shift + 1 is 1
const key_override_t ko_sh_2 = ncts_ko_shift_num_dvp( KC_2 );     // shift + 2 is 2
const key_override_t ko_sh_3 = ncts_ko_shift_num_dvp( KC_3 );     // shift + 3 is 3
const key_override_t ko_sh_4 = ncts_ko_shift_num_dvp( KC_4 );     // shift + 4 is 4
const key_override_t ko_sh_5 = ncts_ko_shift_num_dvp( KC_5 );     // shift + 5 is 5
const key_override_t ko_sh_6 = ncts_ko_shift_num_dvp( KC_6 );     // shift + 6 is 6
const key_override_t ko_sh_7 = ncts_ko_shift_num_dvp( KC_7 );     // shift + 7 is 7
const key_override_t ko_sh_8 = ncts_ko_shift_num_dvp( KC_8 );     // shift + 8 is 8
const key_override_t ko_sh_9 = ncts_ko_shift_num_dvp( KC_9 );     // shift + 9 is 9
const key_override_t ko_sh_0 = ncts_ko_shift_num_dvp( KC_0 );     // shift + 0 is 0

const key_override_t **key_overrides = (const key_override_t *[]){
  &ko_grv,
  &ko_1,
  &ko_2,
  &ko_3,
  &ko_4,
  &ko_5,
  &ko_6,
  &ko_7,
  &ko_8,
  &ko_9,
  &ko_0,
  &ko_lbr,
  &ko_rbr,
  &ko_eql,

  &mod_ko_4,
  &mod_ko_5,
  &mod_ko_7,
  &mod_ko_eql,

  &ko_sh_grv,
  &ko_sh_rbr,
  &ko_sh_eql,
  &ko_sh_bsl,
  &ko_sh_lbr,

  &ko_sh_1,
  &ko_sh_2,
  &ko_sh_3,
  &ko_sh_4,
  &ko_sh_5,
  &ko_sh_6,
  &ko_sh_7,
  &ko_sh_8,
  &ko_sh_9,
  &ko_sh_0,
  NULL
};

void show_layer_leds(uint16_t l_id) {
  l_id++;
  writePin( LED_CAPS_LOCK_PIN, !(l_id >> 3 & 1) );
  writePin( LED_SCROLL_LOCK_PIN, !(l_id >> 3 & 1) );
  writePin( LED_WIN_LOCK_PIN, !(l_id >> 1 & 1) );
  writePin( LED_MR_LOCK_PIN, !(l_id & 1) );
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWRT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWR_LAYER);
        show_layer_leds(_QWR_LAYER);
      }
      return false;
      break;
    case DVRK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DV_LAYER);
        show_layer_leds(_DV_LAYER);
      }
      return false;
      break;
    case DVRK_P:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVP_LAYER);
        show_layer_leds(_DVP_LAYER);
      }
      return false;
      break;
  }
  return true;
}

// start the keybard with the default layer
// and signal this status on the keyboard LEDs
void keyboard_post_init_user(void) {
  set_single_persistent_default_layer(_QWR_LAYER);
  show_layer_leds(_QWR_LAYER);
}

void double_tap_q(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code16(KC_Q);
    reset_tap_dance(state);
  }
  if (state->count == 2) {
    SEND_STRING(":q");
    tap_code16(KC_ENT);
    reset_tap_dance(state);
  }
  if (state->count == 3) {
    SEND_STRING(":q!");
    tap_code16(KC_ENT);
    reset_tap_dance(state);
  }
}
