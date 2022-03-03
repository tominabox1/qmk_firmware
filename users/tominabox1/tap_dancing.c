// Tap Dances

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'dcap' tap dance.
static td_tap_t dcaptap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void qdot_each(qk_tap_dance_state_t *state, void *user_data){
    switch (state->count) {
        case 1:
            register_code(KC_DOT);
            break;
        case 2:
            register_code(KC_SLSH);
            break;
    }
}

void qdot_reset(qk_tap_dance_state_t *state, void *user_data) {
            unregister_code(KC_DOT);
            unregister_code(KC_SLSH);
    }

void dlp_each(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code16(KC_DLR);
            break;
        case 2:
            register_code16(KC_LPRN);
            break;
        case 3:
            register_code16(KC_LBRC);
            break;
        case 4:
            register_code16(KC_LCBR);
            break;
    }
}

void dlp_reset(qk_tap_dance_state_t *state, void *user_data) {
            unregister_code16(KC_DLR);
            unregister_code16(KC_LPRN);
            unregister_code16(KC_LBRC);
            unregister_code16(KC_LCBR);

    }

void arp_each(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code16(KC_AMPR);
            break;
        case 2:
            register_code16(KC_RPRN);
            break;
        case 3:
            register_code16(KC_RBRC);
            break;
        case 4:
            register_code16(KC_RCBR);
            break;
    }
}

void arp_reset(qk_tap_dance_state_t *state, void *user_data) {
            unregister_code16(KC_AMPR);
            unregister_code16(KC_RPRN);
            unregister_code16(KC_RBRC);
            unregister_code16(KC_RCBR);
    }

void dance_reset_finish(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >=4) {
        reset_keyboard();
    }
}

void dcap_finished(qk_tap_dance_state_t *state, void *user_data) {
    dcaptap_state.state = cur_dance(state);
    switch (dcaptap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_D); break;
        case TD_SINGLE_HOLD: register_code(KC_CAPS); break;
        case TD_DOUBLE_TAP: tap_code(KC_D); tap_code(KC_D); break;
        // case TD_DOUBLE_HOLD: register_code(KC_D); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_D); tap_code(KC_D); break;
        default: tap_code(KC_D);
    }
}

void dcap_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (dcaptap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_D); break;
        case TD_SINGLE_HOLD: unregister_code(KC_CAPS); break;
        case TD_DOUBLE_TAP: unregister_code(KC_D); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_D);
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_D);
        default: unregister_code(KC_D);
    }
    dcaptap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_QUESDOT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, qdot_each, qdot_reset, 175),
    [TD_DLR_LP] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dlp_each, dlp_reset, 300),
    [TD_AMP_RP] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, arp_each, arp_reset, 300),
    [TD_RESET] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_reset_finish, NULL, 500),
    [TD_SLS_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH,KC_ENT),
    [TD_DCAP] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dcap_finished, dcap_reset, 250)
    };

/* Per key tapdance configs */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_N):
            return 215;
        case LT(_NUM_SYM, KC_SPC):
            return 250;
        case KC_NAV_ENT:
            return 200;
        case LCTL_T(KC_TAB):
            return 120;
        case LSFT_T(KC_T):
            return 200;
        case LALT_T(KC_R):
            return 300;
        case RALT_T(KC_I):
            return 285;
        case RGUI_T(KC_O):
            return 300;
        case LGUI_T(KC_A):
            return 250;
        case LCTL_T(KC_S):
            return 210;
        case RCTL_T(KC_E):
            return 250;
        case KC_FDOT:
            return 200;
        case LT(_FKEY, KC_M):
            return 200;
        case LT(_NAV, KC_Z):
            return 200;
        case LT(_NAV, KC_B):
            return 200;
        case TD(TD_SLS_ENT):
            return 200;
        case TD(TD_DCAP):
            return 200;
        default:
            return TAPPING_TERM;
    }
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
      return true;
  }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case LSFT_T(KC_T):
    // return true;
    // case LGUI_T(KC_A):
    // return true;
    // case LT(_NUM_SYM, KC_SPC):
    // return true;
    // case LCTL_T(KC_S):
    // return true;
    // case RCTL_T(KC_E):
    // return true;
    // case RGUI_T(KC_O):
    // return true;
    default:
    return false;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case RGUI_T(KC_O):
    //   return true;
    // case LGUI_T(KC_A):
    //     return true;
    // case LSFT_T(KC_T):
    //     return true;
    // case RSFT_T(KC_N):
    //     return true;
    // case RALT_T(KC_I):
    //     return true;
    default:
      return false;
  }
}
