// Combos

enum combo_events {
  CRET,
  COMBOPP,
  COMBO_NEXT,
  COMBO_PREV,
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_ESC2,
  COMBO_DEL,
  COMBO_QUES,
  CRET2
};

const uint16_t PROGMEM cret[] = {RCTL_T(KC_E), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_pp[] = {KC_7, KC_9, COMBO_END};
const uint16_t PROGMEM combo_next[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_prev[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_Y, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {LCTL_T(KC_S), LALT_T(KC_R), COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_esc2[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_U, KC_Y, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_ques[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cret2[] = {KC_F, KC_P, COMBO_END};

combo_t key_combos[] = {
  [CRET] = COMBO(cret, KC_ENT),
  [COMBOPP] = COMBO(combo_pp, KC_MPLY),
  [COMBO_NEXT] = COMBO(combo_next,KC_MNXT),
  [COMBO_PREV] = COMBO(combo_prev,KC_MPRV),
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_GESC),
  [COMBO_ESC2] = COMBO(combo_esc2,KC_GESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  [COMBO_QUES] = COMBO(combo_ques,KC_SLSH),
  [CRET2] = COMBO(cret2,KC_ENT),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // combo index, i.e. its name from enum.
    switch (index) {
        case CRET:
            return 17;
    }

    return COMBO_TERM;

}
