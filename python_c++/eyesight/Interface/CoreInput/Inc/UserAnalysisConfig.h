#ifndef __UserAnalysisConfig_H_
#define __UserAnalysisConfig_H_

#include "GlobalConst.h"
//#include "CoreStructures.h"
//#include "CoreObjects.h"


class CORE_API UserAnalysisConfig
{
public:
	UserAnalysisConfig();
	UserAnalysisConfig(UserAnalysisConfig* pSrc);
	~UserAnalysisConfig();
	void reset();
	void validate();

	// Parameters
	int		m_nMaxNumOfUsers;			// Maximum number of processed users
	bool	m_bOutputValidationUsers;	// Controls users output during validation (For debug)
	bool	m_bSingleFrameProcessing;	// If true, the full process will end in a single call to processFrame
	bool	m_bLowCPUMode;				// Set all processing to low CPU mode
	bool	m_bOutputIntermediateFaces;	// Output detected faces before full frame is processed
	bool	m_bRemoveOverlapingUsers;	// If two users overlap, remove one of them
	bool	m_bLandmarkDetector;		// Enables landmark detectors
	bool	m_bLandmarkLocalization;	// Enables landmark localization
	bool	m_bExpression;				// Enables facial expression
	bool	m_bPartMuteProcessors;		// Enables Mute detection
	bool	m_bPartFingerProcessors;	// Enables Finger detection
	bool	m_bPartFaceProcessors;		// Enables Face processor
	bool	m_bPartUpperBodyProcessors;  // Enables Upper body processor
	bool	m_bRecognizePerson;			// Enables face recognition
	bool	m_bRecognizeGender;			// Enables gender recognition
	bool	m_bRecognizeAge;			// Enables age estimation
	bool	m_bRecognizeChild;			// Enables child recognition
	bool	m_bFullScanMode;			// Enables face detection from full frame scans
	bool	m_bMotionAnalysis;			// Enables face detection from motion candidates
	bool	m_bEnableMaskGenerator;		// Enables mask generator to avoid rescanning regions with faces
	int		m_nStabilityPeriod;			// number of frames to wait before performing recognition
	float	m_fMaxBudgetCNN;			// max computation budget of the CNN models
	bool	m_bStopAfterStability;		// stop CNNs after m_nStabilityPeriod
	bool	m_bHeadPoseLM;				// CNN for landmarks and head pose
	bool	m_bAttributesLM;			// CNN for landmarks and attributes
	bool    m_bUseYuvPlanarFullScan;	// whether to use yuv planer in full scan - doesn't impact motion scan.
	bool	m_bUseNPDForFullScan;		// Alternative face detection method
	bool	m_bFaceUserDet;				// add users by face detector
	bool	m_bUpperBodyDet;			// add users by upper body detector
	bool	m_bPersonDet;				// add person detector
	bool	m_bPersonDetNoLowerLegs;	// detect person without lower legs
	bool	m_bUpperBodyProcess;		// Upper body detection as users' processor
	bool	m_bDummyLandmarksDetector;	// Skipping facial part detectors by predefined location relative to face bbox
	bool	m_bEnableIrisDetection;		// Iris localization
	bool	m_bEstimateHeadPose;		// head pose estimation (3d)
	void*	m_pExternalMaskGenerator;	// For internal use
};

#endif //__UserAnalysisConfig_H_
