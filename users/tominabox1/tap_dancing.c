// Tap Dances

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

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_QUESDOT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, qdot_each, qdot_reset, 175),
    [TD_DLR_LP] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dlp_each, dlp_reset, 300),
    [TD_AMP_RP] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, arp_each, arp_reset, 300),
    [TD_RESET] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_reset_finish, NULL, 500),
    [TD_SLS_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH,KC_ENT)
    };

/* Per key tapdance configs */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_N):
            return 200;
        case LT(_NUM_SYM, KC_SPC):
            return 250;
        case KC_NAV_ENT:
            return 200;
        case LCTL_T(KC_TAB):
            return 120;
        case LSFT_T(KC_T):
            return 180;
        case LALT_T(KC_R):
            return 300;
        case RALT_T(KC_I):
            return 285;
        case RGUI_T(KC_O):
            return 250;
        case LGUI_T(KC_A):
            return 250;
        case LCTL_T(KC_S):
            return 175;
        case RCTL_T(KC_E):
            return 250;
        case KC_FDOT:
            return 200;
        case LT(_FKEY, KC_M):
            return 200;
        case LT(_NAV, KC_V):
            return 200;
        case LT(_NAV, KC_B):
            return 200;
        case TD(TD_SLS_ENT):
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
