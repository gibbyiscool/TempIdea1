/**
 * @file TempIdea_gen.h
 * @brief Auto-generated UI header (extended) for TempIdea.
 *
 * Exposes LVGL object handles so application code (TempIdea.c)
 * can update labels, attach event callbacks, and switch screens.
 */

#ifndef TEMPIDEA_GEN_H
#define TEMPIDEA_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
  #include "lvgl.h"
#else
  #include "lvgl/lvgl.h"
#endif

/**********************
 * GLOBAL OBJECTS
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/* Main (Idle) screen */
extern lv_obj_t *ui_MainScreen;
extern lv_obj_t *ui_MainPanel;        /* full-screen touch area */
extern lv_obj_t *ui_LabelTempBig;     /* current interior temp (big) */
extern lv_obj_t *ui_LabelFan;         /* fan duty e.g., "45%" */
extern lv_obj_t *ui_LabelTargetSmall; /* "Target: 30.0°C" */

/* Set Target screen */
extern lv_obj_t *ui_SetScreen;
extern lv_obj_t *ui_SetPanel;
extern lv_obj_t *ui_LabelSetTitle;    /* "Set Target" */
extern lv_obj_t *ui_LabelSetValue;    /* current slider value text */
extern lv_obj_t *ui_SliderTarget;     /* 15.0°C .. 45.0°C (0.1°C steps) */
extern lv_obj_t *ui_BtnSave;
extern lv_obj_t *ui_BtnCancel;

/* Options screen (long-press) */
extern lv_obj_t *ui_OptsScreen;
extern lv_obj_t *ui_OptsPanel;
extern lv_obj_t *ui_SwitchUnits;      /* °C/°F */
extern lv_obj_t *ui_SwitchManual;     /* manual override on/off */
extern lv_obj_t *ui_SliderManual;     /* manual duty 0..100% */
extern lv_obj_t *ui_SwitchAlarm;      /* over-temp alarm enable */
extern lv_obj_t *ui_BtnBack;

/*----------------
 * Global styles / fonts / images
 * (declare here if your generator exposes them)
 *----------------*/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * @brief Initialize all generated UI objects.
 * @param asset_path Optional path to images/fonts; pass NULL if not used.
 */
void TempIdea_init_gen(const char *asset_path);

/*----------------
 * Event Callbacks (to be attached by app code)
 *----------------*/

/* Main panel: handles tap vs long-press */
void ui_event_main_panel(lv_event_t *e);

/* Set Target */
void ui_event_slider_target(lv_event_t *e);
void ui_event_btn_save(lv_event_t *e);
void ui_event_btn_cancel(lv_event_t *e);

/* Options */
void ui_event_sw_units(lv_event_t *e);
void ui_event_sw_manual(lv_event_t *e);
void ui_event_slider_manual(lv_event_t *e);
void ui_event_sw_alarm(lv_event_t *e);
void ui_event_btn_back(lv_event_t *e);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* TEMPIDEA_GEN_H */
