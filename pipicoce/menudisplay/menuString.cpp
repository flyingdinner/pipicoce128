#include "menuString.hpp"

SymLib::LineData MenuString::toLineData() const
{
    // FIXME: Implement
    return SymLib::LineData();
}
//

//
SymLib::LineData MenuString::GetMenuString(const MenuStringDesign linemsd, bool selected)
{
    //get line of data
    SymLib::LineData line;
    SymLib::LineData spice = SymLib::LineDataOfSpice(linemsd.spice0);
    line = SymLib::Merge(line, spice);
    //--->> string 0<<---
    for (size_t i = 0; i < linemsd.text0.length(); i++)
    {
        auto c = linemsd.text0[i];
        line = SymLib::Merge(line, SymLib::LineDataOfSymbol(c));
        /* code */
    }

    //
    spice = SymLib::LineDataOfSpice(linemsd.spice1);
    line = SymLib::Merge(line, spice);
    //--->> string 1<<---
    for (size_t i = 0; i < linemsd.text1.length(); i++)
    {
        auto c = linemsd.text1[i];
        line = SymLib::Merge(line, SymLib::LineDataOfSymbol(c));
        /* code */
    }
    //
    spice = SymLib::LineDataOfSpice(linemsd.spice2);
    line = SymLib::Merge(line, spice);
    //--------------if inversion------------
    if (selected)
    {        
        for(auto &q: line) {
            q ^= 0xFF;   
        }
    }
    //--------------end inversion-----------

    return (line);
}
