#ifdef _WINDOW_CONFIG

/* default window dimensions (overwritten via -g option): */
enum {
	WIN_WIDTH  = 1800,
	WIN_HEIGHT = 1000
};

/* bar font:
 * (see fonts-conf(5) subsection "FONT NAMES" for valid values)
 */
static const char * const BAR_FONT = "UW Ttyp0:size=9";

/* colors:
 * (see X(7) section "COLOR NAMES" for valid values)
 */
static const char * const WIN_BG_COLOR = "#000000";
static const char * const WIN_FS_COLOR = "#000000";
static const char * const SEL_COLOR    = "#EEEEEE";
static const char * const BAR_BG_COLOR = "#191919";
static const char * const BAR_FG_COLOR = "#EEEEEE";

#endif
#ifdef _IMAGE_CONFIG

/* levels (in percent) to use when zooming via '-' and '+':
 * (first/last value is used as min/max zoom level)
 */
static const float zoom_levels[] = {
    10, 10.5, 11.03, 11.58, 12.16, 12.76, 13.4, 14.07, 14.77, 15.51, 16.29, 17.1, 17.96, 18.86, 19.8, 20.79, 21.83, 22.92, 24.07, 25.27, 26.53, 27.86, 29.25, 30.72, 32.25, 33.86, 35.56, 37.33, 39.2, 41.16, 43.22, 45.38, 47.65, 50.03, 52.53, 55.16, 57.92, 60.81, 63.85, 67.05, 70.4, 73.92, 77.62, 81.5, 85.57, 89.85, 94.34, 100.00, 104.01, 109.21, 114.67, 120.41, 126.43, 132.75, 139.39, 146.36, 153.67, 161.36, 169.43, 177.9, 186.79, 196.13, 200.0, 216.23, 227.05, 238.4, 250.32, 262.83, 275.98, 289.78, 300.00, 319.48, 335.45, 352.22, 369.84, 388.33, 400.00, 428.13, 449.54, 472.01, 495.61, 520.4, 546.41, 573.74, 602.42, 632.54, 664.17, 697.38, 732.25, 768.86, 807.3, 847.67, 890.05, 934.55, 981.28
};

/* default slideshow delay (in sec, overwritten via -S option): */
enum { SLIDESHOW_DELAY = 5 };

/* gamma correction: the user-visible ranges [-GAMMA_RANGE, 0] and
 * (0, GAMMA_RANGE] are mapped to the ranges [0, 1], and (1, GAMMA_MAX].
 * */
static const double GAMMA_MAX   = 10.0;
static const int    GAMMA_RANGE = 32;

/* command i_scroll pans image 1/PAN_FRACTION of screen width/height */
static const int PAN_FRACTION = 10;

/* if false, pixelate images at zoom level != 100%,
 * toggled with 'a' key binding
 */
static const bool ANTI_ALIAS = true;

/* if true, use a checkerboard background for alpha layer,
 * toggled with 'A' key binding
 */
static const bool ALPHA_LAYER = false;

#endif
#ifdef _THUMBS_CONFIG

/* thumbnail sizes in pixels (width == height): */
static const int thumb_sizes[] = { 32, 64, 96, 128, 160, 192, 254, 368 };

/* thumbnail size at startup, index into thumb_sizes[]: */
static const int THUMB_SIZE = 3;

#endif
#ifdef _MAPPINGS_CONFIG

