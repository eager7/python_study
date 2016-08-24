#ifndef __CoreOutput_H_
#define __CoreOutput_H_

#include "CoreStructures.h"
#include "CoreObjects.h"

typedef struct
{
	int module;
	int error_type;
} es_error_t;


class CORE_API CoreOutput{
private:
	static int error_count;
	static es_error_t errors[10];

public:
	ThreeChPixel* m_pPixelData;
	int m_nWidth, m_nHeight;

	int m_nStartY;
	int m_nEndY;
	int m_nStartX;
	int m_nEndX;

	

	CoreOutput();
	virtual ~CoreOutput();

	static void resetError() {error_count = 0;}
	static void writeError(int module,int error_type) {CoreOutput::errors[CoreOutput::error_count].module = module;
													   CoreOutput::errors[CoreOutput::error_count].error_type = error_type;CoreOutput::error_count++;CoreOutput::error_count = CoreOutput::error_count%10;}
	static int getErrorCount() {return CoreOutput::error_count;}
	static es_error_t getError(int index) {return CoreOutput::errors[index%10];}


	
	void Reset();
};

#endif //__CoreOutput_H_

