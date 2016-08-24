#ifndef __eyeCanData_H_
#define __eyeCanData_H_

#include "GlobalConst.h"
#include "CoreStructures.h"
#include "CoreObjects.h"

//#define EYECAN_V1
//#define EYECAN_CLASSIFIERS

class CORE_API eyeCanData{
public:

	// This Must Always be the first data member!!!!
	int m_nXmlDataVersion;

	RoiConfig m_cRoiConfig;
	eyeCanGrid m_sEyeCanGrid;
	FlowConfig m_sFlowConfig;
	EyeCanOutputDelay m_sOutputDelay;

	int m_nWaveFramesLimit;
	int m_nWaveDurationLimit;
	int m_nActionsForWave;

	int m_nWidth;
	int m_nHeight;

	bool m_bMobile;
	bool m_bLeftRight;
	bool m_bWave;
	bool m_bUpDown;
	bool m_bDisableDown;
	bool m_bClap;
	bool m_bSelect;
	bool m_bDirDelay;
	bool m_bWaveOnly;
	bool m_bHistEq;
	bool m_bBlocksErosion;
	bool m_bCustomized;
	int m_nHandGradeThreshold;

	int m_nStableHandDuration;//tv
	bool m_bAddFullFOV;//tv
	bool m_bTriggerByStableHand;//tv
	bool m_bTriggerByInitialDetection;//tv
	bool m_bTriggerScanByWave;//pc
	bool m_bGesturesFilter;//pc
	bool m_bUseFirstGestureV2; //tv
	bool m_bFilterTrackingGesture; // filter gestures while in track mode
	int m_nLowTrackingSpeedTH;
	int m_nHighTrackingSpeedTH;
	bool m_bFirstGestureOutOfBoundsReset;
	int m_nFrameOutOfRegionResetTh;
	int m_nCountSinceDownMovementTh;//pc

	// TV configs
	bool m_bResetOnWave;
	bool m_bResetOnReCap;
	bool m_bResetOnFist;
	bool m_bResetOnTracking;
	int m_nSwipesDuringTrackingDelay;

	int m_nDirectQuality;

	int m_nPostOutputDelay;
	bool m_bPostOutputReset;

	static const int m_nCurrentDataVersion=2;

	eyeCanData();
	~eyeCanData();
	void setPcCfg();
	void Reset();

	void setDebugImage();
	void setRelativeToFace();
	void setMotionEstCfg();
	void setWaveOnlyCfg();
	void setMobileCfg();
	void setCarCfg();
	void setTvCfg();

};

#endif //__eyeCanData_H_
