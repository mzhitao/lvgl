/*
 * LvDisplay.h
 *
 *  created on: sep 29, 2020
 *      author: fstuffdev
 */

#ifndef LVDISPLAY_H_
#define LVDISPLAY_H_

//#include "../../lv_conf.h"
#include "lvglpp.h"

#ifndef LV_DISP_BUFFER_STATIC
#define LV_DISP_BUFFER_STATIC 1
#endif

namespace lvglpp {

typedef enum { LV_DISP_ROT_NONE = 0, LV_DISP_ROT_90, LV_DISP_ROT_180, LV_DISP_ROT_270 } lv_disp_rot_t;

class LvDisplay {
  private:
    LvPointer<lv_display_t, lv_free> disp;

  public:
    LvDisplay() : LvDisplay(480, 480){};
    LvDisplay(unsigned int hres, unsigned int vres);
    virtual ~LvDisplay();
};

} // namespace lvglpp

#endif /* LVDISPLAY_H_ */
