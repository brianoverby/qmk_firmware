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
  NEW_SAFE_RANGE
};

/* Define mod keys */
#define GAME TG(_GAME)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define RSET RESET
