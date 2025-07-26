#include QMK_KEYBOARD_H
extern uint8_t is_master;

#define COLEMAK 0
#define SYMBOL 1
#define NUM 2
#define FUNC 3
#define UTIL 4

#define OSL_FUN  OSL(FUNC)
#define SHIFT_TAB MT(MOD_LSFT, KC_TAB)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define NUM_L MO(NUM)
#define SYMBOL_L MO(SYMBOL)
#define UTIL_L MO(UTIL)
#define TOG_FUNC_L TT(FUNC)
#define SCRNSHT LGUI(LSFT(KC_S))
#define INSPECT LCTL(LSFT(KC_I))
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
#define MV_LFT LCTL(LSFT(LALT(KC_L)))
#define MV_RGT LCTL(LSFT(LALT(KC_R)))
#define FLLS_T LCTL(LSFT(LALT(KC_F)))
#define TGGL_T LCTL(LSFT(LALT(KC_T)))
#define QUIT LCTL(LSFT(LALT(KC_Q)))
#define CLOSE_W LCTL(LSFT(LALT(KC_W)))
#define PREV LCTL(LSFT(LALT(KC_P)))
#define EDIT_HAR LCTL(LSFT(LALT(KC_C)))
#define QP_HAR LCTL(LSFT(LALT(KC_D)))
#define HAR_1 LCTL(LSFT(LALT(KC_E)))
#define HAR_2 LCTL(LSFT(LALT(KC_G)))
#define HAR_3 LCTL(LSFT(LALT(KC_H)))
#define HAR_4 LCTL(LSFT(LALT(KC_I)))
#define ZEN_TOGG LCTL(LSFT(LALT(KC_M)))
#define FOC_EDIT LCTL(LSFT(LALT(KC_Z)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    TOG_FUNC_L,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN,  _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O     ,KC_ENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH  ,KC_LCTL,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      UTIL_L, SYMBOL_L, SHIFT_TAB,        KC_BSPC,  KC_SPC, LT(NUM_L, KC_ESC)\
                                      //`--------------------------'  `--------------------------'
  ),

  [SYMBOL] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX,KC_TILDE, KC_LBRC, KC_RBRC, KC_PERC,                     KC_EXLM,  KC_MINS, KC_UNDS, KC_AMPR, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      INSPECT,  KC_PIPE, KC_GRV, KC_DQT, KC_QUOT,  KC_PLUS,                      KC_CIRC,  KC_LPRN, KC_RPRN, KC_EQL,  KC_DLR, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, OSM_GUI, OSM_ALT, OSM_CTL, OSM_SFT, KC_HASH,                       KC_AT, KC_LCBR, KC_RCBR,  KC_PAST, KC_BSLS, _______,\
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
      XXXXXXX,  QUIT,   CLOSE_W, FLLS_T,  PREV,   TGGL_T,                       ZEN_TOGG, FOC_EDIT, EDIT_HAR, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MV_LFT,  SCR_4,  SCR_3,   SCR_2,   SCR_1,  MV_RGT,                        QP_HAR,   HAR_1,   HAR_2,    HAR_3,  HAR_4, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       SCR_6, SCR_0,   SCR_9,   SCR_8,    SCR_7, SCR_5,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          UTIL, _______, _______,       XXXXXXX, LALT(KC_S), XXXXXXX\
                                      //`--------------------------'  `--------------------------'
  )
};
