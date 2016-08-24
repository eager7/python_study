#ifndef __eyeSignOutput_H_
#define __eyeSignOutput_H_

#include "CoreOutput.h"
#include "CoreStructures.h"
#include "GlobalConst.h"

class CORE_API eyeSignOutput : public CoreOutput{
public:
	
	ObjectStruct m_pSignStructs;
	eyeSignInfo m_pEyeSignInfo[2];
	RectStruct m_sPersonRect; // Bounding box for detected person
	float m_fDualHandZoomRat; // Ratio
	float m_fDualHandAng; // Radians
	
	float m_fSlider1, m_fSlider2, m_fSlider3, m_fSlider4;

	TOutOfFOVEvent m_eOutOfFOVEvent;
	int m_nDPadEvent;
	int2 m_n2TilesGridLocation;

	bool m_bIsValid;

	//Multiple hands output
	int m_nMaxNumOfMultipleHands;
	ObjectStruct * m_pMultipleHands;
	unsigned short m_NumOfMultipleHands;

	eyeSignOutput();
	~eyeSignOutput();
	void initilizeStructus(eyeSignInfo * sHand);
	void Reset();
	void ResetHand(eyeSignInfo * sHand);

	void setMultipleHandStruct(ObjectStruct * pHandCandidates, int NumOfMultipleHands);
};

#endif //__eyeSignOutput_H_
