#include "core/bus_HAL.h"
#include "core/powerSave.h"
#include "core/utils.h"
#include <Arduino.h>
#include <interface.h>

/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the device
***************************************************************************************/
void _setup_gpio() {
    // เรียกฟังก์ชั่นตั้งค่าโหมดขา Analog ของปุ่มกด
    setupInterface();
    bruceConfig.colorInverted = 0;
}

/***************************************************************************************
** Function name: _post_setup_gpio()
** Location: main.cpp
** Description:   second stage gpio setup to make a few functions work
***************************************************************************************/
void _post_setup_gpio() {
    // 1. ตั้งค่าแสงสว่างหน้าจอ
    pinMode(TFT_BL, OUTPUT);
    ledcAttach(TFT_BL, TFT_BRIGHT_FREQ, TFT_BRIGHT_Bits);
    ledcWrite(TFT_BL, 255);

#ifdef TFT_INVERSION_ON
    bruceConfig.colorInverted = 0;
    tft.invertDisplay(0);
#else
    bruceConfig.colorInverted = 1;
    tft.invertDisplay(1);
#endif

    // 2. ตั้งค่าขา GPS และ RF/IR พื้นฐาน
    bruceConfigPins.gps_bus.rx = (gpio_num_t)GPS_SERIAL_RX;
    bruceConfigPins.gps_bus.tx = (gpio_num_t)GPS_SERIAL_TX;
    bruceConfigPins.gpsBaudrate = 9600;

    bool pinsChanged = false;
    if (bruceConfigPins.rfTx != 22) { bruceConfigPins.rfTx = 22; pinsChanged = true; }
    if (bruceConfigPins.rfRx != 22) { bruceConfigPins.rfRx = 22; pinsChanged = true; }
    if (bruceConfigPins.irTx != 13) { bruceConfigPins.irTx = 13; pinsChanged = true; }
    if (bruceConfigPins.irRx != 14) { bruceConfigPins.irRx = 14; pinsChanged = true; }
    if (pinsChanged) bruceConfigPins.saveFile();
}

/***************************************************************************************
** Function name: getBattery()
** location: display.cpp
** Description:   Delivers the battery value from 1-100
***************************************************************************************/
int getBattery() { 
    // หากยังไม่มีวงจรเช็คแบตเตอรี่ ให้คืนค่า 100 ไปก่อน เพื่อไม่ให้ไอคอนแจ้งเตือนแบตหมด
    return 100; 
}

/*********************************************************************
** Function: setBrightness
** location: settings.cpp
** set brightness value
**********************************************************************/
void _setBrightness(uint8_t brightval) {
    int dutyCycle;
    if (brightval == 100) dutyCycle = 255;
    else if (brightval == 75) dutyCycle = 130;
    else if (brightval == 50) dutyCycle = 70;
    else if (brightval == 25) dutyCycle = 20;
    else if (brightval == 0) dutyCycle = 0;
    else dutyCycle = ((brightval * 255) / 100);

    ledcWrite(TFT_BL, dutyCycle);
}

/*********************************************************************
** Function: InputHandler
** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
    checkPowerSaveTime();
    
    // รีเซ็ตสถานะปุ่มกดทั้งหมด
    PrevPress = false;
    NextPress = false;
    SelPress = false;
    AnyKeyPress = false;
    EscPress = false;
    UpPress = false;
    DownPress = false;
    NextPagePress = false;
    PrevPagePress = false;

    // อ่านค่าปุ่มกดปัจจุบัน
    ButtonCode btn = getPressedButton();

    // เงื่อนไข: ถ้ามีการกดปุ่มใดๆ (รวมทุกปุ่ม)
    if (btn != BTN_NONE) {
        if (!wakeUpScreen()) AnyKeyPress = true;
        else goto END;
    }

    // แมปปุ่มที่กดเข้ากับตัวแปรควบคุม
    if (btn == KEY_UP || btn == KEY_LEFT) { 
        PrevPress = true; 
        if (btn == KEY_UP) UpPress = true;
        if (btn == KEY_LEFT) PrevPagePress = true;
    }
    if (btn == KEY_DOWN || btn == KEY_RIGHT) { 
        NextPress = true; 
        if (btn == KEY_DOWN) DownPress = true;
        if (btn == KEY_RIGHT) NextPagePress = true;
    }
    if (btn == KEY_BACK) { EscPress = true; }
    if (btn == KEY_OK) { SelPress = true; }

END:
    // หน่วงเวลาเพื่อป้องกันการกดปุ่มเบิ้ล (Debounce)
    if (AnyKeyPress || btn != BTN_NONE) {
        long tmp = millis();
        // รอจนกว่าจะปล่อยปุ่ม หรือผ่านไป 200ms
        while ((millis() - tmp) < 200 && getPressedButton() != BTN_NONE) {
            delay(10);
        }
    }
}

/*********************************************************************
** Function: keyboard
** location: mykeyboard.cpp
** Starts keyboard to type data
**********************************************************************/
String keyboard(String mytext, int maxSize, String msg) {
    // บอร์ดนี้ไม่มี Touchscreen ระบบจะดึง UI คีย์บอร์ดแบบปุ่มกด (On-Screen Keyboard ของ Bruce) มาใช้แทน
    // ในโครงสร้างบอร์ด Custom คืนค่า mytext ไว้เพื่อไม่ให้แอปแครช
    return mytext; 
}

/*********************************************************************
** Function: powerOff
** location: mykeyboard.cpp
** Turns off the device (or try to)
**********************************************************************/
void powerOff() {
    ledcWrite(TFT_BL, 0); // ปิดไฟจอก่อน
    esp_deep_sleep_start();
}

/*********************************************************************
** Function: checkReboot
** location: mykeyboard.cpp
** Btn logic to turn off the device (name is odd btw)
**********************************************************************/
void checkReboot() {
    // ปล่อยว่างไว้ตามเทมเพลต
}
