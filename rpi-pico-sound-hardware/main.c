#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define SENSOR_PIN 26  // GP26 (ADC0)

int main() {
    stdio_init_all();
    adc_init();
    adc_gpio_init(SENSOR_PIN);
    adc_select_input(0);  // Use ADC0

    while(true) {
        // Read ADC value
        uint16_t raw = adc_read();
        
        // Convert to 16-bit value
        uint16_t output = raw << 4;
        
        // Send raw binary data
        putchar_raw(output & 0xFF);
        putchar_raw(output >> 8);
        
        sleep_ms(10);  // 100Hz sample rate
    }
}