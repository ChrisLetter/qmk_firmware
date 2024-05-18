#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE
};

#define COLEMAK 0
#define LOWER 1
#define RAISE 2
#define FUNC 3

#define OSL_FUN  OSL(FUNC)
#define GUI_CAPS  GUI_T(KC_CAPS)
#define LOW_ESC LT(LOWER, KC_ESC)
#define ALT_TAB  LT(KC_RALT, ALT_TAB)
#define OSM_SFT OSM(MOD_LSFT)
#define RAISE_L  MO(RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                     KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN  ,KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                     KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_ENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      GUI_CAPS,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                     KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,OSL_FUN,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      OSM_SFT, LOW_ESC, ALT_TAB,           KC_BSPC,  KC_SPC  , RAISE_L\
                                      //`--------------------------'  `--------------------------'
  ),

  [LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX,KC_TILDE, KC_LBRC, KC_RBRC, XXXXXXX,                     KC_EXLM,  KC_MINS, KC_UNDS, KC_AMPR, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PIPE, KC_PLUS, KC_DQT, KC_QUOT,  KC_GRV,                      KC_CIRC,  KC_LPRN, KC_RPRN, KC_EQL,  KC_RABK, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_PERC, KC_HASH, XXXXXXX,                       KC_AT, KC_LCBR, KC_RCBR,  KC_PAST, KC_BSLS, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  LOWER , _______,      _______, _______, KC_DLR \
                                      //`--------------------------'  `--------------------------'
    ),

  [RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_VOLU,   KC_7,    KC_8,   KC_9,  XXXXXXX,                      XXXXXXX, XXXXXXX,  KC_END,  XXXXXXX,  XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_0,    KC_4,    KC_5,   KC_6,  XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_VOLD,   KC_1,    KC_2,   KC_3,  XXXXXXX,                      XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX,  XXXXXXX,_______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______, _______,    _______,  _______, RAISE \
                                      //`--------------------------'  `--------------------------'
  ),

  [FUNC] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,                         KC_F7,    KC_F8,   KC_F9, KC_F10,  KC_F11,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______, _______,    _______,  _______, _______\
                                      //`--------------------------'  `--------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LT(KC_RALT, ALT_TAB):
            return TAPPING_TERM_THUMB;
      case LT(LOWER, KC_ESC):
            return TAPPING_TERM_THUMB;
      default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TAB:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
        unregister_code(KC_LALT);
      }
      return false;
    default:
      return true;
  }
}
