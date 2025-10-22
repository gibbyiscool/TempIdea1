/**
 * @file TempIdea_gen.c
 */

#include "TempIdea_gen.h"

/*********************
 *  FORWARD DECLS
 *********************/
/* Event callbacks are implemented by your app (TempIdea.c) */
void ui_event_main_panel(lv_event_t *e);
void ui_event_slider_target(lv_event_t *e);
void ui_event_btn_save(lv_event_t *e);
void ui_event_btn_cancel(lv_event_t *e);
void ui_event_sw_units(lv_event_t *e);
void ui_event_sw_manual(lv_event_t *e);
void ui_event_slider_manual(lv_event_t *e);
void ui_event_sw_alarm(lv_event_t *e);
void ui_event_btn_back(lv_event_t *e);

/**********************
 *  GLOBAL OBJECTS
 **********************/
lv_obj_t *ui_MainScreen;
lv_obj_t *ui_MainPanel;
lv_obj_t *ui_LabelTempBig;
lv_obj_t *ui_LabelFan;
lv_obj_t *ui_LabelTargetSmall;

lv_obj_t *ui_SetScreen;
lv_obj_t *ui_SetPanel;
lv_obj_t *ui_LabelSetTitle;
lv_obj_t *ui_LabelSetValue;
lv_obj_t *ui_SliderTarget;
lv_obj_t *ui_BtnSave;
lv_obj_t *ui_BtnCancel;

lv_obj_t *ui_OptsScreen;
lv_obj_t *ui_OptsPanel;
lv_obj_t *ui_SwitchUnits;
lv_obj_t *ui_SwitchManual;
lv_obj_t *ui_SliderManual;
lv_obj_t *ui_SwitchAlarm;
lv_obj_t *ui_BtnBack;

/**********************
 *  STATIC: styles
 **********************/
static lv_style_t st_bg_dark;
static lv_style_t st_lbl_big;
static lv_style_t st_lbl_sm;
static lv_style_t st_card;

/**********************
 *  STATIC HELPERS
 **********************/
static void styles_init(void) {
    lv_style_init(&st_bg_dark);
    lv_style_set_bg_color(&st_bg_dark, lv_color_hex(0x111111));
    lv_style_set_bg_opa(&st_bg_dark, LV_OPA_COVER);

    lv_style_init(&st_lbl_big);
    lv_style_set_text_color(&st_lbl_big, lv_color_white());
    lv_style_set_text_font(&st_lbl_big, &lv_font_montserrat_48);

    lv_style_init(&st_lbl_sm);
    lv_style_set_text_color(&st_lbl_sm, lv_color_hex(0xE0E0E0));
    lv_style_set_text_font(&st_lbl_sm, &lv_font_montserrat_20);

    lv_style_init(&st_card);
    lv_style_set_pad_all(&st_card, 8);
    lv_style_set_radius(&st_card, 8);
    lv_style_set_bg_color(&st_card, lv_color_hex(0x1C1C1C));
    lv_style_set_bg_opa(&st_card, LV_OPA_COVER);
    lv_style_set_border_color(&st_card, lv_color_hex(0x2A2A2A));
    lv_style_set_border_width(&st_card, 1);
}

/* Label factory */
static lv_obj_t* make_label(lv_obj_t *parent, const char *txt, const lv_style_t *sty) {
    lv_obj_t *l = lv_label_create(parent);
    if (sty) lv_obj_add_style(l, (lv_style_t*)sty, 0);
    if (txt) lv_label_set_text(l, txt);
    return l;
}

/* Simple button with text */
static lv_obj_t* make_btn(lv_obj_t *parent, const char *txt, lv_event_cb_t cb) {
    lv_obj_t *b = lv_btn_create(parent);
    lv_obj_add_event_cb(b, cb, LV_EVENT_CLICKED, NULL);
    lv_obj_t *t = lv_label_create(b);
    lv_label_set_text(t, txt);
    lv_obj_center(t);
    return b;
}

/**********************
 *  BUILD: Main screen
 **********************/
static void build_main_screen(void) {
    ui_MainScreen = lv_obj_create(NULL);
    lv_obj_add_style(ui_MainScreen, &st_bg_dark, 0);

    ui_MainPanel = lv_obj_create(ui_MainScreen);
    lv_obj_remove_style_all(ui_MainPanel);
    lv_obj_set_size(ui_MainPanel, LV_PCT(100), LV_PCT(100));
    lv_obj_add_event_cb(ui_MainPanel, ui_event_main_panel, LV_EVENT_ALL, NULL);

    ui_LabelTempBig = make_label(ui_MainPanel, "--°", &st_lbl_big);
    lv_obj_center(ui_LabelTempBig);

    ui_LabelFan = make_label(ui_MainPanel, "Fan --%", &st_lbl_sm);
    lv_obj_align(ui_LabelFan, LV_ALIGN_BOTTOM_LEFT, 10, -10);

    ui_LabelTargetSmall = make_label(ui_MainPanel, "Target --.-°", &st_lbl_sm);
    lv_obj_align(ui_LabelTargetSmall, LV_ALIGN_BOTTOM_RIGHT, -10, -10);
}

/************************
 *  BUILD: Set Target UI
 ************************/
