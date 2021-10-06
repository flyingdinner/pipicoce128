#include "menuString.hpp"
Input *maininput;
SymLib::LineData MenuString::toLineData() const
{
    // FIXME: Implement
    return SymLib::LineData();
}
//fix me
bool ButtonInt(int buttonid)
{
    switch (buttonid)
    {
    case 0:
        return maininput->up;
        break;
    case 1:
        return maininput->down;
        break;

    case 2:
        return maininput->left;
        break;

    case 3:
        return maininput->right;
        break;

    case 4:
        return maininput->ok;
        break;

    default:
        return false;
        break;
    }
}
//
SymLib::LineData MenuString::GetMenuString(const MenuStringDesign &linemsd, bool selected)
{
    //get line of data
    SymLib::LineData line;
    SymLib::LineData spice; // = SymLib::LineDataOfSpice(linemsd.spice0);

    //--->> string 0<<---
    switch (linemsd.spice0)
    {
    case SymLib::Spice::buttonon:
        //add first icon
        if (ButtonInt(linemsd.id))
        {
            spice = SymLib::LineDataOfSpice(SymLib::Spice::buttonon);
        }
        else
        {
            spice = SymLib::LineDataOfSpice(SymLib::Spice::buttonoff);
        }
        line = SymLib::Merge(line, spice);
        //add text
        {
            for (size_t i = 0; i < linemsd.text0.length(); i++)
            {
                auto c = linemsd.text0[i];
                line = SymLib::Merge(line, SymLib::LineDataOfSymbol(c));                
            }
            //
            spice = SymLib::LineDataOfSpice(linemsd.spice1);
            line = SymLib::Merge(line, spice);
        }

        return line;
        break;

    default:
        spice = SymLib::LineDataOfSpice(linemsd.spice0);
        line = SymLib::Merge(line, spice);
        break;
    }
    //old _------------------------------------
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
        for (auto &q : line)
        {
            q ^= 0xFF;
        }
    }
    //--------------end inversion-----------

    return (line);
}
//~~~~~~~~~~~~ GENERATOR ~~~~~~~~~~~~~~~~~~~~
//------------------MENU---------------------
void MenuString::GenerateStartMenu(Input &pipicoInput)
{
    maininput = &pipicoInput;
    MenuPage _mp;
    //
    _mp.name = "buttons_test";
    _mp.selectedStringNumber = 0;
    _mp.strings[8];
    //---str---
    //#0
    MenuStringDesign _msd;
    _msd.spice0 = SymLib::Spice::constInfo;
    _msd.text0 = "buttons";
    _mp.strings[0] = _msd;
    //1
    _msd.spice0 = SymLib::Spice::buttonon;
    _msd.text0 = "button_up";
    _msd.id = 0;
    _mp.strings[1] = _msd;
    //2
    _msd.spice0 = SymLib::Spice::buttonon;
    _msd.text0 = "button_down";
    _msd.id = 1;
    _mp.strings[2] = _msd;
    //3
    _msd.spice0 = SymLib::Spice::buttonon;
    _msd.text0 = "button_left";
    _msd.id = 2;
    _mp.strings[3] = _msd;
    //4
    _msd.spice0 = SymLib::Spice::buttonon;
    _msd.text0 = "button_right";
    _msd.id = 3;
    _mp.strings[4] = _msd;
    //5
    _msd.spice0 = SymLib::Spice::buttonon;
    _msd.text0 = "button_ok";
    _msd.id = 4;
    _mp.strings[5] = _msd;
    //#6
    _msd.spice0 = SymLib::Spice::constInfo;
    _msd.text0 = "pipicoce_test";
    _mp.strings[6] = _msd;
    //#7
    _msd.spice0 = SymLib::Spice::constInfo;
    _msd.text0 = "__asdfghjkltwrrw";
    _mp.strings[7] = _msd;
    //---endstr
    pageCollection[0] = _mp;
    //--->>--nexpPage
}
//---------------END--MENU-------------------