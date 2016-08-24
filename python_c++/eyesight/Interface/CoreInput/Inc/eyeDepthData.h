#ifndef __eyeDepthData_H_
#define __eyeDepthData_H_

#include "GlobalConst.h"
	
enum eEsDepthMode{
	FULL_FOV_DISPARITY		= 0,
	SINGLE_EYESIGN			= 1,
	DUAL_EYESIGN			= 2,
};
enum DISPARITY_METHOD {
	BLOCKMATCHING   = 0, 
	BROX            = 1,
	BROXOCL         = 2
};
class CORE_API eyeDepthData
{
public:
	eyeDepthData();
	~eyeDepthData();
	void Reset();
	int m_nNumOfDepthPoints;
	int m_eDetectionType;
	eEsDepthMode m_eEyeDepthMode;
	int m_nDataQueLength;
	int m_nSamplingWidth;
	int m_nSamplingHeight;

	// slider configuration
	bool m_bAccelerateSlider;
	bool m_bRectify;
	float m_fSliderDispLimFrac;
	DISPARITY_METHOD m_eDisparityMethod;
	bool m_bSwapBuffers;
	int m_nBroxLevels;
	float m_fBroxRatio;
	int m_nBroxFilterSize;
	float m_fBroxAlpha;
	int m_nOuterIteration;
	int m_nInnerIteration;
	int m_nSORIteration;
	bool m_bBackgroundSubstraction;
	int m_nBackgroundLevel;
};

#endif //__eyeDepthData_H_
