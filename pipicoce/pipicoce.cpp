/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.`
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "hardware/clocks.h"
//
#include "hardware/gpio.h"

#include "display.h"

#include <vector>


//KHOnKu
//#define FIRST_GPIO 2
const uint8_t BUTTON_R_GPIO =(13);
const uint8_t BUTTON_D_GPIO =(21);
const uint8_t BUTTON_OK_GPIO =(20);
const uint8_t BUTTON_U_GPIO =(19);
const uint8_t BUTTON_L_GPIO =(18);
void InitButtons(){

    // We are using the button to pull down to 0v when pressed, so ensure that when
    // unpressed, it uses internal pull ups. Otherwise when unpressed, the input will
    // be floating.
    std::vector<uint8_t> buttons = {
        BUTTON_R_GPIO,
        BUTTON_D_GPIO,
        BUTTON_OK_GPIO,
        BUTTON_U_GPIO,
        BUTTON_L_GPIO,
    };
    for(auto _b : buttons){
        gpio_init(_b);
        gpio_set_dir(_b, GPIO_IN);
        gpio_pull_up(_b);
    }
    

}
int main() {
    
    Display::InitDisplay();
    //кнопки
    InitButtons();
    Display::Write8x8_kresto(128);  
        sleep_ms(1000); 
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(10);
        Display::Write8x8_clear(0);    

        
        //
        //
        // Count upwards or downwards depending on button input
    // We are pulling down on switch active, so invert the get to make
    // a press count downwards
    #define CHECK_BUTTON(BTN_INDEX, NUM_OUT)  \
    if (!gpio_get(BTN_INDEX)) { \
        Display::GetSingleNomber(NUM_OUT) ; \
        Display::PrintLitera(_ws); \
    }    
        CHECK_BUTTON(BUTTON_R_GPIO, 1);
        CHECK_BUTTON(BUTTON_D_GPIO, 2);//d
        CHECK_BUTTON(BUTTON_OK_GPIO, 3);//ok
        CHECK_BUTTON(BUTTON_U_GPIO, 4);//up
        CHECK_BUTTON(BUTTON_L_GPIO, 5);//l

    #undef CHECK_BUTTON
    MenuStringDesign _msd ;
    _msd.spice0 = SymLib::Spice::kresto;

    _msd.spice1 = SymLib::Spice::leftSelect;

    _msd.spice2 = SymLib::Spice::rightSelect;

     Display::PrintMenuString(_msd,false) ;  
        gpio_put(LED_PIN, 0);
        sleep_ms(10); 
    }    

}

