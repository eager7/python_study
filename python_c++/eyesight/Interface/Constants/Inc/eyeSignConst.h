#ifndef __eyeSignConst_H_
#define __eyeSignConst_H_

#include "CoreStructures.h"
#include "CoreObjects.h"
#include "datatypes.h"
#include "DataQueue.h"
#include "IObjectDetector.h"

typedef struct {
	short nDriftTHS;

	short nNumFramesToSlider;
	short nStableLimit;

	double m_dParallelFactor;
	double m_dHandSizeFactorY;
	double m_dFistSizeFactorY;
	double m_dThumbSizeFactorY;
	double m_dFingerSizeFactorY;
	double m_dFinger2LowerFingerSizeFactorY;
	double m_dMuteSizeFactorY;
	double m_dArmSizeFactorY;
	double m_dExtendedFistFactorY;
	double m_dPartialMuteSizeFactorY;
	double m_dTentSizeFactorY;
	double m_dHeadSizeFactorY;
	double m_dMouthMuteSizeFactorY;
	double m_dMuteContextSizeFactorY;
	double m_dVictorySizeFactorY;
	double m_dPalmUpperSizeFactorY;
	double m_dRealMouthMuteSizeFactorY;

	short m_nUpperDetectionThresh;
	short m_nLowerDetectionThresh;
	float m_fDistFrac;

	float m_fAngThresh;
	float m_fScaleFrac;

	float m_fTrackerAngIncr;
	int nLKErrorThs;

	int m_nNumStableFramesToEnterClickMode;
	float m_fMaxLKErrorForStableHand;

	int m_nMotionCountTrackInitLimit;
	int m_nMotionCountNotDetectedLimit;
	float fMinAppSep;
	float fAppProbQnt;

	float fAppErrorLoThresh;
	float fAppErrorHiThresh;
	float fMappedPointWdFrac;
	float fMappedPointHtFrac;
	float fFingerMappedPointWdFrac;
	float fFingerMappedPointHtFrac;

	unsigned char m_nHandSearchRegionWidthFactor;
	unsigned char m_nHandSearchRegionHeightFactor;
	unsigned char m_nBlobAppearanceTh;
	int m_nBlobMinimalWidth;
	
	ObjectDetectionCommand<> m_sMuteFaceValidationCommand;
	ObjectDetectionCommand<> m_sMuteMouthValidationCommandH;
	ObjectDetectionCommand<> m_sMuteMouthValidationCommandC;
	ObjectDetectionCommand<> m_sPersonValidationForCandidateCommand;
	ObjectDetectionCommand<> m_sFingerDetectionCommand; 
	ObjectDetectionCommand<> m_sFingerValidationCommand;
	ObjectDetectionCommand<> m_sMuteValidationCommand;
	

}eyeSignConsts;

typedef struct{
	bool m_bClickEvent;
	bool m_bDragEvent;
	bool m_bDropEvent;
	bool m_bAnyEvent;
}EyeSignEvents;

enum EyeSignStates{
	IDLE_MODE = 1,
	TEMPORARY_SCAN_MODE = 2,
	SCAN_MODE = 3,
	TRACK_MODE = 4,
};

enum EyeSignModes{
	PALM_MODE = 1,
	POINT_MODE = 2,
	FIST_MODE = 3,
	THUMB_MODE = 4,
};

typedef struct {
	int nGrade;
	int nMaxGrade;
	int nMinGrade;
}GradeStats;

typedef struct HandCandidate {
	unsigned short nCenterX;
	unsigned short nCenterY;
	unsigned short nWidth;
	unsigned short nHeight;
	unsigned short nAge;
	unsigned short nGrade;
	unsigned short nMaxGrade;
	unsigned short nSmoothGrade;
	int nInconsistencyScore;
	GradeStats sAbsDiffStats;

	unsigned short nNumMuteValidated;
	unsigned short nNumDetected;
	unsigned short nSpreadCount;
	unsigned short nNumGrew;
	unsigned short nMotionality;
	bool bBlastDetected;
	bool bStable;
	bool bRising;
	int nAbsSign; // sign without specifying left/right
	bool bIsLeftHanded;
	float fGradeFactor;
	int nID;		// unique ID (for logging)
	unsigned int nDetectionCD;	// count down from detection (for logging)
	int nTrajID;	// Trajectory ID 
}HandCandidate;


