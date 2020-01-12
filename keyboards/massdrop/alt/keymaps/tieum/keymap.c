#include QMK_KEYBOARD_H
#include "rgblight.h"

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    KC_GAME		   //activate Game Mode
};

keymap_config_t keymap_config;

#define _LOWER 0
#define _ONE   1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LOWER] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_ONE),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_ONE] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          KC_GAME, KC_VOLU, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
	uint8_t layer = biton32(layer_state);
	static uint8_t old_layer = 0;

	dprintf("layer is %d oldlayer is %d\n", layer, old_layer);
	if (old_layer != layer) {
		dprintf("layer has changed to %d\n", layer);
		switch (layer) {
			case _LOWER:
				rgblight_sethsv_noeeprom(HSV_RED);
				break;
			case _ONE:
				rgblight_sethsv_noeeprom (HSV_CYAN);
				break;
		}
		old_layer = layer;
	} 
}

void set_leds_gaming_mode(void){
		rgblight_sethsv_noeeprom (HSV_BLUE);
		rgb_matrix_set_color(1, 0,0,0);
		rgb_matrix_set_color(2, 0,0,0);
		rgb_matrix_set_color(3, 0,0,0);
		rgb_matrix_set_color(4, 0,0,0);
		rgb_matrix_set_color(5, 0,0,0);
		rgb_matrix_set_color(6, 0,0,0);
		rgb_matrix_set_color(7, 0,0,0);
		rgb_matrix_set_color(8, 0,0,0);
		rgb_matrix_set_color(9, 0,0,0);
		rgb_matrix_set_color(10, 0,0,0);
		rgb_matrix_set_color(11, 0,0,0);
		rgb_matrix_set_color(12, 0,0,0);
		rgb_matrix_set_color(13, 0,0,0);
		rgb_matrix_set_color(14, 0,0,0);
		rgb_matrix_set_color(15, 0,0,0);
		rgb_matrix_set_color(16, RGB_CYAN);
		rgb_matrix_set_color(17, RGB_BLUE);
		rgb_matrix_set_color(18, RGB_CYAN);
		rgb_matrix_set_color(19, 0,0,0);
		rgb_matrix_set_color(20, 0,0,0);
		rgb_matrix_set_color(21, 0,0,0);
		rgb_matrix_set_color(22, 0,0,0);
		rgb_matrix_set_color(23, 0,0,0);
		rgb_matrix_set_color(24, 0,0,0);
		rgb_matrix_set_color(25, 0,0,0);
		rgb_matrix_set_color(26, 0,0,0);
		rgb_matrix_set_color(27, 0,0,0);
		rgb_matrix_set_color(28, 0,0,0);
		rgb_matrix_set_color(29, 0,0,0);
		rgb_matrix_set_color(30, 0,0,0);
		rgb_matrix_set_color(31, RGB_BLUE);
		rgb_matrix_set_color(32, RGB_BLUE);
		rgb_matrix_set_color(33, RGB_BLUE);
		rgb_matrix_set_color(34, 0,0,0);
		rgb_matrix_set_color(35, 0,0,0);
		rgb_matrix_set_color(36, 0,0,0);
		rgb_matrix_set_color(37, 0,0,0);
		rgb_matrix_set_color(38, 0,0,0);
		rgb_matrix_set_color(39, 0,0,0);
		rgb_matrix_set_color(40, 0,0,0);
		rgb_matrix_set_color(41, 0,0,0);
		rgb_matrix_set_color(42, RGB_BLUE);
		rgb_matrix_set_color(43, 0,0,0);
		rgb_matrix_set_color(44, RGB_BLUE);
		rgb_matrix_set_color(45, 0,0,0);
		rgb_matrix_set_color(46, 0,0,0);
		rgb_matrix_set_color(47, 0,0,0);
		rgb_matrix_set_color(48, 0,0,0);
		rgb_matrix_set_color(49, 0,0,0);
		rgb_matrix_set_color(50, 0,0,0);
		rgb_matrix_set_color(51, RGB_BLUE);
		rgb_matrix_set_color(52, 0,0,0);
		rgb_matrix_set_color(53, 0,0,0);
		rgb_matrix_set_color(54, 0,0,0);
		rgb_matrix_set_color(55, 0,0,0);
		rgb_matrix_set_color(56, 0,0,0);
		rgb_matrix_set_color(57, 0,0,0);
		rgb_matrix_set_color(58, RGB_BLUE);
		rgb_matrix_set_color(59, 0,0,0);
		rgb_matrix_set_color(60, 0,0,0);
		rgb_matrix_set_color(61, RGB_BLUE);
		rgb_matrix_set_color(62, 0,0,0);
		rgb_matrix_set_color(63, 0,0,0);
		rgb_matrix_set_color(64, 0,0,0);
		rgb_matrix_set_color(65, 0,0,0);
		rgb_matrix_set_color(66, 0,0,0);
}


bool gaming_mode = false;
void rgb_matrix_indicators_user(void) {
  switch (biton32(layer_state)) {
    case _ONE:
	//rgblight_sethsv_noeeprom (HSV_CYAN);
      break;
    case _LOWER:
			if (gaming_mode){
     		set_leds_gaming_mode();
			} 
			break;

    
    default:
      break;
  }

}

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
	case KC_GAME:
            if (record->event.pressed) {
		gaming_mode = ! gaming_mode;
	    }
            return false;

        default:
	    dprintf("key was %d\n", keycode);
            return true; //Process all other keycodes normally
    }
}
