#pragma once

#define GPIO(port, pin) (((port) << 5) | ((pin) & 0x1F))

#define ROW0 GPIO(0,27)
#define ROW1 GPIO(0,4)
#define ROW2 GPIO(0,6)
#define ROW3 GPIO(0,7)
#define ROW4 GPIO(0,8)
#define ROW5 GPIO(1,8)
#define ROW6 GPIO(1,9)
#define ROW7 GPIO(0,11)

#define COL0 GPIO(1,11)
#define COL1 GPIO(1,10)
#define COL2 GPIO(1,7)
#define COL3 GPIO(0,16)
#define COL4 GPIO(0,17)
#define COL5 GPIO(0,19)
#define COL6 GPIO(0,20)
#define COL7 GPIO(0,21)
#define COL8 GPIO(0,22)
#define COL9 GPIO(0,23)
#define COL10 GPIO(0,24)
#define COL11 GPIO(0,25)
#define COL12 GPIO(1,0)
#define COL13 GPIO(1,1)
#define COL14 GPIO(1,2)
#define COL15 GPIO(1,6)
#define COL16 GPIO(1,5)
#define COL17 GPIO(1,4)

#define THIS_DEVICE_ROWS MATRIX_ROWS
#define THIS_DEVICE_COLS MATRIX_COLS

// wiring of each half
#define MATRIX_ROW_PINS { ROW0, ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7 }
//#define MATRIX_ROW_PINS { ROW0, ROW0, ROW0, ROW0, ROW0, ROW0, ROW0, ROW0 }
#define MATRIX_COL_PINS { \
  COL0, COL1, COL2, COL3, COL4, COL5, COL6, COL7, COL8, COL9,\
  COL10, COL11, COL12, COL13, COL14, COL15, COL16, COL17 }
