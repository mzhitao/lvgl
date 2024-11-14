/*
 * LvChart.cpp
 *
 */

#include "LvChart.h"

namespace lvglpp {

LvChart::LvChart() : LvChart(NULL)
{}

LvChart::LvChart(LvObj * Parent) : LvObj(Parent)
{
    if(Parent)
        cObj.reset(lv_chart_create(Parent->raw()));
    else
        cObj.reset(lv_chart_create(lv_scr_act()));

    setUserData(this);
}

LvChart::~LvChart()
{}

} /* namespace lvglpp */
