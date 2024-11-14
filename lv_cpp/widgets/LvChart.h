/*
 * LvChart.h
 *
 */

#ifndef LVCHART_H_
#define LVCHART_H_

#include "../core/LvObj.h"
#include <cstdint>

namespace lvglpp {

class LvChart : public LvObj {
  public:
    LvChart();
    LvChart(const LvChart &)             = delete;
    LvChart(LvChart &&)                  = delete;
    LvChart & operator=(const LvChart &) = delete;
    LvChart & operator=(LvChart &&)      = delete;
    LvChart(LvObj * Parent);
    virtual ~LvChart() override;
    // LvChart& setType(lv_chart_type_t type);
    // LvChart& setPointCount(uint16_t cnt);
    // LvChart& setRange(lv_chart_axis_t axis, lv_coord_t min, lv_coord_t max);
    // LvChart& setUpdateMode(lv_chart_update_mode_t update_mode);
    // LvChart& setDivLineCount(uint8_t hdiv, uint8_t vdiv);
    // LvChart& setZoomX(uint16_t zoom_x);
    // LvChart& setZoomY(uint16_t zoom_y);
    // uint16_t getZoomX() const noexcept ;
    // uint16_t getZoomY() const noexcept ;
    // LvChart& setAxisTick(lv_chart_axis_t axis, lv_coord_t major_len, lv_coord_t minor_len, lv_coord_t major_cnt,
    // lv_coord_t minor_cnt, bool label_en, lv_coord_t draw_size); lv_chart_type_t getType() const noexcept ; uint16_t
    // getPointCount() const noexcept ; uint16_t getXStartPoint(lv_chart_series_t *ser) const noexcept ; LvChart&
    // getPointPosById(lv_chart_series_t *ser, uint16_t id, lv_point_t *p_out); LvChart& refresh(); lv_chart_series_t
    // *addSeries(lv_color_t color, lv_chart_axis_t axis); LvChart& removeSeries(lv_chart_series_t *series); LvChart&
    // hideSeries(lv_chart_series_t *series, bool hide); LvChart& setSeriesColor(lv_chart_series_t *series, lv_color_t
    // color); LvChart& setXStartPoint(lv_chart_series_t *ser, uint16_t id); lv_chart_series_t *getSeriesNext(const
    // lv_chart_series_t *ser) const noexcept ; lv_chart_cursor_t *addCursor(lv_color_t color, lv_dir_t dir); LvChart&
    // setCursorPos(lv_chart_cursor_t *cursor, lv_point_t *pos); LvChart& setCursorPoint(lv_chart_cursor_t *cursor,
    // lv_chart_series_t *ser, uint16_t point_id); lv_point_t getCursorPoint(lv_chart_cursor_t *cursor) const noexcept ;
    // LvChart& setAllValue(lv_chart_series_t *ser, lv_coord_t value);
    // LvChart& setNextValue(lv_chart_series_t *ser, lv_coord_t value);
    // LvChart& setNextValue2(lv_chart_series_t *ser, lv_coord_t x_value, lv_coord_t y_value);
    // LvChart& setValueById(lv_chart_series_t *ser, uint16_t id, lv_coord_t value);
    // LvChart& setValueById2(lv_chart_series_t *ser, uint16_t id, lv_coord_t x_value, lv_coord_t y_value);
    // LvChart& setExtYArray(lv_chart_series_t *ser, lv_coord_t array[]);
    // LvChart& setExtXArray(lv_chart_series_t *ser, lv_coord_t array[]);
    // lv_coord_t *getYArray(lv_chart_series_t *ser) const noexcept ;
    // lv_coord_t *getXArray(lv_chart_series_t *ser) const noexcept ;
    // uint32_t getPressedPoint() const noexcept ;
    LvChart & setType(lv_chart_type_t type)
    {
        lv_chart_set_type(cObj.get(), type);
        return *this;
    }
    LvChart & setPointCount(uint16_t cnt)
    {
        lv_chart_set_point_count(cObj.get(), cnt);
        return *this;
    }
    LvChart & setRange(lv_chart_axis_t axis, lv_coord_t min, lv_coord_t max)
    {
        lv_chart_set_range(cObj.get(), axis, min, max);
        return *this;
    }
    LvChart & setUpdateMode(lv_chart_update_mode_t update_mode)
    {
        lv_chart_set_update_mode(cObj.get(), update_mode);
        return *this;
    }
    LvChart & setDivLineCount(uint8_t hdiv, uint8_t vdiv)
    {
        lv_chart_set_div_line_count(cObj.get(), hdiv, vdiv);
        return *this;
    }
    lv_chart_type_t getType() const noexcept
    {
        return lv_chart_get_type(cObj.get());
    }
    uint32_t getPointCount() const noexcept
    {
        return lv_chart_get_point_count(cObj.get());
    }
    uint32_t getXStartPoint(lv_chart_series_t * ser) const noexcept
    {
        return lv_chart_get_x_start_point(cObj.get(), ser);
    }
    void getPointPosById(lv_chart_series_t * ser, uint16_t id, lv_point_t * p_out)
    {
        lv_chart_get_point_pos_by_id(cObj.get(), ser, id, p_out);
    }
    void refresh()
    {
        lv_chart_refresh(cObj.get());
    }

