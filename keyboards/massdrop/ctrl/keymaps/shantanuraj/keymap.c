#include QMK_KEYBOARD_H

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

enum {
    TD_W_CMD_W,
    TD_E_CMD_E,
    TD_R_CMD_R,
    TD_T_CMD_T,
    TD_Y_CMD_Y,
    TD_U_CMD_U,
    TD_I_CMD_I,
    TD_O_CMD_O,
    TD_P_CMD_P,
    TD_A_CMD_A,
    TD_S_CMD_S,
    TD_D_CMD_D,
    TD_F_CMD_F,
    TD_G_CMD_G,
    TD_H_CMD_H,
    TD_J_CMD_J,
    TD_K_CMD_K,
    TD_L_CMD_L,
    TD_Z_CMD_Z,
    TD_X_CMD_X,
    TD_C_CMD_C,
    TD_V_CMD_V,
    TD_B_CMD_B,
    TD_N_CMD_N,
    TD_M_CMD_M,
    TD_SPC_CMD_SPC,
    TD_TAB_CMD_TAB,
    TD_1_CMD_1,
    TD_2_CMD_2,
    TD_3_CMD_3,
    TD_4_CMD_4,
    TD_5_CMD_5,
    TD_6_CMD_6,
    TD_7_CMD_7,
    TD_8_CMD_8,
    TD_9_CMD_9,
    TD_0_CMD_0,
    TD_ENT_CMD_ENT,
    TD_BSPC_CMD_BSPC,
    TD_GRV_CMD_GRV,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_W_CMD_W]  = ACTION_TAP_DANCE_DOUBLE(KC_W, LGUI(KC_W)),
    [TD_E_CMD_E]  = ACTION_TAP_DANCE_DOUBLE(KC_E, LGUI(KC_E)),
    [TD_R_CMD_R]  = ACTION_TAP_DANCE_DOUBLE(KC_R, LGUI(KC_R)),
    [TD_T_CMD_T]  = ACTION_TAP_DANCE_DOUBLE(KC_T, LGUI(KC_T)),
    [TD_Y_CMD_Y]  = ACTION_TAP_DANCE_DOUBLE(KC_Y, LGUI(KC_Y)),
    [TD_U_CMD_U]  = ACTION_TAP_DANCE_DOUBLE(KC_U, LGUI(KC_U)),
    [TD_I_CMD_I]  = ACTION_TAP_DANCE_DOUBLE(KC_I, LGUI(KC_I)),
    [TD_O_CMD_O]  = ACTION_TAP_DANCE_DOUBLE(KC_O, LGUI(KC_O)),
    [TD_P_CMD_P]  = ACTION_TAP_DANCE_DOUBLE(KC_P, LGUI(KC_P)),
    [TD_A_CMD_A]  = ACTION_TAP_DANCE_DOUBLE(KC_A, LGUI(KC_A)),
    [TD_S_CMD_S]  = ACTION_TAP_DANCE_DOUBLE(KC_S, LGUI(KC_S)),
    [TD_D_CMD_D]  = ACTION_TAP_DANCE_DOUBLE(KC_D, LGUI(KC_D)),
    [TD_F_CMD_F]  = ACTION_TAP_DANCE_DOUBLE(KC_F, LGUI(KC_F)),
    [TD_G_CMD_G]  = ACTION_TAP_DANCE_DOUBLE(KC_G, LGUI(KC_G)),
    [TD_H_CMD_H]  = ACTION_TAP_DANCE_DOUBLE(KC_H, LGUI(KC_H)),
    [TD_J_CMD_J]  = ACTION_TAP_DANCE_DOUBLE(KC_J, LGUI(KC_J)),
    [TD_K_CMD_K]  = ACTION_TAP_DANCE_DOUBLE(KC_K, LGUI(KC_K)),
    [TD_L_CMD_L]  = ACTION_TAP_DANCE_DOUBLE(KC_L, LGUI(KC_L)),
    [TD_Z_CMD_Z]  = ACTION_TAP_DANCE_DOUBLE(KC_Z, LGUI(KC_Z)),
    [TD_X_CMD_X]  = ACTION_TAP_DANCE_DOUBLE(KC_X, LGUI(KC_X)),
    [TD_C_CMD_C]  = ACTION_TAP_DANCE_DOUBLE(KC_C, LGUI(KC_C)),
    [TD_V_CMD_V]  = ACTION_TAP_DANCE_DOUBLE(KC_V, LGUI(KC_V)),
    [TD_B_CMD_B]  = ACTION_TAP_DANCE_DOUBLE(KC_B, LGUI(KC_B)),
    [TD_N_CMD_N]  = ACTION_TAP_DANCE_DOUBLE(KC_N, LGUI(KC_N)),
    [TD_M_CMD_M]  = ACTION_TAP_DANCE_DOUBLE(KC_M, LGUI(KC_M)),
    [TD_SPC_CMD_SPC] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, LGUI(KC_SPC)),
    [TD_TAB_CMD_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, LGUI(KC_TAB)),
    [TD_1_CMD_1]  = ACTION_TAP_DANCE_DOUBLE(KC_1, LGUI(KC_1)),
    [TD_2_CMD_2]  = ACTION_TAP_DANCE_DOUBLE(KC_2, LGUI(KC_2)),
    [TD_3_CMD_3]  = ACTION_TAP_DANCE_DOUBLE(KC_3, LGUI(KC_3)),
    [TD_4_CMD_4]  = ACTION_TAP_DANCE_DOUBLE(KC_4, LGUI(KC_4)),
    [TD_5_CMD_5]  = ACTION_TAP_DANCE_DOUBLE(KC_5, LGUI(KC_5)),
    [TD_6_CMD_6]  = ACTION_TAP_DANCE_DOUBLE(KC_6, LGUI(KC_6)),
    [TD_7_CMD_7]  = ACTION_TAP_DANCE_DOUBLE(KC_7, LGUI(KC_7)),
    [TD_8_CMD_8]  = ACTION_TAP_DANCE_DOUBLE(KC_8, LGUI(KC_8)),
    [TD_9_CMD_9]  = ACTION_TAP_DANCE_DOUBLE(KC_9, LGUI(KC_9)),
    [TD_0_CMD_0]  = ACTION_TAP_DANCE_DOUBLE(KC_0, LGUI(KC_0)),
    [TD_ENT_CMD_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, LGUI(KC_ENT)),
    [TD_BSPC_CMD_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, LGUI(KC_BSPC)),
    [TD_GRV_CMD_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, LGUI(KC_GRV)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS,
        TD(TD_GRV_CMD_GRV),  TD(TD_1_CMD_1),    TD(TD_2_CMD_2),    TD(TD_3_CMD_3),    TD(TD_4_CMD_4),    TD(TD_5_CMD_5),    TD(TD_6_CMD_6),    TD(TD_7_CMD_7),    TD(TD_8_CMD_8),    TD(TD_9_CMD_9),    TD(TD_0_CMD_0),    KC_MINS, KC_EQL,  TD(TD_BSPC_CMD_BSPC),   KC_INS,  KC_HOME, KC_PGUP,
        TD(TD_TAB_CMD_TAB),  KC_Q,    TD(TD_W_CMD_W),    TD(TD_E_CMD_E),    TD(TD_R_CMD_R),    TD(TD_T_CMD_T),    TD(TD_Y_CMD_Y),    TD(TD_U_CMD_U),    TD(TD_I_CMD_I),    TD(TD_O_CMD_O),    TD(TD_P_CMD_P),    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,
        KC_ESC, TD(TD_A_CMD_A),    TD(TD_S_CMD_S),    TD(TD_D_CMD_D),    TD(TD_F_CMD_F),    TD(TD_G_CMD_G),    TD(TD_H_CMD_H),    TD(TD_J_CMD_J),    TD(TD_K_CMD_K),    TD(TD_L_CMD_L),    KC_SCLN, KC_QUOT, TD(TD_ENT_CMD_ENT),
        KC_LSFT, TD(TD_Z_CMD_Z),    TD(TD_X_CMD_X),    TD(TD_C_CMD_C),    TD(TD_V_CMD_V),    TD(TD_B_CMD_B),    TD(TD_N_CMD_N),    TD(TD_M_CMD_M),    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   TD(TD_SPC_CMD_SPC),                             KC_RALT, MO(1),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU,
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD,
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______,                              _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______
    ),
};

#define MODS_SHIFT  (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL   (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT    (get_mods() & MOD_MASK_ALT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
