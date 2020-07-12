#ifndef CUSTOM_BOARD_H
#define CUSTOM_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#if 0

//#include "nrf_gpio.h"

#define GPIO(port, pin) ((port << 6) | pin)
#define PIN1 GPIO(0,8)
#define PIN2 GPIO(0,11)
#define PIN5 GPIO(0,18)
#define PIN6 GPIO(0,16)
#define PIN7 GPIO(0,19)
#define PIN8 GPIO(0,20)
#define PIN9 GPIO(0,22)
#define PIN10 GPIO(0,23)
#define PIN11 GPIO(1,0)
#define PIN12 GPIO(1,3)

#define PIN13 GPIO(0,9)
#define PIN14 GPIO(0,10)
#define PIN15 GPIO(1,15)
#define PIN16 GPIO(1,14)
#define PIN17 GPIO(0,3)
#define PIN18 GPIO(0,30)
#define PIN19 GPIO(0,0)
#define PIN20 GPIO(0,5)
#define PIN22 GPIO(0,7)
#endif
//#define NRF_LOG_ENABLED 0
//#define NRF_LOG_BACKEND_SERIAL_USES_UART 0
//#define NRF_LOG_BACKEND_SERIAL_UART_TX_PIN 5
#define NRF_LOG_BACKEND_UART_TX_PIN 31
//#define DEBUG

// using E73 internal oscillator (if there's no external crystal soldered)
#define NRF_CLOCK_LFCLKSRC      {.source        = 0,            \
                                 .rc_ctiv       = 16,                                \
                                 .rc_temp_ctiv  = 2,                                \
                                 .xtal_accuracy = 7}

#ifdef __cplusplus
}
#endif

#endif // CUSTOM_BOARD_H
