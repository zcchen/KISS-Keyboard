#include "KeyMatrix.h"

/*Normal key map setting*/
#define N_col0 { \
    KEYCODE_ESCAPE,                     KEYCODE_1_AND_EXCLAMATION,         \
    KEYCODE_2_AND_AT,                   KEYCODE_3_AND_HASHMARK,            \
    KEYCODE_4_AND_DOLLAR,               KEYCODE_5_AND_PERCENTAGE,          \
    KEYCODE_6_AND_CARET,                KEYCODE_7_AND_AND_AMPERSAND,       \
    KEYCODE_8_AND_ASTERISK,             KEYCODE_9_AND_OPENING_PARENTHESIS, \
    KEYCODE_0_AND_CLOSING_PARENTHESIS,  KEYCODE_MINUS_AND_UNDERSCORE,      \
    KEYCODE_EQUAL_AND_PLUS,             KEYCODE_BACKSLASH_AND_PIPE,        \
    KEYCODE_GRAVE_ACCENT_AND_TILDE,     KEYCODE_NONE,                      \
}
#define N_col1 { \
    KEYCODE_TAB,    KEYCODE_Q,      KEYCODE_W,      KEYCODE_E,      \
    KEYCODE_R,      KEYCODE_T,      KEYCODE_Y,      KEYCODE_U,      \
    KEYCODE_I,      KEYCODE_O,                                      \
    KEYCODE_P,      KEYCODE_OPENING_BRACKET_AND_OPENING_BRACE,      \
    KEYCODE_CLOSING_BRACKET_AND_CLOSING_BRACE,      KEYCODE_NONE,   \
    KEYCODE_BACKSPACE,              KEYCODE_NONE,                   \
}
#define N_col2 { \
    KEYCODE_LEFT_CONTROL,   KEYCODE_A,   KEYCODE_S,  KEYCODE_D,         \
    KEYCODE_F,              KEYCODE_G,   KEYCODE_H,  KEYCODE_J,         \
    KEYCODE_K,              KEYCODE_L,                                  \
    KEYCODE_SEMICOLON_AND_COLON,    KEYCODE_APOSTROPHE_AND_QUOTE,       \
    KEYCODE_NONE,                   KEYCODE_ENTER,                      \
    KEYCODE_NONE,                   KEYCODE_NONE,                       \
}
#define N_col3 { \
    KEYCODE_LEFT_SHIFT, KEYCODE_Z,      KEYCODE_X,      KEYCODE_C,         \
    KEYCODE_V,          KEYCODE_B,      KEYCODE_N,      KEYCODE_M,         \
    KEYCODE_COMMA_AND_LESS_THAN_SIGN,   KEYCODE_DOT_AND_GREATER_THAN_SIGN, \
    KEYCODE_SLASH_AND_QUESTION_MARK,    KEYCODE_NONE,                      \
    KEYCODE_RIGHT_SHIFT,                KEYCODE_NONE,                      \
    KEYCODE_Fn_KEY,                     KEYCODE_NONE,                      \
}
#define N_col4 { \
    KEYCODE_NONE,   KEYCODE_LEFT_ALT,   KEYCODE_LEFT_GUI,   KEYCODE_NONE,   \
    KEYCODE_SPACE,  KEYCODE_NONE,       KEYCODE_ENTER,      KEYCODE_NONE,   \
    KEYCODE_RIGHT_ALT,                  KEYCODE_RIGHT_GUI,                  \
    KEYCODE_NONE,                       KEYCODE_RIGHT_CONTROL,              \
    KEYCODE_NONE,   KEYCODE_NONE,       KEYCODE_NONE,       KEYCODE_NONE,   \
}
#define N_col5 {}

/*Function key map setting*/
#define F_col0 {}
#define F_col1 {}
#define F_col2 {}
#define F_col3 {}
#define F_col4 {}
#define F_col5 {}

struct KeySwitchStr KeySwitch0 = \
                 KeySwitchDef(2, 0, 0, KEYCODE_CAPS_LOCK);

uint8_t N_KeyMatrix[detectLinesNum][scanLinesNum] = {
    N_col0,  N_col1,  N_col2,  N_col3,  N_col4,  N_col5
};

uint8_t F_KeyMatrix[detectLinesNum][scanLinesNum] = {
    F_col0,  F_col1,  F_col2,  F_col3,  F_col4,  F_col5
};

struct KeySwitchStr* KeySwitchesPtr[10] = {
    &KeySwitch0,
};

