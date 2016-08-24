#ifndef __eyeDepthOutput_H_
#define __eyeDepthOutput_H_

#include "CoreOutput.h"

class CORE_API eyeDepthOutput : public CoreOutput{
public:
	
	PointStruct3D* m_pDepthPoints;
	int m_nNumOfDepthPoints;

	PointStruct3D m_sHandLeft;
	PointStruct3D m_sHandRight;
	PointStruct3D m_sFace;
	PointStruct3D m_sElbowLeft;
	PointStruct3D m_sElbowRight;
	PointStruct3D m_sShoulderLeft;
	PointStruct3D m_sShoulderRight;

	eyeDepthOutput();
	virtual ~eyeDepthOutput();
	void Reset();
	void Reset3DPointStruct(PointStruct3D *p3DPS);
};
#endif //__eyeDepthOutput_H_
