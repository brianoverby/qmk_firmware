#include "keymap_danish.h"
#include "brianoverby.h"

__attribute__ ((weak))
layer_state_t layer_state_set_keymap (layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _SYSTEM);
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case COMM:    // , | <
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          unregister_code16(KC_LSFT);  // Remove shift before sending the keycode
          register_code16(DK_LABK);
          register_code16(KC_LSFT);
        } else {
          register_code16(KC_COMM);
        }
      } else {
        unregister_code16(DK_LABK);
        unregister_code16(KC_COMM);
      }
      return false;
      break;

    case DOT:    // . | >
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(DK_RABK);
        } else {
          register_code16(KC_DOT);
        }
      } else {
        unregister_code16(DK_RABK);
        unregister_code16(KC_DOT);
      }
      return false;
      break;

    case SLSH:    // / | ?
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(DK_QUES);
        } else {
          register_code16(DK_SLSH);
        }
      } else {
        unregister_code16(DK_QUES);
        unregister_code16(DK_SLSH);
      }
      return false;
      break;

    case SCLN:    // ; | :
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(DK_COLN);
        } else {
          register_code16(DK_SCLN);
        }
      } else {
        unregister_code16(DK_COLN);
        unregister_code16(DK_SCLN);
      }
      return false;
      break;

    case QUOT:    // ' | "
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(DK_DQUO);
        } else {
          register_code16(DK_QUOT);
        }
      } else {
        unregister_code16(DK_DQUO);
        unregister_code16(DK_QUOT);
      }
      return false;
      break;
  }
  return process_record_keymap(keycode, record);
};

#ifdef RGB_MATRIX_ENABLE

void rgb_matrix_indicators_user() {

  switch (biton32(layer_state)) {
    case _BASE:
      rgb_matrix_set_color_all(255, 255, 255);
      break;
    case _GAME:
      rgb_matrix_set_color_all(50, 0, 50);
      break;
    case _LOWER:
      rgb_matrix_set_color_all(50, 0, 250);
      break;
    case _RAISE:
      rgb_matrix_set_color_all(250, 0, 50);
      break;
    case _FN:
      rgb_matrix_set_color(22, 0, 0, 255);
      rgb_matrix_set_color(23, 0, 0, 255);
      rgb_matrix_set_color(11, 0, 0, 255);
      rgb_matrix_set_color(1, 50, 0, 50);
      rgb_matrix_set_color(2, 50, 0, 50);
      rgb_matrix_set_color(3, 50, 0, 50);
      rgb_matrix_set_color(4, 50, 0, 50);
      rgb_matrix_set_color(13, 50, 0, 50);
      rgb_matrix_set_color(14, 50, 0, 50);
      rgb_matrix_set_color(15, 50, 0, 50);
      rgb_matrix_set_color(16, 50, 0, 50);
      rgb_matrix_set_color(25, 50, 0, 50);
      rgb_matrix_set_color(26, 50, 0, 50);
      rgb_matrix_set_color(27, 50, 0, 50);
      rgb_matrix_set_color(28, 50, 0, 50);
      break;
    case _SYSTEM:
      rgb_matrix_set_color_all(0, 0, 50);
      break;
    default:
      rgb_matrix_set_color_all(255, 255, 255);
    break;
  }

  rgb_matrix_set_color(41, 0, 0, 0); // Disable spacebar light

}
#endif
