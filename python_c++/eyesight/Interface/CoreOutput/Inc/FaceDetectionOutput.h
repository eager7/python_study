#ifndef __FaceDetectionOutput_H_
#define __FaceDetectionOutput_H_

#include "CoreOutput.h"

class CORE_API FaceDetectionOutput : public CoreOutput
{
public:

	FaceDetectionOutput(int nMaxNumOfFaces);
	virtual ~FaceDetectionOutput();

	void reset();

	int m_nMaxNumOfFaces;
	int m_nNumOfFaces;
	int m_nFrameSinceLastDetection;
	bool m_bUpdated;
	FaceDataStruct *m_pFacesData;
};
#endif //__faceDetectionOutput_H_