#define TRACKOBJECT_LKERROR_HISTORY_LENGTH 10
class TrackObject{
public:
	TrackObject() 
#if TRACKOBJECT_LKERROR_HISTORY_LENGTH > 1
	  : m_pLKErrorHistory(TRACKOBJECT_LKERROR_HISTORY_LENGTH) 
#endif
	  {};

	bool bIsUpdated;

	unsigned short nInitCenterX, nInitCenterY;
	unsigned short nInitWidth, nInitHeight;
	unsigned short nCenterX, nCenterY;

	unsigned short nWidth, nHeight;
	unsigned short nGrade, nPrevTestedGrade;

	int nCountStable;
	int nCountUnStable;
	unsigned short nSpreadCount;

	bool bStable;
	bool bLeftSide;
	int m_nAbsSign; // classifier sign, without specifying left/right

	int nTrajID;

	bool m_bFreezePoint;
	bool m_bFreezePointExtended;

	int m_nDownMovementFreezeCounter;

	float2 m_f2CursorDiff;
	int m_nPrevPosX;
	int m_nPrevPosY;

	int m_nPrevPrevPosY;
	int m_nPrevWidth;
	int m_nPrevHeight;
	int m_nCountFixedHand;
	int m_nCountToUnfreeze;
	int m_nCountToUnfreezeExtended;

	ObjectProps m_sLastHand;
	ObjectProps m_sLastFist;
	float2 m_f2LastPos;

	int m_nDetectedFistLocationY; 

	int m_nNotStableHandX, m_nNotStableHandY; // This point continues updating as long as hand is not stable
	int m_nNotFixedHandX, m_nNotFixedHandY; // This point continues updating as long as hand is not fixed
	
	int m_nLastFixedHandX, m_nLastFixedHandY;	// This point continues updating as long as hand is fixed
	int m_nLastFixedHandW, m_nLastFixedHandH;	// This point continues updating as long as hand is fixed
	int m_nLastFixedSign;						// This point continues updating as long as hand is fixed

	int m_nNumNonDetectedFrames;
	float m_fLargestLKErrorSinceNonDetected;
	int m_nNumProtectedTrackingFrames;
	
#if TRACKOBJECT_LKERROR_HISTORY_LENGTH > 1
	DataQueue<float> m_pLKErrorHistory;
#endif

	unsigned int m_nHogMaxCPUCounter;

	int m_nFramesInSliderTrackMode;
	int m_nNumFramesTracked;
	int m_nCountNotDetected;

	float m_fScaleOffset;

	//App model
	int m_nCountAppDrift;
	//Modes
	bool m_bDragMode;
	EyeSignStates m_nState, m_nPrevState;
	//Events
	EyeSignEvents m_sEyeSignEvents;
	//Output
	TEventType m_nLastOutput;
	//
	EyeSignModes m_eEyeSignMode;
	// hog angle tracking
	float m_fAngOffset;
	float m_fAngUpdate;
	//Object confidence
	short m_nConfidence;
	int m_nLastHandCounter;
	bool m_bSignDetectedDuringTransition;
	bool m_bGestureProcessed;

	bool m_bStable;

	int m_nDetectorGradeAtLKPosition;

	void getObjectProps(ObjectProps *pObjectProps)
	{
		pObjectProps->nCenterX = this->nCenterX;
		pObjectProps->nCenterY = this->nCenterY;
		pObjectProps->nWidth = this->nWidth;
		pObjectProps->nHeight = this->nHeight;
		pObjectProps->bIsUpdated = 1;
		pObjectProps->bIsValid = 1;
	};
};



#endif //__eyeSignConst_H_

