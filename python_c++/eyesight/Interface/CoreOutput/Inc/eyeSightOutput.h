#ifndef __eyeSightOutput_H_
#define __eyeSightOutput_H_

#include "GlobalConst.h"
#include "CoreStructures.h"
#include "CoreOutput.h"
#include "eyeCanOutput.h"
#include "eyeDepthOutput.h"
#include "eyeSignOutput.h"
#include "eyeSnipOutput.h"
#include "FaceDetectionOutput.h"

class CORE_API eyeSightOutput : public CoreOutput{
public:

	VideoConfig m_sVideoConfig;

	eyeCanOutput** m_pEyeCanOutput;
	eyeSignOutput** m_pEyeSignOutput;
	eyeDepthOutput** m_pEyeDepthOutput;
	FaceDetectionOutput* m_pFaceDetectionOutput;
	eyeSnipOutput **m_pEyeSnipOutput;
	
	crop_config m_sCropConfig;
	
	bool m_bValid;
	float m_fProcessFrameTime;
	int m_nMaxUsers, m_nMaxFace;
	int m_nFrameCounter;

	EsLightCondition m_eLightCondition;
	EsCoreStatus m_eEsCoreStatus;

	eyeSightOutput(VideoConfig sVideoConfig, int nMaxUsers, int nMaxFace);
	virtual ~eyeSightOutput();

	void resetOutput();

};
#endif //__eyeSightOutput_H_
