#include QMK_KEYBOARD_H
#include "keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process


enum combo_events {
	ADDISON,
	CURL,
    PAGE,
    ARROW_KEYS,
    SCROLL_WHEEL,
    MOUSE,
    VOLUME,
    COMBO_LENGTH,
};

int COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM BSPC_A_COMBO[]   = {KC_RGHT,  KC_A,    COMBO_END};
const uint16_t PROGMEM BSPC_C_COMBO[]   = {KC_RGHT,  KC_C,    COMBO_END};

const uint16_t PROGMEM Q_A_COMBO[]   = {KC_Q,  KC_A,    COMBO_END};
const uint16_t PROGMEM Q_Z_COMBO[]   = {KC_Q,  KC_Z,    COMBO_END};
const uint16_t PROGMEM Q_X_COMBO[]   = {KC_Q,  KC_X,    COMBO_END};
const uint16_t PROGMEM Q_C_COMBO[]   = {KC_Q,  KC_C,    COMBO_END};
const uint16_t PROGMEM Q_V_COMBO[]   = {KC_Q,  KC_V,    COMBO_END};

enum encoder_modes {
    ENC_MODE_PAGE,
    ENC_MODE_ARROW,
    ENC_MODE_SCROLL,
    ENC_MODE_MOUSE,
    ENC_MODE_VOLUME,
};

uint8_t encoder_mode = ENC_MODE_SCROLL;

combo_t key_combos[COMBO_COUNT] = {
	[ADDISON]    = COMBO_ACTION(BSPC_A_COMBO),
	[CURL]    = COMBO_ACTION(BSPC_C_COMBO),
    [PAGE]    = COMBO_ACTION(Q_A_COMBO),
    [SCROLL_WHEEL]    = COMBO_ACTION(Q_Z_COMBO),
    [ARROW_KEYS]    = COMBO_ACTION(Q_X_COMBO),
    [MOUSE]    = COMBO_ACTION(Q_C_COMBO),
    [VOLUME]    = COMBO_ACTION(Q_V_COMBO),
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
            break;
        case PAGE:
            if (pressed) {
                    encoder_mode = ENC_MODE_PAGE;
            }
            break;     
        case ARROW_KEYS:
            if (pressed) {
                    encoder_mode = ENC_MODE_ARROW;
            }
            break;    
        case SCROLL_WHEEL:
            if (pressed) {
                    encoder_mode = ENC_MODE_SCROLL;
            }
            break;     
        case MOUSE:
            if (pressed) {
                    encoder_mode = ENC_MODE_MOUSE;
            }
            break;        
        case VOLUME:
            if (pressed) {
                    encoder_mode = ENC_MODE_VOLUME;
            }
            break;    
	}
       
};



bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (encoder_mode) {
        case ENC_MODE_ARROW:
            if (IS_LAYER_ON(3)) {
                if (clockwise){
                  tap_code(KC_DOWN);
                } else{
                  tap_code(KC_UP);
                }
            } else {
               if (clockwise){
                  tap_code(KC_RGHT);
                } else{
                  tap_code(KC_LEFT);
                }
            }
            break;
        case ENC_MODE_SCROLL:
            if (IS_LAYER_ON(3)) {
                if (clockwise){
                  tap_code(KC_WH_L);
                  tap_code(KC_WH_L);

                } else{
                  tap_code(KC_WH_R);
                  tap_code(KC_WH_R);
                }
            } else {
                if (clockwise){
                  tap_code(KC_WH_U);
                  tap_code(KC_WH_U);
                } else{
                  tap_code(KC_WH_D);
                  tap_code(KC_WH_D);
                }
            }
            break;
        case ENC_MODE_PAGE:
            if (clockwise){
              tap_code(KC_PGDN);
            } else{
              tap_code(KC_PGUP);
            }
            break;    
        case ENC_MODE_VOLUME:
            if (clockwise){
              tap_code(KC_VOLU);
            } else{
              tap_code(KC_VOLD);
            }
            break;
        case ENC_MODE_MOUSE:
            if (IS_LAYER_ON(3)) {
                if (clockwise){
                  tap_code(KC_MS_D);
                  tap_code(KC_MS_D);
                  tap_code(KC_MS_D);
                  tap_code(KC_MS_D);
                } else{
                  tap_code(KC_MS_U);
                  tap_code(KC_MS_U);
                  tap_code(KC_MS_U);
                  tap_code(KC_MS_U);
                }
            } 
            else {
                if (clockwise){
                  tap_code(KC_MS_R);
                  tap_code(KC_MS_R);
                  tap_code(KC_MS_R);
                  tap_code(KC_MS_R);
                } else{
                  tap_code(KC_MS_L);
                  tap_code(KC_MS_L);
                  tap_code(KC_MS_L);
                  tap_code(KC_MS_L);
                }
            }
            break;            
        default: 
            if (IS_LAYER_ON(3)) {
                if (clockwise){
                  tap_code(KC_WH_L);
                } else{
                  tap_code(KC_WH_R);
                }
            } else {
                if (clockwise){
                  tap_code(KC_WH_U);
                } else{
                  tap_code(KC_WH_D);
                }
            }
            break;   
    }
    return true;
};


// bool encoder_update_user(uint8_t index, bool clockwise) {
//     switch(biton32(layer_state)){
//         case 3: 
//             if (clockwise){
//               tap_code(KC_RGHT);
//             } else{
//               tap_code(KC_LEFT);
//             }
//             break;
//         case 4:
//             if (clockwise){
//               tap_code(KC_WH_L);
//             } else{
//               tap_code(KC_WH_R);
//             }     
//             break;    
//         default: 
//             if (clockwise){
//               tap_code(KC_WH_U);
//             } else{
//               tap_code(KC_WH_D);
//             }
//             break;
//     }
//            return true;

// };
    