static void build_set_screen(void) {
    ui_SetScreen = lv_obj_create(NULL);
    lv_obj_add_style(ui_SetScreen, &st_bg_dark, 0);

    ui_SetPanel = lv_obj_create(ui_SetScreen);
    lv_obj_remove_style_all(ui_SetPanel);
    lv_obj_set_size(ui_SetPanel, LV_PCT(100), LV_PCT(100));
    lv_obj_add_style(ui_SetPanel, &st_card, 0);

    ui_LabelSetTitle = make_label(ui_SetPanel, "Set Target", &st_lbl_sm);
    lv_obj_align(ui_LabelSetTitle, LV_ALIGN_TOP_MID, 0, 8);

    ui_LabelSetValue = lv_label_create(ui_SetPanel);
    lv_obj_set_style_text_font(ui_LabelSetValue, &lv_font_montserrat_36, 0);
    lv_label_set_text(ui_LabelSetValue, "--.-°C");
    lv_obj_align(ui_LabelSetValue, LV_ALIGN_TOP_MID, 0, 34);

    ui_SliderTarget = lv_slider_create(ui_SetPanel);
    lv_obj_set_width(ui_SliderTarget, LV_PCT(88));
    /* 15.0°C .. 45.0°C in 0.1°C steps */
    lv_slider_set_range(ui_SliderTarget, 150, 450);
    lv_obj_align(ui_SliderTarget, LV_ALIGN_CENTER, 0, -8);
    lv_obj_add_event_cb(ui_SliderTarget, ui_event_slider_target, LV_EVENT_VALUE_CHANGED, NULL);

    /* Button row */
    lv_obj_t *row = lv_obj_create(ui_SetPanel);
    lv_obj_remove_style_all(row);
    lv_obj_set_size(row, LV_PCT(88), LV_SIZE_CONTENT);
    lv_obj_align(row, LV_ALIGN_BOTTOM_MID, 0, -12);
    lv_obj_set_flex_flow(row, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_gap(row, 10, 0);

    ui_BtnCancel = make_btn(row, "Cancel", ui_event_btn_cancel);
    lv_obj_set_size(ui_BtnCancel, LV_PCT(50), 42);

    ui_BtnSave = make_btn(row, "Save", ui_event_btn_save);
    lv_obj_set_size(ui_BtnSave, LV_PCT(50), 42);
}

/************************
 *  BUILD: Options screen
 ************************/
static void build_opts_screen(void) {
    ui_OptsScreen = lv_obj_create(NULL);
    lv_obj_add_style(ui_OptsScreen, &st_bg_dark, 0);

    ui_OptsPanel = lv_obj_create(ui_OptsScreen);
    lv_obj_remove_style_all(ui_OptsPanel);
    lv_obj_set_size(ui_OptsPanel, LV_PCT(100), LV_PCT(100));
    lv_obj_add_style(ui_OptsPanel, &st_card, 0);

    /* Layout */
    lv_obj_set_flex_flow(ui_OptsPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(ui_OptsPanel, 8, 0);
    lv_obj_set_style_pad_all(ui_OptsPanel, 10, 0);

    /* Units switch */
    {
        lv_obj_t *cont = lv_obj_create(ui_OptsPanel);
        lv_obj_remove_style_all(cont);
        lv_obj_set_width(cont, LV_PCT(100));
        lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_gap(cont, 8, 0);

        lv_obj_t *lbl = make_label(cont, "Units (°C/°F)", &st_lbl_sm);
        (void)lbl;

        ui_SwitchUnits = lv_switch_create(cont);
        lv_obj_add_event_cb(ui_SwitchUnits, ui_event_sw_units, LV_EVENT_VALUE_CHANGED, NULL);
        lv_obj_align(ui_SwitchUnits, LV_ALIGN_RIGHT_MID, 0, 0);
    }

    /* Manual override + slider */
    {
        lv_obj_t *cont = lv_obj_create(ui_OptsPanel);
        lv_obj_remove_style_all(cont);
        lv_obj_set_width(cont, LV_PCT(100));
        lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_gap(cont, 8, 0);

        lv_obj_t *lbl = make_label(cont, "Manual override", &st_lbl_sm);
        (void)lbl;

        ui_SwitchManual = lv_switch_create(cont);
        lv_obj_add_event_cb(ui_SwitchManual, ui_event_sw_manual, LV_EVENT_VALUE_CHANGED, NULL);
        lv_obj_align(ui_SwitchManual, LV_ALIGN_RIGHT_MID, 0, 0);

        ui_SliderManual = lv_slider_create(ui_OptsPanel);
        lv_obj_set_width(ui_SliderManual, LV_PCT(100));
        lv_slider_set_range(ui_SliderManual, 0, 100);
        lv_obj_add_event_cb(ui_SliderManual, ui_event_slider_manual, LV_EVENT_VALUE_CHANGED, NULL);
    }

    /* Alarm switch */
    {
        lv_obj_t *cont = lv_obj_create(ui_OptsPanel);
        lv_obj_remove_style_all(cont);
        lv_obj_set_width(cont, LV_PCT(100));
        lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_gap(cont, 8, 0);

        lv_obj_t *lbl = make_label(cont, "Overheat alarm", &st_lbl_sm);
        (void)lbl;

        ui_SwitchAlarm = lv_switch_create(cont);
        lv_obj_add_event_cb(ui_SwitchAlarm, ui_event_sw_alarm, LV_EVENT_VALUE_CHANGED, NULL);
        lv_obj_align(ui_SwitchAlarm, LV_ALIGN_RIGHT_MID, 0, 0);
    }

    /* Back button */
    ui_BtnBack = make_btn(ui_OptsPanel, "Back", ui_event_btn_back);
    lv_obj_set_size(ui_BtnBack, LV_PCT(100), 42);
}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void TempIdea_init_gen(const char *asset_path) {
    (void)asset_path;

    styles_init();

    build_main_screen();
    build_set_screen();
    build_opts_screen();

    /* Load main screen by default.
     * Your app can switch via lv_scr_load(ui_SetScreen) / ui_OptsScreen. */
    lv_scr_load(ui_MainScreen);
}

/**********************
 *   END OF FILE
 **********************/
