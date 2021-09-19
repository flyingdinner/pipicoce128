
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


extern const uint LED_PIN;
extern uint8_t _ws[4];

void InitDisplay();
uint8_t *GetSingleNomber (int i);
void PrintLitera(uint8_t l[] );

#endif //HEADER_H_DISPLAY
