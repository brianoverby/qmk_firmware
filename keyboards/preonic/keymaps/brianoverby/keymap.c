#include QMK_KEYBOARD_H
#include "keymap_danish.h" // Includes Danish and custom keymaps

enum preonic_layers {
  _BASE,
  _LOWER,
  _FN,
  _SYSTEM
};

enum preonic_keycodes {
  BASE = SAFE_RANGE,
  LOWER
};

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
  esc,  n1,   n2,   n3,   n4,   n5,   n6,   n7,   n8,   n9,   n0,   bspc,
  tab,  q,    w,    e,    r,    t,    y,    u,    i,    o,    p,    plus, 
  lt,   a,    s,    d,    f,    g,    h,    j,    k,    l,    quot, ent,
  lsft, z,    x,    c,    v,    b,    n,    m,    comm, dot,  up,   rsft, 
  lctl, fn,   lgui, lalt, lw,   spc,  spc,  ralt, mins, left, down, rght 
),

[_LOWER] = LAYOUT_preonic_grid(
  grv,  f1,   f2,   f3,   f4,   f5,   f6,   f7,   f8,   f9,   f10,  del,
  tild, f11,  f12,  xxxx, xxxx, xxxx, xxxx, xxxx, pipe, xxxx, xxxx, xxxx,
  ____, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, acut, ____,
  ____, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, mute, xxxx, uml,  volu, ____,
  ____, ____, ____, ____, ____, ____, ____, ____, xxxx, xxxx, vold, xxxx
),

[_FN] = LAYOUT_preonic_grid(
  ____, f1,   f2,   f3,   f4,   f5,   f6,   f7,   f8,   f9,   f10,  del,
  ____, f11,  f12,  xxxx, xxxx, xxxx, xxxx, xxxx, ins,  xxxx, prnt, aa,
  xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, ae,   oe,
  ____, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, pgup, ____,
  ____, ____, ____, ____, ____, ____, ____, ____, xxxx, home, pgdn, end
),

[_SYSTEM] = LAYOUT_preonic_grid(
  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
  ____, ____, ____, ____, rset, ____, ____, ____, ____, ____, ____, ____,
  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____  
)

};

/* Hold Lower + Raise to activate SYSTEM layer */
uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _LOWER, _FN, _SYSTEM);
  return state;
}
