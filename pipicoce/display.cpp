#include "display.h"
#include <iostream>

// ivar definitions
const uint LED_PIN = PICO_DEFAULT_LED_PIN;
uint8_t _ws[4] = {0,0,0,0};


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
 const uint8_t SET_COM_PIN_CFG =0x12;
 const uint8_t SET_DISP_CLK_DIV =0x80;
 const uint8_t SET_PRECHARGE =0xD9;
 const uint8_t SET_VCOM_DESEL =0xDB;
 const uint8_t SET_CHARGE_PUMP =0x8D;
const uint8_t SET_DISP_OFFSET =0x8D;


void Display::InitDisplay(){

    #define PIN_SDA 0
    #define PIN_SCL 1
    //
    gpio_set_function(PIN_SDA, GPIO_FUNC_I2C);
    gpio_set_function(PIN_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(PIN_SDA);
    gpio_pull_up(PIN_SCL);
    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PIN_SDA, PIN_SCL, GPIO_FUNC_I2C));

    i2c_init(i2c_default, 100 * 1000);
    //
    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);  
    gpio_put(LED_PIN, 1);
    sleep_ms(5);
    gpio_put(LED_PIN, 0);
    sleep_ms(5); 
    DisplayUpdate();
    gpio_put(LED_PIN, 1);
    sleep_ms(5);
    gpio_put(LED_PIN, 0);
    sleep_ms(5);
    MoveCursorToZero();
}

uint8_t *Display::GetSingleNomber (int i){ 
    
    switch (i)
	{
	case 0:    
     _ws[0]=0b00000000;
     _ws[1]=0b11111110;
     _ws[2]=0b10000010;
     _ws[3]=0b11111110;
            
    break;
    case 1:
     _ws[0]=0b00000000;
     _ws[1]=0b10000000;
     _ws[2]=0b11111110;
     _ws[3]=0b10000100;
          
    break;
    case 2:
    _ws[0]=0b00000000;
    _ws[1]=0b10001110;
    _ws[2]=0b10001010;
    _ws[3]=0b11111010;
          
    break;
    case 3:    
    _ws[0]=0b00000000;
    _ws[1]=0b11111110;
    _ws[2]=0b10010010;
    _ws[3]=0b10000010;
     
    break;
    case 4:
    _ws[0]=0b00000000;
    _ws[1]=0b11111110;
    _ws[2]=0b00010000;
    _ws[3]=0b00011100;
     
    break;
    case 5:
    _ws[0]=0b00000000;
    _ws[1]=0b11110010;
    _ws[2]=0b10010010;
    _ws[3]=0b10011110;
        
    break;
    case 6:
    _ws[0]=0b00000000;
    _ws[1]=0b11110010;
    _ws[2]=0b10010010;
    _ws[3]=0b11111110;
       
    break;
    case 7:
    _ws[0]=0b00000000;
    _ws[1]=0b00000110;
    _ws[2]=0b11111010;
    _ws[3]=0b00000010;
         
    break;
    case 8:
    _ws[0]=0b00000000;
    _ws[1]=0b11101110;
    _ws[2]=0b10010010;
    _ws[3]=0b11101110;
      
    break;
    case 9:
    _ws[0]=0b00000000;
    _ws[1]=0b11111110;
    _ws[2]=0b10010010;
    _ws[3]=0b10011110;

    break;
    //
    default:
    _ws[0]=0b00000000;
    _ws[1]=0b00000000;
    _ws[2]=0b00000000;
    _ws[3]=0b00000000;
     
    break;         
	};    
    
}
//
void Display::PrintLitera(uint8_t l[] ){
    uint8_t w[5];
    w[0]=0x40;
    w[1]=l[3];
    w[2]=l[2];
    w[3]=l[1];
    w[4]=l[0];    
    i2c_write_blocking(i2c0,0b0111100,w,sizeof(w)/sizeof(w[0]),false);
}
//
void Display::WriteComandSingle(uint8_t f){
    uint8_t w[] = {
        0x80,
        f,
             
    };
    i2c_write_blocking(i2c0,0b0111100,w,sizeof(w)/sizeof(w[0]),false);
}
void Display::WriteComandDuble(uint8_t f,uint8_t s){
    uint8_t w[] = {
        0x80,
        f,
        s,        
    };
    i2c_write_blocking(i2c0,0b0111100,w,sizeof(w)/sizeof(w[0]),false);
}
void Display::WriteComandTriple(uint8_t f,uint8_t s, uint8_t th){
    uint8_t w[] = {
        0x80,
        f,
        s,
        th,
    };
    i2c_write_blocking(i2c0,0b0111100,w,sizeof(w)/sizeof(w[0]),false);
}
//-----------------------
void Display::Write8x8_clear(int count){
    uint8_t w[] = {
        0x40,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    };
    i2c_write_blocking(i2c0,0b0111100,w,sizeof(w)/sizeof(w[0]),false);
    //sleep_ms(10);
    if(count<=0)return;
    Write8x8_clear(count-1);
}
void Display::Write8x8_kresto(int count){
    SymLib::LineData line;
    SymLib::LineData kresto = SymLib::LineDataOfSpice(SymLib::Spice::kresto);
    for(int i = 0; i < count; i++) {
        line = SymLib::Merge(line, kresto);
    }
    WriteLine(line);
}
void Display::MoveCursorToZero(){
   // i2c.writeto(0x3c, bytes([0x80,0xB0]))    
    //i2c.writeto(0x3c, bytes([0x80,0x00]))
    //i2c.writeto(0x3c, bytes([0x80,0x10]))
    WriteComandSingle(0xB0);
    WriteComandSingle(0x00);
    WriteComandSingle(0x10);
}
void Display::MoveCursorToPage(uint8_t page){

    WriteComandSingle(176+page);
    WriteComandSingle(0x00);
    WriteComandSingle(0x10);
}
//fixme

