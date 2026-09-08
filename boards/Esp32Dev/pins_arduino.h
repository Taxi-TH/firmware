#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

static const uint8_t TX = 1;
static const uint8_t RX = 3;
static const uint8_t TXD2 = 17;
static const uint8_t RXD2 = 16;
static const uint8_t SDA = 21;
static const uint8_t SCL = 22;

static const uint8_t SS = 5;
static const uint8_t MOSI = 23;
static const uint8_t MISO = 19;
static const uint8_t SCK = 18;

static const uint8_t G0 = 0;
static const uint8_t G1 = 1;
static const uint8_t G2 = 2;
static const uint8_t G3 = 3;
static const uint8_t G4 = 4;
static const uint8_t G5 = 5;
static const uint8_t G12 = 12;
static const uint8_t G13 = 13;
static const uint8_t G14 = 14;
static const uint8_t G15 = 15;
static const uint8_t G22 = 22;
static const uint8_t G27 = 27;
static const uint8_t G32 = 32;
static const uint8_t G33 = 33;
static const uint8_t G34 = 34;
static const uint8_t G35 = 35;
static const uint8_t G36 = 36;
static const uint8_t G39 = 39;

#define RGB_LED -1
#define BAD_TX 21
#define BAD_RX 22

#define SERIAL_TX 21
#define SERIAL_RX 22
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX

#define HAS_BTN 1
#define HAS_5_BUTTONS 1
#define SEL_BTN 34
#define UP_BTN 36
#define DW_BTN 35
#define R_BTN 39
#define L_BTN 13
#define BTN_ALIAS "\"Ok\""
#define BTN_ACT LOW

#define TXLED -1
#define LED_ON HIGH
#define LED_OFF LOW

#define SPI_SCK_PIN 18
#define SPI_MISO_PIN 19
#define SPI_MOSI_PIN 23
#define SPI_SS_PIN 5

#define IR_TX_PIN 22
#define IR_RX_PIN 27

#define CC1101_GDO0_PIN 22
#define CC1101_SS_PIN 27
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

#define NRF24_CE_PIN 16
#define NRF24_SS_PIN 17
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

#define FP 1
#define FM 1
#define FG 2

#define HAS_SCREEN 1
#define ROTATION 0
#define MINBRIGHT 160
#define USER_SETUP_LOADED 1
#define ST7789_DRIVER 1
#define TFT_RGB_ORDER 1
#define TFT_WIDTH 172
#define TFT_HEIGHT 320
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4
#define TFT_BL   32 
#define TFT_BACKLIGHT_ON 1
#define TOUCH_CS -1 


#define SDCARD_CS 5
#define SDCARD_SCK 18
#define SDCARD_MISO 19
#define SDCARD_MOSI 23


#endif /* Pins_Arduino_h */
