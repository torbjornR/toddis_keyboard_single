/* Copyright 2021 torbjorn rasmusson
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
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    	BASE,
	SYMBOLS
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

// Define rgb layers
/*
const rgblight_segment_t PROGMEM my_alpha_layer[] = RGBLIGHT_LAYER_SEGMENTS(
				{1, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_number_layer[]= RGBLIGHT_LAYER_SEGMENTS(
				{1, 1, HSV_RED}
);

const rgblight_segment_t const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
				my_alpha_layer,
				my_number_layer
);


void keyboard_post_init_uner(void) {
	// enable led layers
	rgblight_layers = my_rgb_layers;
}
*/
/*
layer_state_t layer_state_set_user(layer_state_t state){
		switch(biton32(state)) {
				case SYMBOLS :
					rgblight_sethsv_at(120,120,120,0);
					break;
				default:	
					rgblight_sethsv_at(120,100,120	,0);
					break;
		}
		return state;
}
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
 [BASE] = LAYOUT(  // layer 0 : default
        // left hand
         KC_ESC,       KC_TAB,    	LCTL(KC_F),   	LCTL(KC_A),    	LCTL(KC_Y), 	KC_DEL,
         KC_Y,         KC_LSFT,    	LCTL(KC_X),  	LCTL(KC_C), 	LCTL(KC_V), 	KC_RALT,
         KC_C,         KC_LCTRL,    	RCS(KC_TAB),    LCTL(KC_TAB),   LCTL(KC_Z), 	KC_F5,
                           	                        KC_TAB,  	KC_ENT, 	KC_BSPC
    ), 
 [SYMBOLS] = LAYOUT(  // layer 0 : default
        // left hand
        KC_TAB,  KC_Q, KC_7, KC_8, KC_9, KC_T,
	KC_CLCK, KC_A, KC_4, KC_5, KC_6, KC_G,  
        KC_LSFT, KC_Z, KC_1, KC_2, KC_3, KC_B,
                           	                                  KC_SPC,  KC_ENT, KC_BSPC
    ),

};
 
const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0, 2, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
		{0, 2, HSV_RED}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	my_base_layer,
	my_layer1_layer	
);


layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
	rgblight_set_layer_state(1, layer_state_cmp(state, SYMBOLS));
	return state;
}

void keyboard_post_init_user(void) {
	rgblight_layers = my_rgb_layers;
} 


/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
	return true;
}
*/
