#ifndef __loggerData_H_
#define __loggerData_H_

#include "GlobalConst.h"
#include "stdarg.h"


class CORE_API loggerData{
public:	
	
	void (*m_fpWriteLog)(const char* msg,int numArgs,va_list args);
	loggerData();
	~loggerData();
	void Reset();

};

#endif //__loggerData_H_
