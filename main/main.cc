#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

extern "C" {
  void app_main();
}

constexpr gpio_num_t led = GPIO_NUM_2;

void app_main(void)
{
  gpio_pad_select_gpio(led);
  gpio_set_direction(led, GPIO_MODE_OUTPUT);
  while (true) {
    printf("Turning off LED\n");
    gpio_set_level(led, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    printf("Turning on the LED\n");
    gpio_set_level(led, 1);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
//  std::cout << "Hello world!\n";
//
//  /* Print chip information */
//  esp_chip_info_t chip_info;
//  esp_chip_info(&chip_info);
//  printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
//          chip_info.cores,
//          (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
//          (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
//
//  printf("silicon revision %d, ", chip_info.revision);
//
//  printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
//          (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
//
//  for (int i = 10; i >= 0; i--) {
//      printf("Restarting in %d seconds...\n", i);
//      vTaskDelay(1000 / portTICK_PERIOD_MS);
//  }
//  printf("Restarting now.\n");
//  fflush(stdout);
//  esp_restart();
}
