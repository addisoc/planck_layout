#include QMK_KEYBOARD_H
#include "keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process


enum combo_events {
	ADDISON,
	CLASS,
	EXTENDS,
    OBJECT,
    OVERRIDE,
    VAL,
    COMBO_LENGTH,
};

int COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM BSPC_A_COMBO[]   = {KC_BSPC,  KC_A,    COMBO_END};
const uint16_t PROGMEM BSPC_C_COMBO[]   = {KC_BSPC,  KC_C,    COMBO_END};
const uint16_t PROGMEM BSPC_E_COMBO[]   = {KC_BSPC,  KC_E,    COMBO_END};
const uint16_t PROGMEM BSPC_O_B_COMBO[]   = {KC_BSPC,  KC_O, KC_B,   COMBO_END};
const uint16_t PROGMEM BSPC_O_R_COMBO[]   = {KC_BSPC,  KC_O, KC_R,   COMBO_END};
const uint16_t PROGMEM BSPC_V_COMBO[]   = {KC_BSPC,  KC_V,   COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
	[ADDISON]    = COMBO_ACTION(BSPC_A_COMBO),
	[CLASS]    = COMBO_ACTION(BSPC_C_COMBO),
	[EXTENDS]    = COMBO_ACTION(BSPC_E_COMBO),
    [OBJECT]    = COMBO_ACTION(BSPC_O_B_COMBO),
    [OVERRIDE]    = COMBO_ACTION(BSPC_O_R_COMBO),
    [VAL]    = COMBO_ACTION(BSPC_V_COMBO),
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
        case CLASS:
            if (pressed) {
                    send_string("class ");
	        }
        break;
        case EXTENDS:
            if (pressed) {
                    send_string("extends ");
	        }
        break;
        case OBJECT:
            if (pressed) {
                    send_string("object ");
	        }
        break;
        case OVERRIDE:
            if (pressed) {
                    send_string("override ");
	        }
        break;
        case VAL:
            if (pressed) {
                    send_string("val ");
	        }
        break;
	}
       
};