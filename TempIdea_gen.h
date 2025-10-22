/**
 * @file TempIdea_gen.h
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

/*********************
 *      DEFINES
 *********************/

#define COL_BG_DARK lv_color_hex(0x111111)

#define COL_CARD lv_color_hex(0x1C1C1C)

#define COL_BORDER lv_color_hex(0x2A2A2A)

#define COL_TEXT lv_color_hex(0xFFFFFF)

#define COL_TEXT_SM lv_color_hex(0xE0E0E0)

#define PAD_MD 8

#define PAD_LG 10

#define RADIUS_MD 8

#define LONG_PRESS_MS 700

#define IDLE_DIM_S 30

#define TARGET_MIN_TENTHSC 150

#define TARGET_MAX_TENTHSC 450

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t st_bg_dark;
extern lv_style_t st_lbl_big;
extern lv_style_t st_lbl_sm;
extern lv_style_t st_card;
extern lv_style_t st_btn_primary;

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * font_m20;

extern lv_font_t * font_m36;

extern lv_font_t * font_m48;

/*----------------
 * Images
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_temp_c;
extern lv_subject_t subject_target_c;
extern lv_subject_t subject_fan_duty;
extern lv_subject_t subject_units;
extern lv_subject_t subject_manual_override;
extern lv_subject_t subject_manual_duty;
extern lv_subject_t subject_alarm_enabled;
extern lv_subject_t subject_alarm_high_c;
extern lv_subject_t subject_cal_offset_c;
extern lv_subject_t subject_brightness_pct;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void TempIdea_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*TEMPIDEA_GEN_H*/