#ifndef HEADER_H_SYMLIB
#define HEADER_H_SYMLIB

#include <cstdio> 
#include <vector> 

#include "spice.h"

namespace SymLib {

typedef std::vector<uint8_t> LineData;

LineData LineDataOfSpice(Spice spice);
LineData LineDataOfSymbol(char symbol);
LineData Merge(const LineData &lhs, const LineData &rhs);

}; // namespace SymLib


#endif //HEADER_H_SYMLIB
