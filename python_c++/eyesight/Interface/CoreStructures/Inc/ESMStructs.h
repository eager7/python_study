#ifndef __ESMSTRUCTS_H__
#define __ESMSTRUCTS_H__

#define MAX_PERSONS 5
#define MAX_PARTS   5
#define MAX_POINTS  10

typedef struct ESMHeader {
	char pFileStr[15];                            // .esm identifier
	unsigned char nVersionMajor, nVersionMinor;   // .esm version number
	unsigned char nBPP;                           // bytes per pixel
	unsigned int nWidth, nHeight;                 // frames dimensions
	unsigned int nFrameSize;                      // frame buffer size. if 0, then size is nWidth*nHeight*nBPP
	                                              // otherwise, use given size.
	unsigned char nInputType;                     // from TVideoFormat enum
	unsigned char nRotation;                      // from TRotation enum
	unsigned char bFlipped;                       // 1 for flipped, 0 otherwise
	unsigned char bMirrored;                      // 1 for mirrored, 0 otherwise
	unsigned char nAvgFPS;                        // average FPS
	unsigned int nFramesCount;                    // number of video frames
	unsigned char nPersonCount;                   // allocated number of persons per frame
	unsigned char nPartsCount;                    // allocated number of parts per person
	unsigned char bHasAcceleromterData;           // acceleration on x,y,z axes for each frame

	// additional data sizes (in bytes)
	unsigned int nVideoAdditionalDataSize;
	unsigned int nFrameAdditionalDataSize;
	unsigned int nPersonAdditionalDataSize;
	unsigned int nPartAdditionalDataSize;
}ESMHeader;


#endif // __ESMSTRUCTS_H__
