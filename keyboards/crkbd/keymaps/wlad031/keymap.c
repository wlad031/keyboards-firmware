/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

/*enum td_keycodes {*/
/*    TD_LGUI*/
/*};*/
/*typedef enum {*/
/*  SINGLE_TAP = 1,*/
/*  SINGLE_HOLD = 2,*/
/*  DOUBLE_TAP = 3,*/
/*  DOUBLE_HOLD = 4,*/
/*  DOUBLE_SINGLE_TAP = 5, //send two single taps*/
/*  TRIPLE_TAP = 6,*/
/*  TRIPLE_HOLD = 7*/
/*} td_state_t;*/
/*static td_state_t td_state;*/
/*int cur_dance(tap_dance_state_t *state);*/
/*void td_lgui_finished(tap_dance_state_t *state, void *user_data);*/
/*void td_lgui_reset(tap_dance_state_t *state, void *user_data);*/

#define L_BASE 0
#define L_NUM 1
/*#define L_SPEC 2*/
#define L_FUN 2

/*int cur_dance(tap_dance_state_t *state) {*/
/**/
/*  if (state->count == 1) {*/
/*         if (state->interrupted) return SINGLE_HOLD;*/
/*    else if (state->pressed)     return SINGLE_HOLD;*/
/*    else                         return SINGLE_TAP;*/
/*  }*/
/**/
/*  if (state->count == 2) {*/
/*         if (state->interrupted) return DOUBLE_HOLD;*/
/*    else if (state->pressed)     return DOUBLE_HOLD;*/
/*    else                         return DOUBLE_TAP;*/
/*  }*/
/**/
/*  if (state->count == 3) {*/
/*         if (state->interrupted) return TRIPLE_HOLD;*/
/*    else if (state->pressed)     return TRIPLE_HOLD;*/
/*    else                         return TRIPLE_TAP;*/
/*  }*/
/**/
/*  //magic number. At some point this method will expand to work for more presses*/
/*  return 8;*/
/*}*/
/**/
/*void td_lgui_finished(tap_dance_state_t *state, void *user_data) {*/
/*  td_state = cur_dance(state);*/
/*  switch (td_state) {*/
/*    case SINGLE_HOLD:*/
/*      break;*/
/*    case DOUBLE_HOLD:*/
/*      if (!layer_state_is(L_NUM)) {*/
/*        layer_on(L_NUM);*/
/*      }*/
/*      break;*/
/*    case TRIPLE_HOLD:*/
/*      if (!layer_state_is(L_SPEC)) {*/
/*        layer_on(L_SPEC);*/
/*      }*/
/*      break;*/
/*    default:*/
/*      break;*/
/*  }*/
/*  register_mods(MOD_BIT(KC_LGUI));*/
/*}*/
/**/
/*void td_lgui_reset(tap_dance_state_t *state, void *user_data) {*/
/*  switch (td_state) {*/
/*    case SINGLE_HOLD:*/
/*      break;*/
/*    case DOUBLE_HOLD:*/
/*      if (layer_state_is(L_NUM)) {*/
/*        layer_off(L_NUM);*/
/*      }*/
/*      unregister_mods(MOD_BIT(KC_LGUI));*/
/*      break;*/
/*    case TRIPLE_HOLD:*/
/*      if (layer_state_is(L_SPEC)) {*/
/*        layer_off(L_SPEC);*/
/*      }*/
/*      break;*/
/*    default:*/
/*      break;*/
/*  }*/
/*  unregister_mods(MOD_BIT(KC_LGUI));*/
/*}*/
/**/
/*//Associate our tap dance key with its functionality*/
/*tap_dance_action_t tap_dance_actions[] = {*/
/*  [TD_LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lgui_finished, td_lgui_reset)*/
/*};*/

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /*case TD(TD_LGUI):*/
        /*    return 175;*/
        /*case LCTL_T(KC_TAB):*/
        /*    return 300;*/
        case LSFT_T(KC_SPC):
            return 250;
        case LSFT_T(KC_ENT):
            return 200;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // BASE
    [L_BASE] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,-----------------------------------------------------.
                KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|-----------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_LALT,          KC_LGUI,   LSFT_T(KC_SPC),                        LSFT_T(KC_ENT),       MO(L_NUM),        MO(L_FUN)

  ),

  // NUMBERS
    [L_NUM] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,-----------------------------------------------------.
                KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                KC_TAB,  KC_GRV, XXXXXXX, KC_MINS,  KC_EQL, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_LBRC, KC_RBRC,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|-----------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_LALT,          KC_LGUI,   LSFT_T(KC_SPC),                        LSFT_T(KC_ENT),          _______,          XXXXXXX
  ),

    /*
  // SPECIAL CHARACTERS
    [L_SPEC] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,-----------------------------------------------------.
                KC_ESC, KC_TILD, KC_AMPR, KC_ASTR, XXXXXXX, KC_UNDS,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSPC,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                KC_TAB, XXXXXXX,  KC_DLR, KC_PERC, KC_CIRC, KC_PPLS,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_LCTL, XXXXXXX, KC_EXLM,   KC_AT, KC_HASH, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-----------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                      MO(L_FUN),          KC_LGUI,   LSFT_T(KC_SPC),                        LSFT_T(KC_ENT),          XXXXXXX,          _______
  ),
    */

  // FUNCTION + MEDIA
    [L_FUN] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,-----------------------------------------------------.
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRIU,                      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  //|-----------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_LALT,          KC_LGUI,   LSFT_T(KC_SPC),                        LSFT_T(KC_ENT),          XXXXXXX,          _______
  )
};

