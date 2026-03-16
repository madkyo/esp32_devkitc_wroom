#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

#define BUILD_STATE "bring"
#define LED_ON_OFFSEC_TEST 0

static struct gpio_callback button_cb_data;

static const struct gpio_dt_spec led =
  GPIO_DT_SPEC_GET(DT_NODELABEL(blinking_led), gpios);

static const struct gpio_dt_spec button =
  GPIO_DT_SPEC_GET(DT_NODELABEL(button), gpios);

void button_pressed(const struct device *dev,
        struct gpio_callback *cb,
        uint32_t pins)
{
  int ret;
  int state;

  state = gpio_pin_get_dt(&button);

  printk("%s: %d", __func__, state);

  if (state) {
    ret = gpio_pin_toggle_dt(&led);
    printk("toggle ok\n");
    if (ret != 0) {
      printk("Could not toggle LED\n");
    }
  } else {
    printk("end \n");
  }
}

int main(void)
{
  int ret, irq_key;

  printk("Hi %s state %s Up \n", CONFIG_SOC, BUILD_STATE);

  if (!device_is_ready(led.port)) {
    return 0;
  }

  if (!device_is_ready(button.port)) {
    return 0;
  }

  ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
  if (ret != 0) {
    return 0;
  }

  ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
  if (ret != 0) {
    return 0;
  }

  ret = gpio_pin_interrupt_configure_dt(&button,
          GPIO_INT_EDGE_BOTH);

  if (ret != 0) {
    return 0;
  }

  gpio_init_callback(&button_cb_data, button_pressed,
         BIT(button.pin));
  gpio_add_callback(button.port, &button_cb_data);

  irq_key = irq_lock();
  button_pressed(button.port, &button_cb_data, BIT(button.pin));
  irq_unlock(irq_key);

#if LED_ON_OFFSEC_TEST
  while (true) {
    ret = gpio_pin_toggle_dt(&led);
    if (ret != 0) {
      return 0;
    }
    k_msleep(1000);
    printk(" LED toggle \n");
  }
#endif

}
