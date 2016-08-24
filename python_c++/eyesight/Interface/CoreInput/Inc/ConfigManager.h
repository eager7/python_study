#ifndef __ConfigManager_H_
#define __ConfigManager_H_

#include "GlobalConst.h"
#include "CoreData.h"
#include "FaceDetectionData.h"
#include "eyeCanData.h"
#include "eyeSignData.h"
#include "eyeSnipData.h"
#include "loggerData.h"
#include "customerConfiguration.h"
#include "dynamicCroppingData.h"
#include "eyeDepthData.h"
#include "UserAnalysisConfig.h"

class CORE_API ConfigManager{
public:

	CoreData m_pCoreData[1];	
	FaceDetectionData m_pFaceDetectionData[1];
	eyeCanData m_pEyeCanData[1];
	eyeSignData m_pEyeSignData[1];
	eyeSnipData m_pEyeSnipData[1];
	loggerData m_pLoggerData[1];
	dynamicCroppingData m_pDynamicCroppingData[1];
	eyeDepthData m_pEyeDepthData[1];
	UserAnalysisConfig m_pUserAnalysisConfig[1];

	EsProductTypes m_nProductType;
	EsCustomers m_nCustomer;
	int m_nIniProductNumber;
	char *m_pXMLData;
	void *m_pXML;
	ConfigManager(int nFileType, char* tName);

	~ConfigManager();

	void Reset();
	void loadingByFile(char* tName);

	void SaveToXMLFile(char* pFileName);
	void WriteToHeaderFile(char* pFileName);
	char* ToString();
	void setConfigFromConstVector(const unsigned char *pConfigData);

	void setProduct(int nProductType, bool bReset = true);

	void setCustomer(int nCostumer);
	int getCustomer();

	void setMuteDetection(bool bEnabled);
	bool getMute();

	int setFaceDetection(bool bEnabled,int nMaxNumOfFaces);
	bool getFaceDetection();
	int getMaxNumOfFace();
	
	void setSliderSigns(int nNumSliderSigns,ClassifierSign *pSliderSigns);
	int getSliderSigns(ClassifierSign *pSliderSigns);

	void setLeftRight(bool en);
	bool getLeftRight();

	void setWave(bool en);
	bool getWave();

	void setTwoHands(bool en);
	bool getTwoHands();

	void setDynamicCropping(bool en);
	bool getDynamicCropping();

	void setSlider(SliderType eType, bool en);
	bool getSlider(SliderType eType);

	int getCursorAccelerationCurveLength();
	void getCursorAccelerationCurve(float **pAccCurve,float **pAccCurveSlope);

	void resetStructs();

};

#endif //__ConfigManager_H_
