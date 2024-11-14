/*
 * LvInput.h
 *
 *  Created on: Sep 29, 2020
 *      Author: fstuffdev
 */

#ifndef LVINPUT_H_
#define LVINPUT_H_

#include "../../lv_conf.h"
#include "lvglpp.h"
#include "../../lvgl/lvgl.h"
#include "../widgets/LvImg.h"

namespace lvglpp {

class LvInput {
  private:
    lv_indev_t indev_drv;
    LvPointer<lv_indev_t, lv_free> indev;
    LvPointerUnique<LvImg> Cursor;

  public:
    LvInput();
    LvInput(lv_indev_t * drv);
    virtual ~LvInput();

    LvInput & setCursor(LvImg & Img);
    LvInput & enableCursor();
};

} // namespace lvglpp

#endif /* LVINPUT_H_ */
