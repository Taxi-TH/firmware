#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

// ขา Default พื้นฐานของ ESP32 DevKit V1
static const uint8_t TX = 1;
static const uint8_t RX = 3;

static const uint8_t TXD2 = 17;
static const uint8_t RXD2 = 16;

static const uint8_t SDA = 21;
static const uint8_t SCL = 22;

// กำหนด SPI พื้นฐาน (VSPI)
static const uint8_t SS = 5;
static const uint8_t MOSI = 23;
static const uint8_t MISO = 19;
static const uint8_t SCK = 18;

// รายการ GPIO ที่ ESP32 DevKit V1 มี
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
static const uint8_t G34 = 34; // ใช้สำหรับ Analog Buttons
static const uint8_t G35 = 35; // ใช้สำหรับ Analog Buttons
static const uint8_t G36 = 36;
static const uint8_t G39 = 39;

#define RGB_LED -1

#define BAD_TX 21
#define BAD_RX 22

// SERIAL (GPS) dedicated pins
#define SERIAL_TX 21
#define SERIAL_RX 22
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX

// ----------------------------------------------------
// ระบบปุ่มกดแบบ Analog (ใช้ร่วมกับ interface.cpp)
// ----------------------------------------------------
#define HAS_BTN 1
#define BTN_ANALOG 1
#define BTN_ADC_PIN1 34
#define BTN_ADC_PIN2 35
#define BTN_ALIAS "\"Ok\""
#define BTN_ACT LOW

#define TXLED -1
#define LED_ON HIGH
#define LED_OFF LOW

// การตั้งค่าบัส SPI
#define SPI_SCK_PIN 18
#define SPI_MISO_PIN 19
#define SPI_MOSI_PIN 23
#define SPI_SS_PIN 5

// ----------------------------------------------------
// ขาสำหรับโมดูล IR (เพิ่มกลับมาตามที่ใช้งานจริง)
// ----------------------------------------------------
#define IR_TX_PINS '{{"IR TX", 13}}'
#define IR_RX_PINS '{{"IR RX", 14}}'

#define IR_TX_PIN 13
#define IR_RX_PIN 14

// ----------------------------------------------------
// ขาสำหรับโมดูล CC1101 (RF)
// ----------------------------------------------------
#define CC1101_GDO0_PIN 22
#define CC1101_SS_PIN 27
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

// NRF24 Pins
#define NRF24_CE_PIN 16
#define NRF24_SS_PIN 17
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

#define FP 1
#define FM 1
#define FG 2

// ----------------------------------------------------
// ข้อมูลจอ ST7789
// ----------------------------------------------------
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

// ข้อมูล SD Card
#define SDCARD_CS 4
#define SDCARD_SCK 18
#define SDCARD_MISO 19
#define SDCARD_MOSI 23

#define GROVE_SDA 33
#define GROVE_SCL 26

#endif /* Pins_Arduino_h */
