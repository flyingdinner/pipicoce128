#ifndef HEADER_H_MENUSTRING
#define HEADER_H_MENUSTRING

#include "../symlib/symlib.hpp"
#include <string>

struct MenuStringDesign{
SymLib::Spice spice0;
std::string text0;
SymLib::Spice spice1;
std::string text1;
SymLib::Spice spice2;
//номер кнопки , страниц,номер булевой
uint8_t id;
//MenuPage *nextmenu;
};
struct MenuPage{
    uint8_t selectedStringNumber;
    std::string name;
    MenuStringDesign strings[];    
};

class MenuString {
public:
static SymLib::LineData GetMenuString(const MenuStringDesign &linemsd,bool selected);

SymLib::Spice s0;
std::string text;
MenuPage pageCollection[];
SymLib::LineData toLineData() const;
};
#endif //HEADER_H_MENUSTRING
