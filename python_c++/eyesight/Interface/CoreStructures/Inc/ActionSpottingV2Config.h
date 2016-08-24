#ifndef __ACTIONSPOTTINGV2_CONFIG_H__
#define __ACTIONSPOTTINGV2_CONFIG_H__

#include "GlobalConst.h"
//#include <limits>

enum EOperationMode{
	ELongDistance          = 0,
	EShortDistance         = 1,
	EVeryLongDistance      = 2,
	EUserSuspectExtraction = 3
};


typedef struct{
	int m_nMinGestureTrajLen;			// under this number of frames, the trajectory is not classified
	int m_nSkipFramesAfterGesture;		// number of frames with no classification after gesture has been detected

	bool m_bValidatePerson;				// person validation required for gesture recognition
	int m_nValidatePersonFrames;		// number of frames in which the person need to be validated

	bool m_bDetectHandRaise;			// classify only UP trajectories (used mainly for DynamicCropping requests)
	bool m_bDetectSwipes;				// classify only UP trajectories (used mainly for DynamicCropping requests)
	bool m_bEllipseFitting;

	float m_fLeftClassifierHighThreshold;
	float m_fRightClassifierHighThreshold;
	float m_fUpClassifierHighThreshold;
	EOperationMode m_EOperationMode;

	bool m_bUseNewClassifier;
	bool m_bHandShapeFilter;
}GesturesSpottingConfig;



typedef struct{
	int m_nMinAttentionTrajLen;  // minimum number of points in trajectory to be considered as valid attention trajectory
	int m_nMaxNumAttentionROIs;
	int m_nConfidenceThreshold;
	bool m_bEnableAttention;
	bool m_bFilterNonRisingTrj;
	bool m_bFilterLowConfidence;
	bool bIgnoreParallelTraj;
	bool m_bUseNewConfig;
}AttentionSpottingConfig;


typedef struct{
	// limits:
	int m_nMaxHistoryLength;          // maximal length of the trajectory (coordinates are FIFO'ed)
	int m_nMaxNumTraj;                // maximal number of trajectories per frame
	int m_nMaxGlobalTrajInd;          // max global trajectory index (maximal number of trajectories)

	// connectivity parameters:
	float m_fMaxConnectivityDist;     // maximal distance factor for suspect connectivity
	int m_nMaxConnectivityTempGap;    // maximal temporal gap for suspect connectivity
	float m_fMaxConnectivityWidthFac; // maximal width factor for suspect connectivity
	bool m_bUseDirCondition;          // connect only if the suspect position agrees with current trajectory's direction

	// extrapolation parameters:
	bool m_bExtrapTrajectory;         // whether to extrapolate trajectory after it has ended
	int m_nMinLengthToExtrap;         // trajectory's minimum required length for extrapolation
	int m_nMaxExtrapFrames;           // extrapolation duration

	bool bDirectionalExtrap;
	bool bAttentionTrajUpCond;
	bool m_bUseNewConfig;

}TrajectoryConfig;


typedef struct{
	unsigned char m_nMinSuspectSize;   // minimal size of the motion blob to be processed
	unsigned char m_nMaxNumSuspects;    // maximal number of suspects
	bool m_bVerticalRescale;          // re-calc the suspect's height and Cy
	bool m_bDoEllipseFitting;          // check suspects whether they can be well approximated by ellipse
	bool m_bCCSuspectExtr;             // use connected components method
	bool m_bItProjSuspectExtr;          // use iterative projections method
	float m_fRatioThr;                 // ellipse fitting parameter
	float m_fRatioThrNearBnd;          // ellipse fitting parameter
	float m_fLimitRotX;                // reliable ellipse direction (acos(m_fLimitRotX) <= theta <= 180 - acos(m_fLimitRotX))
	unsigned char m_nCtrShiftFactor;   // shift ellipse center by m_nCtrShift*MinorAxis along MajorAxis

	bool m_bUseNewConfig;
	bool m_bfitSuspectByDT;

}SuspectsConfig;


typedef struct{
	int m_nSmoothingWinSize;
	float m_fSmoothingWinAreaFac;

	bool m_bExternalImageDiffHelper;

	bool m_bExtractMHI;
	unsigned char m_nMaxValMHI;		
	unsigned char m_nNumMHIFramesToUse;

	// std parameters for sigma-delta motion estimation:
	unsigned char m_nMinStd;
	unsigned char m_nMaxStd;

	bool m_bCenterSurround;
}ASImageOpsConfig;


struct ImageDiffHelperCfg{
	//sample size
	int m_nSampleX;
	int m_nSampleY;

	// motion maps resolution  
	int m_nPointsX;
 	int m_nPointsY;

	// image diff helper averaging block size:
	int m_nBlockSize;

	bool m_bExtractDiffPyramid;
	bool m_bPyramidOnDiff;

	// SD absdiff parameters:
	bool m_bUseSDAbsDiff;	
	unsigned char m_nMinSTD;
	unsigned char m_nMaxSTD;
	float m_fThresholdSTD;

	// SD basic parameters:
	bool m_bUseSDBasic;
	unsigned char m_nMaxUpdateVal;		
	int m_nLogFactor;	
	char m_nNumChannelsSDbasic;
	char m_nLogicChannelsSDBasic;	
	int m_nBlockDiffSwitch;

	bool m_bExtractPSD;
	int m_nDftLength;
	int m_nDftGridRes;
public: 
	void reset();

};


class CORE_API ActionSpottingV2Config{

public:
	ImageDiffHelperCfg      m_sImageDiffHelperCfg;
	ASImageOpsConfig        m_sImageOpsCfg; 
	GesturesSpottingConfig  m_sGesturesCfg;
	AttentionSpottingConfig m_sAttentionCfg;
	TrajectoryConfig        m_sTrajCfg;
	SuspectsConfig          m_sSuspectsConfig;

	int m_nSuspectDelay;         // may be unnecessary parameter 
	bool m_bFrameSubSampling;
	
	void Reset();
	void setMode(EOperationMode eMode);
	void setSwipes(bool bEnableSwipes, bool bEnableValidation, bool bForceStable);
	
	EOperationMode m_EOperationMode;

	ActionSpottingV2Config(){ Reset(); };
	~ActionSpottingV2Config(){};
};

#endif
