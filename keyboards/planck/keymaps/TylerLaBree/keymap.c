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

enum planck_layers {
  _WORKMAN,
  _GAMING,
  _MDA,
  _NAV,
  _MSE,
  _SYM,
  _NUM,
  _FNC,
  _MDE
};

enum planck_keycodes {
  WORKMAN = SAFE_RANGE,
  GAMING,
};

//Define layers
#define MDA MO(_MDA) // Media
#define NAV MO(_NAV) // Navigation
#define MSE MO(_MSE) // Mouse
#define SYM MO(_SYM) // Symbols (same as NUM + Shift)
#define NUM MO(_NUM) // Numbers
#define FNC MO(_FNC) // Function
#define MDE MO(_MDE) // Mode

//Tap-hold thumb layers
#define MDA_ESC LT(_MDA, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define MSE_TAB LT(_MSE, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define NUM_BSC LT(_NUM, KC_BSPC)
#define FNC_DEL LT(_FNC, KC_DEL)

//Tap-hold home row modifiers
#define ALT_A LALT_T(KC_A)
#define GUI_S LGUI_T(KC_S)
#define SHFT_H LSFT_T(KC_H)
#define CTRL_T LCTL_T(KC_T)
#define CTRL_N LCTL_T(KC_N)
#define SHFT_E LSFT_T(KC_E)
#define GUI_O LGUI_T(KC_O)
#define ALT_I LALT_T(KC_I)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_WORKMAN] = LAYOUT_planck_grid(
    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    HYPR(KC_1), HYPR(KC_2), KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN,
    ALT_A,   GUI_S,   SHFT_H,  CTRL_T,  KC_G,    HYPR(KC_3), HYPR(KC_4), KC_Y,    CTRL_N,  SHFT_E,  GUI_O,   ALT_I,
    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    HYPR(KC_5), HYPR(KC_6), KC_K,    KC_L,    KC_DOT,  KC_QUOT, KC_QUES,
    XXXXXXX, GAMING,  MDA_ESC, NAV_SPC, MSE_TAB, HYPR(KC_0), HYPR(KC_0), SYM_ENT, NUM_BSC, FNC_DEL, WORKMAN, MDE
),

[_GAMING] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, GAMING,  KC_ESC,  KC_SPC,  KC_TAB,  KC_SPC,  KC_SPC,  SYM_ENT, NUM_BSC, FNC_DEL, WORKMAN, MDE
),

[_MDA] = LAYOUT_planck_grid(
    RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, AU_ON,   AU_OFF,  XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,
    KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, XXXXXXX, AU_ON,   AU_OFF,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAI, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SAI, RGB_HUI, RGB_TOG,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX
),

[_NAV] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_COLN,
    KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, XXXXXXX, KC_COMM, KC_DQT,  KC_EXLM,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_MSE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
    KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX
),

[_SYM] = LAYOUT_planck_grid(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_RCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_NUM] = LAYOUT_planck_grid(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_RBRC, KC_4,    KC_5,    KC_6,    KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_FNC] = LAYOUT_planck_grid(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_MENU, KC_SPC,  KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_MDE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAMING,  WORKMAN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WORKMAN:
      if (record->event.pressed) {
        rgblight_disable();
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        rgblight_enable();
        set_single_persistent_default_layer(_GAMING);
      }
      return false;
      break;
  }
  return true;
}

