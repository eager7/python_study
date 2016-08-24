#ifndef __eyeSignData_H_
#define __eyeSignData_H_

#include "CoreStructures.h"
#include "GlobalConst.h"
#include "CoreObjects.h"

enum TrackingQuality
{
	TQ_PC_DEFAULT = 0,				// Highest CPU usage
	TQ_TV_DEFAULT = 1,				// Consume CPU only when LK reports fast movement or rotation
	TQ_TV_IMPROVED_ROTATION = 2,	// Always test rotations
	TQ_TV_NO_MAXCPU_MODE = 3,		// Don't enter MaxCPU mode even if LK has large error
	TQ_TV_HALF_SCANS_5x5 = 4,		// Perform scans every second frame, always do 5x5
	TQ_TV_HALF_SCANS_3x3 = 5,		// Perform scans every second frame, do 5x5 for fast movements
	TQ_LOW_CPU = 6					// lowest CPU consumption mode
};

class CORE_API eyeSignData{
public:
	// This Must Always be the first data member!!!!
	int m_nXmlDataVersion;
	
	//detection params
	bool m_bDetectUpperHand;
	bool m_bDetectHand;
	bool m_bDetectFist;
	bool m_bDetectLowerFinger;
	bool m_bDetectFinger;
	bool m_bDetectThumbsUp;
	bool m_bDetectMuteSign;
	bool m_bDetectPartialMuteSign;
	bool m_bDetectTentSign;
	bool m_bDetectVictorySign;
	bool m_bDetectPhoneSign;
	//track based gestures 
	bool m_bFingerClick;
	bool m_bFingerDnd;
	int m_nFingerFreezeLen;
	bool m_bPalmClick;
	bool m_bPalmDnd;
	int m_nPalmFreezeLen;
	bool m_bAngleResetAfterTransition;
	bool m_bAllowWave;
	bool m_bWaveResetOnTileEvent;

	// gestures config
	bool m_bUseGestureRecognizer;
	int m_nPostGestureFreezeLen;
	int m_nGestureAggWinLen;
	int m_nCursorDelay;
	float m_fGestureClassifiersTh;
	bool m_bEnableSignChangeWatchDog;
	bool m_bApplyRegionBasedGesture;
	bool m_bKeepFrameBufferHistory;
	int m_nDragDropVersion;
	float m_fDragTh;
	float m_fDropTh;
	float m_fClickTh;
	bool m_bDetectBackGesture;

	enum VAL_TYPE
	{
		val_none			= 0,
		val_detscore		= (1 << 0),
		val_movement_y		= (1 << 1),
		val_movement_total	= (1 << 2),
		val_track_err		= (1 << 3),
		val_fov				= (1 << 4),
	};
	int m_nHandValidityForDrag;

	// additional parameters
	bool m_bRelativeFingerMapping;
	bool m_bHistEq;	

	AcquisitionData m_sAcquisitionData;
	ValidationData m_sValidationData;
	TrackingData m_sTrackingData;
	DetectionData m_sDetectionData;
	LocationTransformConfig m_sMappingData;
	SlidersCfg m_sSlidersCfg;
	ClassifierSign m_pSliderSigns[10];
	SignScannerCfg m_pSignScannerCfg;
	ActionSpottingV2Config m_cActionSpottingConfig;
	PreProcessingConfig m_sHogPreProcessingConfig;
	TrackingCPUCfg m_sTrackingCPUCfg;	// Tracking CPU Saving options 

	static const int m_nCurrentDataVersion=2;

	eyeSignData();
	eyeSignData(eyeSignData * pSrc);
	~eyeSignData();
	void Reset();

	// This function enforces relationships between parameters.
	void Validate();

	void setTrackingQuality(TrackingQuality eQuality);

	void resetSlidersCfg();
	void setSlidersAcceleration(bool bVertSliderAcc,bool bZoomSliderAcc,bool bHorzSliderAcc);
	void setActiveSliders(bool bZoomSlider,bool bRotSlider,bool bVerticalSlider,bool bHorizontalSlider);
	void setSliderSensitivity(float fZoomSliderFrac, float fVerticalSliderFrac,float fHorizontalSliderFrac, float fAngSliderFrac);
	void setTilesResolution(bool bMapTilesGrid, int nGridResolutionHorz, int nGridResolutionVert);
	void setSliderSigns(int nNumSliderSigns,ClassifierSign *pSliderSigns);
	void setSingleCueGrid();
	void setSingleCueMapping();

	void setMuteDetection(bool bEnabled);
	bool getMuteDetection();

	void configDataScale(int nNumScansWidth, int nNumScansHeight);
	void setDefaultLocationTransformConfig(LocationTransformConfig *pConf);

	void setDefaultTvConfig();
	void setDefaultPcConfig();



};

#endif //__eyeSignData_H_
