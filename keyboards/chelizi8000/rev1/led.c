#include <nrf_gpio.h>
#include <led.h>
#include <wait.h>

#define NUMS_LED_PIN NRF_GPIO_PIN_MAP(0, 13)
#define CAPS_LED_PIN NRF_GPIO_PIN_MAP(0, 14)
#define SCRO_LED_PIN NRF_GPIO_PIN_MAP(0, 15)

void led_init(void)
{
  nrf_gpio_cfg_output(NUMS_LED_PIN);
  nrf_gpio_cfg_output(CAPS_LED_PIN);
  nrf_gpio_cfg_output(SCRO_LED_PIN);
  nrf_gpio_pin_set(CAPS_LED_PIN);
  nrf_gpio_pin_set(NUMS_LED_PIN);
  nrf_gpio_pin_set(SCRO_LED_PIN);
  wait_ms(100);
  nrf_gpio_pin_clear(CAPS_LED_PIN);
  nrf_gpio_pin_clear(NUMS_LED_PIN);
  nrf_gpio_pin_clear(SCRO_LED_PIN);
}

void led_set(uint8_t usb_led)
{
	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    nrf_gpio_pin_set(NUMS_LED_PIN);
	} else {
    nrf_gpio_pin_clear(NUMS_LED_PIN);
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    nrf_gpio_pin_set(CAPS_LED_PIN);
	} else {
    nrf_gpio_pin_clear(CAPS_LED_PIN);
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
    nrf_gpio_pin_set(SCRO_LED_PIN);
	} else {
    nrf_gpio_pin_clear(SCRO_LED_PIN);
	}
}
