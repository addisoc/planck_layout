#include QMK_KEYBOARD_H
#include "keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process


enum combo_events {
	ADDISON,
	CURL,
    COMBO_LENGTH,
};

int COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM BSPC_A_COMBO[]   = {KC_BSPC,  KC_A,    COMBO_END};
const uint16_t PROGMEM BSPC_C_COMBO[]   = {KC_BSPC,  KC_C,    COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
	[ADDISON]    = COMBO_ACTION(BSPC_A_COMBO),
	[CURL]    = COMBO_ACTION(BSPC_C_COMBO),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    // Process mod-taps before the combo is fired,
    // this helps making modifier-aware combos,
    // like UY_PRN or BSPCN_NOT, more fluid
    // when I use them with home row mods.
    action_tapping_process((keyrecord_t){});
    switch(combo_index) {
    	case ADDISON:
            if (pressed) {
                    send_string("addison.chung@lunatech.nl");
	        }
        break;
        case CURL:
            if (pressed) {
                    send_string("curl localhost:9095 ");
	        }
	}
       
};