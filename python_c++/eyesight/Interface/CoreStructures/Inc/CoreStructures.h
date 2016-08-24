#ifndef __CoreStructures_H_
#define __CoreStructures_H_

#include "GlobalConst.h"

#ifndef __cplusplus
typedef unsigned char bool;
#endif

#define MAX_ACC_CURVE_LEN 16
#define HOOF_NUM_OF_BINS 8

static const unsigned char m_cGradToThetaLutVH[11] = {
	4,3,2,0,5,0,1,0,6,7,8
};

typedef struct{
	union{
		int bins[HOOF_NUM_OF_BINS];
		float bins_flt[HOOF_NUM_OF_BINS];
	};
}HooF;


typedef struct {
	int tVideoFormat;
	int nWidth;
	int nHeight;
	int nFps;
	int nRotateByTheta;
	char bFlip;
	char bMirror;
}VideoConfig;

typedef struct {
	unsigned char nValue[3];
}ThreeChPixel;


typedef struct {
	float fCenterX, fCenterY;
	float fDir1X, fDir1Y, fDir2X, fDir2Y;
}EllipseProps;

typedef struct {
	int numOfBlocksX;
	int numOfBlocksY;
	int BlockWidth;
	int BlockHeight;
}eyeCanGrid;

struct crop_config{
	unsigned int num;
	unsigned int region_width;		// 1..[VideoConfig.width]
	unsigned int region_height;		// 1..[VideoConfig.height]
	unsigned int center_x;			// 0..[VideoConfig.width]
	unsigned int center_y;			// 0..[VideoConfig.height]
	unsigned int upper_left_x;		// 0..[VideoConfig.width]
	unsigned int upper_left_y;		// 0..[VideoConfig.height]
	unsigned int dest_width;		// in sensor domain; 0 for highest possible
	unsigned int dest_height;		// in sensor domain; 0 for highest possible
};

typedef struct {
	int nX;
	int nY;
	int nXmap;
	int nYmap;
	int nDistX;
	int nDistY;
	enum TEventType eType;
	float fX;
	float fY;
	float fDx;
	float fDy;
	float fZ;
}PointStruct;

typedef struct {
	bool bValid;
	int nX;
	int nY;
	float fZ;
	int nXmap;
	int nYmap;
	float fZmap;
	int nWidth;
	int nHeight;
	int nDepth;
	float fAngle;
	enum TParts ePartType;
	enum TEventType eType;
}PointStruct3D;

typedef struct {
	bool bValid;
	float fX;
	float fY;
	float fZ;
}PointData3D;

typedef struct {
	// common features:
	int nCenterX;
	int nCenterY;
	int nWidth;
	int nHeight;
	int nValid;

	int nTrajInd;
	int nConfidence;


	// for confidence computation in AttentionSpotting class:
	short nGradeMHI;
	short nGradeDir;


	// trajectory related features:
	float fMHIdir;
	short nLength;

	unsigned short nNumExtrapolated;
	unsigned short nNumDelayed;
	int nSegmentDir;	
}ObjectStruct;


typedef struct {
	bool bLongDistance;
	bool m_bDetectSwipes;
	bool m_bDetectSwipesStable;
	bool m_bExtractMHI;
	float m_fLeftClassifierHighThreshold;
	float m_fRightClassifierHighThreshold;
	float m_fUpClassifierHighThreshold;
	int m_nMotionImageWidth;
	int m_nMotionImageHeight;
}MotionCfg;



typedef struct {
	int nX;
	int nY;
	float fZ;
	int nScaleX;
	int nScaleY;
	bool bValid;
	float fAngle; // in Radians
	float fNomScale;
	int nDy, nDx;
}RectStruct;



typedef struct {
	int nActionState, nSpeed, nType, nInProcess, nX,nY;
}EyePlayOutput;


