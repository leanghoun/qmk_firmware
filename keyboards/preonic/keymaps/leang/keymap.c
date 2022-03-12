/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum preonic_layers {
  _COLEMAK,
  _QWERTY,
  _SUPER,
  _LOWER,
  _RAISE,
  _MACRO,
  _ADJUST
};

enum preonic_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  SUPER,
  LOWER,
  RAISE,
  MACRO,
  GMAIL,
  ABMAIL,
  MYPASS,
  ABPASS,
  ALT_TAB,
  SCRNSHT,
  OS_TOG,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool is_mac = true;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_preonic_1x2uC( \
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,  \
    KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_QUOT,  \
    SUPER,    KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_ENT,   \
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_UP,    \
    KC_LCTL,  MACRO,    KC_LALT,  KC_LCMD,  LOWER,         KC_SPC,        RAISE,    ALT_TAB,  KC_LEFT,  KC_RGHT,  KC_DOWN   \
),

[_QWERTY] = LAYOUT_preonic_1x2uC( \
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,  \
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_QUOT,  \
    SUPER,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,   \
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_UP,    \
    KC_LCTL,  MACRO,    KC_LALT,  KC_LCMD,  LOWER,         KC_SPC,        RAISE,    ALT_TAB,  KC_LEFT,  KC_RGHT,  KC_DOWN   \
),

[_SUPER] = LAYOUT_preonic_1x2uC( \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  SCRNSHT,  KC_DEL,   \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  SGUI(KC_4), \
    SUPER,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  _______,  \
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,  \
    _______,  MACRO,    _______,  _______,  LOWER,         _______,       RAISE,    _______,  _______,  _______,  _______   \
),

[_LOWER] = LAYOUT_preonic_1x2uC( \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSLS,  KC_PAST,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  \
    SUPER,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P1,    KC_P2,    KC_P3,    _______,  \
    _______,  MACRO,    _______,  _______,  LOWER,         _______,       RAISE,    KC_KP_0,  _______,  KC_PDOT,  KC_PENT   \
),

[_RAISE] = LAYOUT_preonic_1x2uC( \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_GRV,   \
    SUPER,    _______,  _______,  _______,  _______,  _______,  _______,  KC_MINS,  KC_EQL,  _______,  _______,  _______,   \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  KC_BSLS,  _______,  \
    _______,  MACRO,    _______,  _______,  LOWER,         _______,       RAISE,    _______,  _______,  _______,  _______   \
),

[_MACRO] = LAYOUT_preonic_1x2uC( \
    _______,  GMAIL,    ABMAIL,   MYPASS,   ABPASS,   _______,  _______,  _______,  _______,  DYN_MACRO_PLAY1,  DYN_MACRO_PLAY2,  DYN_REC_STOP,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  DYN_REC_START1,   DYN_REC_START2,   _______,  \
    SUPER,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_VOLU,  \
    _______,  MACRO,    _______,  _______,  LOWER,         _______,       RAISE,    KC_MPLY,  KC_MRWD,  KC_MFFD,  KC_VOLD   \
),

[_ADJUST] = LAYOUT_preonic_1x2uC( \
    _______,  COLEMAK,  QWERTY,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    SUPER,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  MACRO,    _______,  _______,  LOWER,         _______,       RAISE,    OS_TOG,   _______,  _______,  _______   \
)

/* [_NAME] = LAYOUT_preonic_1x2uC( \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    SUPER,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  MACRO,    _______,  _______,  LOWER,         _______,       RAISE,    _______,  _______,  _______,  _______   \
), */


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case SUPER:
          if (record->event.pressed) {
            layer_on(_SUPER);
          } else {
            layer_off(_SUPER);
          }
          return false;
          break;
        case MACRO:
          if (record->event.pressed) {
            layer_on(_MACRO);
          } else {
            layer_off(_MACRO);
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
        case GMAIL:
          if (record->event.pressed) {
            SEND_STRING("leanghoun@gmail.com");
          } else {}
          break;
        case ABMAIL:
          if (record->event.pressed) {
            SEND_STRING("Leang.Houn@AdvancedBionics.com");
          } else {}
          break;
        case MYPASS:
          if (record->event.pressed) {
            SEND_STRING("hannah(28)May");
          } else {}
          break;
        case ABPASS:
          if (record->event.pressed) {
            SEND_STRING("brandon(12)Feb2022");
          } else {}
          break;
        case ALT_TAB:
          if (record->event.pressed) {
            if (!is_alt_tab_active) {
              is_alt_tab_active = true;
              if (!is_mac) {
                register_code(KC_LALT);
              } else {
                register_code(KC_LCMD);
              }
            }
            alt_tab_timer = timer_read();
            register_code(KC_TAB);
          } else {
            unregister_code(KC_TAB);
          }
          break;
        case SCRNSHT:
          if (record->event.pressed) {
            if (!is_mac) {
              register_code(KC_PSCR);
            } else {
              register_code(KC_LSFT);
              register_code(KC_LGUI);
              register_code(KC_4);
            }
          } else {
            if (!is_mac) {
              unregister_code(KC_PSCR);
            } else {
              unregister_code(KC_LSFT);
              unregister_code(KC_LGUI);
              unregister_code(KC_4);
            }
          }
          break;
        case OS_TOG:
          if (record->event.pressed) {
            if (!is_mac) {
              is_mac = true;
            } else {
              is_mac = false;
            }
          } else {}
          break;
      }
    return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LCMD);
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
};
