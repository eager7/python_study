#ifndef __eyeSnipData_H_
#define __eyeSnipData_H_

#include "CoreStructures.h"
#include "GlobalConst.h"
#include "CoreObjects.h"

class eyeSignData;

class CORE_API eyeSnipData{
public:	
	// This Must Always be the first data member!!!!
	int m_nXmlDataVersion;
	static const int m_nCurrentDataVersion=1;

	eyeSnipData();
	~eyeSnipData();
	void Reset();

	// EyeSnipV2 parameters
	unsigned short m_nMaxInputSize; // Default: 320
	char m_nSensitivity; // >0 higher sensitivity, <0 lower sensitivity. Default: 0

};

#endif //__CeyePointData_H_
