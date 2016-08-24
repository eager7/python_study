#ifndef __eyeSnipOutput_H_
#define __eyeSnipOutput_H_

#include "CoreOutput.h"
#include "CoreStructures.h"
#include "GlobalConst.h"
#include "datatypes.h"

class CORE_API eyeSnipOutput : public CoreOutput{
public:
	
	eyeSnipOutput();
	~eyeSnipOutput();
	void Reset();
	TEyeSnipState m_eState;
	bool m_bRectFound;
	RectStruct m_sRectOut;
	RectStruct m_sRectIn;
	int2 m_n2ULRect;
	int2 m_n2URRect;
	int2 m_n2BRRect;
	int2 m_n2BLRect;

};
#endif //__eyeSnipOutput_H_
