#include QMK_KEYBOARD_H
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define LOW_MHN LT(_LOWER, KC_MHEN)
#define RAI_HNK LT(_RAISE, KC_HENK)
#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Esc |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|Delete|||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, EISU,             LOWER,   KC_SPC , KC_DEL,        KC_BSPC,KC_ENT , RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   |  |      |      |      |      |      |   ~  |                    |      |      |      |      |      |      | Caps |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ?   |   "  |   <  |   >  |   #  |   $  |   {  |                    |   }  |   %  |   &  |   (  |   )  |   `  |  *   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  +   |      |      |      | Find |      |   [  |                    |   ]  |      |      |      |      |      |  =   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift| Undo |  Cut | Copy | Paste|      |  ESC |                    |  Tab |      |      |      |      |      |  _   |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    JP_PIPE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TILD,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
    KC_QUES, JP_DQT,  KC_LABK, KC_RABK, KC_HASH, KC_DLR,  _______,                        _______, KC_PERC, KC_AMPR, JP_LPRN, JP_RPRN, KC_GRV,  KC_ASTR, \
    JP_PLUS, KC_NO,   KC_NO,   KC_NO,   KC_FIND, KC_NO,   _______,                        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   JP_EQL , \
    KC_LSFT, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,KC_NO,   _______,                        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UNDS, \
    KC_LCTL, KC_LGUI, KC_LALT, _______,          _______, _______ , _______,      _______,_______, _______,          KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   6  |   7  |   8  |   9  |   0  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  |  F12 | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL ,                        KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DQT , \
    KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6 ,                         KC_F7 ,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, EISU,             KC_SPC,  LOWER , KC_DEL,         KC_BSPC,RAISE ,  KC_ENT,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_NO, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,KC_NO,                       KC_NO, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_NO, KC_NO, \
    KC_NO, KC_NO, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,KC_NO,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,KC_NO,KC_NO,       KC_NO,KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO  \
  )
};

#ifdef AUDIO_ENABLE
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        print("mode just switched to dvorak and this is a huge string\n");
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}