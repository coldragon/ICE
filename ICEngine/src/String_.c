﻿#include "hdr/String_.h"

// Basic dynamic string with header value to have standar usable char* as object

#include <stdio.h>
#include <stdlib.h>

// Number of char per int on that platform
static const int cpi = sizeof(int) / sizeof(char);

// Return size of a standard string (work on ICE_String too)
int ICE_StringSTDSize(char * string)
{
	char actual; int size_string = 0;
	if (string)
	{
		do
		{
			actual = string[size_string];
			size_string++;
		} while (actual != '\0');
	}

	return size_string;
}

// Return size of the array of a ICE_String (dont work on std char*) (it's multiple of int)
int ICE_StringSize(ICE_String string)
{
	int *tmp = (int*)(string - cpi * 2);
	return tmp[0];
}

// Return size of the string (if there is 5 letter there is 6 char with the `\0`)
int ICE_StringContain(ICE_String string)
{
	int *tmp = (int*)(string - cpi * 2);
	return tmp[1];
}

// Init a string with header int with information about the array and the string
ICE_String ICE_StringInit(char* stdstring)
{
	const int size_string = ICE_StringSTDSize(stdstring);
	int nb_int_to_malloc = size_string / cpi;

	if (size_string % cpi != 0)
		nb_int_to_malloc++;

	nb_int_to_malloc += 2;

	int * tmp = (int*)malloc(sizeof(int)*nb_int_to_malloc);
	char* string = (char*)(tmp + 2);

	int* size_array = (int*)(string - (2 * cpi));
	int* contain_array = (int*)(string - (1 * cpi));

	*size_array = (nb_int_to_malloc - 2) * cpi;
	*contain_array = size_string;

	for (int i = 0; i < size_string; i++)
		string[i] = stdstring[i];

	return (ICE_String)string;
}

void ICE_StringDelete(ICE_String string)
{
	int *tmp = (int*)(string - (2 * cpi));
	free(tmp);
}

// Draw string + header informations
void ICE_StringDraw(ICE_String string)
{
	printf("STRING : \"%s\", SIZE : %d, CONTAIN : %d \n", string, ICE_StringSize(string), ICE_StringContain(string));

}

// Resize the string, it will troncate to the exact size writed (with `\0` counted) 
// but the actual size of the array will be a multiple of char per int
void ICE_StringResize(ICE_String* ptr_string, const int size)
{
	ICE_String ice_string = *ptr_string;

	int *tmp = (int*)(ice_string - (2 * cpi));

	int contain_array = tmp[1];

	int nb_int_to_realloc = size / cpi;
	if (size%cpi)
		nb_int_to_realloc++;

	int bool_tronc;

	if (size < contain_array)
	{
		bool_tronc = 1;
		contain_array = size;
	}
	else
		bool_tronc = 0;

	tmp = (int*)realloc(tmp, sizeof(int)*(2 + nb_int_to_realloc));
	tmp[0] = nb_int_to_realloc * cpi;
	tmp[1] = bool_tronc ? size : contain_array;
	ice_string = (char*)(tmp + 2);
	if (bool_tronc)
		(ice_string)[contain_array - 1] = '\0';

	*ptr_string = ice_string;
}