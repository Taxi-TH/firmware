#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

// ==========================================
// 1. BASE ESP32 HARDWARE PINS
// ==========================================
static const uint8_t TX = 1;
static const uint8_t RX = 3;


static const uint8_t SDA = GROVE_SDA;
static const uint8_t SCL = GROVE_SCL;

#define GROVE_SDA 27
#define GROVE_SCL 22

// Main SPI Bus (Shared: TFT, SD, NRF24, CC1101)
#define SPI_SCK_PIN 18
#define SPI_MISO_PIN 19
#define SPI_MOSI_PIN 23
#define SPI_SS_PIN 5

static const uint8_t SS = SPI_SS_PIN;
static const uint8_t MOSI = SPI_MOSI_PIN;
static const uint8_t MISO = SPI_MISO_PIN;
static const uint8_t SCK = SPI_SCK_PIN;

// Analog Inputs
static const uint8_t A0 = 36;
static const uint8_t A3 = 39;
static const uint8_t A4 = 32;
static const uint8_t A5 = 33;
static const uint8_t A6 = 34;
static const uint8_t A7 = 35;
static const uint8_t A10 = 4;
static const uint8_t A11 = 0;
static const uint8_t A12 = 2;
static const uint8_t A13 = 15;
static const uint8_t A14 = 13;
static const uint8_t A15 = 12;

static const uint8_t DAC1 = 25;
static const uint8_t DAC2 = 26;

// ==========================================
// 2. SERIAL / BADUART CONFIGURATION
// ==========================================
#define BAD_TX=GROVE_SDA
#define BAD_RX=GROVE_SCL
#define SERIAL_TX 3
#define SERIAL_RX 1
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX

#define RGB_LED -1
#define TXLED -1
#define LED_ON HIGH
#define LED_OFF LOW

// ==========================================
// 3. BUTTONS CONFIGURATION (YOUR 5 BUTTONS)
// ==========================================
#define HAS_BTN 1
#define HAS_5_BUTTONS 1
#define SEL_BTN 34
#define UP_BTN 36
#define DW_BTN 35
#define R_BTN 39
#define L_BTN 13
#define BTN_ALIAS "\"Ok\""
#define BTN_ACT LOW

// ==========================================
// 4. INFRARED (IR) PINS
// ==========================================
#define IR_TX_PIN '{{"Pin 22", 22}, {"Pin 27", 27}}'
#define IR_RX_PIN '{{"Pin 22", 22}, {"Pin 27", 27}}'

// ==========================================
// 5. SUB-GHZ CC1101 (FIXED TO PIN 22 & 27)
// ==========================================
#define USE_CC1101_VIA_SPI
#define CC1101_GDO0_PIN 22
#define CC1101_SS_PIN 27
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

// ==========================================
// 6. NRF24L01 (SPI SHARED)
// ==========================================
#define USE_NRF24_VIA_SPI
#define NRF24_CE_PIN 16
#define NRF24_SS_PIN 4
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

#define FP 1
#define FM 2
#define FG 3

// ==========================================
// 7. TFT ST7789 1.47" DISPLAY (172x320)
// ==========================================
#define USER_SETUP_LOADED 
#define ST7789_DRIVER 
#define CGRAM_OFFSET
#define TFT_WIDTH 172
#define TFT_HEIGHT 320
#define TFT_MOSI SPI_MOSI_PIN           // 23
#define TFT_SCLK SPI_SCK_PIN           // 18
#define TFT_CS 15
#define TFT_DC 2
#define TFT_RST -1
#define TFT_BL 32                     //  Display backlight control pin
#define TFT_BACKLIGHT_ON HIGH 
#define SMOOTH_FONT 1
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 6000000

#define HAS_SCREEN
#define ROTATION 3
#define MINBRIGHT (uint8_t)1


// ==========================================
// 8. SD CARD CONFIGURATION (SPI SHARED)
// ==========================================
#define SDCARD_CS 5
#define SDCARD_SCK SPI_SCK_PIN
#define SDCARD_MISO SPI_MISO_PIN
#define SDCARD_MOSI SPI_MOSI_PIN

#endif /* Pins_Arduino_h */
