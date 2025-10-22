/**
 * @file TempIdea_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "TempIdea_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Global styles
 *----------------*/

lv_style_t st_bg_dark;
lv_style_t st_lbl_big;
lv_style_t st_lbl_sm;
lv_style_t st_card;
lv_style_t st_btn_primary;

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_m20;
extern uint8_t Montserrat_Regular_ttf_data[];
extern size_t Montserrat_Regular_ttf_data_size;
lv_font_t * font_m36;
lv_font_t * font_m48;

/*----------------
 * Images
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_temp_c;
lv_subject_t subject_target_c;
lv_subject_t subject_fan_duty;
lv_subject_t subject_units;
lv_subject_t subject_manual_override;
lv_subject_t subject_manual_duty;
lv_subject_t subject_alarm_enabled;
lv_subject_t subject_alarm_high_c;
lv_subject_t subject_cal_offset_c;
lv_subject_t subject_brightness_pct;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void TempIdea_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&st_bg_dark);
        lv_style_set_bg_color(&st_bg_dark, COL_BG_DARK);
        lv_style_set_bg_opa(&st_bg_dark, (255 * 100 / 100));

        lv_style_init(&st_lbl_big);
        lv_style_set_text_color(&st_lbl_big, COL_TEXT);
        lv_style_set_text_font(&st_lbl_big, font_m48);

        lv_style_init(&st_lbl_sm);
        lv_style_set_text_color(&st_lbl_sm, COL_TEXT_SM);
        lv_style_set_text_font(&st_lbl_sm, font_m20);

        lv_style_init(&st_card);
        lv_style_set_bg_color(&st_card, COL_CARD);
        lv_style_set_bg_opa(&st_card, (255 * 100 / 100));
        lv_style_set_pad_all(&st_card, PAD_MD);
        lv_style_set_radius(&st_card, RADIUS_MD);
        lv_style_set_border_color(&st_card, COL_BORDER);
        lv_style_set_border_width(&st_card, 1);

        lv_style_init(&st_btn_primary);
        lv_style_set_pad_all(&st_btn_primary, PAD_MD);
        lv_style_set_radius(&st_btn_primary, RADIUS_MD);
        lv_style_set_bg_color(&st_btn_primary, lv_color_hex(0x2F87FF));
        lv_style_set_bg_opa(&st_btn_primary, (255 * 100 / 100));
        lv_style_set_text_color(&st_btn_primary, lv_color_hex(0xFFFFFF));
        lv_style_set_text_font(&st_btn_primary, font_m20);

        style_inited = true;
    }

    /*----------------
     * Fonts
     *----------------*/

    /* create tiny ttf font 'font_m20' from C array */
    font_m20 = lv_tiny_ttf_create_data(Montserrat_Regular_ttf_data, Montserrat_Regular_ttf_data_size, 20);
    /* create tiny ttf font 'font_m36' from C array */
    font_m36 = lv_tiny_ttf_create_data(Montserrat_Regular_ttf_data, Montserrat_Regular_ttf_data_size, 36);
    /* create tiny ttf font 'font_m48' from C array */
    font_m48 = lv_tiny_ttf_create_data(Montserrat_Regular_ttf_data, Montserrat_Regular_ttf_data_size, 48);


    /*----------------
     * Images
     *----------------*/
    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&subject_temp_c, 275);
    lv_subject_init_int(&subject_target_c, 300);
    lv_subject_init_int(&subject_fan_duty, 20);
    lv_subject_init_int(&subject_units, 0);
    lv_subject_init_int(&subject_manual_override, 0);
    lv_subject_init_int(&subject_manual_duty, 60);
    lv_subject_init_int(&subject_alarm_enabled, 1);
    lv_subject_init_int(&subject_alarm_high_c, 450);
    lv_subject_init_int(&subject_cal_offset_c, 0);
    lv_subject_init_int(&subject_brightness_pct, 100);

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */
    lv_xml_register_font(NULL, "font_m20", font_m20);
    lv_xml_register_font(NULL, "font_m36", font_m36);
    lv_xml_register_font(NULL, "font_m48", font_m48);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_temp_c", &subject_temp_c);
    lv_xml_register_subject(NULL, "subject_target_c", &subject_target_c);
    lv_xml_register_subject(NULL, "subject_fan_duty", &subject_fan_duty);
    lv_xml_register_subject(NULL, "subject_units", &subject_units);
    lv_xml_register_subject(NULL, "subject_manual_override", &subject_manual_override);
    lv_xml_register_subject(NULL, "subject_manual_duty", &subject_manual_duty);
    lv_xml_register_subject(NULL, "subject_alarm_enabled", &subject_alarm_enabled);
    lv_xml_register_subject(NULL, "subject_alarm_high_c", &subject_alarm_high_c);
    lv_xml_register_subject(NULL, "subject_cal_offset_c", &subject_cal_offset_c);
    lv_xml_register_subject(NULL, "subject_brightness_pct", &subject_brightness_pct);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/