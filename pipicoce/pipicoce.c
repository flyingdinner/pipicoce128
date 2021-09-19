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


//KHOnKu
//#define FIRST_GPIO 2
const uint8_t BUTTON_L_GPIO =(27);
const uint8_t BUTTON_R_GPIO =(21);
const uint8_t BUTTON_U_GPIO =(20);
const uint8_t BUTTON_D_GPIO =(19);
const uint8_t BUTTON_OK_GPIO =(18);

int main() {
    
    InitDisplay();
    //кнопки
    gpio_init(BUTTON_L_GPIO);
    gpio_set_dir(BUTTON_L_GPIO, GPIO_IN);
    // We are using the button to pull down to 0v when pressed, so ensure that when
    // unpressed, it uses internal pull ups. Otherwise when unpressed, the input will
    // be floating.
    gpio_pull_up(BUTTON_L_GPIO);
    gpio_pull_up(BUTTON_R_GPIO);
    gpio_pull_up(BUTTON_U_GPIO);
    gpio_pull_up(BUTTON_D_GPIO);
    gpio_pull_up(BUTTON_OK_GPIO);

    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(10);       
        GetSingleNomber(0) ;
        PrintLitera(_ws);
        
        
        gpio_put(LED_PIN, 0);
        sleep_ms(10); 
    }    

}

