#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)
// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)


// Combos for esc, tab, bsp
const uint16_t PROGMEM esc_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(tab_combo, KC_TAB),
    COMBO(bspc_combo, KC_BSPC),
    COMBO(ent_combo, KC_ENT)
};

enum layers {
    _BASE,
    _EXT,
    _NUM,
    _SYM,
};

enum custom_keycodes {
    L_PARANG = SAFE_RANGE,
    R_PARANG,
    FSLASH_BSLASH
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_PARANG:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    // Shift is held, send `<`
                    tap_code16(KC_LABK);
                } else {
                    // Shift is not held, send `(`
                    tap_code16(KC_LPRN);
                }
            }
            return false;
        
        case R_PARANG:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    // Shift is held, send `>`
                    tap_code16(KC_RABK);
                } else {
                    // Shift is not held, send `)`
                    tap_code16(KC_RPRN);
                }
            }
            return false;
        
        case FSLASH_BSLASH:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_SLSH);
            } else if (record->event.pressed) {
                tap_code16(KC_BSLS);
            }
            return false;

        default:
            return true;  // Process all other keycodes normally
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_2(
        KC_Q, KC_W, KC_F, KC_P, KC_B,               KC_J, KC_L, KC_U, KC_Y, KC_SCLN, 
        HOME_A, HOME_R, HOME_S, HOME_T, KC_G,       KC_M, HOME_N, HOME_E, HOME_I, HOME_O, 
        KC_Z, KC_X, KC_C, KC_D, KC_V,               KC_K, KC_H, KC_COMM, KC_DOT, KC_SLASH,
                    QK_TRI_LAYER_LOWER, KC_SPC,           KC_LSFT, QK_TRI_LAYER_UPPER
    ),
    [_EXT] = LAYOUT_split_3x5_2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_INSERT, KC_HOME, KC_PGDN, KC_PGUP, KC_END, 
        KC_TRNS, KC_TRNS, MS_BTN2, MS_BTN1, KC_TRNS,         KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT,
                        KC_TRNS, KC_TRNS,                    KC_LSFT, KC_TRNS
    ),
    [_NUM] = LAYOUT_split_3x5_2(
        KC_LPRN, KC_7, KC_8, KC_9, KC_RPRN,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_QUOTE, KC_4, KC_5, KC_6, KC_MINUS,      KC_TRNS, KC_GRAVE, KC_EQUAL, KC_BSLS, KC_TRNS, 
        KC_LBRC, KC_1, KC_2, KC_3, KC_RBRC,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_0,           KC_LSFT, KC_TRNS
    ),
    [_SYM] = LAYOUT_split_3x5_2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                 KC_TRNS, KC_TRNS,       KC_LSFT, KC_TRNS
    ),    
};
