#ifndef JD40_H
#define JD40_H

#include "quantum.h"
#include "led.h"

#define LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
	K10, K11, K12, K13, K14, K15, K16, K17, K18, K19,      K1B, \
	K20,      K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
	K30, K31, K32, K33,      K35, K36,      K38, K39, K3A, K3B \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B}, \
	{ K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, KC_NO, K1B}, \
	{ K20, KC_NO, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B}, \
	{ K30, K31, K32, K33,KC_NO,K35, K36, KC_NO, K38, K39, K3A, K3B} \
}

#endif