typedef struct
{
	int		m_nDstWidth;
	int		m_nDstHeight;

	float	m_fXinitFactor;
	float	m_fYinitFactor;

	float	m_fAccelerationFactorX; 
	float	m_fAccelerationFactorY;

	bool	m_bResetPointToCenter;
	bool	m_bDisableAllAccelerations;

	float	m_fMarginDistanceFactor;
	float	m_fMarginVelocityFactor;

	int		m_nSamplesMemorySize;

	float	m_fMaxAcc;
	int		m_nAccCurveOffset;
	int		m_nAccCurveLen;

	float	m_pAccCurveX[MAX_ACC_CURVE_LEN];
	float	m_pAccCurveSlope[MAX_ACC_CURVE_LEN];

	bool	m_bObstructiveBlobAccel;
	float	m_fObstructiveBlobVelocityFactor;
	float	m_fObstructiveBlobDistanceFactor;
	bool	m_bClipVals;

	bool	m_bFreezeCursorLoweringHand;					// Freeze cursor while fast lowering of hand
	bool	m_bDisabledFreezeCursorLoweringHandDuringDND;	// Disabled freeze detection during drag and drop
	bool	m_bFreezeCursorLargeLKError;					// Freeze cursor when large LK error is detected
	float	m_bFreezeCursorLargeLKErrorThreshold;			// lk error threshold
	int		m_bFreezeCursorLargeLKErrorScoreDiffThreshold;	// prev detection score - curr detection score > th

	bool	m_bMappingBasedGestures;

}LocationTransformConfig;


typedef struct{
	ObjectStruct m_sMotionCands;
	int m_nNumOfMotionCands;
	EllipseProps m_sMoments;
	int m_nFingerFreezeFrameNum;
}eyeDebug;


typedef struct{

	int m_nSignGrade;

	int m_nSignX;
	int m_nSignY;
	//int m_nType;
	bool m_bIsValid;

	int m_nVideoStartY;
	int m_nVideoEndY;
	int m_nVideoStartX;
	int m_nVideoEndX;

	PointStruct m_sOutputPoint;
	PointData3D m_sfingerTip;

	RectStruct m_sSrcRoi;
	RectStruct m_sDstRoi;
	RectStruct m_sInitRoi;

	bool m_bLeftSide;

	eyeDebug m_sDebug;

	int m_nDetectedSign;

	short m_nConfidence;
}eyeSignInfo;



typedef struct{
	bool bApplyFilter;
	float fSigmaR;
	float fSigmaS;
	int nFilterHalfWidth;
}BilateralConfig;



typedef struct{
	int nWidth;
	int nHeight;
	int nPatchWidth;
	int nPatchHeight;
	int nPointsX;
	int nPointsY;
	bool bPush;
	bool bUp;
	bool bWave;
	int nWaveZeroCrossTh;
}FlowConfig;


typedef struct{
	int nSwipeHorz;
	int nSwipeVert;
	int nWave;
	int nPush;
}EyeCanOutputDelay;


typedef struct{
	int nHandIndex;
	int nPosX, nPosY;
} CursorProps;

typedef struct
{
	bool m_bApplyProportionUpdate;		// Check various height-width ratios to find optimal for acquired hand
	bool m_bSignScanner;				// sliding window scanner for acquisition 
	bool m_bImageScanningMode;			// enables bruteforce complete scan in single frame 
	bool m_bUseMotion;					// enables motion detection for hand raise bassed acquisition
	bool m_bCheckStability;				// enables stability counter over the number of detection frames
	bool m_bSoftAcquisition;			// Enters tracking quickly (ignores stability test), but enforces 
										// high detection grade during first few frames
	bool m_bTwoHands;					// enables 2 hands mode for acquisition and tracking
	bool m_bEnforceFingerStability;		// requires hand stopping before acquistion
	bool m_bAllowSlowFinger;			// allow more frames for stability
	bool m_bEnforceMuteStability;		// requires hand stopping before acquistion for mute sign
	bool m_bEnforcePalmStability;		// requires hand stopping before acquistion for palm sign
	bool m_bLimitedTrajectoryMode;		// avoid re-scanning objects which had not moved
	bool m_bAddExtraMuteScan;			// too close mute support
	bool m_bDetectionClusterMode;		// Spread count condition for acquisition
	bool m_bScanLastPositionEnabled;	// enables re-acquisition after track loss
	bool m_bTwoHandsSpatialScanningOpt;	// reduced CPU for second hand scanning
	bool m_bTwoHandsPropertiesCheck;	// allows second hand only if it geometricly fits the first hand
	bool m_bTwoHandsAppearanceCheck;	// allows second hand only if it's apearance fits the first hand
	int m_nMinimalHandWidth;			// defines minimum hand size for acquisition
	int m_nMaximalHandWidth;			// defines maximum hand size for acquisition
	int m_nAcquisitionSensitivity;		// sensitivity level for the classifier grade
	float m_fTwoHandsSpatialFactorX;	// second hand horz location constraint
	float m_fTwoHandsSpatialFactorY;	// second hand vert location constraint
	bool m_bFilterHandOutputReset;		// filter hand output in case of detection
	bool m_bFilterFistOutputReset;		// filter fist output in case of detection
	bool m_bFilterHandOutput;			// filter hand output and resets tracking
	bool m_bFilterFistOutput;			// filter hand output and resets tracking
	bool m_bBoundaryCheck;				// out of FOV contraint
	bool m_bUseAcqHandShake;			// enables hand shake for tracking
	int m_nHandShakeFrameLimit;			// duration limit for performing handshake before reset
	int m_nHandShakeIdleTrigger;		// duration for re-enabling the handshake after tracking session
	bool m_bSingleTrajBudget;			// Scan one candidate per trajectory.
	bool m_bTrackVictorySign;			// Scan one candidate per trajectory.
} AcquisitionData;


