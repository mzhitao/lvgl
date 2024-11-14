/*
 * LvTabview.cpp
 *
 */

#include "LvTabview.h"

namespace lvglpp {

LvTabview::LvTabview() : LvTabview(NULL)
{}

LvTabview::LvTabview(LvObj * Parent)
{
    if(Parent)
        cObj.reset(lv_tabview_create(Parent->raw()));
    else
        cObj.reset(lv_tabview_create(lv_scr_act()));

    setUserData(this);
}

LvTabview::~LvTabview()
{}
LvObj & LvTabview::addTab(const char * name)
{
    LvObj * tab = new LvObj(this);
    tab->setCObj(lv_tabview_add_tab(cObj.get(), name));
    return *tab;
}
LvTabview & LvTabview::setAct(uint32_t id, lv_anim_enable_t anim_en)
{
    lv_tabview_set_act(cObj.get(), id, anim_en);
    return *this;
}
uint16_t LvTabview::getTabAct() const noexcept
{
    return lv_tabview_get_tab_act(cObj.get());
}

} /* namespace lvglpp */
