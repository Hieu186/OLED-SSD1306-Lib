/* 
@file oled.h
*/

#ifndef _OLED_H_
#define _OLED_H_

#include "stm32f10x.h"

// 
#define OLED_I2C_ADDR         0x78 
#define OLED_WIDTH            128
#define OLED_HEIGHT           64

// color
#define OLED_COLOR_BLACK         0x00
#define OLED_COLOR_WHITE         0x01

void Oled_Init(void);
void Oled_UpdateScreen(void);
void Oled_Clear(void);
void Oled_Draw(uint8_t x, uint8_t y, uint8_t color);
void Oled_PrintString(uint8_t x, uint8_t y, char *str, uint8_t color);
void Oled_PrintChar(uint8_t x, uint8_t y, char c, uint8_t color);

#endif