typedef struct
{
	bool m_bUseLBPValidation;
	bool m_bValidateFinger;
	bool m_bValidateFist;
	bool m_bValidateMute;

	bool m_bFingerValidationMode;	
	bool m_bValidateFingerWithCascade;
	int  m_nValidateFingerWithCascadeInd;
	int  m_nValidateFingerWithCascadeThr;
	int  m_nValidateFingerWithCascadeThrEnd;
	bool m_bPalmLBPEnabled;
	bool m_bFistLBPEnabled;
	bool m_bFingerLBPEnabled;
	bool m_bThumbsUpLBPEnabled;
	bool m_bMuteLBPEnabled;
	bool m_bLowerFingerLBPEnabled;
	bool m_bPartialMuteLBPEnabled;
	bool m_bValidateFistVsFinger;
	bool m_bValidatePartialMute;
	bool m_bValidateFingerTip;
	bool m_bValidateAbsDiff;
	bool m_bValidatePersonEnabled;
	unsigned int m_nValidateFaceClassifierInd;
	bool m_bValidateFaceUseOnlyLargeClassifier;
	float m_fFaceValidationGammaCorrection;
	int  m_nValidatePersonNumFrames;
	bool m_bValidateMuteByPerson;
	bool m_bValidateMuteByHead;
	bool m_bValidateMuteByMouthRegion;
	bool m_bValidateMuteByMouthHist;	
	bool m_bValidateMuteByFace;
	int m_nValidateMuteByFaceSpatialThMode;
	bool m_bValidateMuteByUpperFace;
	int m_nValidateMuteByUpperFaceStepSize;
	int m_nValidateMuteByUpperFacePosThr;
	bool m_bValidateMuteByLowerFace; // m_bValidateMuteByFace must be true

	// DEV ONLY!
	int m_nValidateMuteByLowerFaceClassifierInd;
	int m_nValidateMuteByLowerFaceMode;

	bool m_bValidateFingerByCNN;
	bool m_bValidateMuteByACF;
	bool m_bValidateMuteFingerByDense;
	bool m_bCheckFingerVsFist;
	bool m_bCheckFingerVsPalm;	
	bool m_bEnableMuteContext;
	bool m_bPostponeMuteValidation;
	bool m_bPostponeFingerValidation;
	bool m_bCheckFingerVsVictory;
	bool m_bCheckFingerVsThumb;
	bool m_bCheckFingerLvsR;

	int m_nFingerValACFModelInd;
	int m_nFingerValACFModelThresh;				// ACF costant soft cascade threshold
	int m_nFingerValACFModelThreshEnd;			// ACF last tree threshold
	int m_nFingerValACFModelNumScanPerCand;		// sets the number of ACF scans (windows) around a candidate.
	int m_nFingerValACFModelNumScalePerCand;	// sets the number of scales to scan around the main scale dictated from the motion candidate.

	int m_nFingerValACFModelGridStep;
	int m_nFingerValACFModelGridThresh;
	bool m_bFingerValACFModelStopAt1stDet;

} ValidationData;


