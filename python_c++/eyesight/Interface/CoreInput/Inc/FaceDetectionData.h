#ifndef __FaceDetectionData_H_
#define __FaceDetectionData_H_

#include "CoreStructures.h"
#include "CoreObjects.h"
#include "GlobalConst.h"

//class FaceDetectionData provides input parameters (user's requirements) to Face Detector


class CORE_API FaceDetectionData
{
public:
	int m_nMaxNumOfFaces;	//number of expected faces

	//min/max sizes of objects/faces:
	esSize<> m_sMinObjectSize;
	esSize<> m_sMaxObjectSize;
	int m_nOutRejectStages;
	float m_fScaleFactor;
	float m_fSubScaleFactor;

	//Grouping type (maximum supression or weighted averaging) and minimum numebr of objects in group:
	int m_nMinNeighbors;
	GROUP_TYPE m_eGroupingType;

	enum {
		HAAR = 0, SURF = 1,
	} m_eClassifierType; // 0: Haar, 1: SURF

	union{
		CASC_CPU_MODE m_eCPUMode;
		int m_nFrameDividing;
	};
	
	FaceDetectionData();
	~FaceDetectionData();
	
	void Reset();
	void setObjSizeLimits(esSize<> a_minObjSize, esSize<> a_maxObjSize);
	void setStages(bool doAnalysis, int numStages);
};

#endif //__FaceDetectionData_H_
