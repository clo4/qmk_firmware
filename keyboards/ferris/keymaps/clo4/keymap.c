#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK_DH,
  _EXT,
  _SYM,
  _FUN,
  _NUM,
  _RES,
};

// The defines are used to keep everything neatly aligned by columns
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_RALT OSM(MOD_RALT)
#define KC_LCTZ LCTL(KC_Z)
#define KC_LCTX LCTL(KC_X)
#define KC_LCTC LCTL(KC_C)
#define KC_LCTV LCTL(KC_V)
#define KC_LCTB LCTL(KC_B)

enum custom_keycodes {
  /* Types ` = ` when pressed. This requires some hand-gymnastics without it. */
  STR_EQL = SAFE_RANGE,
};

// This layout is based on Seniply:
// https://stevep99.github.io/seniply/
//
// Seniply is a well-designed layout that pairs extremely well with Colemak-DH.
// It was created by the same person that created Colemak-DH.
//
// The only major change from the stock layout is how the layers are ordered.
// There are 4 thumb keys on the Ferris Sweep: A, B # C, D (where # is the split)
// B is shift and C is space. These never change in any layer.
// Hold A to enter EXT. Hold A->D to enter FUN.
// Hold D to enter SYM. Hold D->A to enter NUM.
//
// There is also a RES layer to type QK_BOOT. This is accessed by entering the 
// NUM layer, holding the top-right key, then tapping the key in the W position.
//
// There are other minor changes that are documented in comments above each layer.

// Styleguide:
// - Limit key names to at most 8 chars
// - Align by columns (see below)
// - Keep two spaces either side of the split comment /**/
// - Use XXXXXXX and _______ instead of the corresponding KC_*

// To align by cols, type this sequence when your cursor is over the { below
// mi{sLAY<enter>j3xS,<ret>_<A-;>&
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
  [_COLEMAK_DH] = LAYOUT(
    KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     /**/  KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     /**/  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,     /**/  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                  MO(_EXT), KC_LSFT,  /**/  KC_SPC,  MO(_SYM)
  ),
  // I've added a key for C-b to make tmux easier to use.
  // Custom: QK_REP, QK_AREP, KC_LCTB
  [_EXT] = LAYOUT(
    KC_ESC,   XXXXXXX,  QK_REP,   QK_AREP,  KC_LCTB,  /**/  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_CAPS,
    OSM_LCTL, OSM_LALT, OSM_LSFT, OSM_LGUI, OSM_RALT, /**/  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
    KC_LCTZ,  KC_LCTX,  KC_LCTC,  KC_LGUI,  KC_LCTV,  /**/  KC_ENT,  KC_BSPC, KC_TAB,  KC_APP,  KC_PSCR,
                                  _______,  XXXXXXX,  /**/  KC_ENT,  MO(_FUN) 
  ),
  // Custom: STR_EQL in bottom left, KC_SPC on left thumb
  [_SYM] = LAYOUT(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  /**/  KC_EQL,  KC_GRV,  KC_COLN, KC_SCLN, KC_PLUS,
    KC_LCTL,  KC_LALT,  KC_LSFT,  KC_LGUI,  KC_CIRC,  /**/  KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS,
    STR_EQL,  XXXXXXX,  KC_BSLS,  KC_PIPE,  KC_AMPR,  /**/  KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS,
                                  MO(_NUM), KC_SPC,   /**/  XXXXXXX, _______
  ),
  [_FUN] = LAYOUT(
    KC_MSTP,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_BRIU,  /**/  KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,
    KC_LCTL,  KC_LALT,  KC_LSFT,  KC_LGUI,  KC_BRID,  /**/  KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX,
    KC_MUTE,  KC_VOLD,  XXXXXXX,  KC_VOLU,  XXXXXXX,  /**/  KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX,
                                  _______,  XXXXXXX,  /**/  XXXXXXX, _______
  ),
  // Number pad:
  //  = 7 8 9 +
  //  * 4 5 6 -
  //  0 1 2 3 /
  // Custom: KC_DOT in bottom left
  [_NUM] = LAYOUT(
    MO(_RES), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  /**/  KC_PEQL, KC_7,    KC_8,    KC_9,    KC_PPLS,
    KC_LCTL,  KC_LALT,  KC_LSFT,  KC_LGUI,  KC_RALT,  /**/  KC_PAST, KC_4,    KC_5,    KC_6,    KC_PMNS,
    KC_DOT,   KC_APP,   KC_TAB,   KC_BSPC,  KC_ENT,   /**/  KC_0,    KC_1,    KC_2,    KC_3,    KC_PSLS,
                                  _______,  XXXXXXX,  /**/  KC_SPC,  _______
  ),
  [_RES] = LAYOUT(
    _______,  QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                  XXXXXXX,  XXXXXXX,  /**/  XXXXXXX, XXXXXXX 
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case STR_EQL:
      if (record->event.pressed) {
        SEND_STRING(" = ");
        return false;
      }
  }
  return true;
}
