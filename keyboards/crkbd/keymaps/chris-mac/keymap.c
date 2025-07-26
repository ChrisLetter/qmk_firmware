#include QMK_KEYBOARD_H
extern uint8_t is_master;

#define COLEMAK 0
#define SYMBOL 1
#define NUM 2
#define FUNC 3
#define UTIL 4

#define SFT_BSPC MT(MOD_LSFT, KC_BSPC)

// One shot modifiers
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)

#define NUM_L MO(NUM)
#define SYMBOL_L MO(SYMBOL)
#define UTIL_L MO(UTIL)
#define TOG_FUNC_L TT(FUNC)
#define SCRNSHT LGUI(LSFT(KC_4))
#define INSPECT LGUI(LALT(KC_I))
#define SCR_1 LSFT(LALT(KC_1))
#define SCR_2 LSFT(LALT(KC_2))
#define SCR_3 LSFT(LALT(KC_3))
#define SCR_4 LSFT(LALT(KC_4))
#define SCR_5 LSFT(LALT(KC_5))
#define SCR_6 LSFT(LALT(KC_6))
#define SCR_7 LSFT(LALT(KC_7))
#define SCR_8 LSFT(LALT(KC_8))
#define SCR_9 LSFT(LALT(KC_9))
#define SCR_0 LSFT(LALT(KC_0))
#define SCR_LEFT LSFT(LALT(KC_H))
#define SCR_RIGHT LSFT(LALT(KC_L))
#define SCR_UP LSFT(LALT(KC_E))
#define SCR_DOWN LSFT(LALT(KC_N))
#define MV_LFT LSFT(LALT(KC_S))
#define MV_RGT LSFT(LALT(KC_R))
#define MV_UP LSFT(LALT(KC_U))
#define MV_DOWN LSFT(LALT(KC_D))
#define QUIT LSFT(LALT(KC_Q))
#define CLOSE_W LSFT(LALT(KC_W))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB ,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN,  TOG_FUNC_L,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O     ,KC_ENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH  ,KC_LSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      UTIL_L, SYMBOL_L, KC_LEFT_GUI,        SFT_BSPC,  KC_SPC, LT(NUM_L, KC_ESC)\
                                      //`--------------------------'  `--------------------------'
  ),

  [SYMBOL] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX,KC_TILDE, KC_LBRC, KC_RBRC, KC_PERC,                     KC_EXLM,  KC_MINS, KC_UNDS, KC_AMPR, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      INSPECT,  KC_PIPE, KC_GRV, KC_DQT, KC_QUOT,  KC_PLUS,                      KC_CIRC,  KC_LPRN, KC_RPRN, KC_EQL,  KC_DLR, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, OSM_CTL, OSM_ALT, OSM_GUI, OSM_SFT, KC_HASH,                       KC_AT, KC_LCBR, KC_RCBR,  KC_PAST, KC_BSLS, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  SYMBOL , _______,      _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),

  [NUM] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_COMM,   KC_7,    KC_8,   KC_9,  XXXXXXX,                      XXXXXXX, KC_END,  XXXXXXX, XXXXXXX,  XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_0,    KC_4,    KC_5,   KC_6,  XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,_______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_DOT,   KC_1,    KC_2,   KC_3,  XXXXXXX,                      XXXXXXX, KC_HOME, _______,  _______, XXXXXXX,_______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______, _______,    _______,  _______, NUM \
                                      //`--------------------------'  `--------------------------'
  ),

  [FUNC] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_COMM,   KC_7,    KC_8,   KC_9,  KC_F11,                        KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_0,    KC_4,    KC_5,   KC_6,  KC_F10,                        KC_F7,    KC_F8,   KC_F9, KC_F10,  KC_F11,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_DOT,   KC_1,    KC_2,   KC_3, KC_F8,                        XXXXXXX, RGB_MOD, RGB_TOG, KC_VOLD, KC_VOLU, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        SCRNSHT,  KC_ENT, TG(FUNC),    _______,  _______, _______\
                                      //`--------------------------'  `--------------------------'
  ),

  [UTIL] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  XXXXXXX, XXXXXXX, MV_UP,  MV_DOWN, XXXXXXX,                    _______, SCR_RIGHT, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MV_LFT,  SCR_4,  SCR_3,   SCR_2,   SCR_1,  MV_RGT,                        _______, SCR_DOWN, SCR_UP , _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, SCR_9,   SCR_8,   SCR_7,    SCR_5, SCR_6,                        _______, SCR_LEFT, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          UTIL, _______, _______,       XXXXXXX, LALT(KC_S), XXXXXXX\
                                      //`--------------------------'  `--------------------------'
  )
};
