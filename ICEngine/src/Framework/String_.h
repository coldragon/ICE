﻿#ifndef DEF_ICE_DYNSTRING
#define DEF_ICE_DYNSTRING

typedef char* ICE_String;

/**
 * \brief Return the size of a std string (Work on ICE_String but is less faster)
 * \param string String evaluated
 * \return Size of the string
 */
int ICE_String_STDSize(char * string);

/**
 * \brief Return size of the array of a ICE_String (dont work on std char*) (it's multiple of int)
 * \param string String evaluated
 * \return Size of the string
 */
int ICE_String_Size(ICE_String string);

/**
 * \brief Return the containing size of the string (if there is 5 letter there is 6 char with the `\0`)
 * \param string String evaluated
 * \return 
 */
int ICE_String_Contain(ICE_String string);

/**
 * \brief Init a string with header int with information about the array and the string
 * \param stdstring String to init into ICE_String
 * \return A ICE_String that need to be Delete
 */
ICE_String ICE_String_Init(char* stdstring);

/**
 * \brief Free everything from the string
 * \param string String to free
 */
void ICE_String_Delete(ICE_String string);

/**
 * \brief Write string on console + header information
 * \param string String to write
 */
void ICE_String_Write(ICE_String string);

/**
 * \brief Resize the string, it will troncate to the exact size writed (with `\0` counted) 
 * but the actual size of the array will be a multiple of char per int
 * \param ptr_string Pointer of ICE_String
 * \param size Size to resize string
 */
void ICE_String_Resize(ICE_String* ptr_string, int size);

#endif
