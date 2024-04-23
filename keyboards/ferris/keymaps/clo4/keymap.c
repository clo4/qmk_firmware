#include "action_util.h"
#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _RST,
};

const uint16_t PROGMEM combo_scln[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_mins[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_coln[] = {KC_H, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_scln, KC_SCLN),
    COMBO(combo_mins, KC_MINS),
    COMBO(combo_coln, KC_COLN),
};

#define G_SPC LGUI(KC_SPC)
#define S_G_SPC LSFT(LGUI(KC_SPC))
#define S_C_TAB LSFT(LCTL(KC_TAB))
#define C_TAB LCTL(KC_TAB)
#define A_BSPC LALT(KC_BSPC)
#define MO_RST MO(_RST)

// To align by cols, type this sequence when your cursor is over the { below
// mi{sLAY<ret>j3xS,<ret>_<A-;>&
// Broken down:
// - mi{ selects inside the array
// - sLAY<ret> selects the LAYOUT macros (we don't need the entire macro, just a cursor on it)
// - j moves the cursor down into the LAYOUT parentheses
// - 3x selects 3 lines
// - S,<ret> splits by commas, so now you have a selection for each item
// - _ trims any whitespace from the selections
// - <A-;> swaps the selection head and anchor, so the alignment will happen on the left
// - & aligns the selections to columns
// You must align the thumb row manually.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,     /**/  KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,     /**/  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,     /**/  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                               TL_LOWR, KC_SPC,   /**/  KC_LSFT, TL_UPPR
  ),
  [_LOWER] = LAYOUT(
    KC_ESC,  S_G_SPC, S_C_TAB, C_TAB,   XXXXXXX,  /**/  XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_CAPS,
    KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, G_SPC,    /**/  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
    MO_RST,  XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX,  /**/  XXXXXXX, KC_BSPC, A_BSPC,  KC_TAB,  KC_DEL,
                               _______, _______,  /**/  _______, _______
  ),
  [_RAISE] = LAYOUT(
    KC_GRV,  KC_LBRC, KC_RBRC, KC_TILD, KC_PERC,  /**/  KC_ASTR, KC_HASH, KC_LABK, KC_RABK, KC_DQUO,
    KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_AMPR,  /**/  KC_DLR,  KC_RGUI, KC_RCTL, KC_RALT, KC_RSFT,
    KC_SCLN, KC_BSLS, KC_EQL,  KC_MINS, KC_PLUS,  /**/  KC_CIRC, KC_PIPE, KC_UNDS, KC_AT,   KC_EXLM,
                               _______, _______,  /**/  _______, _______
  ),
  [_ADJUST] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    /**/  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     /**/  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, KC_F11,   /**/  KC_F12,  KC_RGUI, KC_RCTL, KC_RALT, KC_RSFT,
                               _______, _______,  /**/  _______, _______
  ),
  [_RST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX,  /**/  XXXXXXX, XXXXXXX
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Disables shift after 1 keypress for better rolling
  if (record->event.pressed) {
    if (get_mods() & MOD_MASK_SHIFT) {
      // Doesn't send a report immediately, so shift is only unregistered
      // for the next keypress
      del_mods(MOD_MASK_SHIFT);
    }
  }
  return true;
}
