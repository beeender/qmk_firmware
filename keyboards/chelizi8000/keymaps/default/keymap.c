/* Copyright 2019 Salicylic_Acid
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
#include "app_ble_func.h"

#define _BASE 0
#define _FUNC 1

enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    USB_TOG,              /* Toggle USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
};

// Fillers to make layering more clear
#define ______ KC_TRNS
#define XXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_104(\
KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,          KC_PSCR,LT(_FUNC, KC_SLCK),KC_PAUS,                        \
KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSPC,   KC_INS,KC_HOME,KC_PGUP,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS, \
KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,KC_BSLS,   KC_DEL, KC_END,KC_PGDN,  KC_P7,  KC_P8,  KC_P9,KC_PPLS, \
KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,         KC_ENT,                            KC_P4,  KC_P5,  KC_P6,      \
KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT,      KC_SLSH,        KC_RSFT,            KC_UP,          KC_P1,  KC_P2,  KC_P3,KC_PENT, \
KC_LCTL,KC_LGUI, KC_LALT,                 KC_SPC,                                KC_RALT,KC_RGUI, KC_APP,KC_RCTL, KC_LEFT,KC_DOWN,KC_RGHT, KC_P0,KC_PDOT),
[_FUNC] = LAYOUT_104(\
XXXXXX,  DEL_ID0,  DEL_ID1,  DEL_ID2,  DEL_ID3,  DEL_ID4,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX, XXXXXX, XXXXXX, XXXXXX,          XXXXXX,______,XXXXXX,                        \
XXXXXX,  ADV_ID0, ADV_ID1, ADV_ID2, ADV_ID3, ADV_ID4,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,XXXXXX, XXXXXX,XXXXXX,   XXXXXX,XXXXXX,XXXXXX,  XXXXXX,XXXXXX,XXXXXX,XXXXXX, \
XXXXXX,  XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   USB_TOG,   XXXXXX,   XXXXXX,   XXXXXX,XXXXXX,XXXXXX,XXXXXX,   XXXXXX, XXXXXX,XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,XXXXXX, \
XXXXXX, XXXXXX,   XXXXXX,   DELBNDS,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,XXXXXX,XXXXXX,         XXXXXX,                            XXXXXX,  XXXXXX,  XXXXXX,      \
XXXXXX, XXXXXX,   XXXXXX,   XXXXXX,   XXXXXX,   ENT_DFU,   XXXXXX,   XXXXXX,   XXXXXX,XXXXXX,      XXXXXX,        XXXXXX,            XXXXXX,          XXXXXX,  XXXXXX,  XXXXXX,XXXXXX, \
XXXXXX,XXXXXX, XXXXXX,                 XXXXXX,                                XXXXXX,XXXXXX, XXXXXX,XXXXXX, XXXXXX,XXXXXX,XXXXXX, XXXXXX,XXXXXX)
};

extern void led_function_layer_state(bool s);

uint32_t layer_state_set_user(uint32_t state) {
  if (state &= (1UL << _FUNC)) {
      led_function_layer_state(true);
  } else {
      led_function_layer_state(false);
  }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];
  if (record->event.pressed) {
    switch (keycode) {
      case DELBNDS:
        delete_bonds();
        return false;
      case AD_WO_L:
        restart_advertising_wo_whitelist();
        return false;
      case ENT_DFU:
        bootloader_jump();
        return false;
      case USB_TOG:
        set_usb_enabled(!get_usb_enabled());
        break;
      case ADV_ID0:
        restart_advertising_id(0);
        return false;
      case ADV_ID1:
        restart_advertising_id(1);
        return false;
      case ADV_ID2:
        restart_advertising_id(2);
        return false;
      case ADV_ID3:
        restart_advertising_id(3);
        return false;
      case ADV_ID4:
        restart_advertising_id(4);
        return false;
      case DEL_ID0:
        delete_bond_id(0);
        return false;
      case DEL_ID1:
        delete_bond_id(1);
        return false;
      case DEL_ID2:
        delete_bond_id(2);
        return false;
      case DEL_ID3:
        delete_bond_id(3);
        return false;
      case BATT_LV:
        sprintf(str, "%4dmV", get_vcc());
        send_string(str);
        return false;
      default:
        break;
    }
  }

  return true;
}
