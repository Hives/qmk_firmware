#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    NAV, // navigation
    NUM, // numbers
    FUNC, // function
    SYMB, // symbols
    /* MDIA,  // media keys */
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    | Esc  | Alt  | Shift| Ctrl | Win  | LEFT |           | RIGHT| Win  | Ctrl | Shift|  Alt | Win  | Bksc   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  | Tab  |           | Bksp |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Esc/Ctl |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |Enter | Ctl    |
 * |--------+------+------+------+------+------| Esc  |           | Enter|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Alt  | Func |                                       | Shift| Ctl  |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Nav  | Num  |------|       |------|  Symb  |Space |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,          KC_ESC,      KC_LALT,       KC_LSHIFT, KC_LCTL, KC_LGUI, KC_LEFT,      KC_RGHT,  KC_RGUI,   KC_LCTL,  KC_RSHIFT, KC_LALT, KC_RGUI,  KC_BSPC,
  KC_DEL,          KC_Q,        KC_W,          KC_E,      KC_R,    KC_T,    KC_TAB,       KC_BSPC,  KC_Y,      KC_U,     KC_I,      KC_O,    KC_P,     KC_BSLS,
  LCTL_T(KC_ESC),  KC_A,        KC_S,          KC_D,      KC_F,    KC_G,                            KC_H,      KC_J,     KC_K,      KC_L,    KC_ENT,   KC_RCTL,
  KC_LSFT,         CTL_T(KC_Z), KC_X,          KC_C,      KC_V,    KC_B,    KC_ESC,       KC_ENTER, KC_N,      KC_M,     KC_COMM,   KC_DOT,  KC_SLASH, KC_RSFT,
  LT(SYMB,KC_GRV), KC_QUOT,     LALT(KC_LSFT), KC_LALT,   MO(FUNC),                                 KC_RSHIFT, KC_RCTRL, KC_LBRC,   KC_RBRC, TT(SYMB),
                                                             ALT_T(KC_APP), KC_LGUI,      KC_LALT,  CTL_T(KC_ESC),
                                                                            KC_HOME,      KC_PGUP,
                                                          MO(NAV), MO(NUM), KC_END,       KC_PGDN,  MO(SYMB), KC_SPACE
),
/* Keymap 1: Navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Enter| STab | Tab  | Esc  | Del  |      |           |      | Stab | PgUp |  Up  | PgDn |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Alt  | Shift| Ctrl | Win  |------|           |------| Bksc | Left | Down |Right |Enter |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | Tab  | Home | Del  | End  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAV] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS, KC_ENTER, LSFT(KC_TAB), KC_TAB,    KC_ESC,  KC_DEL,  KC_TRNS,     KC_TRNS, LSFT(KC_TAB), KC_PGUP, KC_UP,   KC_PGDN,  KC_TRNS,  KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_LALT,      KC_LSHIFT, KC_LCTL, KC_LGUI,                       KC_BSPC,      KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENTER, KC_MPLY,
  KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TAB,       KC_HOME, KC_DEL,  KC_END,   KC_TRNS,  KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_TRNS,      KC_BTN1,   KC_BTN2,                                              KC_VOLU, KC_VOLD, KC_MUTE,  KC_TRNS,  KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  !   | STab | Tab  |  =   | Del  |      |           |      |   -  |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Alt  | Shift| Ctrl | Win  |------|           |------| Bksc |   4  |   5  |   6  |Enter |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  (   |  <   |  %   |  >   |  )   |      |           |      |   +  |   1  |   2  |   3  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   .  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUM] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,   KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,
  KC_TRNS, KC_EXLM, LSFT(KC_TAB), KC_TAB,    KC_KP_EQUAL, KC_DEL,  KC_TRNS,     KC_TRNS, KC_KP_MINUS, KC_7,    KC_8,    KC_9,    KC_KP_ASTERISK, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_LALT,      KC_LSHIFT, KC_LCTL,     KC_LGUI,                       KC_BSPC,     KC_4,    KC_5,    KC_6,    KC_KP_ENTER,    KC_TRNS,
  KC_TRNS, KC_LPRN, KC_LABK,      KC_PERC,   KC_RABK,     KC_RPRN, KC_TRNS,     KC_TRNS, KC_KP_PLUS,  KC_1,    KC_2,    KC_3,    KC_KP_SLASH,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,   KC_TRNS,                                                 KC_0,    KC_DOT,  KC_TRNS, KC_TRNS, KC_TRNS,

                                                          KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,     KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Function
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |  F10 |  F11 |  F12 |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  F7  |  F8  |  F9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Alt  | Shift| Ctl  | Win  |------|           |------| Ins  |  F4  |  F5  |  F6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  F1  |  F2  |  F3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FUNC] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_F10,  KC_F11,  KC_F11,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_LALT, KC_LSHIFT, KC_LCTL, KC_LGUI,                       KC_BSPC, KC_F4,   KC_F5,   KC_F6,   KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: Symbols
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   ;  |   -  |   "  |   +  |   |  |      |           |      |   {  |   [  |   (  |   <  |   /  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   :  |   _  |   '  |   =  |   &  |------|           |------|   }  |   ]  |   )  |   >  |   \  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   !  |   ?  |   @  |   ^  |   *  |      |           |      |   #  |   $  |   %  |   ~  |   `  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_SCLN, KC_MINS, KC_DQT,  KC_PLUS, S(KC_PIPE), KC_TRNS,     KC_TRNS, KC_LCBR, KC_LBRC, KC_LPRN, KC_LT,   KC_SLSH, KC_TRNS,
  KC_TRNS, KC_COLN, KC_UNDS, KC_QUOT, KC_EQL,  KC_AMPR,                          KC_RCBR, KC_RBRC, KC_RPRN, KC_GT,   KC_BSLS, KC_TRNS,
  KC_TRNS, KC_EXLM, KC_QUES, KC_AT,   KC_CIRC, KC_ASTR,    KC_TRNS,     KC_TRNS, KC_HASH, KC_DLR,  KC_PERC, KC_TILD, KC_GRV,  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,
                                                           KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap X: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/* [MDIA] = LAYOUT_ergodox_pretty( */
/*   // left hand */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*   KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,                                         KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, */

/*                                                KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, */
/*                                                         KC_TRNS,     KC_TRNS, */
/*                                       KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_WBAK */
/* ), */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
