﻿#ifndef DEF_ICE_INPUT
#define DEF_ICE_INPUT

#include "TypesCore.h"

/**
 * \brief The key value of the input
 */
enum ICE_Key
{
	// FROM SDL JUST RENAMED
	ICE_KEY_UNKNOWN = 0,
	ICE_KEY_A = 4,
	ICE_KEY_B = 5,
	ICE_KEY_C = 6,
	ICE_KEY_D = 7,
	ICE_KEY_E = 8,
	ICE_KEY_F = 9,
	ICE_KEY_G = 10,
	ICE_KEY_H = 11,
	ICE_KEY_I = 12,
	ICE_KEY_J = 13,
	ICE_KEY_K = 14,
	ICE_KEY_L = 15,
	ICE_KEY_M = 16,
	ICE_KEY_N = 17,
	ICE_KEY_O = 18,
	ICE_KEY_P = 19,
	ICE_KEY_Q = 20,
	ICE_KEY_R = 21,
	ICE_KEY_S = 22,
	ICE_KEY_T = 23,
	ICE_KEY_U = 24,
	ICE_KEY_V = 25,
	ICE_KEY_W = 26,
	ICE_KEY_X = 27,
	ICE_KEY_Y = 28,
	ICE_KEY_Z = 29,
	ICE_KEY_1 = 30,
	ICE_KEY_2 = 31,
	ICE_KEY_3 = 32,
	ICE_KEY_4 = 33,
	ICE_KEY_5 = 34,
	ICE_KEY_6 = 35,
	ICE_KEY_7 = 36,
	ICE_KEY_8 = 37,
	ICE_KEY_9 = 38,
	ICE_KEY_0 = 39,
	ICE_KEY_RETURN = 40,
	ICE_KEY_ESCAPE = 41,
	ICE_KEY_BACKSPACE = 42,
	ICE_KEY_TAB = 43,
	ICE_KEY_SPACE = 44,
	ICE_KEY_MINUS = 45,
	ICE_KEY_EQUALS = 46,
	ICE_KEY_LEFTBRACKET = 47,
	ICE_KEY_RIGHTBRACKET = 48,
	ICE_KEY_BACKSLASH = 49,
	ICE_KEY_NONUSHASH = 50,
	ICE_KEY_SEMICOLON = 51,
	ICE_KEY_APOSTROPHE = 52,
	ICE_KEY_GRAVE = 53,
	ICE_KEY_COMMA = 54,
	ICE_KEY_PERIOD = 55,
	ICE_KEY_SLASH = 56,
	ICE_KEY_CAPSLOCK = 57,
	ICE_KEY_F1 = 58,
	ICE_KEY_F2 = 59,
	ICE_KEY_F3 = 60,
	ICE_KEY_F4 = 61,
	ICE_KEY_F5 = 62,
	ICE_KEY_F6 = 63,
	ICE_KEY_F7 = 64,
	ICE_KEY_F8 = 65,
	ICE_KEY_F9 = 66,
	ICE_KEY_F10 = 67,
	ICE_KEY_F11 = 68,
	ICE_KEY_F12 = 69,
	ICE_KEY_PRINTSCREEN = 70,
	ICE_KEY_SCROLLLOCK = 71,
	ICE_KEY_PAUSE = 72,
	ICE_KEY_INSERT = 73, 
	ICE_KEY_HOME = 74,
	ICE_KEY_PAGEUP = 75,
	ICE_KEY_DELETE = 76,
	ICE_KEY_END = 77,
	ICE_KEY_PAGEDOWN = 78,
	ICE_KEY_RIGHT = 79,
	ICE_KEY_LEFT = 80,
	ICE_KEY_DOWN = 81,
	ICE_KEY_UP = 82,
	ICE_KEY_NUMLOCKCLEAR = 83,
	ICE_KEY_KP_DIVIDE = 84,
	ICE_KEY_KP_MULTIPLY = 85,
	ICE_KEY_KP_MINUS = 86,
	ICE_KEY_KP_PLUS = 87,
	ICE_KEY_KP_ENTER = 88,
	ICE_KEY_KP_1 = 89,
	ICE_KEY_KP_2 = 90,
	ICE_KEY_KP_3 = 91,
	ICE_KEY_KP_4 = 92,
	ICE_KEY_KP_5 = 93,
	ICE_KEY_KP_6 = 94,
	ICE_KEY_KP_7 = 95,
	ICE_KEY_KP_8 = 96,
	ICE_KEY_KP_9 = 97,
	ICE_KEY_KP_0 = 98,
	ICE_KEY_KP_PERIOD = 99,
	ICE_KEY_NONUSBACKSLASH = 100, 
	ICE_KEY_APPLICATION = 101, 
	ICE_KEY_POWER = 102, 
	ICE_KEY_KP_EQUALS = 103,
	ICE_KEY_F13 = 104,
	ICE_KEY_F14 = 105,
	ICE_KEY_F15 = 106,
	ICE_KEY_F16 = 107,
	ICE_KEY_F17 = 108,
	ICE_KEY_F18 = 109,
	ICE_KEY_F19 = 110,
	ICE_KEY_F20 = 111,
	ICE_KEY_F21 = 112,
	ICE_KEY_F22 = 113,
	ICE_KEY_F23 = 114,
	ICE_KEY_F24 = 115,
	ICE_KEY_EXECUTE = 116,
	ICE_KEY_HELP = 117,
	ICE_KEY_MENU = 118,
	ICE_KEY_SELECT = 119,
	ICE_KEY_STOP = 120,
	ICE_KEY_AGAIN = 121,   
	ICE_KEY_UNDO = 122,
	ICE_KEY_CUT = 123,
	ICE_KEY_COPY = 124,
	ICE_KEY_PASTE = 125,
	ICE_KEY_FIND = 126,
	ICE_KEY_MUTE = 127,
	ICE_KEY_VOLUMEUP = 128,
	ICE_KEY_VOLUMEDOWN = 129,
	ICE_KEY_KP_COMMA = 133,
	ICE_KEY_KP_EQUALSAS400 = 134,
	ICE_KEY_INTERNATIONAL1 = 135, 
	ICE_KEY_INTERNATIONAL2 = 136,
	ICE_KEY_INTERNATIONAL3 = 137, 
	ICE_KEY_INTERNATIONAL4 = 138,
	ICE_KEY_INTERNATIONAL5 = 139,
	ICE_KEY_INTERNATIONAL6 = 140,
	ICE_KEY_INTERNATIONAL7 = 141,
	ICE_KEY_INTERNATIONAL8 = 142,
	ICE_KEY_INTERNATIONAL9 = 143,
	ICE_KEY_LANG1 = 144, 
	ICE_KEY_LANG2 = 145, 
	ICE_KEY_LANG3 = 146, 
	ICE_KEY_LANG4 = 147, 
	ICE_KEY_LANG5 = 148,
	ICE_KEY_LANG6 = 149, 
	ICE_KEY_LANG7 = 150, 
	ICE_KEY_LANG8 = 151, 
	ICE_KEY_LANG9 = 152, 
	ICE_KEY_ALTERASE = 153, 
	ICE_KEY_SYSREQ = 154,
	ICE_KEY_CANCEL = 155,
	ICE_KEY_CLEAR = 156,
	ICE_KEY_PRIOR = 157,
	ICE_KEY_RETURN2 = 158,
	ICE_KEY_SEPARATOR = 159,
	ICE_KEY_OUT = 160,
	ICE_KEY_OPER = 161,
	ICE_KEY_CLEARAGAIN = 162,
	ICE_KEY_CRSEL = 163,
	ICE_KEY_EXSEL = 164,
	ICE_KEY_KP_00 = 176,
	ICE_KEY_KP_000 = 177,
	ICE_KEY_THOUSANDSSEPARATOR = 178,
	ICE_KEY_DECIMALSEPARATOR = 179,
	ICE_KEY_CURRENCYUNIT = 180,
	ICE_KEY_CURRENCYSUBUNIT = 181,
	ICE_KEY_KP_LEFTPAREN = 182,
	ICE_KEY_KP_RIGHTPAREN = 183,
	ICE_KEY_KP_LEFTBRACE = 184,
	ICE_KEY_KP_RIGHTBRACE = 185,
	ICE_KEY_KP_TAB = 186,
	ICE_KEY_KP_BACKSPACE = 187,
	ICE_KEY_KP_A = 188,
	ICE_KEY_KP_B = 189,
	ICE_KEY_KP_C = 190,
	ICE_KEY_KP_D = 191,
	ICE_KEY_KP_E = 192,
	ICE_KEY_KP_F = 193,
	ICE_KEY_KP_XOR = 194,
	ICE_KEY_KP_POWER = 195,
	ICE_KEY_KP_PERCENT = 196,
	ICE_KEY_KP_LESS = 197,
	ICE_KEY_KP_GREATER = 198,
	ICE_KEY_KP_AMPERSAND = 199,
	ICE_KEY_KP_DBLAMPERSAND = 200,
	ICE_KEY_KP_VERTICALBAR = 201,
	ICE_KEY_KP_DBLVERTICALBAR = 202,
	ICE_KEY_KP_COLON = 203,
	ICE_KEY_KP_HASH = 204,
	ICE_KEY_KP_SPACE = 205,
	ICE_KEY_KP_AT = 206,
	ICE_KEY_KP_EXCLAM = 207,
	ICE_KEY_KP_MEMSTORE = 208,
	ICE_KEY_KP_MEMRECALL = 209,
	ICE_KEY_KP_MEMCLEAR = 210,
	ICE_KEY_KP_MEMADD = 211,
	ICE_KEY_KP_MEMSUBTRACT = 212,
	ICE_KEY_KP_MEMMULTIPLY = 213,
	ICE_KEY_KP_MEMDIVIDE = 214,
	ICE_KEY_KP_PLUSMINUS = 215,
	ICE_KEY_KP_CLEAR = 216,
	ICE_KEY_KP_CLEARENTRY = 217,
	ICE_KEY_KP_BINARY = 218,
	ICE_KEY_KP_OCTAL = 219,
	ICE_KEY_KP_DECIMAL = 220,
	ICE_KEY_KP_HEXADECIMAL = 221,
	ICE_KEY_LCTRL = 224,
	ICE_KEY_LSHIFT = 225,
	ICE_KEY_LALT = 226,
	ICE_KEY_LGUI = 227,
	ICE_KEY_RCTRL = 228,
	ICE_KEY_RSHIFT = 229,
	ICE_KEY_RALT = 230,
	ICE_KEY_RGUI = 231,
	ICE_KEY_MODE = 257,
	ICE_KEY_AUDIONEXT = 258,
	ICE_KEY_AUDIOPREV = 259,
	ICE_KEY_AUDIOSTOP = 260,
	ICE_KEY_AUDIOPLAY = 261,
	ICE_KEY_AUDIOMUTE = 262,
	ICE_KEY_MEDIASELECT = 263,
	ICE_KEY_WWW = 264,
	ICE_KEY_MAIL = 265,
	ICE_KEY_CALCULATOR = 266,
	ICE_KEY_COMPUTER = 267,
	ICE_KEY_AC_SEARCH = 268,
	ICE_KEY_AC_HOME = 269,
	ICE_KEY_AC_BACK = 270,
	ICE_KEY_AC_FORWARD = 271,
	ICE_KEY_AC_STOP = 272,
	ICE_KEY_AC_REFRESH = 273,
	ICE_KEY_AC_BOOKMARKS = 274,
	ICE_KEY_BRIGHTNESSDOWN = 275,
	ICE_KEY_BRIGHTNESSUP = 276,
	ICE_KEY_DISPLAYSWITCH = 277,
	ICE_KEY_KBDILLUMTOGGLE = 278,
	ICE_KEY_KBDILLUMDOWN = 279,
	ICE_KEY_KBDILLUMUP = 280,
	ICE_KEY_EJECT = 281,
	ICE_KEY_SLEEP = 282,
	ICE_KEY_APP1 = 283,
	ICE_KEY_APP2 = 284,
	ICE_KEY_AUDIOREWIND = 285,
	ICE_KEY_AUDIOFASTFORWARD = 286,
	ICE_KEY_SCANCODES = 512,
	ICE_KEY_OTHER = 600,

	//  Mouse
	ICE_KEY_LEFTCLICK = 601,
	ICE_KEY_RIGHTCLICK = 602,
	ICE_KEY_WHEELUP = 603,
	ICE_KEY_WHEELDOWN = 604,
	ICE_KEY_MAX
};

/**
 * \brief Detect if you pressed the corresponding key
 * \param button The key value
 * \return ICE_True or ICE_False
 */
ICE_Bool ICE_Input_Pressed(enum ICE_Key button);
ICE_Bool ICE_Input_OnPress(enum ICE_Key button);
ICE_Bool ICE_Input_OnRelease(enum ICE_Key button);

/**
 * \brief Send the Quit instruction to the engine
 */
void ICE_Input_Quit();

/**
 * \brief Reset every input to 0. Can be usefull in some case
 */
void ICE_Input_Reset();

int ICE_Input_MouseX();
int ICE_Input_MouseY();
ICE_Vect ICE_Input_MouseVector();
int ICE_Input_MouseX_World();
int ICE_Input_MouseY_World();
ICE_Vect ICE_Input_MouseVector_World();

#endif