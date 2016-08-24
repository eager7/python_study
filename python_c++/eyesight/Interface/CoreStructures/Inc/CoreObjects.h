#ifndef __CoreObjects_H_
#define __CoreObjects_H_

#include "CoreStructures.h"
#include "datatypes.h"
#include "esTypes.h"
#include <string.h> // for using NULL
#include "ActionSpottingV2Config.h"

class ESOutMap{
public:
	int nWidth;
	int nHeight;
	int *pWidth;
	int *pHeight;
	int nBytesPerPixel;
	int nNumOfChannels;
	int nChannelToShow; // -1 for RGB
	bool bSigned;
	bool bNorm;
	bool bManualNorm;
	int nMaxVal;
	int nMinVal;
	void *pPixelData;
	char pMapName[200];

	ESOutMap()
	{
		nWidth = nHeight = 0;
		nBytesPerPixel = nNumOfChannels = 1;
		nChannelToShow = -1;
		bSigned = bNorm = bManualNorm = false;
		nMinVal = 0;
		nMaxVal = 255;
		pWidth = pHeight = NULL;
	}
};

class CORE_API RoiConfig
{
public:
	double m_dOffsetX;
	double m_dOffsetY;
	double m_dRoiFactorX;
	double m_dRoiFactorY;
	bool m_bAllowUpsampling;
	bool m_bAllowLpf;
	bool m_bAllowChange;
	bool m_bMapRGB;
	bool m_bMapGray;
	bool m_bMapBlockHistograms;
	bool m_bBlockHistogramsNoStretch;
	bool m_bUseNormChStretch;
	bool m_bMapYUV;
	bool m_bYUV_Planar;
	bool m_bMirrorROI;
	bool m_bEnableOpenCLAccelartion;

//	BilateralConfig m_sBilateralCfg;
//	bool m_bUseCLHistEq;
//	bool m_bUseAdaptiveHistEq;
//	bool m_bUseAdaptiveHistEqWithGlobal;
//	bool m_bUseHDRTrans;


	void Reset();
	RoiConfig() {Reset();};
	~RoiConfig(){};

};

class AABB
{
public:
	int m_nXStart;
	int m_nYStart;
	int m_nXEnd;
	int m_nYEnd;
	AABB() {}
	AABB(int nXStart, int nYStart, int nXEnd, int nYEnd) :
	m_nXStart(nXStart), m_nYStart(nYStart), m_nXEnd(nXEnd), m_nYEnd(nYEnd) {}
};

struct FaceDataStruct
//class FaceDataStruct
{
//public:
	int nCenterX, nCenterY;
	int nWidth, nHeight;
	bool bIsValid;
	float fGrade;
	float fAngle;
	//char pName[200];
	int nUserInd;
	int nPersonID;
	int nPersonGender;
	int nPersonAge;
	int nPersonAgeErr;
	int nPersonIsChild;
	int2 sLeftEye;
	int2 sRightEye;
	int2 sMouth;

	int nLeftEyeOpenProb;	
	int	nRightEyeOpenProb;

	int	nFacialLandmarksValid;

	int	nHeadPoseValid;
	int	nHeadPoseYaw;
	int	nHeadPosePitch;
	int	nHeadPoseRoll;

	int m_nNumOfLandmarks;
	int m_nFacialLandmarksX[100];
	int m_nFacialLandmarksY[100];

	int sUpperBody[4];
	int sFullBody[4];
	USER_EXPRESSION eExpression;

	int sHandLeft[4];
	int sHandRight[4];
	ClassifierSign eHandSign[2];
public:
	void reset();
	
};


typedef struct
{
	int x, y, scale, prob, distance, size, orientation, classGrag;
	int xr, yr;
	bool bSmoothValid;
	int nCounter;
	bool bValid;
}ObjectParam;


class ObjectProps{
public:
	int nCenterX, nCenterY;
	int nWidth, nHeight;
	bool bIsUpdated;
	bool bIsValid;
	bool bUseRotation;
	float fRotaionDirX;
	float fRotaionDirY;
	
	ObjectProps(ROI *pROI, bool _bIsUpdated = true, bool _bIsValid = true);
	ObjectProps(esRect<int,AL_CENTERED> _sRect, bool _bIsUpdated = true, bool _bIsValid = true);
	ObjectProps(esRect<int,AL_UPPERLEFT> _sRect, bool _bIsUpdated = true, bool _bIsValid = true);

	ObjectProps()
	{
		reset();
	}
	void setLocation(int aW, int aH, int aCx, int aCy);

	void reset()
	{
		bIsUpdated   = false;
		bIsValid     = false;
		bUseRotation = false;
		nCenterY = nCenterX = 0;
		nWidth = nHeight = 0;
		fRotaionDirX = 0.f;
		fRotaionDirY = 1.f;
	}
};


class OpticalFlowConfig{
private:
	//patch size:
	int m_nPatchWidth;
	int m_nPatchHeight;
	enum TrackerType m_eTrackerType;
	enum ModeTrack m_eMode;// Global (0)- whole image is sent to Tracker, Local (1)- local area (important to BMTracker),
							//possible: Flexible (2)
public:
	//frame size (required resolution):
	int m_nWidth;
	int m_nHeight;
	//number of grid points:
	int m_nPointsX;
	int m_nPointsY;
	//size of area search (used in BMTracker):
	int m_nSearchAreaW;
	int m_nSearchAreaH;
	//update in-points from previous frame
	bool m_bUpdateInPoints;
	//number of pyramid levels:
	int m_nLevel;
	//post process
	bool m_bPPErosion;
	bool m_bPPMedian;
	bool m_bPPGaussianAvg;
	unsigned int m_nRefine;	

