#include "keymap_danish.h"
#include "brianoverby.h"

// For Win key and game mode toggle
bool winkey_enabled = true;
bool gamemode_enabled = false;
bool mac_layout = false;

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

// Send keycodes matching the legend on the keycaps (US keycaps, Danish keyboard layout in OS)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case COMM:    // , | <
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          if(mac_layout) {
            unregister_code16(KC_LSFT);  // Remove shift before sending the keycode
            register_code16(KC_GRV);     // This is < on Danish Mac keyboard
            register_code16(KC_LSFT);
          } else {
            unregister_code16(KC_LSFT);  // Remove shift before sending the keycode
            register_code16(DK_LABK);
            register_code16(KC_LSFT);
          }            
        } else {
          register_code16(KC_COMM);
        }
      } else {
        unregister_code16(KC_GRV);
        unregister_code16(DK_LABK);
        unregister_code16(KC_COMM);
      }
      return false;
      break;

    case DOT:    // . | >
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          if(mac_layout) {
            register_code16(KC_GRV);
          } else {
            register_code16(DK_RABK);
          }
        } else {
          register_code16(KC_DOT);
        }
      } else {
        unregister_code16(KC_GRV);
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
    
    case WNTG:
      if (record->event.pressed) { // Toggle Windows Key
        winkey_enabled = !winkey_enabled;
      }
      return false;
      break;
    
    case KC_LGUI: // Check if Windows Key is disabled 
      if (!winkey_enabled) {
        return false;
      } else {
        return true;
      }
      break;
    
    case GAME:
      if (record->event.pressed) { // Toggle game mode
        gamemode_enabled = !gamemode_enabled;
      }
      return false;
      break;
    
    case MACTG:
      if (record->event.pressed) { // Toggle Windows / Mac layout
        mac_layout = !mac_layout;
      }
      return false;
      break;
    
    case DK_TILD: // Send TAB, when game mode is enabled else send ~ or `
    case DK_GRV:
      if(gamemode_enabled) {
        if (record->event.pressed) {
          register_code(KC_TAB);
        } else {
          unregister_code(KC_TAB);
        }
        return false;
      } else {
        return true;
      }
      break;

    case DK_AT:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LALT(KC_NUHS));
        } else {
          unregister_code16(LALT(KC_NUHS));
        }
        return false;
      } else {
        return true;
      }
      break;
    
    case DK_DLR:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LSFT(LALT(KC_3)));
        } else {
          unregister_code16(LSFT(LALT(KC_3)));
        }
        return false;
      } else {
        return true;
      }
      break;
    
    case DK_BSLS:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LSFT(LALT(KC_7)));
        } else {
          unregister_code16(LSFT(LALT(KC_7)));
        }
        return false;
      } else {
        return true;
      }
      break;

    case DK_PIPE:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LALT(DK_I));
        } else {
          unregister_code16(LALT(DK_I));
        }
        return false;
      } else {
        return true;
      }
      break;

    case DK_LCBR:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LSFT(LALT(KC_8)));
        } else {
          unregister_code16(LSFT(LALT(KC_8)));
        }
        return false;
      } else {
        return true;
      }
      break;

    case DK_RCBR:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LSFT(LALT(KC_9)));
        } else {
          unregister_code16(LSFT(LALT(KC_9)));
        }
        return false;
      } else {
        return true;
      }
      break;

  }
  return process_record_keymap(keycode, record);
};


#ifdef RGB_CUSTOM_MODE
// This code is only active if I set RGB_CUSTOM_MODE in my user/config.h

/* |----+----+----+----+----+----+----+----+----+----+----+----|
 * |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 |
 * |----+----+----+----+----+----+----+----+----+----+----+----|
 * | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 |
 * |----+----+----+----+----+----+----+----+----+----+----+----|
 * | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 33 | 34 | 35 |
 * |----+----+----+----+----+----+----+----+----+----+----+----|
 * | 36 | 37 | 38 | 39 | 40 |   41    | 42 | 43 | 44 | 45 | 46 |
 * |----+----+----+----+----+----+----+----+----+----+----+----|
 */

int arrNum[] = {0,1,2,3,4,5,6,7,8,9,10,13,14,15,25,23,26,27,38};
int arrGame[] = {0,37,38,39};
int arrNavMedia[] = {34,44,45,46};
int arrSymLower[] = {0,1,2,3,4,5,6,7,8,9,10,19,20,21,22,23,31,32,33,34,43,44};
int arrFkeys[] = {1,2,3,4,13,14,15,16,25,26,27,28,8,10};
int arrDel[] = {12,35};
int arrDKChar[] = {11,22,23};


int arrNumSize = *(&arrNum + 1) - arrNum;
int arrNavMediaSize = *(&arrNavMedia + 1) - arrNavMedia;
int arrSymLowerSize = *(&arrSymLower + 1) - arrSymLower;
int arrFkeysSize = *(&arrFkeys + 1) - arrFkeys;
int arrDelSize = *(&arrDel + 1) - arrDel;
int arrDKCharSize = *(&arrDKChar + 1) - arrDKChar;
int arrGameSize = *(&arrGame + 1) - arrGame;

void set_color_matrix(int *numbers, int arrSize, int r_val, int g_val, int b_val)
{
  for(int i = 0; i < arrSize; i++)
  {
    rgb_matrix_set_color(numbers[i],r_val,g_val,b_val);
  }
}


void rgb_matrix_indicators_user() {

    // Set different colors based on active layer
    switch (biton32(layer_state)) {
      case _BASE:
        rgb_matrix_set_color_all(255, 255, 255);
        rgb_matrix_set_color(37, 0, 255, 0); // Fn
        break;
      case _GAME:
        rgb_matrix_set_color_all(255, 255, 255);
        set_color_matrix(arrGame,arrGameSize, 255, 0, 255);
        break;
      case _LOWER:
        rgb_matrix_set_color_all(255, 255, 255);
        set_color_matrix(arrSymLower,arrSymLowerSize, 30, 144, 255);
        rgb_matrix_set_color(37, 0, 255, 0); // Fn
        break;
      case _RAISE:
        rgb_matrix_set_color_all(255, 255, 255);
        set_color_matrix(arrNum,arrNumSize, 255, 69, 0);
        set_color_matrix(arrNavMedia,arrNavMediaSize, 255, 69, 0);
        rgb_matrix_set_color(37, 0, 255, 0); // Fn
        break;
      case _FN:
        rgb_matrix_set_color_all(255, 255, 255);
        set_color_matrix(arrFkeys,arrFkeysSize, 0, 255, 0);
        set_color_matrix(arrNavMedia,arrNavMediaSize, 0, 255, 0);
        set_color_matrix(arrDel,arrDelSize, 255, 0, 0);
        set_color_matrix(arrDKChar,arrDKCharSize, 255, 255, 0);
        rgb_matrix_set_color(37, 0, 255, 0); // Fn
        break;
      case _SYSTEM:
        rgb_matrix_set_color_all(255, 255, 255);
        rgb_matrix_set_color(17, 255, 0, 255); // Game layer toggle
        rgb_matrix_set_color(2, 255, 0, 0); // Win key toggle
        rgb_matrix_set_color(4, 255, 0, 0); // Reset key

        break;
      default:
        rgb_matrix_set_color_all(255, 255, 255);
      break;
    }
    rgb_matrix_set_color(40, 30, 144, 255); //Lower
    rgb_matrix_set_color(42, 255, 69, 0); //Raise

}
#endif
