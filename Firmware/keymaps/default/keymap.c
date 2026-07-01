// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */

     // need to think about what keys to use
     // placeholder 
    [0] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,   KC_PDOT, KC_PENT
    ),

    [1] = LAYOUT(
        KC_ESC,     LCTL(KC_Z),  LCTL(KC_Y),
        LCTL(KC_C), LCTL(KC_V),  LCTL(KC_X),
        KC_MPLY,    KC_MUTE,     KC_CALC,
        KC_BSPC,    KC_SPC,      KC_PENT
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // placeholder
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }, 
    [1] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
        
};
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("petpad"),false);

    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"),false);
            break;
        case 1:
            oled_write_P(PSTR("Layer2\n"),false);
            break;
        case 2:
            oled_write_P(PSTR("Layer3\n"),false);
            break;
    }
    return false;
}
#endif
