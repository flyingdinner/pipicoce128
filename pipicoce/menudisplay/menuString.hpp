#ifndef HEADER_H_MENUSTRING
#define HEADER_H_MENUSTRING

#include "../symlib/symlib.hpp"
#include <string>

class MenuString {
public:
SymLib::Spice s0;
std::string text;

    SymLib::LineData toLineData() const;
};

#endif //HEADER_H_MENUSTRING
