/* Copyright 2021 Jay Greco
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
#include "action_layer.h"

#define _MLRM1    0
#define _MLRM2    1
#define _MCAP1    2
#define _MCAP2    3
#define _WLRM1    4
#define _WLRM2    5
#define _WCAP1    6
#define _WCAP2    7
#define _9KEY     8
#define _FUNC     9

#ifdef OLED_ENABLE

// Set OLED rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_layer_state(void) {
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case _MLRM1:
            /*  —,           Adjust Slider,  Previous Slider,  Next Slider
               View Style,   Panels,         Undo,      	     Redo
               Library,      Up,     	       Develop,          —
               Left,         Down,     	     Right,            —
               Reject/Next,  Pick/Next,       —,               — */
            oled_write_P(PSTR("MLRM1\n"), false);
            oled_write_P(PSTR(" -SPN\n"), false);
            oled_write_P(PSTR(" VPUR\n"), false);
            oled_write_P(PSTR(" LUD-\n"), false);
            oled_write_P(PSTR(" LDR-\n"), false);
            oled_write_P(PSTR(" RP- \n"), false);
            break;
        case _MLRM2:
            /* —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, — */
            oled_write_P(PSTR("MLRM2\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" --- \n"), false);
            break;
        case _MCAP1:
            /* —,        Adjust Slider,  Previous Image, Next Image
               Exposure,  Contrast,       Brightness,     Saturation
               Highlight, Shadow,         White,          Black
               Kelvin,    Tint,           Dehaze,         Clarity
               Undo,      Redo,           Before/After,   — */
            oled_write_P(PSTR("MCAP1\n"), false);
            oled_write_P(PSTR(" -SPN\n"), false);
            oled_write_P(PSTR(" ECBS\n"), false);
            oled_write_P(PSTR(" HSWB\n"), false);
            oled_write_P(PSTR(" WTDC\n"), false);
            oled_write_P(PSTR(" URB \n"), false);
            break;
        case _MCAP2:
            /*             _______,       XXXXXXX,   XXXXXXX,
              Focus Mask,  Before/After,  Grid,      Exposure Warning,
              3 Star,      5 Star,        0 Star,    Auto Adjust,
              Previous,    Next,          Copy Adj,  Paste Adj,
              Select,      Zoom Out,      Zoom In,    -  */
            oled_write_P(PSTR("MCAP2\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" FBGE\n"), false);
            oled_write_P(PSTR(" 350A\n"), false);
            oled_write_P(PSTR(" PNCP\n"), false);
            oled_write_P(PSTR(" S-+ \n"), false);
            break;
        case _WLRM1:
            /* —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, — */
            oled_write_P(PSTR("WLRM1\n"), false);
            oled_write_P(PSTR(" -SPN\n"), false);
            oled_write_P(PSTR(" VPUR\n"), false);
            oled_write_P(PSTR(" LUD-\n"), false);
            oled_write_P(PSTR(" LDR-\n"), false);
            oled_write_P(PSTR(" RP- \n"), false);
            break;
        case _WLRM2:
            /* —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, — */
            oled_write_P(PSTR("WLRM2\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" --- \n"), false);
            break;
        case _WCAP1:
            /* —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, — */
            oled_write_P(PSTR("WCAP1\n"), false);
            oled_write_P(PSTR(" -SPN\n"), false);
            oled_write_P(PSTR(" ECBS\n"), false);
            oled_write_P(PSTR(" HSWB\n"), false);
            oled_write_P(PSTR(" WTDC\n"), false);
            oled_write_P(PSTR(" URB \n"), false);
            break;
        case _WCAP2:
            /* —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, — */
            oled_write_P(PSTR("WCAP2\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" --- \n"), false);
            break;
        case _9KEY:
            /* —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, — */
            oled_write_P(PSTR("9KEY \n"), false);
            oled_write_P(PSTR(" ---/\n"), false);
            oled_write_P(PSTR(" 789*\n"), false);
            oled_write_P(PSTR(" 456-\n"), false);
            oled_write_P(PSTR(" 123+\n"), false);
            oled_write_P(PSTR(" 0-.=\n"), false);
            break;
        case _FUNC:
            /* —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, —
               —, —, —, — */
            oled_write_P(PSTR("FUNC \n"), false);
            oled_write_P(PSTR(" ----\n"), false);
            oled_write_P(PSTR(" --M-\n"), false);
            oled_write_P(PSTR(" --H-\n"), false);
            oled_write_P(PSTR(" --S-\n"), false);
            oled_write_P(PSTR(" R-VT\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("UNDEF"), false);
            break;
    }

    // Host Keyboard LED Status
    /* led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM  ") : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP  ") : PSTR("     "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR  ") : PSTR("     "), false); */
}

bool oled_task_user(void) {
    render_layer_state();
    return true;
}

#endif

enum custom_keycodes {
  PROG = SAFE_RANGE,
  LGND,
};

enum td_keycodes {
    TD_ENTER_LAYER
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for KP_ENTER, twice for _FUNC layer
    [TD_ENTER_LAYER] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_KP_ENTER, 1),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base layer (numpad)
  /* [_BASE] = LAYOUT(
           KC_NO,    KC_KP_ASTERISK, KC_KP_MINUS, \
  KC_KP_7, KC_KP_8,  KC_KP_9,        KC_KP_PLUS, \
  KC_KP_4, KC_KP_5,  KC_KP_6,        KC_NO, \
  KC_KP_1, KC_KP_2,  KC_KP_3,        TD(TD_ENTER_LAYER), \
  KC_NO,   KC_KP_0,  KC_KP_DOT,      KC_NO \
  ),  */
  [_MLRM1] = LAYOUT(
              LGND,     KC_COMM,     KC_DOT,      \
    KC_J,     KC_TAB,   LCMD(KC_Z),  SCMD(KC_Z),  \
    KC_G,     KC_UP,    KC_D,        S(KC_P),     \
    KC_LEFT,  KC_DOWN,  KC_RGHT,     S(KC_X),     \
    KC_NO,    KC_NO,    KC_NO,       TO(_MLRM2)  \
  ),

  // Mac Lightroom layer (numpad)
  /* —,            Adjust Slider,  Previous Slider,  Next Slider
     View Style,   Panels,         Undo,      	     Redo
     Library,      Up,     	       Develop,          —
     Left,         Down,     	     Right,            —
     Reject/Next,  Pick/Next,       —,               — */
  [_MLRM2] = LAYOUT(
             _______,  KC_NO,   KC_NO,       \
    KC_NO,   KC_NO,    KC_NO,   KC_NO,       \
    KC_NO,   KC_NO,    KC_NO,   KC_NO,       \
    KC_NO,   KC_NO,    KC_NO,   KC_NO,       \
    KC_NO,   KC_NO,    KC_NO,    TO(_MLRM1) \
  ),

  // Mac Capture One 1
  /* —,         Adjust Slider,  Previous Image, Next Image
     Exposure,  Contrast,       Brightness,     Saturation
     Highlight, Shadow,         White,          Black
     Kelvin,    Tint,           Dehaze,         Clarity
     Undo,      Redo,           Before/After,   — */
  [_MCAP1] = LAYOUT(
                 LGND,        LCMD(KC_LEFT),  LCMD(KC_RGHT),  \
    KC_Q,        KC_W,        KC_E,           KC_R,           \
    KC_A,        KC_S,        KC_D,           KC_F,           \
    KC_1,        KC_2,        KC_Z,           KC_X,           \
    LCMD(KC_Z),  SCMD(KC_Z),  KC_Y,           TO(_MCAP2)      \
  ),

    // Mac Capture One 2
    /*             _______,       XXXXXXX,   XXXXXXX,
      Focus Mask,  Before/After,  Grid,      Exposure Warning,
      3 Star,      5 Star,        0 Star,    Auto Adjust,
      Previous,    Next,          Copy Adj,  Paste Adj,
      Select,      Zoom Out,      Zoom In,    -  */
  [_MCAP2] = LAYOUT(
                    _______,        KC_NO,         KC_NO,       \
    LCMD(KC_F),     KC_Y,           KC_G,          LCMD(KC_E),  \
    KC_3,           KC_5,           KC_0,          LCMD(KC_L),  \
    LCMD(KC_LEFT),  LCMD(KC_RGHT),  SCMD(KC_C),    SCMD(KC_V),  \
    KC_SPC,         LCMD(KC_MINS),  LCMD(KC_EQL),  TO(_MCAP1)   \
  ),

  // Windows Lightroom layer (numpad)
  /* Next Layer,   Adjust Slider,  Previous Slider,  Next Slider
     View Style,   Panels,         Undo,      	     Redo
     Library,      Up,     	       Develop,          —
     Left,         Down,     	     Right,            —
     Reject/Next,  Pick/Next,      —,                — */
  [_WLRM1] = LAYOUT(
              LGND,     KC_COMM,  KC_DOT,      \
    KC_J,     KC_TAB,   C(KC_Z),  S(C(KC_Z)),  \
    KC_G,     KC_UP,    KC_D,     S(KC_P),     \
    KC_LEFT,  KC_DOWN,  KC_RGHT,  S(KC_X),     \
    KC_NO,    KC_NO,    KC_NO,    TO(_WLRM2)  \
  ),
  [_WLRM2] = LAYOUT(
             _______,  KC_NO,   KC_NO,       \
    KC_NO,   KC_NO,    KC_NO,   KC_NO,       \
    KC_NO,   KC_NO,    KC_NO,   KC_NO,       \
    KC_NO,   KC_NO,    KC_NO,   KC_NO,       \
    KC_NO,   KC_NO,    KC_Z,    TO(_WLRM1)  \
  ),

  // Mac Capture One layer (numpad)
  /* —,         Adjust Slider,  Previous Image, Next Image
     Exposure,  Contrast,       Brightness,     Saturation
     Highlight, Shadow,         White,          Black
     Kelvin,    Tint,           Dehaze,         Clarity
     Undo,      Redo,           Before/After,   — */
  [_WCAP1] = LAYOUT(
              LGND,        C(KC_LEFT),  C(KC_RGHT),  \
    KC_Q,     KC_W,        KC_E,        KC_R,        \
    KC_A,     KC_S,        KC_D,        KC_F,        \
    KC_1,     KC_2,        KC_Z,        KC_X,        \
    C(KC_Z),  S(C(KC_Z)),  KC_Y,        TO(_WCAP2)   \
  ),

  [_WCAP2] = LAYOUT(
              _______,  KC_NO,    KC_NO,       \
    KC_NO,    KC_NO,    KC_NO,    KC_NO,       \
    KC_NO,    KC_NO,    KC_NO,    KC_NO,       \
    KC_NO,    KC_NO,    KC_NO,    KC_NO,       \
    KC_NO,    KC_NO,    KC_NO,    TO(_WCAP1)   \
  ),

  // Base layer (numpad)
  /*          _______,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX  */
  [_9KEY] = LAYOUT(
              LGND,     KC_NO,    KC_PSLS,  \
    KC_P7,    KC_P8,    KC_P9,    KC_PAST,  \
    KC_P4,    KC_P5,    KC_P6,    KC_PMNS,  \
    KC_P1,    KC_P2,    KC_P3,    KC_PPLS,  \
    KC_P0,    KC_NO,    KC_PDOT,  KC_PENT   \
  ),

  // Function layer (numpad)
  /*          _______,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX  */
  [_FUNC] = LAYOUT(
              LGND,     KC_NO,    KC_NO,    \
    KC_NO,    KC_NO,    RGB_MOD,  KC_NO,    \
    KC_NO,    KC_NO,    RGB_HUI,  KC_NO,    \
    KC_NO,    KC_NO,    RGB_SAI,  KC_NO,    \
    RESET,    KC_NO,    RGB_VAI,  RGB_TOG   \
  ),

  // Layer Name (numpad)
  /*          _______,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX  */
  /*
  [_NAME] = LAYOUT(
              _______,  XXXXXXX,  XXXXXXX,  \
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  \
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  \
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  \
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX   \
  ),
  */

};

void matrix_init_user(void) {
  matrix_init_remote_kb();
  //register_code(KC_NLCK);
}

void matrix_scan_user(void) {
  matrix_scan_remote_kb();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_record_remote_kb(keycode, record);

  switch(keycode) {
    case PROG:
      if (record->event.pressed) {
        set_bitc_LED(LED_DIM);
        rgblight_disable_noeeprom();
        bootloader_jump(); //jump to bootloader
      }
      return false;
    case LGND:
      if (record->event.pressed) {
        if (get_highest_layer(layer_state)==_MLRM1) {
          layer_move(_MCAP1);
        } else if (get_highest_layer(layer_state)==_MCAP1) {
          layer_move(_WLRM1);
        } else if (get_highest_layer(layer_state)==_WLRM1) {
          layer_move(_WCAP1);
        } else if (get_highest_layer(layer_state)==_WCAP1) {
          layer_move(_9KEY);
        } else if (get_highest_layer(layer_state)==_9KEY) {
          layer_move(_FUNC);
        } else if (get_highest_layer(layer_state)==_FUNC) {
          layer_move(_MLRM1);
        }
      }
      return false;

    default:
      return true;
  }
}

// LH: Oddly, have to reverse the keys
bool encoder_update_user(uint8_t index, bool clockwise) {
  switch (get_highest_layer(layer_state)) {
        case _MLRM1:
            if (clockwise) {
        	    	tap_code(KC_MINS);
      	    } else {
                tap_code(KC_EQL);
      	    }
            break;
        case _MCAP1:
            if (clockwise) {
        	    	tap_code(KC_WH_D);
      	    } else {
                tap_code(KC_WH_U);
      	    }
            break;
        case _WLRM1:
            if (clockwise) {
        	    	tap_code(KC_MINS);
      	    } else {
                tap_code(KC_EQL);
      	    }
            break;
        case _WCAP1:
            if (clockwise) {
        	    	tap_code(KC_WH_D);
      	    } else {
                tap_code(KC_WH_U);
      	    }
            break;
        case _9KEY:
            if (clockwise) {
    	    	    tap_code(KC_VOLD);
      	    } else {
              	tap_code(KC_VOLU);
      	    }
            break;
        case _FUNC:
            if (clockwise) {
                /*if (oled_get_brightness() > 0) {
                  oled_set_brightness(1);
                }*/
      	    } else {
                /*if (oled_get_brightness() < 255) {
                  oled_set_brightness(255);
                }*/
      	    }
            break;
    }

    return true;
}
