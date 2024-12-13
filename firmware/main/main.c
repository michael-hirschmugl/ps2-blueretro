#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_rom_sys.h"
#include "esp_log.h"
#include "driver/adc.h"

#define BUZZER_PIN 18
#define LED1_PIN   17
#define LED2_PIN   12
#define LED3_PIN   15
#define IO16_PIN   16
#define IO14_PIN   14
#define IO0_PIN    0

// Zuordnung der ADC-Kanäle zu den Pins:
// IO36 -> ADC1_CH0
// IO39 -> ADC1_CH3
// IO35 -> ADC1_CH7

void app_main(void)
{
    ESP_LOGI("MAIN", "app_main gestartet");

    // LEDs konfigurieren
    gpio_config_t io_conf_led = {
        .pin_bit_mask = (1ULL << LED1_PIN) | (1ULL << LED2_PIN) | (1ULL << LED3_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = 0,
        .pull_up_en = 0,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf_led);

    // Buzzer-Pin konfigurieren
    gpio_config_t io_conf_buzzer = {
        .pin_bit_mask = (1ULL << BUZZER_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = 0,
        .pull_up_en = 0,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf_buzzer);

    gpio_config_t io_conf_io16 = {
        .pin_bit_mask = (1ULL << IO16_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = 1,
        .pull_up_en = 0,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf_io16);

    gpio_set_level(IO16_PIN, 1);

    gpio_config_t io_conf_io14 = {
        .pin_bit_mask = (1ULL << IO14_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = 1,
        .pull_up_en = 0,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf_io14);

    gpio_config_t io_conf_io0 = {
        .pin_bit_mask = (1ULL << IO0_PIN),
        .mode = GPIO_MODE_INPUT,
        .pull_down_en = 0, // Kein Pull-Down
        .pull_up_en = 1,   // Optional: Pull-Up aktivieren, falls der Pin offen ist
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf_io0);

    // ADC konfigurieren (12 Bit Auflösung, 0 - 4095)
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11); // IO36
    adc1_config_channel_atten(ADC1_CHANNEL_3, ADC_ATTEN_DB_11); // IO39
    adc1_config_channel_atten(ADC1_CHANNEL_7, ADC_ATTEN_DB_11); // IO35

    while (1) {
        // LEDs an definierten Zustand setzen
        gpio_set_level(LED1_PIN, 1);
        gpio_set_level(LED2_PIN, 0);
        gpio_set_level(LED3_PIN, 1);
        gpio_set_level(IO14_PIN, 1);

        // Kurzes Zirpen des Buzzers
        //for (int i = 0; i < 50; i++) {
            //gpio_set_level(BUZZER_PIN, 1);
        //    esp_rom_delay_us(2);   // sehr kurze HIGH-Phase
            //gpio_set_level(BUZZER_PIN, 0);
            //esp_rom_delay_us(248); // Rest der Periode für etwa 4 kHz
        //}

        // ADC-Werte lesen
        int val35 = adc1_get_raw(ADC1_CHANNEL_7);
        int val36 = adc1_get_raw(ADC1_CHANNEL_0);
        int val39 = adc1_get_raw(ADC1_CHANNEL_3);

        int io0_value = gpio_get_level(IO0_PIN);

        ESP_LOGI("MAIN", "ADC readings: IO35=%d, IO36=%d, IO39=%d", val35, val36, val39);
        ESP_LOGI("MAIN", "IO0 value: %d", io0_value);

        vTaskDelay(pdMS_TO_TICKS(1000)); // 1 Sekunde warten

        // LEDs in anderem Zustand
        gpio_set_level(LED1_PIN, 0);
        gpio_set_level(LED2_PIN, 1);
        gpio_set_level(LED3_PIN, 0);
        gpio_set_level(IO14_PIN, 0);

        // Wieder ein kurzes Zirpen
        //for (int i = 0; i < 50; i++) {
            //gpio_set_level(BUZZER_PIN, 1);
        //    esp_rom_delay_us(2);
            //gpio_set_level(BUZZER_PIN, 0);
        //    esp_rom_delay_us(248);
        //}

        // Erneut ADC-Werte lesen
        val35 = adc1_get_raw(ADC1_CHANNEL_7);
        val36 = adc1_get_raw(ADC1_CHANNEL_0);
        val39 = adc1_get_raw(ADC1_CHANNEL_3);

        io0_value = gpio_get_level(IO0_PIN);

        ESP_LOGI("MAIN", "ADC readings: IO35=%d, IO36=%d, IO39=%d", val35, val36, val39);
        ESP_LOGI("MAIN", "IO0 value: %d", io0_value);

        vTaskDelay(pdMS_TO_TICKS(1000)); // 1 Sekunde warten
    }
}
