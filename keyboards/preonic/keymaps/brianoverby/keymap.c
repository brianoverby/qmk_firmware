#include QMK_KEYBOARD_H
#include "brianoverby.h" // Includes Danish and custom keymaps

extern keymap_config_t keymap_config;

enum preonic_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _FN,
  _SYSTEM
};

/*
enum preonic_keycodes {
  BASE = SAFE_RANGE,
  LOWER
};
*/

bool winkey_enabled = true;

/* Define mod keys */
#define lw MO(_LOWER)
#define ra MO(_RAISE)
#define fn MO(_FN)
#define rset RESET

#define ____ KC_TRNS
#define xxxx KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_preonic_grid(
  GRV,  n1,   NUM2, n3,   NUM4, n5,   NUM6, NUM7, NUM8, NUM9, NUM0, bspc,
  tab,  q,    w,    e,    r,    t,    y,    u,    i,    o,    p,    BSLS, 
  esc,  a,    s,    d,    f,    g,    h,    j,    k,    l,    SCLN, QUOT,
  LSFT, z,    x,    c,    v,    b,    n,    m,    COMM, DOT,  up,   ent, 
  lctl, fn,   lgui, lalt, lw,   spc,  spc,  ra,   SLSH, left, down, rght 
),

[_LOWER] = LAYOUT_preonic_grid(
  ____, f1,   f2,   f3,   f4,   f5,   f6,   f7,   f8,   f9,   f10,  del,
  ____, f11,  f12,  eql,  xxxx, xxxx, xxxx, unds, xxxx, lcbr, rcbr, xxxx,
  ____, plus, mins, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, lbrc, rbrc, acut,
  ____, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, mute, xxxx, xxxx, volu, ____,
  ____, ____, ____, ____, ____, ____, ____, ____, xxxx, xxxx, vold, xxxx
),

[_RAISE] = LAYOUT_preonic_grid(
  ____, f1,   f2,   f3,   f4,   f5,   f6,   f7,   f8,   f9,   f10,  del,
  ____, f11,  f12,  eql,  xxxx, xxxx, xxxx, unds, xxxx, lcbr, rcbr, xxxx,
  ____, plus, mins, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, lbrc, rbrc, uml,
  ____, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, mute, xxxx, xxxx, volu, ____,
  ____, ____, ____, ____, ____, ____, ____, ____, xxxx, xxxx, vold, xxxx
),

[_FN] = LAYOUT_preonic_grid(
  xxxx, f1,   f2,   f3,   f4,   f5,   f6,   f7,   f8,   f9,   f10,  del,
  ____, f11,  f12,  xxxx, xxxx, xxxx, xxxx, xxxx, ins,  xxxx, prnt, aa,
  ____, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, ae,   oe,
  ____, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, pgup, ____,
  ____, ____, ____, ____, ____, ____, ____, ____, xxxx, home, pgdn, end
),

[_SYSTEM] = LAYOUT_preonic_grid(
  xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, ____,
  ____, xxxx, xxxx, xxxx, rset, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
  ____, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
  ____, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, ____,
  ____, ____, ____, ____, ____, ____, ____, ____, xxxx, xxxx, xxxx, xxxx  
)

};

/* Hold Lower + Raise to activate SYSTEM layer */
uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _SYSTEM);
  return state;
}
