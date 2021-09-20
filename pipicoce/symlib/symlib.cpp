#include "symlib.hpp"
#include <string>
namespace SymLib {

LineData LineDataOfSpice(Spice spice) {
    switch (spice)
    {
    case Spice::kresto:
        return LineData {
        0b00000000,
        0b01000010,
        0b00100100,
        0b00011000,
        0b00011000,
        0b00100100,
        0b01000010,
        0b00000000,
        };
    case Spice::leftSelect:
        return LineData {
        0b00000000,
        0b00011000,
        0b00011000,
        0b00111100,
        0b00111100,
        0b01111110,
        0b01111110,
        0b00000000,
        };
    case Spice::rightSelect:
        return LineData {
        0b00000000,
        0b01111110,
        0b01111110,
        0b00111100,
        0b00111100,
        0b00011000,
        0b00011000,
        0b00000000,
        };
    case Spice::locked:
        return LineData {
        0b00000000,
        0b01111000,
        0b01111111,
        0b01011001,
        0b01011001,
        0b01111111,
        0b01111000,
        0b00000000,
        };
    case Spice::unlocked:
        return LineData {
        0b00000000,
        0b01111000,
        0b01111001,
        0b01011001,
        0b01011001,
        0b01111111,
        0b01111000,
        0b00000000,
        };          
    default:
        return LineData();
    }
}

LineData LineDataOfSymbol(char symbol) {
    switch (symbol)
    {
        case ('A'):
        return LineData {
        0b01111110,
        0b00010001,
        0b00010001,
        0b00010001,
        0b01111110,
        0b00000000,
        };     
        case ('B'):
        return LineData {
        0b01111110,
        0b01001001,
        0b01001001,
        0b01001110,
        0b01110000,
        0b00000000,
        }; 
        case ('C'):
        return LineData {
        0b00111110,
        0b01000001,
        0b01000001,
        0b01000001,
        0b00100010,
        0b00000000,
        };      
    default:
        return LineData();
    }
    // FIXME: Implement
    return LineData();
}

LineData Merge(const LineData &lhs, const LineData &rhs) {
    if (rhs.empty()) {
        return lhs;
    }
    LineData result = lhs;
    result.insert( result.end(), rhs.begin(), rhs.end() );
    return result;
}

}; // namespace SymLib