void Display::PrintMenuString(MenuStringDesign linemsd,bool selected){
SymLib::LineData line;
SymLib::LineData spice = SymLib::LineDataOfSpice(linemsd.spice0);
line = SymLib::Merge(line,spice);
//--->> string 0<<---

//
spice = SymLib::LineDataOfSpice(linemsd.spice1);
line = SymLib::Merge(line,spice);
//--->> string 1<<---

//
spice = SymLib::LineDataOfSpice(linemsd.spice2);
line = SymLib::Merge(line,spice);
//--------------
WriteLine(line);
}
//-------
void Display::DisplayUpdate(){

    uint8_t colpos = 0x14;   
    const int height  = 64;
    int addr = 0x3C;
    //bool external_vcc = false;
    bool reset = false;
    bool reset_pin = false;
    bool page_addressing = false;
    uint8_t pages = height / 8;
    bool _power = false;
    //pagebuffer = None
    bool page_column_start = false;
    sleep_ms(100);
    ///i2c.writeto(0x3c, bytes(SET_DISP | 0x01));
    //i2c_write_blocking(i2c0,addr,SET_DISP | 0x01,2,false); /// TODO: Check and restore?
    
    //sleep_ms(500);

    _power = true;
    uint8_t u8ts[] = {
       		SET_DISP,  // off
        // address setting
        SET_MEM_ADDR,
        0x10,  // Page Addressing Mode
        0x00,  // Horizontal Addressing Mode
        // resolution and layout
        SET_DISP_START_LINE,
        SET_SEG_REMAP | 0x01,  // column addr 127 mapped to SEG0
        SET_MUX_RATIO,
        height - 1,//7?
        SET_COM_OUT_DIR | 0x08,  // scan from COM[N] to COM0
        SET_DISP_OFFSET,
        0x00,
        SET_COM_PIN_CFG,
        0x02, // 0x12,
        // timing and driving scheme
        SET_DISP_CLK_DIV,
        0x80,
        SET_PRECHARGE,
        0xF1,
        SET_VCOM_DESEL,
        0x30, //# 0.83*Vcc  # n.b. 
		//#specs for ssd1306 64x32
		//#oled screens 
		//#imply this should be 0x40
        //# display
        SET_CONTRAST,
        0xFF,//  # maximum
        SET_ENTIRE_ON,//  # output follows RAM contents
        SET_NORM_INV,//  # not inverted
        0xAD, //SET_IREF_SELECT,
        0x30,//  # enable internal IREF during display on
        //# charge pump
        SET_CHARGE_PUMP,
        //#0x10 if self.external_vcc else
	    0x14,
        SET_DISP | 0x01, // # display on
    };    
    i2c_write_blocking(i2c0,0b0111100,u8ts,sizeof(u8ts)/sizeof(u8ts[0]),false);
    sleep_ms(100);
    MoveCursorToZero();
    //i2c_write_blocking(i2c0,0b0111100,0x80|0xAE,2,false);
    Write8x8_clear(128);
    //uint8_t dispon[]= {0x80,0xAE};
    //i2c_write_blocking(i2c0,0b0111100,dispon,sizeof(dispon)/sizeof(dispon[0]),false);
    Write8x8_kresto(128);

}

void Display::WriteLine(const SymLib::LineData &lineData) {
    auto fullData = SymLib::Merge(SymLib::LineData{ 0x40 }, lineData);
    i2c_write_blocking(i2c0, 0b0111100, fullData.data(), fullData.size(), false);
}
