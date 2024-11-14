/*
 * LvCanvas.h
 *
 */

#ifndef LVCANVAS_H_
#define LVCANVAS_H_

#include "../core/LvObj.h"

namespace lvglpp {

class LvCanvas : public LvObj {
  public:
    LvCanvas();
    LvCanvas(LvObj * Parent);
    virtual ~LvCanvas() override;
    // LvCanvas & setBuffer(void * buf, lv_coord_t w, lv_coord_t h, lv_img_cf_t cf);
    // LvCanvas & setPx(lv_coord_t x, lv_coord_t y, lv_color_t c);
    // LvCanvas & setPalette(uint8_t id, lv_color_t c);
    // lv_color_t getPx(lv_coord_t x, lv_coord_t y) const noexcept;
    lv_image_dsc_t * getImg() const noexcept;
    LvCanvas & copyBuf(lv_obj_t * obj, const lv_area_t * canvas_area, lv_draw_buf_t * dest_buf,
                       const lv_area_t * dest_area);
    // LvCanvas & transform(lv_image_dsc_t * img, int16_t angle, uint16_t zoom, lv_coord_t offset_x, lv_coord_t
    // offset_y,
    //                      int32_t pivot_x, int32_t pivot_y, bool antialias);
    // LvCanvas & blurHor(const lv_area_t * area, uint16_t r);
    // LvCanvas & blurVer(const lv_area_t * area, uint16_t r);
    LvCanvas & fillBg(lv_color_t color, lv_opa_t opa);
    LvCanvas & drawRect(const lv_draw_rect_dsc_t * dsc, const lv_area_t * coords);
    LvCanvas & drawLabel(const lv_draw_label_dsc_t * dsc, const lv_area_t * coords);
    LvCanvas & drawImg(const lv_draw_image_dsc_t * dsc, const lv_area_t * coords);
    LvCanvas & drawLine(const lv_draw_line_dsc_t * draw_dsc);
    LvCanvas & drawVector(lv_vector_dsc_t * draw_dsc);
    LvCanvas & drawArc(const lv_draw_arc_dsc_t * draw_dsc);
};

} /* namespace lvglpp */

#endif /* LVCANVAS_H_ */
