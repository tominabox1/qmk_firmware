/*
 * pin_assign.h
 *
 *  Created on: 2019/01/01
 *      Author: sekigon
 */

#ifndef KEYBOARDS_alpha_BLE_REV1_PIN_ASSIGN_H_
#define KEYBOARDS_alpha_BLE_REV1_PIN_ASSIGN_H_


#include "custom_board.h"


#undef B0
#undef B1
#undef B2
#undef B3
#undef B4
#undef B5
#undef B6
#undef C6
#undef D0
#undef D1
#undef D2
#undef D3
#undef D4
#undef D7
#undef E6
#undef F4
#undef F5
#undef F6
#undef F7

#define GPIO(port, pin) ((port << 6) | pin)
#define D3 GPIO(0,6)
#define D2 GPIO(0,8)

#define D1 GPIO(0,17)
#define D0 GPIO(0,20)
#define D4 GPIO(0,22)
#define C6 GPIO(0,24)
#define D7 GPIO(1,0)
#define E6 GPIO(0,11)
#define B4 GPIO(1,4)
#define B5 GPIO(1,6)
#define B6 GPIO(0,9)
#define B2 GPIO(0,10)
#define B3 GPIO(1,11)
#define B1 GPIO(1,13)
#define F7 GPIO(1,15)
#define F6 GPIO(0,2)
#define F5 GPIO(0,29)
#define F4 GPIO(3,31)

#define THIS_DEVICE_ROWS 3
#define MATRIX_ROW_PINS { D4, B4, B5  }

#define THIS_DEVICE_COLS 10
#define MATRIX_COL_PINS { D7, E6, C6, B6, B2, B3, B1, F7, F6, F5 }

#endif /* KEYBOARDS_stonehenge30_BLE_REV1_PIN_ASSIGN_H_ */
