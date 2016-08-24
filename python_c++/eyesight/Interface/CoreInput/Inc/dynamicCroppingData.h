#ifndef __dynamicCroppingData_H_
#define __dynamicCroppingData_H_

#include "GlobalConst.h"

class CORE_API dynamicCroppingData
{
public:
	dynamicCroppingData();
	~dynamicCroppingData();
	void setDetectionBasedCfg();
	void Reset();

	bool m_bResetDetectionOutput;
	int m_nWaitForAct;
	int m_nWaitForRescan;
	int m_nMaximalHandSize;
	int m_nMinTriggerCount;
	int m_nMaxTriggerCount;

	float m_fMaxZoomRatioX;
	float m_fMaxZoomRatioY;

};

#endif //__dynamicCroppingData_H_
