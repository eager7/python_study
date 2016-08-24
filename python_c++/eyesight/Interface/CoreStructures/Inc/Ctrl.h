#ifndef __Ctrl_H_
#define __Ctrl_H_

#include "FaceDetectionOutput.h"
#include "CoreData.h"
#include "CoreStructures.h"
#include "eyeSightOutput.h"

#ifdef VS
class CORE_API Ctrl{
#else
class Ctrl{
#endif
protected:
	static const char m_pCoreVersion[];
	static const char m_pCoreRevision[];
public:
	static const char m_pCoreApiSignature[];
	/// processes the raw image data and returns the processed data
	virtual eyeSightOutput* processFrame(unsigned short* pFrameAmp, float *pFramePhase, int p_nTimeStamp = -1) = 0;
	virtual eyeSightOutput* processFrame(unsigned char* p_FrameBuffer,int p_nTimeStamp = -1) = 0;
	virtual eyeSightOutput* processFrame(unsigned char* p_FrameBuffer1,unsigned char* p_FrameBuffer2,int p_nTimeStamp = -1) = 0;

	//Ctrl(VideoConfig sVideoConfig);
	virtual ~Ctrl(){};

	virtual void setObjectProps(int nCenterX,int nCenterY,int nSize){};
	virtual void setEsFaceData(FaceDataStruct *pFacesData,int nMaxNumOfFaces){};
	virtual void* getCoreData() = 0;
	virtual void* getConfigManager() = 0;
	virtual eyeSightOutput* getOutputObject() = 0;
	virtual bool IsOpenClSupported()=0;
	virtual	bool IsOpenClEnabled()=0;
	virtual	bool EnableOpenCl(bool value)=0;


	///getters for debug 
	virtual ESOutMap* getOutputMaps(int *pLength) = 0;

	//set fps factor
	virtual void resetEngine() = 0;
	virtual void setFps(int nFps) = 0;
	virtual void setParam(int nParam, int nValue, int nEngineType) = 0;
	virtual void setParam(int nParam, void *pValue, int nEngineType) = 0;
	virtual void getParam(int nParam, int &nValue, int nEngineType) = 0;
	virtual void setAccCurve(float *pXvals, float *pSlope, int nLen) = 0;
	virtual int	 getAccCurve(const float *&pXvals, const float *&pSlope) = 0;
	virtual void setSliderAccCurve(SSliderId nSliderId, float *pXvals, float *pSlope, int nLen) = 0;
	virtual int setFrameProperties(const struct crop_config *c) = 0;
	
	virtual int getCfgCustomer() = 0;
	virtual int getCfgProduct() = 0;
	virtual int getInputResolutionWidth() = 0;
	virtual int getInputResolutionHeight() = 0;

	static const char* GetCoreVersion(bool bSvn = false){ return (bSvn ? m_pCoreRevision : m_pCoreVersion); }
};
#endif //__Ctrl_H_
