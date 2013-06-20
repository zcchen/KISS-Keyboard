#include "KeyMatrix.h"

/*Normal key map setting*/
#define N_col0 { \
    KEYCODE_ESCAPE,                     KEYCODE_1_AND_EXCLAMATION,          \
    KEYCODE_2_AND_AT,                   KEYCODE_3_AND_HASHMARK,             \
    KEYCODE_4_AND_DOLLAR,               KEYCODE_5_AND_PERCENTAGE,           \
    KEYCODE_6_AND_CARET,                KEYCODE_7_AND_AND_AMPERSAND,        \
    KEYCODE_8_AND_ASTERISK,             KEYCODE_9_AND_OPENING_PARENTHESIS,  \
    KEYCODE_0_AND_CLOSING_PARENTHESIS,  KEYCODE_MINUS_AND_UNDERSCORE,       \
    KEYCODE_EQUAL_AND_PLUS,             KEYCODE_GRAVE_ACCENT_AND_TILDE,     \
    KEYCODE_BACKSPACE,                  KEYCODE_NONE,                       \
}
#define N_col1 { \
    KEYCODE_TAB,    KEYCODE_NONE,   KEYCODE_Q,      KEYCODE_W,      \
    KEYCODE_E,      KEYCODE_R,      KEYCODE_T,      KEYCODE_Y,      \
    KEYCODE_U,      KEYCODE_I,      KEYCODE_O,      KEYCODE_P,      \
    KEYCODE_OPENING_BRACKET_AND_OPENING_BRACE,                      \
    KEYCODE_CLOSING_BRACKET_AND_CLOSING_BRACE,                      \
    KEYCODE_BACKSLASH_AND_PIPE,                     KEYCODE_NONE,   \
}
#define N_col2 { \
    KEYCODE_CAPS_LOCK,  KEYCODE_NONE,   \
}
#define N_col3 {}
#define N_col4 {}
#define N_col5 {}

/*Function key map setting*/
#define F_col0 {}
#define F_col1 {}
#define F_col2 {}
#define F_col3 {}
#define F_col4 {}
#define F_col5 {}

KeySwitchStr KeySwitch0 = {
    .detectLineNum      = 2,
    .scanLineNum        = 0,
    .KeyMatrixLayout    = 0,
    .KeycodeNew         = KEYCODE_LEFT_CONTROL,
};

uint8_t N_KeyMatrix[detectLines][scanLines] = {
    N_col0,  N_col1,  N_col2,  N_col3,  N_col4,  N_col5
};

uint8_t F_KeyMatrix[detectLines][scanLines] = {
    F_col0,  F_col1,  F_col2,  F_col3,  F_col4,  F_col5
};

KeySwitchStr* KeySwitchesPtr[10] = {
    &KeySwitch0,
};
