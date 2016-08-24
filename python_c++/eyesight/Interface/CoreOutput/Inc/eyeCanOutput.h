#ifndef __eyeCanOutput_H_
#define __eyeCanOutput_H_

#include "CoreOutput.h"

class CORE_API eyeCanOutput : public CoreOutput{
public:
	bool m_bIsEnabled;
	
	int m_nActionState;
	int m_nSpeed;
	int m_nType;
	int m_nTheta;

	TType m_nHorzType;
	TType m_nVertType;

	eyeCanOutput();
	virtual ~eyeCanOutput();
	void Reset();
};
#endif //__eyeCanOutput_H_
