// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later
#include "lulu.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif

#ifdef OLED_ENABLE 
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return rotation;
}

void render_logo(void) {
    
    oled_write_raw_P(logo, sizeof(logo));
}

void process_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_raw_P(layer_one, sizeof(layer_one));
            break;
        case 1:
             oled_write_raw_P(layer_two, sizeof(layer_two));
            break;
        case 2:
            oled_write_raw_P(layer_three, sizeof(layer_three));
            break;
        case 3:
             oled_write_raw_P(layer_four, sizeof(layer_four));
            break;
        case 4:
             oled_write_raw_P(layer_five, sizeof(layer_five));
            break;
    }
}

bool oled_task_kb(void) {
    if (!oled_task_user()) { 
        return false; 
    }
    if (is_keyboard_master()) {
        process_layer_state();
    } else {
        render_logo();
    }
    return false;
}
#endif