    void addSeries(lv_color_t color, lv_chart_axis_t axis)
    {
        lv_chart_series_t * ser = lv_chart_add_series(cObj.get(), color, axis);
    }
    void removeSeries(lv_chart_series_t * series)
    {
        lv_chart_remove_series(cObj.get(), series);
    }
    void hideSeries(lv_chart_series_t * series, bool hide)
    {
        lv_chart_hide_series(cObj.get(), series, hide);
    }
    void setSeriesColor(lv_chart_series_t * series, lv_color_t color)
    {
        lv_chart_set_series_color(cObj.get(), series, color);
    }
    void setXStartPoint(lv_chart_series_t * ser, uint16_t id)
    {
        lv_chart_set_x_start_point(cObj.get(), ser, id);
    }
    lv_chart_series_t * getSeriesNext(const lv_chart_series_t * ser) const noexcept
    {
        return lv_chart_get_series_next(cObj.get(), ser);
    }
    lv_chart_cursor_t * addCursor(lv_color_t color, lv_dir_t dir)
    {
        return lv_chart_add_cursor(cObj.get(), color, dir);
    }
    void setCursorPos(lv_chart_cursor_t * cursor, lv_point_t * pos)
    {
        lv_chart_set_cursor_pos(cObj.get(), cursor, pos);
    }
    void setCursorPoint(lv_chart_cursor_t * cursor, lv_chart_series_t * ser, uint16_t point_id)
    {
        lv_chart_set_cursor_point(cObj.get(), cursor, ser, point_id);
    }
    lv_point_t getCursorPoint(lv_chart_cursor_t * cursor) const noexcept
    {
        return lv_chart_get_cursor_point(cObj.get(), cursor);
    }
    void setAllValue(lv_chart_series_t * ser, lv_coord_t value)
    {
        lv_chart_set_all_value(cObj.get(), ser, value);
    }
    void setNextValue(lv_chart_series_t * ser, lv_coord_t value)
    {
        lv_chart_set_next_value(cObj.get(), ser, value);
    }
    void setNextValue2(lv_chart_series_t * ser, lv_coord_t x_value, lv_coord_t y_value)
    {
        lv_chart_set_next_value2(cObj.get(), ser, x_value, y_value);
    }
    void setValueById(lv_chart_series_t * ser, uint16_t id, lv_coord_t value)
    {
        lv_chart_set_value_by_id(cObj.get(), ser, id, value);
    }
    void setValueById2(lv_chart_series_t * ser, uint16_t id, lv_coord_t x_value, lv_coord_t y_value)
    {
        lv_chart_set_value_by_id2(cObj.get(), ser, id, x_value, y_value);
    }
    void setExtYArray(lv_chart_series_t * ser, lv_coord_t array[])
    {
        lv_chart_set_ext_y_array(cObj.get(), ser, array);
    }
    void setExtXArray(lv_chart_series_t * ser, lv_coord_t array[])
    {
        lv_chart_set_ext_x_array(cObj.get(), ser, array);
    }
    int32_t * getYArray(lv_chart_series_t * ser) const noexcept
    {
        return lv_chart_get_y_array(cObj.get(), ser);
    }
    int32_t * getXArray(lv_chart_series_t * ser) const noexcept
    {
        return lv_chart_get_x_array(cObj.get(), ser);
    }
    uint32_t getPressedPoint() const noexcept
    {
        return lv_chart_get_pressed_point(cObj.get());
    }
    int32_t getFirstPointCenterOffset()
    {
        return lv_chart_get_first_point_center_offset(cObj.get());
    }
};

} /* namespace lvglpp */

#endif /* LVCHART_H_ */
