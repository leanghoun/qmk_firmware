/* Copyright 2019-2020 DMQ Design
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

#define _MCAP1   0
#define _MCAP2   1
#define _MCAP3   2
#define _MCAP4   3
#define _WCAP1   4
#define _WCAP2   5
#define _WCAP3   6
#define _WCAP4   7
#define _MLRM1   8
#define _MLRM2   9
#define _MLRM3   10
#define _MLRM4   11
#define _WLRM1   12
#define _WLRM2   13
#define _WLRM3   14
#define _WLRM4   15

enum custom_keycodes {
  EXPO = SAFE_RANGE,
  CONT,
  BRIG,
  SATU,
  HIGH,
  SHAD,
  WHIT,
  BLAC,
  KELV,
  TINT,
  DEHA,
  CLAR,
  UNDO,
  REDO,
  BEAF,
  FOCU,
  GRID,
  EXPW,
  STA0,
  STA1,
  STA2,
  STA3,
  STA4,
  STA5,
  AUTO,
  COPY,
  PAST,
  ZOMI,
  ZOMO,
  PICK
};

bool is_mac = true;

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {

  switch (get_highest_layer(layer_state)) {
    case _MCAP1:
      is_mac = true;
      rgblight_sethsv_range(160,255,120,0,3);
      oled_write_P(PSTR("CAPTURE ONE - Mac  1 \n"), false);
      break;
    case _MCAP2:
      oled_write_P(PSTR("CAPTURE ONE - Mac (1)\n"), false);
      break;
    case _MCAP3:
      rgblight_sethsv_range(191,255,120,0,3);
      oled_write_P(PSTR("CAPTURE ONE - Mac  2 \n"), false);
      break;
    case _MCAP4:
      oled_write_P(PSTR("CAPTURE ONE - Mac (2)\n"), false);
      break;
    case _WCAP1:
      is_mac = false;
      rgblight_sethsv_range(223,255,120,0,3);
      oled_write_P(PSTR("CAPTURE ONE - Win  1 \n"), false);
      break;
    case _WCAP2:
      oled_write_P(PSTR("CAPTURE ONE - Win (1)\n"), false);
      break;
    case _WCAP3:
      rgblight_sethsv_range(0,255,120,0,3);
      oled_write_P(PSTR("CAPTURE ONE - Win  2 \n"), false);
      break;
    case _WCAP4:
      oled_write_P(PSTR("CAPTURE ONE - Win (2)\n"), false);
      break;
    case _MLRM1:
      is_mac = true;
      rgblight_sethsv_range(32,255,120,0,3);
      oled_write_P(PSTR("LIGHTROOM - Mac    1 \n"), false);
      break;
    case _MLRM2:
      oled_write_P(PSTR("LIGHTROOM - Mac   (1)\n"), false);
      break;
    case _MLRM3:
      rgblight_sethsv_range(64,255,120,0,3);
      oled_write_P(PSTR("LIGHTROOM - Mac    2 \n"), false);
      break;
    case _MLRM4:
      oled_write_P(PSTR("LIGHTROOM - Mac   (2)\n"), false);
      break;
    case _WLRM1:
      is_mac = false;
      rgblight_sethsv_range(96,255,120,0,3);
      oled_write_P(PSTR("LIGHTROOM - Win    1 \n"), false);
      break;
    case _WLRM2:
      oled_write_P(PSTR("LIGHTROOM - Win   (1)\n"), false);
      break;
    case _WLRM3:
      rgblight_sethsv_range(128,255,120,0,3);
      oled_write_P(PSTR("LIGHTROOM - Win    2 \n"), false);
      break;
    case _WLRM4:
      oled_write_P(PSTR("LIGHTROOM - Win   (2)\n"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("UNDEFINED"), false);
      break;
  }

  // Host Keyboard LED Status
  /* led_t led_state = host_keyboard_led_state();
  oled_write_P(led_state.num_lock ? PSTR("NUM  ") : PSTR("     "), false);
  oled_write_P(led_state.caps_lock ? PSTR("CAP  ") : PSTR("     "), false);
  oled_write_P(led_state.scroll_lock ? PSTR("SCR  ") : PSTR("     "), false); */

}
#endif

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MCAP1] = LAYOUT(/* Mac CAP1 - Layer 1 */
                SATU,    BLAC,    MO(_MCAP2), XXXXXXX,
                BRIG,    WHIT,    BEAF,       XXXXXXX,
                CONT,    SHAD,    REDO,       XXXXXXX,
                EXPO,    HIGH,    UNDO
    ),
    [_MCAP2] = LAYOUT(/* Mac CAP2 - Layer (1) */
                XXXXXXX, XXXXXXX, XXXXXXX,    RESET,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MCAP3] = LAYOUT(/* Mac CAP3 - Layer 2 */
                XXXXXXX, XXXXXXX, MO(_MCAP4), XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MCAP4] = LAYOUT(/* Mac CAP4 - Layer (2) */
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_WCAP1] = LAYOUT(/* Win CAP1 - Layer 1 */
                SATU,    BLAC,   MO(_WCAP2), XXXXXXX,
                BRIG,    WHIT,   BEAF,       XXXXXXX,
                CONT,    SHAD,   REDO,       XXXXXXX,
                EXPO,    HIGH,   UNDO
    ),
    [_WCAP2] = LAYOUT(/* Win CAP1 - Layer (1) */
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_WCAP3] = LAYOUT(/* Win CAP1 - Layer 2 */
                XXXXXXX, XXXXXXX, MO(_WCAP4), XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_WCAP4] = LAYOUT(/* Win CAP1 - Layer (2) */
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MLRM1] = LAYOUT(/* Mac LRM - Layer 1 */
                XXXXXXX, XXXXXXX, MO(_MLRM2), XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MLRM2] = LAYOUT(/* Mac LRM - Layer (1) */
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MLRM3] = LAYOUT(/* Mac LRM - Layer 2 */
                XXXXXXX, XXXXXXX, MO(_MLRM4), XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MLRM4] = LAYOUT(/* Mac LRM - Layer (2) */
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_WLRM1] = LAYOUT(/* Win LRM - Layer 1 */
                XXXXXXX, XXXXXXX, MO(_WLRM2), XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_WLRM2] = LAYOUT(/* Win LRM - Layer (1) */
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_WLRM3] = LAYOUT(/* Win LRM - Layer 2 */
                XXXXXXX, XXXXXXX, MO(_WLRM4), XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_WLRM4] = LAYOUT(/* Win LRM - Layer (2) */
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case MO(_MCAP2):
      rgblight_sethsv_range(160,255,180,0,1);
      return true;
    case MO(_MCAP4):
      rgblight_sethsv_range(191,255,180,0,1);
      return true;
    case MO(_WCAP2):
      rgblight_sethsv_range(223,255,180,0,1);
      return true;
    case MO(_WCAP4):
      rgblight_sethsv_range(0,255,180,0,1);
      return true;
    case MO(_MLRM2):
      rgblight_sethsv_range(32,255,180,0,1);
      return true;
    case MO(_MLRM4):
      rgblight_sethsv_range(64,255,180,0,1);
      return true;
    case MO(_WLRM2):
      rgblight_sethsv_range(96,255,180,0,1);
      return true;
    case MO(_WLRM4):
      rgblight_sethsv_range(128,255,180,0,1);
      return true;
    case EXPO:
      if (record->event.pressed) {
        oled_write("Q: Exposure      ", false);
        register_code(KC_Q);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_Q);
      }
      return false;
      break;
    case CONT:
      if (record->event.pressed) {
        oled_write("W: Contrast      ", false);
        register_code(KC_W);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_W);
      }
      return false;
      break;
    case BRIG:
      if (record->event.pressed) {
        oled_write("E: Brightness    ", false);
        register_code(KC_E);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_E);
      }
      return false;
      break;
    case SATU:
      if (record->event.pressed) {
        oled_write("R: Saturation    ", false);
        register_code(KC_R);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_R);
      }
      return false;
      break;
    case HIGH:
      if (record->event.pressed) {
        oled_write("A: Highlights    ", false);
        register_code(KC_A);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_A);
      }
      return false;
      break;
    case SHAD:
      if (record->event.pressed) {
        oled_write("S: Shadow        ", false);
        register_code(KC_S);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_S);
      }
      return false;
      break;
    case WHIT:
      if (record->event.pressed) {
        oled_write("D: Whites        ", false);
        register_code(KC_D);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_D);
      }
      return false;
      break;
    case BLAC:
      if (record->event.pressed) {
        oled_write("F: Blacks        ", false);
        register_code(KC_F);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_F);
      }
      return false;
      break;
    case KELV:
      if (record->event.pressed) {
        oled_write("1: Kelvin        ", false);
        register_code(KC_1);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_1);
      }
      return false;
      break;
    case TINT:
      if (record->event.pressed) {
        oled_write("2: Tint          ", false);
        register_code(KC_2);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_2);
      }
      return false;
      break;
    case DEHA:
      if (record->event.pressed) {
        oled_write("Z: Dehaze        ", false);
        register_code(KC_Z);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_Z);
      }
      return false;
      break;
    case CLAR:
      if (record->event.pressed) {
        oled_write("X: Clarity       ", false);
        register_code(KC_X);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_X);
      }
      return false;
      break;
    case UNDO:
      if (record->event.pressed) {
        oled_write(" : UNDO          ", false);
        if (is_mac) {
          register_code(KC_LGUI);
        } else {
          register_code(KC_LCTL);
        }
        register_code(KC_Z);
      } else {
        oled_write("                 ", false);
        if (is_mac) {
          unregister_code(KC_LGUI);
        } else {
          unregister_code(KC_LCTL);
        }
        unregister_code(KC_Z);
      }
      return false;
      break;
    case REDO:
      if (record->event.pressed) {
        oled_write(" : REDO          ", false);
        if (is_mac) {
          register_code(KC_LGUI);
          register_code(KC_LSFT);
        } else {
          register_code(KC_LCTL);
          register_code(KC_LSFT);
        }
        register_code(KC_Z);
      } else {
        oled_write("                 ", false);
        if (is_mac) {
          unregister_code(KC_LGUI);
          unregister_code(KC_LSFT);
        } else {
          unregister_code(KC_LCTL);
          unregister_code(KC_LSFT);
        }
        unregister_code(KC_Z);
      }
      return false;
      break;
    case BEAF:
      if (record->event.pressed) {
        oled_write("Y: Before/After  ", false);
        register_code(KC_Y);
      } else {
        oled_write("                 ", false);
        unregister_code(KC_Y);
      }
      return false;
      break;
    case FOCU:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case GRID:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case EXPW:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case STA0:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case STA1:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case STA2:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case STA3:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case STA4:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case STA5:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case AUTO:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case COPY:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case PAST:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case ZOMI:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case ZOMO:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    case PICK:
      if (record->event.pressed) {
      } else {
      }
      return false;
      break;
    default:
      return true;
  }
}

uint8_t selected_layer = 0;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    /* if (clockwise) {
      rgblight_increase_hue(); //Cycle through the RGB hue
    } else {
      rgblight_decrease_hue();
    } */
      if (clockwise) {
          SEND_STRING(SS_TAP(X_LGUI) SS_TAP(X_RGHT));
      } else {
          SEND_STRING(SS_TAP(X_LGUI) SS_TAP(X_LEFT));
      }
  } else if (index == 1) { /* Second encoder */
    /* if (!clockwise) {
      tap_code(KC_VOLU); //Example of using tap_code which lets you use keycodes outside of the keymap
    } else {
      tap_code(KC_VOLD);
    } */
      if (clockwise) {
          tap_code(KC_WH_U);
      } else {
          tap_code(KC_WH_D);
      }
  } else if (index == 2) { /* Third encoder */
      if (clockwise && selected_layer  < 14) {
        selected_layer += 2;
      } else if (clockwise && selected_layer  == 14) {
        selected_layer = 0;
      } else if (!clockwise && selected_layer  > 0){
        selected_layer -= 2;
      } else if (!clockwise && selected_layer  == 0) {
        selected_layer = 14;
      }
      layer_clear();
      layer_on(selected_layer);
  }
}
