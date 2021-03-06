#include QMK_KEYBOARD_H
#include "keymap_danish.h"
#include "ovby.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_planck_grid(
        KC_TAB,  DK_Q, DK_W,    DK_E,    DK_R,  DK_T,   DK_Y,   DK_U,  DK_I, DK_O,    DK_P, KC_BSPC,
        KC_ESC,  DK_A, DK_S,    DK_D,    DK_F,  DK_G,   DK_H,   DK_J,  DK_K, DK_L,    SCLN, QUOT,
        KC_LSFT, DK_Z, DK_X,    DK_C,    DK_V,  DK_B,   DK_N,   DK_M,  COMM, DOT,     KC_UP, KC_ENT,
        KC_LCTL, FN,   KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, SLSH, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_GAME] = LAYOUT_planck_grid(
        DK_1, DK_Q, DK_W, DK_E, DK_R,  DK_T,   DK_Y,   DK_U,  DK_I, DK_O,    DK_P, KC_BSPC,
        _______, DK_A, DK_S, DK_D, DK_F,  DK_G,   DK_H,   DK_J,  DK_K, DK_L,    SCLN, QUOT,
        _______, DK_Z, DK_X, DK_C, DK_V,  DK_B,   DK_N,   DK_M,  COMM, DOT,     KC_UP, KC_ENT,
        _______, DK_4, DK_3, DK_2, LOWER, KC_SPC, KC_SPC, RAISE, SLSH, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LOWER] = LAYOUT_planck_grid(
        DK_TILD, DK_EXLM, DK_AT, DK_HASH, DK_DLR, DK_PERC, DK_CIRC, DK_AMPR, DK_ASTR, DK_LPRN, DK_RPRN, KC_BSPC,
        _______, DK_1,   DK_2,   DK_3,   DK_4,   DK_5,   XXXXXXX, DK_UNDS, DK_PLUS, DK_LCBR, DK_RCBR, DK_ACUT,
        _______, DK_6,   DK_7,   DK_8,   DK_9,   DK_0,   XXXXXXX, DK_MINS, DK_EQL,  DK_LBRC, DK_RBRC, _______,
        _______, FN,   KC_LGUI, KC_LALT, _______, _______, _______, _______, DK_BSLS, DK_PIPE, XXXXXXX, XXXXXXX
    ),

    [_RAISE] = LAYOUT_planck_grid(
        DK_GRV,  DK_1,   DK_2,   DK_3,   DK_4,   DK_5,   DK_6,   DK_7,   DK_8,   DK_9,   DK_0, KC_BSPC,
        _______, DK_4,   DK_5,   DK_6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_DIAE,
        _______, DK_7,   DK_8,   DK_9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_VOLU, _______,
        _______, FN,   KC_LGUI, KC_LALT, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_MPLY
    ),

    [_FN] = LAYOUT_planck_grid(
        KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, KC_PSCR, DK_ARNG,
        KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_AE,   DK_OSTR,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_DEL,
        _______, FN,   KC_LGUI, KC_LALT, _______, _______, _______, _______, XXXXXXX, KC_HOME, KC_PGDN, KC_END
    ),

    [_SYSTEM] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, WNTG, XXXXXXX, RSET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};
