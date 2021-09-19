#include "symlib.hpp"

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
    
    default:
        return LineData();
    }
}

LineData LineDataOfSymbol(char symbol) {
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