﻿#ifndef DEF_ICE_MACROTOOLS_H
#define DEF_ICE_MACROTOOLS_H

#define ICE_MACROTOOLS_STRINGIZE2(s) #s
#define ICE_MACROTOOLS_STRINGIZE(s) ICE_MACROTOOLS_STRINGIZE2(s)
#define ICE_MACROTOOLS_CONCATENATE(A, B) A##B

#endif