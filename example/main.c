/**
 * @file    main.c
 * @brief   Example application demonstrating the SSD1306 OLED library on STM32F10x
 * @hardware
 *          - MCU:  STM32F103C8T6 (Blue Pill)
 *          - OLED: SSD1306 128x64 (I2C1: PB6 -> SCL, PB7 -> SDA)
 */

#include "stm32f10x.h"
#include "oled.h"
#include <stdio.h>

// delay
static void Delay_ms(uint32_t ms) {
    uint32_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 7200; j++) {
            __NOP();
        }
    }
}


static void Draw_Border(void) {
    uint8_t x, y;
    for (x = 0; x < OLED_WIDTH; x++) {
        Oled_Draw(x, 0, OLED_COLOR_WHITE);
        Oled_Draw(x, OLED_HEIGHT - 1, OLED_COLOR_WHITE);
    }
    for (y = 0; y < OLED_HEIGHT; y++) {
        Oled_Draw(0, y, OLED_COLOR_WHITE);
        Oled_Draw(OLED_WIDTH - 1, y, OLED_COLOR_WHITE);
    }
}

int main(void) {
    char buffer[24];
    uint16_t counter = 0;

    // Initialize OLED display and I2C1 peripheral 
    Oled_Init();

    // display screen
    Oled_Clear();
    Draw_Border();
    Oled_PrintString(18, 16, "STM32F10x OLED", OLED_COLOR_WHITE);
    Oled_PrintString(22, 34, "SSD1306 Driver", OLED_COLOR_WHITE);
    Oled_UpdateScreen();
    Delay_ms(2000);

    // Main loop
    while (1) {
        Oled_Clear();
        Draw_Border();

        Oled_PrintString(10, 10, "Status: RUNNING", OLED_COLOR_WHITE);
        
        /* Format counter value into a string and render to buffer */
        sprintf(buffer, "Count: %u", counter++);
        Oled_PrintString(10, 30, buffer, OLED_COLOR_WHITE);

        // transfer frame to Oled screen
        Oled_UpdateScreen();

        Delay_ms(500);
    }
}
