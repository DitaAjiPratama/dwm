/* See LICENSE file for copyright and license details. */

static const unsigned int borderpx  = 2;
static const unsigned int snap      = 32;
static const int showbar            = 1;
static const int topbar             = 1;
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";

static const char col_blue1[]       = "#102D4F";
static const char col_blue2[]       = "#00537A";
static const char col_yellow1[]     = "#F5A201";
static const char col_yellow2[]     = "#FFBA42";
static const char col_blush[]       = "#F8E5EE";

static const char *colors[][3]      = {
	/* fg, bg, border */
	[SchemeNorm] = { col_blush, col_blue1,   col_blue1   },
	[SchemeSel]  = { col_blue1, col_yellow1, col_yellow2 },
};

static const char *tags[] = { "1", "2", "3", "4", "5" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_blue2, "-nf", col_blush, "-sb", col_yellow2, "-sf", col_blue1, NULL };
static const char *termcmd[]  = { "konsole", NULL };
static const char *filecmd[]  = { "dolphin", NULL };

#include "shiftview.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
        { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
        { MODKEY,                       XK_k,      spawn,          {.v = termcmd } },
        { MODKEY,                       XK_e,      spawn,          {.v = filecmd } },

        { MODKEY,                       XK_b,      togglebar,      {0} },

        { MODKEY,                       XK_Prior,  focusstack,     {.i = -1 } },
        { MODKEY,                       XK_Next,   focusstack,     {.i = +1 } },
        { MODKEY,                       XK_Return, zoom,           {0} },

        { MODKEY|ControlMask,           XK_Left,   shiftview,      {.i = -1 } },
        { MODKEY|ControlMask,           XK_Right,  shiftview,      {.i = +1 } },
        TAGKEYS(                        XK_1,                      0)
        TAGKEYS(                        XK_2,                      1)
        TAGKEYS(                        XK_3,                      2)
        TAGKEYS(                        XK_4,                      3)
        TAGKEYS(                        XK_5,                      4)

        { MODKEY,                       XK_q,      killclient,     {0} },
        { MODKEY|ShiftMask,             XK_q,      quit,           {0} },

        { MODKEY|Mod1Mask,              XK_Up,     incnmaster,     {.i = +1 } },
        { MODKEY|Mod1Mask,              XK_Down,   incnmaster,     {.i = -1 } },
        { MODKEY|Mod1Mask,              XK_Left,   setmfact,       {.f = -0.05} },
        { MODKEY|Mod1Mask,              XK_Right,  setmfact,       {.f = +0.05} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