	OpticalFlowConfig(TrackerType eTrackerType = TT_LK, ModeTrack a_eMode = Global){
		reset(eTrackerType, a_eMode);
	}
	void reset(TrackerType eTrackerType, ModeTrack a_eMode = Global);

	void setPatchSize(int nWidth, int nHeight);
	const int getPatchWidth()const{return m_nPatchWidth;};
	const int getPatchHeight()const{return m_nPatchHeight;};
	const TrackerType getTrackerType()const{return m_eTrackerType;};
	const ModeTrack getMode()const{return m_eMode;};
};


class FeatureOFConfig{
private:
	//number of histogram bins:
	int m_numOfBins;
	
	//Grid of cells to Multiresolution Histogram build:
	int2 m_nCellGrid;
public:
	FeatureOFConfig(int a_nBins, int a_nX = 1, int a_nY = 1):m_numOfBins(a_nBins), m_nCellGrid(a_nX,a_nY)
	{};
	FeatureOFConfig()
	{
		m_numOfBins = 8;
		m_nCellGrid.x = 1;
		m_nCellGrid.y = 1;
	};
	void reset(int a_nBins, int a_nX, int a_nY){
		m_numOfBins = a_nBins;
		m_nCellGrid.x = a_nX;
		m_nCellGrid.y = a_nY;
	};
	const int getNumOfBins()const{return m_numOfBins;};
	const int get_nXcells()const{return m_nCellGrid.x;};
	const int get_nYcells()const{return m_nCellGrid.y;};
};

class CORE_API SignScannerCfg{
public:
	int nCandWidth ;
	int nGridResX  ;
	int nGridResY  ;
	int nFactorRes ;
	int nMaxFactor ;
	int nNumOfScans;

	SignScannerCfg(){};

	SignScannerCfg(
		int a_nCandWidth ,
		int a_nGridResX  ,
		int a_nGridResY  ,
		int a_nFactorRes ,
		int a_nMaxFactor ,
		int a_nNumOfScans){
			nCandWidth  = a_nCandWidth ;
			nGridResX   = a_nGridResX  ;
			nGridResY   = a_nGridResY  ;
			nFactorRes  = a_nFactorRes ;
			nMaxFactor  = a_nMaxFactor ;
			nNumOfScans = a_nNumOfScans;
	}

	void setCfg(
		int a_nCandWidth ,
		int a_nGridResX  ,
		int a_nGridResY  ,
		int a_nFactorRes ,
		int a_nMaxFactor ,
		int a_nNumOfScans){
			nCandWidth  = a_nCandWidth ;
			nGridResX   = a_nGridResX  ;
			nGridResY   = a_nGridResY  ;
			nFactorRes  = a_nFactorRes ;
			nMaxFactor  = a_nMaxFactor ;
			nNumOfScans = a_nNumOfScans;
	}

	void setMaxDistCfg(int a_nDist)
	{
		// assuming VGA
		// assuming min CPU
		// 3 ranges:
		//    0 = mobile/hand held - 0-50cm
		//    1 = PC range, lap/desk - up to 1m
		//    2 = full fov scanner up to 1m

		switch(a_nDist)
		{
		case 0:
			setCfg((640/4),6 ,4 ,4,2,1);
			break;
		case 1:
			setCfg((640/8),16,10,8,4,1);
			break;
		case 2:
			setCfg(160,6,4,4,2,96);
			break;
		case 3:
			setCfg(80,16,6,3,2,1);
			break;
		}
	}
	void reset()
	{
		setMaxDistCfg(0);
	}
};

class EsFlowField
{
public:
	float2 *m_pInPoints, *m_pOutPoints;
	float *m_pPointsDiff;
	bool *m_pPointsValid;
	int m_nNumOfPoints;

	EsFlowField()
	{
		m_pInPoints = m_pOutPoints = NULL;
		m_pPointsDiff = NULL;
		m_pPointsValid = NULL;
		m_nNumOfPoints = 0;
	}
};

struct CORE_API PreProcessingConfig
{
	bool m_bUseBilateralFilter;
	float m_fBilaSigmaRange;
	float m_fBilaSigmaSpatial;
	int m_nBilaFilterHalfWidth;
	bool m_bUseCLHistEq;
	bool m_bUseAdaptiveHistEq;
	bool m_bUseAHEqWithGlobal;
	bool m_bUseHDRTrans;
	bool m_bUseNMLByMax;// TOF case
	bool m_bUsePreRunSum;
	float m_fThD;//temp for TOF only 
	PreProcessingConfig():m_bUseBilateralFilter(false),m_bUseCLHistEq(false),m_bUseAdaptiveHistEq(false),
		m_bUseAHEqWithGlobal(false),m_bUseHDRTrans(false), m_bUseNMLByMax(false), m_bUsePreRunSum(false){};
} ;


class SuspectStruct{
public:

	SuspectStruct();
	~SuspectStruct();

	// common features:
	int nCenterX;
	int nCenterY;
	int nWidth;
	int nHeight;
	int nValid;

	// for confidence computation in AttentionSpotting class:
	short nGradeMHI;
	short nGradeDir;
	int nConfidence;

	// trajectory related features:
	float fMHIdir;
	int nSegmentDir;
	short nLength;
	int nTrajInd;
	unsigned short nNumExtrapolated;
	unsigned short nNumDelayed;
};


#endif //__CoreStructures_H_
