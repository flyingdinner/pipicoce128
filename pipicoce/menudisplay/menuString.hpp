#ifndef HEADER_H_MENUSTRING
#define HEADER_H_MENUSTRING
#include <string> 
struct MenuString {
public:
enum class Spice {
            leftSelect,
            rightSelect,
            locked,
            unlocked,
            };
Spice s0;
std::string text;
};

#endif //HEADER_H_MENUSTRING
