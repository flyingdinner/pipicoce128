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
        case ('D'):
        return LineData {
        0b00011100,
        0b00100010,
        0b01000001,
        0b01000001,
        0b01111111,
        0b00000000,
        }; 
        case ('E'):
        return LineData {
        0b01111111,
        0b01001001,
        0b01001001,
        0b01000001,
        0b00000000,
        }; 
        case ('F'):
        return LineData {
        0b01111111,
        0b00001001,
        0b00001001,
        0b00000001,
        0b00000000,
        };       
        case ('G'):
        return LineData {
        0b00111110,
        0b01000001,
        0b01001001,
        0b01001001,
        0b00111000,
        0b00000000,
        }; 
        case ('H'):
        return LineData {
        0b01111111,
        0b00001000,
        0b00001000,
        0b01111111,
        0b00000000,
        };     

        case ('I'):
        return LineData {
        0b01000001,
        0b01111111,
        0b01000001,        
        0b00000000,
        };     
         case ('J'):
        return LineData {
        0b00110000,
        0b01000000,
        0b01000001,
        0b00111111,        
        0b00000000,
        }; 
        case ('K'):
        return LineData {
        0b01111111,
        0b00001000,
        0b00010100,
        0b01100011,
        0b00000000,
        }; 
        case ('L'):
        return LineData {
        0b01111111,
        0b01000000,
        0b01000000,        
        0b00000000,
        };
        case ('M'):
        return LineData {
        0b01111111,
        0b00001000,
        0b00110000,
        0b00001000,
        0b01111111,
        0b00000000,
        };  
        case ('N'):
        return LineData {
        0b01111111,
        0b00000100,
        0b00011000,
        0b00100000,
        0b01111111,
        0b00000000,
        };  
        case ('O'):
        return LineData {
        0b00111111,
        0b01000001,
        0b01000001,
        0b00111110,        
        0b00000000,
        };
        case ('P'):
        return LineData {
        0b01111110,
        0b00001001,
        0b00001001,
        0b00001110,
        0b00000000,        
        }; 
        case ('Q'):
        return LineData {
        0b01111110,
        0b01001001,
        0b01001001,
        0b01001110,
        0b01110000,
        0b00000000,
        }; 
        case ('R'):
        return LineData {
        0b01111110,
        0b00011001,
        0b00101001,
        0b01001110,
        0b00000000,        
        }; 

        case ('S'):
        return LineData {
        0b01100110,
        0b01001001,
        0b01001001,
        0b00110011,
        0b00000000,        
        }; 

        case ('T'):
        return LineData {
        0b00000001,
        0b00000001,
        0b01111111,
        0b00000001,
        0b00000001,        
        0b00000000,        
        }; 
        case ('U'):
        return LineData {
        0b00111111,
        0b01000000,
        0b01000000,
        0b00111111,        
        0b00000000,
        };
        case ('V'):
        return LineData {
        0b00111111,
        0b01100000,        
        0b00111111,        
        0b00000000,
        };
        case ('W'):
        return LineData {
        0b00111111,
        0b01000000,
        0b00111000,
        0b01000000,
        0b00111111,        
        0b00000000,
        };
        case ('X'):
        return LineData {
        0b01000001,
        0b00100010,
        0b00011100,
        0b00100010,    
        0b01000001,     
        0b00000000,
        };
        case ('Y'):
        return LineData {
        0b00000111,
        0b00001000,
        0b01110000,
        0b00001000,
        0b00000111,        
        0b00000000,
        };
        case ('Z'):
        return LineData {
        0b01100001,
        0b01010001,
        0b01001001,
        0b01000101,
        0b01000011,        
        0b00000000,
        };
          
    default:
        return LineData {
        0b01111111,
        0b01111111,
        0b01111111,        
        0b00000000,
        }; 
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