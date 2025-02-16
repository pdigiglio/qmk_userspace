#include QMK_KEYBOARD_H

enum dasbob_layers {
  _QWERTY,
  _LOWER, // L1
  _RAISE, // L2
  _CURS,  // L3
  _LMOD,  // L4
  _RMOD,  // L5
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* Layer base:
      *
      * ┌─────┬─────┬─────┬─────┬─────┐        ┌─────┬─────┬─────┬─────┬─────┐
      * │  Q  │  W  │  E  │  R  │  T  │        │  Y  │  U  │  I  │  O  │  P  │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │  A  │  S  │  D  │  F  │  G  │        │  H  │  J  │  K  │  L  │  :  │
      * │     │     │     │     │     │        │     │     │     │     │  ;  │
      * │ WIN │ SFT │ CTL │ ALT │     │        │     │ ALT │ CTL │ SFT │ WIN │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │  Z  │  X  │  C  │  V  │  B  │        │  N  │  M  │  <  │  >  │  ?  │
      * │     │     │     │     │     │        │     │     │  ,  │  .  │  /  │
      * └─────┴─────┴─────┴─────┴─────┘        └─────┴─────┴─────┴─────┴─────┘
      *               ┌─────┐                            ┌─────┐
      *               │ L3  ├─────┐                ┌─────┤ RAL │
      *               └─────┤ SPC ├─────┐    ┌─────┤ BSP ├─────┘
      *                     │     │ TAB │    │ ESC │     │
      *                     └─────│ L2  │    │ L1  ├─────┘
      *                           └─────┘    └─────┘
      */

    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                      KC_Y,          KC_U,         KC_I,         KC_O,         KC_P,
        LGUI_T(KC_A), LSFT_T(KC_S), LCTL_T(KC_D), LALT_T(KC_F), KC_G,                      KC_H,          LALT_T(KC_J), LCTL_T(KC_K), LSFT_T(KC_L), LGUI_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                      KC_N,          KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                    MO(3),        KC_SPC,       LT(2, KC_TAB),             LT(1, KC_ESC), KC_BSPC,      KC_RALT
    ),

     /* Layer lower:
      *
      * ┌─────┬─────┬─────┬─────┬─────┐        ┌─────┬─────┬─────┬─────┬─────┐
      * │     │     │     │     │     │        │     │  !  │  @  │  #  │  "  │
      * │  !  │  @  │  #  │  ^  │  %  │        │  "  │  1  │  2  │  3  │  '  │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │     │  _  │     │     │     │        │     │  $  │  %  │  ^  │  )  │
      * │  ~  │  -  │  *  │  $  │  &  │        │  :  │  4  │  5  │  6  │  0  │
      * │     │     │     │     │     │        │     │ ALT │ CTL │ SFT │ WIN │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │     │     │  ?  │  +  │     │        │     │  &  │  *  │  (  │  >  │
      * │ XXX │  +  │  /  │  =  │  |  │        │  _  │  7  │  8  │  9  │  .  │
      * └─────┴─────┴─────┴─────┴─────┘        └─────┴─────┴─────┴─────┴─────┘
      *               ┌─────┐                            ┌─────┐
      *               │ L4  ├─────┐                ┌─────┤ ^^^ │
      *               └─────┤ TAB ├─────┐    ┌─────┤ ^^^ ├─────┘
      *                     └─────│ ENT │    │     ├─────┘
      *                           └─────┘    └─────┘
      */

    [_LOWER] = LAYOUT_split_3x5_3(
       KC_EXLM,         KC_AT,           KC_HASH,         KC_CIRC,         KC_PERC,            KC_DQUO,    KC_1,         KC_2,         KC_3,         KC_QUOT,
       KC_TILD,         KC_MINS,         KC_ASTR,         KC_DLR,          KC_AMPR,            KC_COLN,    LALT_T(KC_4), LCTL_T(KC_5), LSFT_T(KC_6), LGUI_T(KC_0),
       XXXXXXX,         KC_PLUS,         KC_SLSH,         KC_EQL,          KC_PIPE,            KC_UNDS,    KC_7,         KC_8,         KC_9,         KC_DOT,
                                         MO(4),           KC_SPC,          KC_ENT,             KC_ENT,     KC_TRNS,      KC_TRNS
                                                                                               /* fake */
    ),

     /* Layer lmod:
      *
      * ┌─────┬─────┬─────┬─────┬─────┐        ┌─────┬─────┬─────┬─────┬─────┐
      * │ ^^^ │ ^^^ │ ^^^ │ ^^^ │ ^^^ │        │ ^^^ │ ^^^ │ ^^^ │ ^^^ │ ^^^ │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │ WIN │ SFT │ CTL │ ALT │ ^^^ │        │ ^^^ │ ^^^ │ ^^^ │ ^^^ │ ^^^ │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │ ^^^ │ ^^^ │ ^^^ │ ^^^ │ ^^^ │        │ ^^^ │ ^^^ │ ^^^ │ ^^^ │ ^^^ │
      * └─────┴─────┴─────┴─────┴─────┘        └─────┴─────┴─────┴─────┴─────┘
      *               ┌─────┐                            ┌─────┐
      *               │     ├─────┐                ┌─────┤ ^^^ │
      *               └─────┤ ^^^ ├─────┐    ┌─────┤ ^^^ ├─────┘
      *                     └─────│ ^^^ │    │     ├─────┘
      *                           └─────┘    └─────┘
      */

    [_LMOD] = LAYOUT_split_3x5_3(
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_LGUI,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                           KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

     /* Layer raise:
      *
      * ┌─────┬─────┬─────┬─────┬─────┐        ┌─────┬─────┬─────┬─────┬─────┐
      * │ F1  │ F2  │ F3  │ F4  │ F5  │        │     │  ~  │  {  │  }  │  "  │
      * │     │     │     │     │     │        │  "  │  `  │  [  │  ]  │  '  │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │ F6  │ F7  │ F8  │ F9  │ F10 │        │     │     │     │     │     │
      * │ WIN │ SFT │ CTL │ ALT │     │        │  :  │  (  │  {  │  }  │  )  │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │     │     │     │     │     │        │     │     │     │     │  ?  │
      * │ XXX │ XXX │ F11 │ F11 │ XXX │        │  _  │  \  │  <  │  >  │  /  │
      * └─────┴─────┴─────┴─────┴─────┘        └─────┴─────┴─────┴─────┴─────┘
      *               ┌─────┐                            ┌─────┐
      *               │ ^^^ ├─────┐                ┌─────┤ L5  │
      *               └─────┤ ^^^ ├─────┐    ┌─────┤ DEL ├─────┘
      *                     └─────│     │    │ ENT ├─────┘
      *                           └─────┘    └─────┘
      */

    [_RAISE] = LAYOUT_split_3x5_3(
        KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,               KC_DQUO,     KC_GRV,          KC_LBRC,         KC_RBRC,         KC_QUOT,
        LGUI_T(KC_F6), LSFT_T(KC_F7), LCTL_T(KC_F8), LALT_T(KC_F9), KC_F10,              KC_COLN,     KC_LPRN,         KC_LCBR,         KC_RCBR,         KC_RPRN,
        XXXXXXX,       XXXXXXX,       KC_F11,        KC_F12,        XXXXXXX,             KC_UNDS,     KC_BSLS,         KC_LT,           KC_GT,           KC_SLSH,
                                      KC_TRNS,       KC_TRNS,       KC_ENT,              KC_ENT,      KC_DEL,          MO(5)
                                                                    /* fake */
    ),

     /* Layer rmod:
      *
      * ┌─────┬─────┬─────┬─────┬─────┐        ┌─────┬─────┬─────┬─────┬─────┐
      * │ ^^^ │ ^^^ │ ^^^ │ ^^^ │ ^^^ │        │ ^^^ │ ^^^ │ ^^^ │ ^^^ │ ^^^ │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │ ^^^ │ ^^^ │ ^^^ │ ^^^ │ ^^^ │        │ ^^^ │ ALT │ CTL │ SFT │ WIN │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │ ^^^ │ ^^^ │ ^^^ │ ^^^ │ ^^^ │        │ ^^^ │ ^^^ │ ^^^ │ ^^^ │ ^^^ │
      * └─────┴─────┴─────┴─────┴─────┘        └─────┴─────┴─────┴─────┴─────┘
      *               ┌─────┐                            ┌─────┐
      *               │ ^^^ ├─────┐                ┌─────┤     │
      *               └─────┤ ^^^ ├─────┐    ┌─────┤ ^^^ ├─────┘
      *                     └─────│     │    │ ^^^ ├─────┘
      *                           └─────┘    └─────┘
      */

    [_RMOD] = LAYOUT_split_3x5_3(
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_LGUI,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                           KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

     /* Layer curs:
      *
      * ┌─────┬─────┬─────┬─────┬─────┐        ┌─────┬─────┬─────┬─────┬─────┐
      * │ XXX │ CWT │ INS │ XXX │ XXX │        │ XXX │ XXX │ XXX │ XXX │ XXX │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │ WIN │ SFT │ CTL │ ALT │ XXX │        │ <-  │ UP  │ DN  │  -> │ XXX │
      * ├─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┼─────┤
      * │ XXX │ XXX │ XXX │ XXX │ XXX │        │ XXX │ XXX │ XXX │ XXX │ XXX │
      * └─────┴─────┴─────┴─────┴─────┘        └─────┴─────┴─────┴─────┴─────┘
      *               ┌─────┐                            ┌─────┐
      *               │     ├─────┐                ┌─────┤ ^^^ │
      *               └─────┤ ^^^ ├─────┐    ┌─────┤ ^^^ ├─────┘
      *                     └─────│ ^^^ │    │ ENT ├─────┘
      *                           └─────┘    └─────┘
      */

    [_CURS] = LAYOUT_split_3x5_3(
        XXXXXXX,    CW_TOGG,    KC_INS,     XXXXXXX,    XXXXXXX,             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,
        KC_LGUI,    KC_LSFT,    KC_LCTL,    KC_LALT,    XXXXXXX,             KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,
                                KC_TRNS,    KC_TRNS,    KC_TRNS,             KC_ENT,     KC_TRNS,    KC_TRNS
                                /* fake */
    ),
};
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_0; }
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        static const char PROGMEM runqmk_logo[] = {0,0,0,0,152,152,152,152,152,152,24,24,24,
        152,152,24,24,24,152,152,24,24,152,152,24,24,24,152,152,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,127,127,13,13,29,63,103,64,0,63,127,96,96,96,127,63,0,0,127,127,7,12,56,
        127,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,252,134,198,198,252,120,0,0,254,254,
        60,224,224,60,254,254,0,254,254,16,24,124,230,130,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,24,24,25,25,25,25,27,24,24,25,25,24,25,25,24,25,25,24,25,25,24,24,24,24,25,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0};


        oled_write_raw_P(runqmk_logo, sizeof(runqmk_logo));

        led_t led_usb_state = host_keyboard_led_state();
        oled_set_cursor(6, 3);
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUM") : PSTR(""), false);
        oled_set_cursor(6, 2);
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
        oled_set_cursor(6, 0);
        oled_write_P(PSTR("by GroooveBob"), false);
            oled_set_cursor(6, 1);
            oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Raise\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_set_cursor(6, 1);
        oled_write_ln_P(PSTR("Undefined"), false);
    }
    } else {
        static const char PROGMEM dasbob_logo[] = {
        0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,  0,128,128,128,192,192,192,192,192,192,192,192,192,192,192,128,128,  0,  0,  0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,  0,128,128,128,128,128,192,192,192,192,192,  0,  0,  0,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,
        0,  0,126,127,255,255,255,255,255,255,255,199,247,255,255,255,255,255,255,255,255,127,252,255,255,255,255,255,255,255,255,255, 15,127,255,255,255,255,255,255,255,255,254,248,  0,126,127,255,255,255,255,255,255,255,199,247,255,255,255,255,255,255,255,255,127,126,255,255,255,255,255,255,255,255,239,239,239,239,207,223,223,223,159, 63,  0,  7, 63,255,255,255,255,255,255,255,254, 14,254,255,255,255,255,255,255,255, 63,241,252,254,255,255,255,255,255,255,255, 31,255,255,255,255,255,255,255,255,255,255,128,  0,
        0,  0,126,255,255,255,255,255,255,255,255,227,255,255,255,255,255,255,255,255,255,  0, 15, 63,127,255,255,255,255,255,255,255,248,255,255,255,255,255,255,255,255,127, 63,  7,  0,126,255,255,255,255,255,255,255,255,227,255,255,255,255,255,255,255,255,255,128,252,253,249,249,251,251,251,251,251,255,255,255,255,255,255,255,255,127, 30,  0,  0,  0,  3, 31,255,255,255,255,255,255,255,255,255,255,255,255,255,255,  7,  0, 63,255,255,255,255,255,255,255,255,255,248,255,255,255,255,255,255,255,255,255,255,255,  0,
        0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,
        };
        oled_write_raw_P(dasbob_logo, sizeof(dasbob_logo));
    }
    return false;
}
#endif

#ifdef QUICK_TAP_TERM_PER_KEY
// Holding a dual-function key after tappping it within QUICK_TAP_TERM repets
// the tap. I want to disable this for come keys; in particular <Tab>, <Ecs>, S
// and L (both of which send <Shift> when held).
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TAB:
        case KC_ESC:
        case LSFT_T(KC_S):
        case LSFT_T(KC_L):
            return 0; // Disable

        default:
            return QUICK_TAP_TERM; // Default value
    }
}
#endif
