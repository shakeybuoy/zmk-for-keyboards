/*
 * Custom Corne peripheral display
 * Bongo Cat typing animation + ZMK built-in widgets
 */

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/bongo_cat.h>
#include <zmk/display/widgets/peripheral_status.h>
#include <lvgl.h>

/* ── Screen layout (128x32) ──
 *
 * +----------+---------+---------+
 * | BT status|         | Battery |
 * +----------+ Bongo   +---------+
 * |          |  Cat    |         |
 * +----------+---------+---------+
 */

static struct zmk_widget_battery_status battery_widget;
static struct zmk_widget_bongo_cat bongo_cat_widget;
static struct zmk_widget_peripheral_status peripheral_widget;

lv_obj_t *zmk_display_status_screen(void) {
    lv_obj_t *screen = lv_obj_create(NULL);

    zmk_widget_bongo_cat_init(&bongo_cat_widget, screen);
    lv_obj_align(zmk_widget_bongo_cat_obj(&bongo_cat_widget), LV_ALIGN_CENTER, 0, 0);

    zmk_widget_peripheral_status_init(&peripheral_widget, screen);
    lv_obj_align(zmk_widget_peripheral_status_obj(&peripheral_widget),
                 LV_ALIGN_TOP_LEFT, 0, 0);

    zmk_widget_battery_status_init(&battery_widget, screen);
    lv_obj_align(zmk_widget_battery_status_obj(&battery_widget),
                 LV_ALIGN_TOP_RIGHT, 0, 0);

    return screen;
}
