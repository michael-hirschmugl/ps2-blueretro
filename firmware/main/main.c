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

        // Kurzes Zirpen des Buzzers
        for (int i = 0; i < 50; i++) {
            gpio_set_level(BUZZER_PIN, 1);
            esp_rom_delay_us(2);   // sehr kurze HIGH-Phase
            gpio_set_level(BUZZER_PIN, 0);
            esp_rom_delay_us(248); // Rest der Periode für etwa 4 kHz
        }

        // ADC-Werte lesen
        int val35 = adc1_get_raw(ADC1_CHANNEL_7);
        int val36 = adc1_get_raw(ADC1_CHANNEL_0);
        int val39 = adc1_get_raw(ADC1_CHANNEL_3);

        ESP_LOGI("MAIN", "ADC readings: IO35=%d, IO36=%d, IO39=%d", val35, val36, val39);

        vTaskDelay(pdMS_TO_TICKS(1000)); // 1 Sekunde warten

        // LEDs in anderem Zustand
        gpio_set_level(LED1_PIN, 0);
        gpio_set_level(LED2_PIN, 1);
        gpio_set_level(LED3_PIN, 0);

        // Wieder ein kurzes Zirpen
        for (int i = 0; i < 50; i++) {
            gpio_set_level(BUZZER_PIN, 1);
            esp_rom_delay_us(2);
            gpio_set_level(BUZZER_PIN, 0);
            esp_rom_delay_us(248);
        }

        // Erneut ADC-Werte lesen
        val35 = adc1_get_raw(ADC1_CHANNEL_7);
        val36 = adc1_get_raw(ADC1_CHANNEL_0);
        val39 = adc1_get_raw(ADC1_CHANNEL_3);

        ESP_LOGI("MAIN", "ADC readings: IO35=%d, IO36=%d, IO39=%d", val35, val36, val39);

        vTaskDelay(pdMS_TO_TICKS(1000)); // 1 Sekunde warten
    }
}
