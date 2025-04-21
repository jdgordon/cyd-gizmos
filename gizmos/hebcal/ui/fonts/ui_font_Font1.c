/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font C:/Users/Jonathan/SquareLine/assets/Provokateur DEMO.otf -o C:/Users/Jonathan/SquareLine/assets\ui_font_Font1.c --format lvgl -r 0x20-0x3f -r 0x5b-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT1
#define UI_FONT_FONT1 1
#endif

#if UI_FONT_FONT1

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0x40,

    /* U+0022 "\"" */
    0xb6, 0xdb, 0x40,

    /* U+0023 "#" */
    0x44, 0x44, 0x44, 0xfe, 0x44, 0x44, 0x44, 0xfe,
    0x44, 0x44, 0x44,

    /* U+0024 "$" */
    0x20, 0x83, 0xbe, 0x82, 0xf, 0x82, 0x9, 0xe6,
    0x8,

    /* U+0025 "%" */
    0x71, 0x1a, 0x22, 0x48, 0x49, 0x9, 0x20, 0xeb,
    0x81, 0x50, 0x29, 0x9, 0x21, 0x28, 0x27, 0x0,

    /* U+0026 "&" */
    0x78, 0x68, 0x28, 0x30, 0x37, 0x75, 0xcd, 0x8d,
    0x87, 0xc6, 0x7e, 0x1,

    /* U+0027 "'" */
    0xfc,

    /* U+0028 "(" */
    0x5, 0xad, 0x24, 0x92, 0x26,

    /* U+0029 ")" */
    0x89, 0x92, 0x49, 0x2d, 0x68,

    /* U+002A "*" */
    0x10, 0x20, 0x47, 0xf3, 0x85, 0x1b, 0x2,

    /* U+002B "+" */
    0x0, 0x20, 0x47, 0xf1, 0x83, 0x4, 0x0,

    /* U+002C "," */
    0x5c,

    /* U+002D "-" */
    0x78,

    /* U+002E "." */
    0x70,

    /* U+002F "/" */
    0x18, 0x84, 0x62, 0x11, 0x8, 0x46, 0x20,

    /* U+0030 "0" */
    0x7f, 0xe3, 0x18, 0xc6, 0x31, 0x8c, 0x5c,

    /* U+0031 "1" */
    0xd5, 0x55, 0x54,

    /* U+0032 "2" */
    0x78, 0x8, 0x10, 0x20, 0x4f, 0x98, 0x20, 0x40,
    0x81, 0xf8,

    /* U+0033 "3" */
    0xfc, 0x6, 0x2, 0x2, 0x6, 0x3c, 0x2, 0x3,
    0x2, 0x6, 0x7c,

    /* U+0034 "4" */
    0x81, 0x2, 0x4, 0x8, 0x50, 0xa1, 0x7f, 0x4,
    0x8, 0x10,

    /* U+0035 "5" */
    0xfd, 0x2, 0x4, 0xf, 0xc0, 0x40, 0x83, 0x7c,

    /* U+0036 "6" */
    0x79, 0x82, 0x4, 0x8, 0x10, 0x3f, 0x41, 0x83,
    0xd, 0xf0,

    /* U+0037 "7" */
    0xfc, 0x30, 0x82, 0x8, 0x61, 0x4, 0x20, 0x80,

    /* U+0038 "8" */
    0x7e, 0x43, 0x41, 0x43, 0x7f, 0x43, 0x81, 0x81,
    0x81, 0x83, 0xfe,

    /* U+0039 "9" */
    0x7e, 0xc3, 0x81, 0x81, 0x81, 0x83, 0x7e, 0x2,
    0x4, 0x4, 0x8,

    /* U+003A ":" */
    0x50, 0xc0,

    /* U+003B ";" */
    0x41, 0x70,

    /* U+003C "<" */
    0x8, 0xcc, 0x44, 0x61, 0x4, 0x10, 0xc0,

    /* U+003D "=" */
    0xf8, 0x3e,

    /* U+003E ">" */
    0x43, 0x8, 0x61, 0xc, 0x62, 0x23, 0x10,

    /* U+003F "?" */
    0xf0, 0x20, 0x41, 0xc, 0x63, 0x8, 0x0, 0x2,
    0x0,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x60,

    /* U+005C "\\" */
    0x86, 0x10, 0x82, 0x10, 0x86, 0x10, 0x86,

    /* U+005D "]" */
    0x64, 0x92, 0x49, 0x24, 0xb4,

    /* U+005E "^" */
    0x30, 0xc3, 0x92, 0x49, 0x3c, 0xc0,

    /* U+005F "_" */
    0x78,

    /* U+0060 "`" */
    0xcc,

    /* U+0061 "a" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc1, 0x83,
    0x6, 0x8,

    /* U+0062 "b" */
    0xc3, 0xe9, 0xa6, 0xfb, 0x78, 0xe1, 0x86, 0x3f,
    0x80,

    /* U+0063 "c" */
    0x39, 0x8, 0x20, 0x82, 0x8, 0x20, 0xc3, 0xf7,
    0xc0,

    /* U+0064 "d" */
    0xf9, 0xfa, 0x34, 0x28, 0x50, 0xa1, 0xc2, 0x85,
    0x1b, 0xe0,

    /* U+0065 "e" */
    0xfc, 0x21, 0x8, 0x7a, 0x10, 0x84, 0x3e,

    /* U+0066 "f" */
    0xfc, 0x21, 0x8, 0x7f, 0xf0, 0x84, 0x20,

    /* U+0067 "g" */
    0x1c, 0x41, 0x2, 0x4, 0x8, 0x33, 0xe1, 0x46,
    0xfc,

    /* U+0068 "h" */
    0x83, 0x6, 0xf, 0xf8, 0x30, 0x60, 0xc1, 0x83,
    0x6, 0x0,

    /* U+0069 "i" */
    0xff, 0xe0,

    /* U+006A "j" */
    0x11, 0x11, 0x11, 0x19, 0x9f, 0x60,

    /* U+006B "k" */
    0x89, 0x22, 0xc5, 0xe, 0x18, 0x38, 0x58, 0x99,
    0x1a, 0x18,

    /* U+006C "l" */
    0x88, 0x88, 0x88, 0x88, 0x88, 0xf0,

    /* U+006D "m" */
    0xc1, 0xf0, 0xf8, 0xb6, 0xdb, 0xcc, 0xc6, 0x23,
    0x1, 0x80, 0xc0, 0x60, 0x20,

    /* U+006E "n" */
    0xc3, 0x87, 0x8d, 0x1b, 0x32, 0x66, 0xc5, 0x8f,
    0xe, 0x18,

    /* U+006F "o" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x7, 0xf8,

    /* U+0070 "p" */
    0xfd, 0xe, 0x1c, 0x38, 0x71, 0xbe, 0x40, 0x81,
    0x2, 0x0,

    /* U+0071 "q" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0xa6, 0x9f,
    0xd0, 0x78,

    /* U+0072 "r" */
    0xfa, 0x38, 0xe3, 0xfa, 0xcb, 0x34, 0xdb, 0x2c,
    0xc0,

    /* U+0073 "s" */
    0x7c, 0x82, 0x4, 0xc, 0xf, 0x81, 0x81, 0x2,
    0xf, 0xe0,

    /* U+0074 "t" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x40,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x7, 0xf8,

    /* U+0076 "v" */
    0xc1, 0x41, 0x43, 0x62, 0x62, 0x24, 0x24, 0x3c,
    0x18, 0x18, 0x18,

    /* U+0077 "w" */
    0x0, 0x50, 0x14, 0x5, 0x1, 0x48, 0x53, 0x15,
    0xe5, 0x49, 0x73, 0x5c, 0x5e, 0xf, 0x83,

    /* U+0078 "x" */
    0x60, 0x88, 0x63, 0x30, 0x68, 0xe, 0x3, 0x1,
    0xc0, 0x58, 0x23, 0x18, 0x44, 0x18,

    /* U+0079 "y" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff,
    0x10, 0x10, 0x10, 0x10,

    /* U+007A "z" */
    0x7f, 0x3, 0x6, 0x4, 0xc, 0x18, 0x10, 0x30,
    0x60, 0x40, 0xff,

    /* U+007B "{" */
    0x32, 0x22, 0x22, 0xe2, 0x22, 0x22, 0x30,

    /* U+007C "|" */
    0xff, 0xe0,

    /* U+007D "}" */
    0xe, 0x22, 0x22, 0x23, 0x24, 0x22, 0x4c,

    /* U+007E "~" */
    0x0, 0xe2, 0xb2, 0x92, 0x93, 0x92, 0x8e
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 88, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 35, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 3, .adv_w = 74, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 6, .adv_w = 138, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 99, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 26, .adv_w = 182, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 144, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 54, .adv_w = 40, .box_w = 1, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 55, .adv_w = 62, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 60, .adv_w = 68, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 65, .adv_w = 110, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 72, .adv_w = 111, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 79, .adv_w = 39, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 80, .adv_w = 89, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 81, .adv_w = 35, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 75, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 107, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 55, .box_w = 2, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 114, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 130, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 126, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 130, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 138, .adv_w = 119, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 102, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 156, .adv_w = 148, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 138, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 36, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 180, .adv_w = 40, .box_w = 2, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 90, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 189, .adv_w = 96, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 191, .adv_w = 83, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 100, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 54, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 212, .adv_w = 75, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 55, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 224, .adv_w = 98, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 230, .adv_w = 89, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 231, .adv_w = 46, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 232, .adv_w = 130, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 242, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 118, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 99, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 94, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 118, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 40, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 86, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 311, .adv_w = 135, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 79, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 327, .adv_w = 170, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 340, .adv_w = 132, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 133, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 118, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 124, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 380, .adv_w = 111, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 389, .adv_w = 125, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 399, .adv_w = 107, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 409, .adv_w = 125, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 136, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 172, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 445, .adv_w = 158, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 140, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 471, .adv_w = 130, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 69, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 489, .adv_w = 37, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 491, .adv_w = 69, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 498, .adv_w = 133, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 32, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 91, .range_length = 36, .glyph_id_start = 33,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    21, 18,
    21, 24,
    49, 60,
    49, 63,
    50, 8,
    50, 58,
    50, 63,
    54, 13,
    54, 15,
    58, 13,
    58, 15,
    58, 27,
    58, 28,
    58, 41,
    58, 45,
    58, 48,
    60, 13,
    60, 15,
    60, 48,
    63, 13,
    63, 15
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -11, -11, -14, -10, -29, -14, -3, -29,
    -25, -29, -22, -22, -22, -10, -10, -20,
    -29, -25, -13, -26, -18
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 21,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Font1 = {
#else
lv_font_t ui_font_Font1 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONT1*/

