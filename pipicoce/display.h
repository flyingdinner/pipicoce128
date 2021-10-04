
#ifndef HEADER_H_DISPLAY
#define HEADER_H_DISPLAY

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "hardware/clocks.h"
//
#include "hardware/gpio.h"
#include <string>
#include "symlib/symlib.hpp"

extern const uint LED_PIN;
extern uint8_t _ws[4];

class Display {
public:
    static void InitDisplay();
    static uint8_t *GetSingleNomber (int i);
    static void PrintLitera(uint8_t l[] );
    static void Write8x8_clear(int count);
    static void Write8x8_kresto(int count);
    static void MoveCursorToPage(uint8_t page);
    //
    static void WriteLine(const SymLib::LineData &lineData);

private:
    static void MoveCursorToZero();
    static void DisplayUpdate();

    static void WriteComandSingle(uint8_t f);
    static void WriteComandDuble(uint8_t f,uint8_t s);
    static void WriteComandTriple(uint8_t f,uint8_t s, uint8_t th);

    
};

#endif //HEADER_H_DISPLAY
