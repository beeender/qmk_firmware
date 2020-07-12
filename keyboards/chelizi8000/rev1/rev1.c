#include "nrf.h"
#include "matrix.h"
#include "quantum.h"
#include "app_ble_func.h"
#include "nrfx_power.h"


void matrix_init_user() {
  set_usb_enabled(true);
  debug_enable = true;
}
