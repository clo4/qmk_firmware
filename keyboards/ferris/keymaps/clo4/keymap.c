#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK_DH,
  _EXT,
  _SYM,
  _FN,
  _NUM,
  _RES,
};

// The defines are used to keep everything neatly aligned by columns
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_RALT OSM(MOD_RALT)
#define KC_LCTZ LCTL_T(KC_Z)
#define KC_LCTX LCTL_T(KC_X)
#define KC_LCTC LCTL_T(KC_C)
#define KC_LCTV LCTL_T(KC_V)

// This layout is based on Seniply:
// https://stevep99.github.io/seniply/
//
// Seniply is a well-designed layout that pairs extremely well with Colemak-DH.
// It was created by the same person that created Colemak-DH.

// To align by cols, type this sequence when your cursor is over the { below
// mi{sLAY<enter>j3xS,_<A-;>&
// Broken down:
// - mi{ selects inside the array
// - sLAY<ret> selects the LAYOUT macros (we don't need the entire macro, just a cursor on it)
// - j moves the cursor down into the LAYOUT parentheses
// - 3x selects 3 lines
// - S, splits by commas, so now you have a selection for each item
// - _ trims any whitespace from the selections
// - <A-;> swaps the selection head and anchor, so the alignment will happen on the left
// - & aligns the selections to columns
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT(
    KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     /**/  KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     /**/  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,     /**/  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                  MO(_EXT), KC_LSFT,  /**/  KC_SPC,  MO(_SYM)
  ),
  [_EXT] = LAYOUT(
    KC_ESC,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    /**/  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_CAPS,
    OSM_LALT, OSM_LGUI, OSM_LSFT, OSM_LCTL, OSM_RALT, /**/  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
    KC_LCTZ,  KC_LCTX,  KC_LCTC,  KC_LGUI,  KC_LCTV,  /**/  KC_ENT,  KC_BSPC, KC_TAB,  KC_APP,  KC_PSCR,
                                  KC_TRNS,  KC_NO,    /**/  KC_ENT,  MO(_FN) 
  ),
  [_SYM] = LAYOUT(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  /**/  KC_EQL,  KC_GRV,  KC_COLN, KC_SCLN, KC_PLUS,
    KC_LALT,  KC_LGUI,  KC_LSFT,  KC_LCTL,  KC_CIRC,  /**/  KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS,
    KC_NO,    KC_NO,    KC_BSLS,  KC_PIPE,  KC_AMPR,  /**/  KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS,
                                  MO(_FN),  MO(_NUM), /**/  KC_NO,   KC_TRNS
  ),
  [_FN] = LAYOUT(
    KC_MSTP,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_BRIU,  /**/  KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_NO,
    KC_LALT,  KC_LGUI,  KC_LSFT,  KC_LCTL,  KC_BRID,  /**/  KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_NO,
    KC_MUTE,  KC_VOLD,  KC_NO,    KC_VOLU,  KC_NO,    /**/  KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_NO,
                                  KC_TRNS,  KC_NO,    /**/  KC_NO,   KC_TRNS
  ),
  [_NUM] = LAYOUT(
    MO(_RES), KC_NO,    KC_NO,    KC_NO,    KC_NO,    /**/  KC_PEQL, KC_7,    KC_8,    KC_9,    KC_PPLS,
    KC_LALT,  KC_LGUI,  KC_LSFT,  KC_LCTL,  KC_RALT,  /**/  KC_PAST, KC_4,    KC_5,    KC_6,    KC_PMNS,
    KC_NO,    KC_APP,   KC_TAB,   KC_BSPC,  KC_ENT,   /**/  KC_0,    KC_1,    KC_2,    KC_3,    KC_PSLS,
                                  KC_NO,    KC_TRNS,  /**/  KC_NO,   KC_NO
  ),
  [_RES] = LAYOUT(
    KC_TRNS,  QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    /**/  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    /**/  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    /**/  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                  KC_NO,    KC_NO,    /**/  KC_NO,   KC_NO 
  ),
};
