/*
 * LvCanvas.cpp
 *
 */
#include "LvCanvas.h"

namespace lvglpp {

LvCanvas::LvCanvas() : LvCanvas(NULL)
{}

LvCanvas::LvCanvas(LvObj * Parent) : LvObj(Parent)
{
    if(Parent)
        cObj.reset(lv_canvas_create(Parent->raw()));
    else
        cObj.reset(lv_canvas_create(lv_scr_act()));

    setUserData(this);
}

LvCanvas::~LvCanvas()
{}
// LvCanvas & LvCanvas::setBuffer(void * buf, lv_coord_t w, lv_coord_t h, lv_img_cf_t cf)
// {
//     lv_canvas_set_buffer(cObj.get(), buf, w, h, cf);
//     return *this;
// }
// LvCanvas & LvCanvas::setPx(lv_coord_t x, lv_coord_t y, lv_color_t c)
// {
//     lv_canvas_set_px(cObj.get(), x, y, c);
//     return *this;
// }
// LvCanvas & LvCanvas::setPalette(uint8_t id, lv_color_t c)
// {
//     lv_canvas_set_palette(cObj.get(), id, c);
//     return *this;
// }
// lv_color_t LvCanvas::getPx(lv_coord_t x, lv_coord_t y) const noexcept
// {
//     return lv_canvas_get_px(cObj.get(), x, y);
// }
lv_image_dsc_t * LvCanvas::getImg() const noexcept
{
    return lv_canvas_get_image(cObj.get());
}
LvCanvas & LvCanvas::copyBuf(lv_obj_t * obj, const lv_area_t * canvas_area, lv_draw_buf_t * dest_buf,
                             const lv_area_t * dest_area)
{
    lv_canvas_copy_buf(obj, canvas_area, dest_buf, dest_area);
    return *this;
}

// LvCanvas & LvCanvas::transform(lv_image_dsc_t * img, int16_t angle, uint16_t zoom, lv_coord_t offset_x,
//                                lv_coord_t offset_y, int32_t pivot_x, int32_t pivot_y, bool antialias)
// {
//     lv_canvas_transform(cObj.get(), img, angle, zoom, offset_x, offset_y, pivot_x, pivot_y, antialias);
//     return *this;
// }

// LvCanvas & LvCanvas::blurHor(const lv_area_t * area, uint16_t r)
// {
//     lv_canvas_blur_hor(cObj.get(), area, r);
//     return *this;
// }
// LvCanvas & LvCanvas::blurVer(const lv_area_t * area, uint16_t r)
// {
//     lv_canvas_blur_ver(cObj.get(), area, r);
//     return *this;
// }

LvCanvas & LvCanvas::fillBg(lv_color_t color, lv_opa_t opa)
{
    lv_canvas_fill_bg(cObj.get(), color, opa);
    return *this;
}
LvCanvas & LvCanvas::drawRect(const lv_draw_rect_dsc_t * dsc, const lv_area_t * coords)
{
    lv_draw_rect((lv_layer_t *)raw(), dsc, coords);
    return *this;
}
LvCanvas & LvCanvas::drawLabel(const lv_draw_label_dsc_t * dsc, const lv_area_t * coords)
{
    lv_draw_label((lv_layer_t *)raw(), dsc, coords);
    return *this;
}
LvCanvas & LvCanvas::drawImg(const lv_draw_image_dsc_t * dsc, const lv_area_t * coords)
{
    lv_draw_image((lv_layer_t *)raw(), dsc, coords);
    return *this;
}
LvCanvas & LvCanvas::drawLine(const lv_draw_line_dsc_t * draw_dsc)
{
    lv_draw_line((lv_layer_t *)raw(), draw_dsc);
    return *this;
}
LvCanvas & LvCanvas::drawVector(lv_vector_dsc_t * draw_dsc)
{
    lv_draw_vector(draw_dsc);
    return *this;
}
LvCanvas & LvCanvas::drawArc(const lv_draw_arc_dsc_t * draw_dsc)
{
    lv_draw_arc((lv_layer_t *)raw(), draw_dsc);
    return *this;
}

} /* namespace lvglpp */
