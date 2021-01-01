
// Combos
enum combo_events {
  CAPS_COMBO,
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
};

const uint16_t PROGMEM caps_combo[] = {LSFT_T(KC_T), RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM cret[] = {LT(_NUM_SYM,KC_B), LT(_NAV, KC_V), COMBO_END};
const uint16_t PROGMEM combo_pp[] = {KC_7, KC_9, COMBO_END};
// const uint16_t PROGMEM combo_pp[] = {LT(_NUM_SYM, KC_SPC), KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_next[] = {KC_8, KC_9, COMBO_END};
// const uint16_t PROGMEM combo_next[] = {LT(_NUM_SYM, KC_SPC), KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_prev[] = {KC_7, KC_8, COMBO_END};
// const uint16_t PROGMEM combo_prev[] = {LT(_NUM_SYM, KC_SPC), KC_U, KC_L, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_Y, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {LCTL_T(KC_S), LALT_T(KC_R), COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_esc2[] = {KC_Q, KC_W, COMBO_END};
// const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_U, KC_Y, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_ques[] = {KC_COMM, KC_DOT, COMBO_END};
// const uint16_t PROGMEM combo_drec1[] = {KC_X, KC_Z, COMBO_END};
// const uint16_t PROGMEM combo_ply1[] = {KC_X, KC_C, COMBO_END};
//const uint16_t PROGMEM combo_space[] = {RCTL_T(KC_E),RALT_T(KC_I), COMBO_END};

combo_t key_combos[] = {
  [CAPS_COMBO] = COMBO(caps_combo, KC_CAPS),
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
//   [COMBO_DREC1] = COMBO(combo_drec1,DM_REC1),
//   [COMBO_PLY1] = COMBO(combo_ply1,DM_PLY1)
//   [COMBO_SPACE] = COMBO(combo_space,KC_SPACE),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);