typedef enum 
{
	AUX_DISABLED = 0,
	AUX_NORMAL = 1,
	AUX_FREEZEPOINT = 2,
	AUX_VERTICAL_ONLY = 3
} AuxMode;


typedef struct
{
	bool	m_bLKCPUOpt;							// Reduce number of LK patches
	bool	m_bLKFastHOGValidationMode;				// Scan HOG in LK ROI, if score is high enough, skip regular HOG scans
	int		m_nLKFastHOGValidationModeThreshold;	// Score threshold for validated LK
	bool	m_bUnifiedLKFilter;						// Filter LK points according to error from median direction and norm
	bool	m_bNewLKParameters;						// Improved LK tracking
	AuxMode	m_eAuxMode;								// AUX_DISABLED (0) / AUX_NORMAL (1) / AUX_FREEZEPOINT (2)
	bool	m_bResetOnLowerThanInit;				// Allow reset tracking when lower than init.
	bool	m_bResetOnDownMovement;					// Allow reset tracking when moving down
	bool	m_bResetOnDownMovementByShape;			// Allow reset tracking when moving down
	float	m_nMinLKErrForDetectionReset;			// Require minimum LK error for reset by no detection
	int		m_nMaxProtectedTrackingFrames;			// Limit the requirement for minimum LK error to max number of frames. (0 = no limit)
	short	m_nNumNonDetectedFramesThresh;			// Reset tracking after no detection for several frames
	short	m_nMaxNumOfFixedHand;					// Reset tracking after no movement for several frames
	bool	m_bLimitROISize;						// Limits the tracking ROI to frame width * 0.5
	bool	m_bFixedROISize;						// Sample ROI to fixed size (LKWRAPPER_FIXED_ROI_WIDTH,LKWRAPPER_FIXED_ROI_HEIGHT)
	bool	m_bAlternativeHOGLKIntegration;			// Simpler heurisitics for combining HOG and LK Trackers
	bool	m_bTrackLowerFinger;					// tracking and validation by lower finger
} TrackingData;

typedef struct
{
	// Tracking CPU Saving options 
	bool	m_bHogHalfScans;						// Scan HoG every other frame
	bool	m_bHogScanRotations;					// Scan rotations even if 0 angle detection score is high
	float	m_fHogScanRotationsThreshold;			// Limit rotation scan to times when LK claim rotation is above this threshold (radians)
	bool	m_bHogScanRotationsByTrackerDirection;	// If enabled, scans only rotation to the side reported by tracker
	bool	m_bHogScanLargeArea;					// Scan 5x5 HOG instead of 3x3
	float	m_fHogScanLargeAreaThreshold;			// Limit large area scan to times when LK claim translation is above this threshold (SQR(% of hand width))
	int		m_nHogMaxCPUFramesAfterUnsafeLK;		// Uses 5x5 and rotations for a few frames after LK reports large errors (0 = disabled)
	int		m_nHogMaxCPUNoDetectionFramesThreshold;	// Number of frames without detection with cause MaxCPU mode
	int		m_nHogMaxCPUFramesAfterNoDetection;		// Number of MaxCPU mode frames after no detection trigger (0 = disabled)
	bool	m_bAppCPUOpt;							// Limit number of apperance bins
	bool	m_bAppNewMode;							// New appearance mode
	int		m_nRescanDuration;						// replace: m_sEyeSignConsts.m_nMaxNumOfLastPlaceSearch
	bool	m_bTwoHandsAux;
	bool	m_bEnableRotation;
} TrackingCPUCfg;

typedef enum 
{
	MO_ORG,
	MO_NEW_WIDE,
	MO_NEW_TIGHT,
	MO_TIGHT,
	MO_SMALL,
	MO_SYMMETRIC
}MuteOperation;