/* keyboard mappings for image and thumbnail mode: */
static const keymap_t keys[] = {
	/* modifiers    key               function              argument */
	{ 0,            XK_q,             g_quit,               None },
	{ 0,            XK_Return,        g_switch_mode,        None },
	{ 0,            XK_f,             g_toggle_fullscreen,  None },
	{ 0,            XK_b,             g_toggle_bar,         None },
	{ ControlMask,  XK_x,             g_prefix_external,    None },
	{ 0,            XK_g,             g_first,              None },
	{ 0,            XK_G,             g_n_or_last,          None },
	{ 0,            XK_r,             g_reload_image,       None },
	{ 0,            XK_D,             g_remove_image,       None },
	{ ControlMask,  XK_Left,          g_scroll_screen,      DIR_LEFT },
	{ ControlMask,  XK_Down,          g_scroll_screen,      DIR_DOWN },
	{ ControlMask,  XK_Up,            g_scroll_screen,      DIR_UP },
	{ ControlMask,  XK_Right,         g_scroll_screen,      DIR_RIGHT },
	{ 0,            XK_plus,          g_zoom,               +1 },
	{ 0,            XK_KP_Add,        g_zoom,               +1 },
	{ 0,            XK_minus,         g_zoom,               -1 },
	{ 0,            XK_KP_Subtract,   g_zoom,               -1 },
	{ 0,            XK_m,             g_toggle_image_mark,  None },
	{ 0,            XK_M,             g_reverse_marks,      None },
	{ ControlMask,  XK_m,             g_unmark_all,         None },
	{ 0,            XK_C,             g_navigate_marked,    +1 },
	{ 0,            XK_P,             g_navigate_marked,    -1 },
	{ 0,            XK_braceleft,     g_change_gamma,       -1 },
	{ 0,            XK_braceright,    g_change_gamma,       +1 },
	{ ControlMask,  XK_g,             g_change_gamma,        0 },

	{ 0,            XK_y,             t_move_sel,           DIR_LEFT },
	{ 0,            XK_Left,          t_move_sel,           DIR_LEFT },
	{ 0,            XK_n,             t_move_sel,           DIR_DOWN },
	{ 0,            XK_Down,          t_move_sel,           DIR_DOWN },
	{ 0,            XK_e,             t_move_sel,           DIR_UP },
	{ 0,            XK_Up,            t_move_sel,           DIR_UP },
	{ 0,            XK_o,             t_move_sel,           DIR_RIGHT },
	{ 0,            XK_Right,         t_move_sel,           DIR_RIGHT },
	{ 0,            XK_R,             t_reload_all,         None },

	{ ControlMask,  XK_n,             i_navigate,           +1 },
	{ 0,            XK_space,         i_navigate,           +1 },
	{ ControlMask,  XK_p,             i_navigate,           -1 },
	{ 0,            XK_BackSpace,     i_navigate,           -1 },
	{ ControlMask,  XK_6,             i_alternate,          None },
	{ 0,            XK_period,        i_navigate_frame,     +1 },
	{ 0,            XK_comma,         i_navigate_frame,     -1 },
	{ ControlMask,  XK_space,         i_toggle_animation,   None },
	{ 0,            XK_y,             i_scroll,             DIR_LEFT },
	{ 0,            XK_Left,          i_scroll,             DIR_LEFT },
	{ 0,            XK_n,             i_scroll,             DIR_DOWN },
	{ 0,            XK_Down,          i_scroll,             DIR_DOWN },
	{ 0,            XK_e,             i_scroll,             DIR_UP },
	{ 0,            XK_Up,            i_scroll,             DIR_UP },
	{ 0,            XK_o,             i_scroll,             DIR_RIGHT },
	{ 0,            XK_Right,         i_scroll,             DIR_RIGHT },
	{ 0,            XK_Y,             i_scroll_to_edge,     DIR_LEFT },
	{ 0,            XK_N,             i_scroll_to_edge,     DIR_DOWN },
	{ 0,            XK_E,             i_scroll_to_edge,     DIR_UP },
	{ 0,            XK_O,             i_scroll_to_edge,     DIR_RIGHT },
	{ 0,            XK_equal,         i_set_zoom,           100 },
	{ 0,            XK_w,             i_fit_to_win,         SCALE_DOWN },
	{ 0,            XK_W,             i_fit_to_win,         SCALE_FIT },
	{ 0,            XK_s,             i_fit_to_win,         SCALE_WIDTH },
	{ 0,            XK_S,             i_fit_to_win,         SCALE_HEIGHT },
	{ 0,            XK_less,          i_rotate,             DEGREE_270 },
	{ 0,            XK_greater,       i_rotate,             DEGREE_90 },
	{ ShiftMask,    XK_Left,          i_rotate,             DEGREE_270 },
	{ ShiftMask,    XK_Right,         i_rotate,             DEGREE_90 },
	{ 0,            XK_question,      i_rotate,             DEGREE_180 },
	{ 0,            XK_bar,           i_flip,               FLIP_HORIZONTAL },
	{ 0,            XK_underscore,    i_flip,               FLIP_VERTICAL },
	{ 0,            XK_a,             i_toggle_antialias,   None },
	{ 0,            XK_A,             i_toggle_alpha,       None },
	{ ControlMask,  XK_s,             i_slideshow,          None },
};

/* mouse button mappings for image mode: */
static const button_t buttons[] = {
	/* modifiers    button            function              argument */
	{ 0,            1,                i_cursor_navigate,    None },
	{ 0,            2,                i_drag,               DRAG_ABSOLUTE },
	{ 0,            3,                g_toggle_fullscreen,  None },
	{ 0,            11,               g_quit,               None },
	{ ShiftMask,    4,                i_navigate,           -1 },
	{ ShiftMask,    5,                i_navigate,           +1 },
	{ 0,            4,                g_zoom,               +1 },
	{ 0,            5,                g_zoom,               -1 },
};

#endif
