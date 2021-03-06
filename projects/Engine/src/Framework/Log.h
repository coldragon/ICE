﻿#ifndef DEF_ICE_LOG
#define DEF_ICE_LOG
#include "Macrotools.h"

/**
 * \brief Different log types and how they are showed
 */
enum ICE_LogTypes
{
	ICE_LOGTYPE_CRITICAL = -3,
	ICE_LOGTYPE_ERROR = -2,
	ICE_LOGTYPE_WARNING = -1,

	ICE_LOGTYPE_INFO = 0,

	ICE_LOGTYPE_SUCCES = 1,
	ICE_LOGTYPE_RUNNING = 2,
	ICE_LOGTYPE_FINISH = 3

}; typedef enum ICE_LogTypes ICE_LogTypes;

#if defined(_DEBUG)
	/// Use in log or other va_args thing : ICE_Log("Is that true ? : %s", ICE_LOG_TRUEFALSE(myBool))
	#define ICE_LOG_TRUEFALSE(X) X?ICE_MACROTOOLS_STRINGIZE(True):ICE_MACROTOOLS_STRINGIZE(False)

	#define ICE_Log_Error(FORMAT, ...) ICE_Log(ICE_LOGTYPE_ERROR, FORMAT, __VA_ARGS__ )
	#define ICE_Log_Critical(FORMAT, ...) ICE_Log(ICE_LOGTYPE_CRITICAL, FORMAT, __VA_ARGS__ )
	#define ICE_Log_Warning(FORMAT, ...) ICE_Log(ICE_LOGTYPE_WARNING, FORMAT, __VA_ARGS__ )
	#define ICE_Log_Info(FORMAT, ...) ICE_Log(ICE_LOGTYPE_INFO, FORMAT, __VA_ARGS__)
	#define ICE_Log_Succes(FORMAT, ...) ICE_Log(ICE_LOGTYPE_SUCCES, FORMAT, __VA_ARGS__)
	#define ICE_Log_Running(FORMAT, ...) ICE_Log(ICE_LOGTYPE_RUNNING, FORMAT, __VA_ARGS__)
	#define ICE_Log_Finish(FORMAT, ...) ICE_Log(ICE_LOGTYPE_FINISH, FORMAT, __VA_ARGS__)
	#define ICE_Log(TYPE, FORMAT, ...) ICE_Log_(0, __FILE__, __LINE__, TYPE, FORMAT, __VA_ARGS__)
	void ICE_Log_(int nb_tab, const char* file, int line, ICE_LogTypes type, const char * format, ...);

	#define ICE_Log_NoReturn(TYPE, FORMAT, ...) ICE_Log_NoReturn_(__FILE__, __LINE__, TYPE, FORMAT, __VA_ARGS__)
	void ICE_Log_NoReturn_(const char* file, int line, ICE_LogTypes type, const char * format, ...);
	
	void ICE_Log_Line();


	void ICE_Log_printf(const char * format, ...);
#else
	#define ICE_Log_Error(FORMAT, ...) 
	#define ICE_Log_Critical(FORMAT, ...) 
	#define ICE_Log_Warning(FORMAT, ...) 
	#define ICE_Log_Info(FORMAT, ...) 
	#define ICE_Log_Succes(FORMAT, ...) 
	#define ICE_Log_Running(FORMAT, ...) 
	#define ICE_Log_Finish(FORMAT, ...) 
	#define ICE_Log(...)
	#define ICE_Log_NoReturn(...)
	#define ICE_Log_Line()	
	#define ICE_Log_printf(...)
#endif


#endif
