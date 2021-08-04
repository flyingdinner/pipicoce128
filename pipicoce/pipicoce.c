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
//KOHCTAHTbI



 const uint8_t SET_CONTRAST =0x81;
 const uint8_t SET_ENTIRE_ON =0xA4;
 const uint8_t SET_NORM_INV =0xA6;
 const uint8_t SET_DISP =0xAE;
 const uint8_t SET_MEM_ADDR =0x20;
 const uint8_t SET_COL_ADDR =0x21;
 const uint8_t SET_PAGE_ADDR =0x22;
 const uint8_t SET_DISP_START_LINE =0x40;
 const uint8_t SET_SEG_REMAP =0xA0;
 const uint8_t SET_MUX_RATIO =0xA8;
 const uint8_t SET_COM_OUT_DIR =0xC0;
 const uint8_t SET_DISP_OFF =0xD3;
 const uint8_t SET_COM_PIN_CFG =0xDA;
 const uint8_t SET_DISP_CLK_DIV =0xD5;
 const uint8_t SET_PRECHARGE =0xD9;
 const uint8_t SET_VCOM_DESEL =0xDB;
 const uint8_t SET_CHARGE_PUMP =0x8D;
const uint8_t SET_DISP_OFFSET =0x8D;
void DisplayUpdate(){

    uint8_t colpos = 0x14;    
    uint8_t u8ts[] = {
       		SET_DISP | 0x00,  // off
            // address setting
            SET_MEM_ADDR,
            0x00,  // horizontal
            // resolution and layout
            SET_DISP_START_LINE | 0x00,
            SET_SEG_REMAP | 0x01,  // column addr 127 mapped to SEG0
            SET_MUX_RATIO,
            //self.height - 1,
            SET_COM_OUT_DIR | 0x08,  // scan from COM[N] to COM0
            SET_DISP_OFFSET,
            0x00,
            SET_COM_PIN_CFG,
            0x02, //if self.width > 2 * self.height else 0x12,
            // timing and driving scheme
            SET_DISP_CLK_DIV,
            0x80,
            SET_PRECHARGE,
            0x22,//if self.external_vcc else 0xF1,
            SET_VCOM_DESEL,
            0x30,  // 0.83*Vcc
            // display
            SET_CONTRAST,
            0xFF,  // maximum            
            SET_ENTIRE_ON,  // output follows RAM contents
            SET_NORM_INV,  // not inverted
            // charge pump
            SET_CHARGE_PUMP,
            0x10 ,//if self.external_vcc else 0x14,
            SET_DISP | 0x01,
    };
    //for(int i =0;i<5;i++){
    //for(int i =0;i<sizeof(u8ts);i++){
        i2c_write_blocking(i2c0,0b0111100,u8ts,sizeof(u8ts)/sizeof(u8ts[0]),false);
        //i2c_write_blocking_until(i2c0,0b0111100,)
    //}
    
}
int main() {
    //stdio_init_all();
    i2c_init(i2c_default, 100 * 1000);
    //
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN,PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    DisplayUpdate();
    //
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        sleep_ms(100);        
    }
    

}