typedef enum 
{
	FO_ORG,
	FO_ORG_SYMMETRIC,
	FO_LOOSE_FINGER,
	FO_LOOSE_FINGER_SYMMETRIC,
	FO_BACK_FINGER,
	FO_ORG_SMALL,
	FO_LOOSE_FINGER_SMALL,
	TOF_Distorted,
	TOF_Undistorted
}FingerOperation;

typedef enum 
{
	PO_ORG,
	TOF_Palm_Distorted,
	TOF_Palm_Undistorted
}PalmOperation;

typedef enum 
{
	VO_ORG,
	TOF_Victory_Undistorted
}VictoryOperation;

typedef enum 
{
	TO_ORG,
	TOF_ThumbUp_Undistorted
}ThumbUpOperation;

typedef struct
{
	bool m_bGrayMode;								// Switch to gray only features (No css)
	bool m_bSymmetric;
	//bool m_bEnableLongDistanceDetector;				// Enable special detector for long distance hands
	
	int m_nHogScannerNumRows;
	int m_nHogScannerNumCols;
	int m_nHogScannerMinCellDim;
	int m_nHogScannerMaxCellDim;
	int m_nSmallScannerMinCellDim;
	int m_nSmallScannerMaxCellDim;
	int m_nMaxSizeForSmallScanner;

	//bool m_bUseLooseFinger;							// Use loose finger classifiers
	bool m_bUseSmallScanner;
	bool m_bUseSoftCascade;
	bool m_bUseTrackingSoftCascade;

	bool m_bUseCandsSoftCascadeMute;
	bool m_bUseCandsSoftCascadeFinger;
	bool m_bUseCandsSoftCascadePalm;

	bool m_bLimitHogScans;
	int m_eMuteOperation;
	int m_eFingerOperation;
	int m_ePalmOperation;
	int m_eThumbUpOperation;
	int m_eVictoryOperation;
	bool m_bUseACFModel;
	int m_nFingerACFModelInd;
	int m_nFingerACFModelThresh;			// ACF costant soft cascade threshold
	int m_nFingerACFModelThreshHand;     // ACF costant soft cascade threshold only for hand candidate
	int m_nFingerACFModelThreshRelHandFinger;	// ACF costant soft cascade threshold only for hand candidate
	int m_nFingerACFModelThreshRelHandMute;	// ACF costant soft cascade threshold only for hand candidate
	bool m_bFingerACFModelThreshConst;		// ACF costant soft cascade type
	int m_nFingerACFModelThreshEnd;			// ACF last tree threshold
	int m_nFingerACFModelNumScanPerCand;	// sets the number of ACF scans (windows) around a candidate.
	int m_nFingerACFModelNumScalePerCand;	// sets the number of scales to scan around the main scale dictated from the motion candidate.
	int m_nFingerACFModelGridStep;			// grid step for cross-talk cascade
	int m_nFingerACFModelGridThresh;		// threshold to use on number of weak learners for cross-talk cascade

} DetectionData;

typedef struct
{
	bool m_bZoomSlider;
	bool m_bRotSlider;
	bool m_bVerticalSlider;
	bool m_bHorizontalSlider;
	bool m_bDominantAxisFilter;

	bool m_bZoomSliderAcc;
	bool m_bVertSliderAcc;
	bool m_bHorzSliderAcc;

	float m_fZoomSliderFrac;
	float m_fVerticalSliderFrac;
	float m_fHorizontalSliderFrac;
	float m_fAngSliderFrac;
	float m_fTileEventMaiginX;
	float m_fTileEventMaiginY;

	int m_nGridResolutionHorz;
	int m_nGridResolutionVert;
	
	bool m_bMapTilesGrid;
	bool m_bResetTilesLocationOnEvent;
	bool m_bResetTilesLocationAfterSession;

	int m_nNumSliderSigns;

	bool m_b2DRadialSlider;
	bool m_b2DRadialLimitDist;
	bool m_bPatternSeqMatching;

	int m_nSeqMatchingRapidEventThreshold;
	int m_nSeqMatchingIdleDurationThreshold;
	bool m_bSeqMatchingEnqueueAll;


	int m_nVerticalSliderDelay;

	int m_nLowGradeDetectionThresh;


} SlidersCfg;
#endif //__CoreStructures_H_
