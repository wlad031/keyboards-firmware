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

/*enum {*/
/*    TD_M_RBRC, // for russian layout, Ь->Ъ, M->]*/
/*    TD_N_LBRC, // for russian laout, Т->Х, N->[*/
/*};*/
/*tap_dance_action_t tap_dance_actions[] = {*/
/*    [TD_M_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_RBRC),*/
/*    [TD_N_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_LBRC),*/
/*};*/
/**/
/*uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {*/
/*    switch (keycode) {*/
/*        case TD(TD_N_LBRC):*/
/*        case TD(TD_M_RBRC):*/
/*            return 200;*/
/*        default:*/
/*            return TAPPING_TERM;*/
/*    }*/
/*}*/

const uint16_t PROGMEM CMB_J_K[] = { KC_J, KC_K, COMBO_END };
combo_t key_combos[] = {
    COMBO(CMB_J_K, KC_ESC),
};
/*const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);*/
/*const key_override_t **key_overrides = (const key_override_t *[]){*/
/*	&delete_key_override,*/
/*	NULL // Null terminate the array of overrides!*/
/*};*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // BASE
    [0] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,-----------------------------------------------------.
                KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        LCTL_T(KC_TAB),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|-----------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_LGUI,    MO(1),  LSFT_T(KC_SPC),                        LSFT_T(KC_ENT),   MO(2),  KC_MEH

  ),

  // NUMBERS
    [1] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,-----------------------------------------------------.
                KC_ESC,  KC_GRV,   KC_P7,   KC_P8,   KC_P9, KC_PMNS,                      KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, XXXXXXX, KC_BSPC,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        LCTL_T(KC_TAB), XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PEQL,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_SCLN, KC_QUOT,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_LALT,   KC_P0,   KC_P1,   KC_P2,   KC_P3, XXXXXXX,                      KC_COMM,  KC_DOT, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|-----------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_LGUI, _______,           KC_SPC,                        LSFT_T(KC_ENT),   MO(3),  KC_MEH
  ),

  // SPECIAL CHARACTERS
    [2] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,-----------------------------------------------------.
                KC_ESC, KC_TILD, KC_AMPR, KC_ASTR, XXXXXXX, KC_UNDS,                      KC_LCBR, KC_RCBR,   KC_LT,   KC_GT, XXXXXXX, KC_BSPC,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        LCTL_T(KC_TAB), XXXXXXX,  KC_DLR, KC_PERC, KC_CIRC, KC_PPLS,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_COLN,  KC_DQT,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_LALT, XXXXXXX, KC_EXLM,   KC_AT, KC_HASH, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUES, KC_PIPE,
  //|-----------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_LGUI,   MO(3),   LSFT_T(KC_SPC),                        LSFT_T(KC_ENT), _______,  KC_MEH
  ),

  // FUNCTION + MEDIA
    [3] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,-----------------------------------------------------.
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRIU,                      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|-----------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  //|-----------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 _______, _______,           KC_SPC,                                KC_ENT, _______, _______
  )
};
