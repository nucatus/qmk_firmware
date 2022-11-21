#include QMK_KEYBOARD_H


enum _layers {
	_QWR_LAYER,
	_DV_LAYER,
	_DVP_LAYER,
  _FN
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

void double_tap_q(qk_tap_dance_state_t *state, void *user_data);

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_CAPS),
    [TD_Q] = ACTION_TAP_DANCE_FN(double_tap_q)
};

#ifndef DEFAULT_LAYOUT
# define DEFAULT_LAYOUT _QWR_LAYER
#endif

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
    KC_ESC,                KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_PAUS,
    KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
    KC_TAB,      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
    TD(TD_CAPS), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
    KC_LSFT,               KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                      KC_UP,
    KC_LCTL,     KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RGUI,  MO(_FN),  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
  [_DV_LAYER] = LAYOUT_tkl_ansi(
    KC_ESC,                KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,
    KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LBRC,  KC_RBRC,  KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
    KC_TAB,      KC_SCLN,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,  KC_EQL,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
    TD(TD_CAPS), KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,  KC_ENT,
    KC_LSFT,               KC_QUOT,  TD(TD_Q), KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     KC_RSFT,                      KC_UP,
    KC_LCTL,     KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RGUI,  MO(_FN),  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
  [_DVP_LAYER] = LAYOUT_tkl_ansi(
    KC_ESC,                KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,
    KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LBRC,  KC_RBRC,  KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
    KC_TAB,      KC_SCLN,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,  KC_EQL,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
    TD(TD_CAPS), KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,  KC_ENT,
    KC_LSFT,               KC_QUOT,  TD(TD_Q), KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     KC_RSFT,                      KC_UP,
    KC_LCTL,     KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RGUI,  MO(_FN),  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
  [_FN] = LAYOUT_tkl_ansi(
    _______,            KC_MPLY,  KC_MSTP,  KC_MPRV,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  QWRT,     DVRK,     DVRK_P,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWRT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWR_LAYER);
      }
      return false;
      break;
    case DVRK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DV_LAYER);
      }
      return false;
      break;
    case DVRK_P:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVP_LAYER);
      }
      return false;
      break;
  }
  return true;
}

void double_tap_q(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code16(KC_Q);
    reset_tap_dance(state);
  }
  if (state->count == 2) {
    SEND_STRING(":q");
    tap_code16(KC_ENT);
    reset_tap_dance(state);
  }
}
