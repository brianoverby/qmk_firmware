#pragma once
#include "quantum.h"

enum userspace_layers {
  _BASE,
  _GAME,
  _LOWER,
  _RAISE,
  _FN,
  _SYSTEM
};

enum userspace_custom_keycodes {
  COMM = SAFE_RANGE,     // , | <
  DOT,                   // . | >
  SLSH,                  // / | ?
  SCLN,                  // ; | :
  QUOT,                  // ' | "
  WNTG,                  // WinKey toggle keycode
  MACTG,                 // MacOS toggle keycode
  NEW_SAFE_RANGE
};

/* Define mod keys */
#define GAME TG(_GAME)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define RSET RESET


#ifdef KEYBOARD_planck_ez
  #define LGT_TOG RGB_TOG
  #define LGT_HUI RGB_HUI // Increase hue
  #define LGT_HUD RGB_HUD // Decrease hue
  #define LGT_SAI RGB_SAI // Increase saturation
  #define LGT_SAD RGB_SAD // Decrease saturation
  #define LGT_BRI RGB_VAI // Increase value (brightness)
  #define LGT_BRD RGB_VAD // Decrease value (brightness)
  #define LGT_SPI RGB_SPI // Increase effect speed
  #define LGT_SPD RGB_SPD // Decrease effect speed
  #define LGT_MOF RGB_MOD // Cycle through modes
  #define LGT_MOR RGB_RMOD// Cycle through modes in reverse
  #define LGT_TST RGB_M_T // RGB test mode
#endif

#ifdef KEYBOARD_planck_rev6
  #define LGT_TOG XXXXXXX
  #define LGT_HUI XXXXXXX // Increase hue
  #define LGT_HUD XXXXXXX // Decrease hue
  #define LGT_SAI XXXXXXX // Increase saturation
  #define LGT_SAD XXXXXXX // Decrease saturation
  #define LGT_BRI XXXXXXX // Increase value (brightness)
  #define LGT_BRD XXXXXXX // Decrease value (brightness)
  #define LGT_SPI XXXXXXX // Increase effect speed
  #define LGT_SPD XXXXXXX // Decrease effect speed
  #define LGT_MOF XXXXXXX // Cycle through modes
  #define LGT_MOR XXXXXXX // Cycle through modes in reverse
  #define LGT_TST XXXXXXX // RGB test mode
#endif