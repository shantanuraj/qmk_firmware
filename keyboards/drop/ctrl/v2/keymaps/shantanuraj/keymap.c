// Copyright 2023 Massdrop, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum ctrl_keycodes {
    MD_BOOT = QK_KB_0,  // Restart into bootloader after hold timeout
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

// Macro to create tap dance functions for each key
#define CREATE_CMD_TAP_DANCE(name, kc) \
    static void name##_finished(tap_dance_state_t *state, void *user_data) { \
        if (state->count == 1) { \
            register_code16(kc); \
        } else if (state->count == 2) { \
            register_code(KC_LGUI); \
            register_code16(kc); \
        } \
    } \
    static void name##_reset(tap_dance_state_t *state, void *user_data) { \
        unregister_code16(kc); \
        unregister_code(KC_LGUI); \
    }

// Create all tap dance functions
CREATE_CMD_TAP_DANCE(td_w, KC_W)
CREATE_CMD_TAP_DANCE(td_e, KC_E)
CREATE_CMD_TAP_DANCE(td_r, KC_R)
CREATE_CMD_TAP_DANCE(td_t, KC_T)
CREATE_CMD_TAP_DANCE(td_y, KC_Y)
CREATE_CMD_TAP_DANCE(td_u, KC_U)
CREATE_CMD_TAP_DANCE(td_i, KC_I)
CREATE_CMD_TAP_DANCE(td_o, KC_O)
CREATE_CMD_TAP_DANCE(td_p, KC_P)
CREATE_CMD_TAP_DANCE(td_a, KC_A)
CREATE_CMD_TAP_DANCE(td_s, KC_S)
CREATE_CMD_TAP_DANCE(td_d, KC_D)
CREATE_CMD_TAP_DANCE(td_f, KC_F)
CREATE_CMD_TAP_DANCE(td_g, KC_G)
CREATE_CMD_TAP_DANCE(td_h, KC_H)
CREATE_CMD_TAP_DANCE(td_j, KC_J)
CREATE_CMD_TAP_DANCE(td_k, KC_K)
CREATE_CMD_TAP_DANCE(td_l, KC_L)
CREATE_CMD_TAP_DANCE(td_z, KC_Z)
CREATE_CMD_TAP_DANCE(td_x, KC_X)
CREATE_CMD_TAP_DANCE(td_c, KC_C)
CREATE_CMD_TAP_DANCE(td_v, KC_V)
CREATE_CMD_TAP_DANCE(td_b, KC_B)
CREATE_CMD_TAP_DANCE(td_n, KC_N)
CREATE_CMD_TAP_DANCE(td_m, KC_M)
CREATE_CMD_TAP_DANCE(td_spc, KC_SPC)
CREATE_CMD_TAP_DANCE(td_tab, KC_TAB)
CREATE_CMD_TAP_DANCE(td_1, KC_1)
CREATE_CMD_TAP_DANCE(td_2, KC_2)
CREATE_CMD_TAP_DANCE(td_3, KC_3)
CREATE_CMD_TAP_DANCE(td_4, KC_4)
CREATE_CMD_TAP_DANCE(td_5, KC_5)
CREATE_CMD_TAP_DANCE(td_6, KC_6)
CREATE_CMD_TAP_DANCE(td_7, KC_7)
CREATE_CMD_TAP_DANCE(td_8, KC_8)
CREATE_CMD_TAP_DANCE(td_9, KC_9)
CREATE_CMD_TAP_DANCE(td_0, KC_0)
CREATE_CMD_TAP_DANCE(td_ent, KC_ENT)
CREATE_CMD_TAP_DANCE(td_bspc, KC_BSPC)
CREATE_CMD_TAP_DANCE(td_grv, KC_GRV)

