# SSD1306 OLED Display Library for STM32F10x

![Platform](https://img.shields.io/badge/platform-STM32F10x-blue.svg)
![Library](https://img.shields.io/badge/library-STM32%20SPL-orange.svg)
![Language](https://img.shields.io/badge/language-C-brightgreen.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

A lightweight C driver for **SSD1306 OLED displays (128x64)** built on top of the **STM32F10x Standard Peripheral Library (SPL)**. It communicates via hardware **I2C1** in Fast Mode (400 kHz) and uses a 1024-byte internal frame buffer for flicker-free rendering.

## Features

- Automatic initialization of `I2C1` and `GPIOB` peripherals (Open-Drain, 50 MHz).
- 1024-byte RAM frame buffer (`128x64` resolution) for fast pixel manipulation.
- Built-in 5x7 ASCII font table (printable characters `0x20` to `0x7E`).
- Automatic line wrapping for long strings.
- Zero external dependencies beyond STM32F10x SPL (`stm32f10x_i2c`, `stm32f10x_gpio`, `stm32f10x_rcc`).
