/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.`
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <string.h>
#include "menudisplay/menuString.hpp"
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
const uint8_t BUTTON_R_GPIO = (13);
const uint8_t BUTTON_D_GPIO = (21);
const uint8_t BUTTON_OK_GPIO = (20);
const uint8_t BUTTON_U_GPIO = (19);
const uint8_t BUTTON_L_GPIO = (18);
//menu---------------------------
MenuPage *currentMenu;
MenuString mainMenu;
//
Input currentinput;
//MenuPage menucollection[10];
//end menu ----------------------
void InitButtons()
{

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
    for (auto _b : buttons)
    {
        gpio_init(_b);
        gpio_set_dir(_b, GPIO_IN);
        gpio_pull_up(_b);
    }
}

//
int main()
{

    Display::InitDisplay();
    //кнопки
    InitButtons();
    Display::Write8x8_kresto(128);
    sleep_ms(1000);
    //
    mainMenu.GenerateStartMenu(currentinput);
    currentMenu = &mainMenu.pageCollection[0];
    //mainMenu.maininput = &currentinput;
    //
    float ledPower = 0;
    while (true)
    {
        currentinput.right = !gpio_get(BUTTON_R_GPIO);
        currentinput.down = !gpio_get(BUTTON_D_GPIO);
        currentinput.ok = !gpio_get(BUTTON_OK_GPIO);
        currentinput.up = !gpio_get(BUTTON_U_GPIO);
        currentinput.left = !gpio_get(BUTTON_L_GPIO);
        //
        gpio_put(LED_PIN, ledPower);
        //sleep_ms(10);
        Display::Write8x8_clear(0);

        for (size_t i = 0; i < 8; i++)
        {
            bool _selected = (i == currentMenu->selectedStringNumber);
            SymLib::LineData ld;
            ld = MenuString::GetMenuString(currentMenu->strings[i], _selected);
            Display::MoveCursorToPage(i);
            Display::WriteLine(ld);
        }
        

        // #define CHECK_BUTTON(BTN_INDEX, NUM_OUT)   \
//     if (!gpio_get(BTN_INDEX))              \
//     {                                      \
//         Display::GetSingleNomber(NUM_OUT); \
//         Display::PrintLitera(_ws);         \
//     }
        //         CHECK_BUTTON(BUTTON_R_GPIO, 1);
        //         CHECK_BUTTON(BUTTON_D_GPIO, 2);  //d
        //         CHECK_BUTTON(BUTTON_OK_GPIO, 3); //ok
        //         CHECK_BUTTON(BUTTON_U_GPIO, 4);  //up
        //         CHECK_BUTTON(BUTTON_L_GPIO, 5);  //l

        // #undef CHECK_BUTTON

        ledPower = ledPower + 0.05f;
        if (ledPower > 1)
        {
            ledPower = 0;
        }

        gpio_put(LED_PIN, ledPower);
        //sleep_ms(10);
    }
}