tap_dance_action_t tap_dance_actions[] = {
    [TD_W_CMD_W]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_w_finished, td_w_reset),
    [TD_E_CMD_E]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_e_finished, td_e_reset),
    [TD_R_CMD_R]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_r_finished, td_r_reset),
    [TD_T_CMD_T]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_t_finished, td_t_reset),
    [TD_Y_CMD_Y]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_y_finished, td_y_reset),
    [TD_U_CMD_U]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_u_finished, td_u_reset),
    [TD_I_CMD_I]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_i_finished, td_i_reset),
    [TD_O_CMD_O]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_o_finished, td_o_reset),
    [TD_P_CMD_P]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_p_finished, td_p_reset),
    [TD_A_CMD_A]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_a_finished, td_a_reset),
    [TD_S_CMD_S]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_s_finished, td_s_reset),
    [TD_D_CMD_D]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_d_finished, td_d_reset),
    [TD_F_CMD_F]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_f_finished, td_f_reset),
    [TD_G_CMD_G]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_g_finished, td_g_reset),
    [TD_H_CMD_H]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_h_finished, td_h_reset),
    [TD_J_CMD_J]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_j_finished, td_j_reset),
    [TD_K_CMD_K]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_k_finished, td_k_reset),
    [TD_L_CMD_L]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_l_finished, td_l_reset),
    [TD_Z_CMD_Z]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_z_finished, td_z_reset),
    [TD_X_CMD_X]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_x_finished, td_x_reset),
    [TD_C_CMD_C]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_c_finished, td_c_reset),
    [TD_V_CMD_V]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_v_finished, td_v_reset),
    [TD_B_CMD_B]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_b_finished, td_b_reset),
    [TD_N_CMD_N]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_n_finished, td_n_reset),
    [TD_M_CMD_M]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_m_finished, td_m_reset),
    [TD_SPC_CMD_SPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_spc_finished, td_spc_reset),
    [TD_TAB_CMD_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_tab_finished, td_tab_reset),
    [TD_1_CMD_1]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_1_finished, td_1_reset),
    [TD_2_CMD_2]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_2_finished, td_2_reset),
    [TD_3_CMD_3]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_3_finished, td_3_reset),
    [TD_4_CMD_4]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_4_finished, td_4_reset),
    [TD_5_CMD_5]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_5_finished, td_5_reset),
    [TD_6_CMD_6]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_6_finished, td_6_reset),
    [TD_7_CMD_7]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_7_finished, td_7_reset),
    [TD_8_CMD_8]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_8_finished, td_8_reset),
    [TD_9_CMD_9]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_9_finished, td_9_reset),
    [TD_0_CMD_0]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_0_finished, td_0_reset),
    [TD_ENT_CMD_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_ent_finished, td_ent_reset),
    [TD_BSPC_CMD_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_bspc_finished, td_bspc_reset),
    [TD_GRV_CMD_GRV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_grv_finished, td_grv_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SCRL, KC_PAUS,
        TD(TD_GRV_CMD_GRV),  TD(TD_1_CMD_1),    TD(TD_2_CMD_2),    TD(TD_3_CMD_3),    TD(TD_4_CMD_4),    TD(TD_5_CMD_5),    TD(TD_6_CMD_6),    TD(TD_7_CMD_7),    TD(TD_8_CMD_8),    TD(TD_9_CMD_9),    TD(TD_0_CMD_0),    KC_MINS, KC_EQL,  TD(TD_BSPC_CMD_BSPC),   KC_INS,  KC_HOME, KC_PGUP,
        TD(TD_TAB_CMD_TAB),  KC_Q,    TD(TD_W_CMD_W),    TD(TD_E_CMD_E),    TD(TD_R_CMD_R),    TD(TD_T_CMD_T),    TD(TD_Y_CMD_Y),    TD(TD_U_CMD_U),    TD(TD_I_CMD_I),    TD(TD_O_CMD_O),    TD(TD_P_CMD_P),    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,
        KC_ESC, TD(TD_A_CMD_A),    TD(TD_S_CMD_S),    TD(TD_D_CMD_D),    TD(TD_F_CMD_F),    TD(TD_G_CMD_G),    TD(TD_H_CMD_H),    TD(TD_J_CMD_J),    TD(TD_K_CMD_K),    TD(TD_L_CMD_L),    KC_SCLN, KC_QUOT, TD(TD_ENT_CMD_ENT),
        KC_LSFT, TD(TD_Z_CMD_Z),    TD(TD_X_CMD_X),    TD(TD_C_CMD_C),    TD(TD_V_CMD_V),    TD(TD_B_CMD_B),    TD(TD_N_CMD_N),    TD(TD_M_CMD_M),    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   TD(TD_SPC_CMD_SPC),                             KC_RALT, MO(1),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_tkl_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU,
        _______, RM_SPDD, RM_VALU, RM_SPDU, RM_HUEU, RM_SATU, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD,
        _______, RM_PREV, RM_VALD, RM_NEXT, RM_HUED, RM_SATD, _______, _______, _______, _______, _______, _______, _______,
        _______, RM_TOGG, _______, _______, _______, MD_BOOT, NK_TOGG, DB_TOGG, _______, _______, _______, _______,                              _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______
    ),
};

#define MODS_SHIFT  (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL   (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT    (get_mods() & MOD_MASK_ALT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RM_TOGG:
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

