#include "stm32f103xb.h"
#include "i2c_lcd.h"
#include "adc.h"
#include <stdint.h>
#include <stdio.h>

#define BUFFER_SIZE 1
uint16_t buffer_pot[BUFFER_SIZE];


int main(void) {
    uint16_t adc_value;
    int i = 0;

    ADC1_Init();

    i2c_init();
    lcd_init();

    lcd_puts("Iniciando...");
    delay_ms(100);
    lcd_clear();
    lcd_puts("ADC value:");

    while (1) {
       adc_value = ADC1_Read();

       buffer_pot[0] = adc_value;

       char adc_string[16];
       snprintf(adc_string, sizeof(adc_string), "%4d", adc_value);

       lcd_command(0xC0);
       lcd_puts(adc_string);

       delay_ms(100);
    }
}
