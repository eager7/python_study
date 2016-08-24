#if !defined(__GlobalConst_H_) || MANAGED

#define MAGIC_NEW_FORMAT_0002

#if MANAGED

#define ENUM public enum struct
namespace MCore {

#else

#define __GlobalConst_H_
#define ENUM enum

#endif

ENUM EsProductTypes{
	EsEyeCanSingle			= 11,
	EsEyePointSingle		= 12,
	EsEyePointCSingle		= 13,
	EsEyeSignSingle			= 14,
	EsFaceDetection			= 17,
	EsLongDistanceFace		= 23,
	EsPC					= 24,
	EsTV					= 25,
	EsTVFinger				= 26,
	EsEyeDepth				= 27,
	EsVideoConverter		= 28,
	EsEyeCar				= 29,
	EsPCFinger				= 30,
	EsTVFingerHand			= 31,
	EsEyeSnip				= 32,
	EsMobile				= 33,
	EsRemote				= 34,
	EsRemoteHD				= 35,
	EsTOF					= 36,
	EsHeaderConfig0			= 100,
	EsHeaderConfig1			= 101,
	EsCustom				= 102,
	EsDeveloper1			= 103,
	EsDeveloper2			= 104,
	EsDeveloper3			= 105,
	EsDeveloper4			= 106,
	EsDeveloper5			= 107,
	EsDeveloper6			= 108,
	EsDeveloper7			= 109,
	EsDeveloper8			= 110,
	EsDeveloper9			= 111,
	EsDeveloperLMarks		= 112,
	EsDeveloperJustin		= 113,
	EsUserAnalysis			= 114,
	EsTest1					= 115,
	EsTest2					= 116,
	EsTest3					= 117,
	EsTest4					= 118,
	EsTest5					= 119,
	EsTest6					= 120,
	EsTest7					= 121,
	EsTest8					= 122,
	EsTest9					= 123,
	EsTest10				= 124,
	EsTest11				= 125,
	EsTest12				= 126,
	EsTest13				= 127,
	EsTest14				= 128,
	EsTest15				= 129,
	EsTest16				= 130,
	EsTest17				= 131,
	EsTest18				= 132,
	EsTest19				= 133,
	EsAssaf1				= 134,
	EsAssaf2				= 135,
	EsAssaf3				= 136,
	EsAssaf4				= 137,
	EsAssaf5				= 138,
	EsAssaf6				= 139,
	EsAssaf7				= 140,
	EsAssaf8				= 141,
	EsAssaf9				= 142,
	EsAssaf10				= 143,
	EsFaceDetNoTracking		= 144,
	EsTestTal				= 145,
	EsTestTal2				= 146,
	munOfProducts
};

ENUM DeveloperRunMode{
	DvNA					= 0,
	DvUserAnalysis			= 1,
	DvSuperPixels			= 2,
	DvHandPosRec			= 3,
	DvUserAnalysisHigh		= 4,
	DvBMTracker				= 5,
	DvDepth					= 6,
	DvBrox					= 7,
	DvOpticalFlow			= 8,
	DvGaze					= 9,
	DvUserScanner			= 10,
	DvMotionSegSP_OF		= 11,
	DvUnUsed2				= 12,
	DvHoughTrans			= 13,
	DvUnUsed3				= 14,
	DvMotionAndBG			= 15,
	DvImageNetDemo			= 16,
	DvActionSpotting        = 17,
	DvCnnTests0		        = 18,
	DvCnnTests1		        = 19,
	DvCnnTests2		        = 20,
	DvCnnTests3		        = 21,
	DvCnnTests4		        = 22,
	DvCnnTests5		        = 23,
	DvCnnTests6		        = 24,
	DvCnnTests7		        = 25,
	DvCnnTests8		        = 26,
	IrisLocalization        = 27,
	DvTracker				= 28,
};

ENUM EsProductTypes_deprecated{
	EsPcDemo				= 24,
	EsLongDistance			= 25,
};

ENUM TPointType{
	TFingerTip,
	TFingerMid,
	TFingerBottom,
	TUnknownPoint=254,
	TInvalidPoint=255
};

ENUM TParts {/// don't change
	TFace=0,
	THand,
	TFinger,
	TFingerHand,
	THandL,
	TElbow,
	TShoulder,
	TUnknownPart=254,
	TInvalidPart=255
};

ENUM THandType{/// don't change
	THandOpen=0,
	THandFist,
	THandVictory,
	THandOK,
	THandPoint,
	THandPartial,
	THandPartialOriented,
	THandLSign,
	THandThumbUp,
	THandThumbDown,
	THandFinger,
	THandFingerTip,
    TPintch,
    TSpread,
    TSwipe,
	THandNumberOfTypes
};




	


ENUM TPartRotate {/// don't change
	TDefaultRotate = 0
};


ENUM TPartSubType {/// don't change
	TUnknownType=254,
	TInvalidType=255
};

ENUM TRotation{
	Theta_0 = 0,
	Theta_90= 1,
	Theta_180 = 2,
	Theta_270 = 3
};

ENUM TRotationDir {
	ROT_NONE = -1,
	ROT_CW = 0,
	ROT_CCW = 1
};


ENUM TEventType {
	EVENT_UNINIT = -2,
	EVENT_NONE = -1,
	EVENT_PALM = 0,
	EVENT_FIST = 1,
	EVENT_CLICK = 2, // deprecated - for backwards compatibility
	EVENT_PALM_CLICK = 2,
	EVENT_WAVE = 3,
	EVENT_BLAST = 4,
	EVENT_PALM_TO_FIST = 5,
	EVENT_FIST_TO_PALM = 6,
	EVENT_EYECAN_INITIALIZED = 8,
	EVENT_EYECAN_TERMINATED = 9,
	EVENT_THUMB = 10,
	EVENT_MUTE = 11,
	EVENT_FINGER = 12,
	EVENT_FINGER_CLICK = 13,
	EVENT_FINGER_TO_FIST = 14,
	EVENT_FIST_TO_FINGER = 15,
	EVENT_TOUCH = 16,
	EVENT_VICTORY = 17,
	EVENT_APPROCH = 18,
};


ENUM TEyeSnipState {
	SEARCH_MODE = 1,
	PREVIEW_MODE = 2,
	CAPTURE_MODE = 3,
};

ENUM TOutOfFOVEvent {
	FOV_EVENT_NONE = 0,
	FOV_EVENT_TOO_LOW = 1,
	FOV_EVENT_TOO_CLOSE = 2,
};


ENUM TFileParam{
	TLoadByFile = 1,
	TLoadByDefault = 2
};

ENUM TType{
	TError = -2,
	TUndefined = -1,
	TRight = 0,
	TUp = 90,
	TLeft = 180,
	TDown = 270,
	TClose = 1,
	TTap = 2,	
	TSwing = 3,
	TBlocking = 4,
	TClap = 5,
	TUnClap = 6,
	TGestureRelocation = 7,
	TGestureInit = 8,
	TGestureTermination = 9,
	TWaveLR = 11,
	KFinger = 30,
	TWaveRL = 13,
	TOpen = 55,
	TPreZoomIn = 65,
	TPreZoomOut = 66
};

ENUM TSpeed{
	SUndefined = -1,
	SStatic = 0,
	SLowSpeed = 1,
	SHighSpeed = 2
};

ENUM TActionState{
	ASError = -2,
	ASIdle = 0,
	ASHighAction = 2
};

ENUM TrackerType{
	TT_LK	= 0,
	TT_BM	= 1
};
ENUM ModeTrack{
	Global	= 0,
	Local	= 1
};

ENUM SSliderId
{
	SSliderZoom=0,
	SSliderVertPos=1,
	SSliderRotation=2,
	SSliderHorzPos=3,
	SSliderDepth=4,
};

ENUM EsCoreStatus
{
	EsCoreStatus_OK = 0,
	EsCoreStatus_DynamicCroppingNoResponce = 1,
	EsCoreStatus_IncreaseLight = 2,
	EsCoreStatus_NEON_Disabled = 3,
	EsCoreStatus_VideoFormatNotSupported = 4,
	EsCoreStatus_BendingDetected = 5,
};

ENUM EsLightCondition
{
	EsLight_OK = 0,
	EsLight_TooLow = 1,
	EsLight_TooHigh = 2
};

ENUM EsDPadEvent
{
	EsDPadDL	= 1,
	EsDPadD		= 2,
	EsDPadDR	= 3,
	EsDPadL		= 4,
	EsDPadNONE	= 5,
	EsDPadR		= 6,
	EsDPadUL	= 7,
	EsDPadU		= 8,
	EsDPadUR	= 9,
};

ENUM EsParamType{
	// eyecan: 0-99
	Es_EYECAN_INT_WAVE_DUR_LIMIT = 10,
	Es_EYECAN_INT_GREY_HISTEQ = 11,
	Es_EYECAN_INT_MOBILEEQLEN = 12,
	Es_EYECAN_INT_WAVE_ENABLE = 13,
	
	// eyesign: 100 - 199
	Es_EYESIGN_BOOL_TOGGLE = 100,
	Es_EYESIGN_FLOAT_ACC_FAC_X = 150,
	Es_EYESIGN_FLOAT_ACC_FAC_Y = 151,
	Es_EYESIGN_BOOL_OBS_BLOB_MODE = 152,
	Es_EYESIGN_INT2_RESET_CURSOR = 153,
	Es_EYESIGN_CURSOR_PROPS_RESET_CURSOR = 154,
	Es_EYESIGN_INT_MAP_FINGER_FLOW_CURSOR = 155,
	Es_EYESIGN_FLOAT_VERT_SLIDER_VAL = 156,
	Es_EYESIGN_BOOL_ALLOW_TWO_HANDS = 157,
	Es_EYESIGN_FLOAT_HORZ_SLIDER_VAL = 158,
	Es_EYESIGN_FLOAT_VERT_MAPPING_OFFSET = 159,
	Es_EYESIGN_INT2_SET_TILES_LOCATION = 160,
	Es_EYESIGN_INT2_DISABLE_TILE_LOCATION = 161,
	Es_EYESIGN_INT2_ENABLE_TILE_LOCATION = 162,
	Es_EYESIGN_FLOAT_MAPPING_LK_ERROR_THRESHOLD = 163,
	Es_EYESIGN_FLOAT_HORIZONTAL_SLIDER_SENSITIVITY = 164,
	Es_EYESIGN_FLOAT_VERTICAL_SLIDER_SENSITIVITY = 165,
	Es_EYESIGN_FLOAT_HORIZONTAL_SLIDER_TILE_MARGIN = 166,
	Es_EYESIGN_FLOAT_VERTICAL_SLIDER_TILE_MARGIN = 167,
	Es_EYESIGN_INT_RESCAN_DURATION = 168,
	Es_EYESIGN_BOOL_ENABLE_HANDSHAKE = 169,
	Es_EYESIGN_BOOL_DISBLE_HANDSHAKE = 170,
	Es_EYESIGN_INT_HANDSHAKE_FRAMES_LIMIT = 171,

	// eyedepth: 300 - 399
	Es_EYEDEPTH_INT_MEMSET_DEPTH_IMG = 300,
	Es_EYEDEPTH_INT_TOGGLE_ZERO_MAP = 301,
	Es_EYEDEPTH_INT_DEPTH_ACC = 302,
	Es_EYEDEPTH_INT_TOGGLE_REL_DEPTH = 303,
	Es_EYEDEPTH_BOOL_RECTIFICATION = 304,
	Es_EYEDEPTH_BOOL_SWAP_BUFFERS = 305,
	Es_EYEDEPTH_BOOL_BACKWARD_FORWARD = 306,
	Es_EYEDEPTH_BOOL_BINARY = 307,
	Es_EYEDEPTH_BOOL_CLOSING_OPENING = 308,
	Es_EYEDEPTH_BOOL_MEDIAN_FILTER =  309,
	Es_EYEDEPTH_BOOL_CLOSING=  310,
	Es_EYEDEPTH_BOOL_OPENNING=  311,
	Es_EYEDEPTH_BOOL_BACKGROUND_SUB=  312,
	Es_EYEDEPTH_INT_BACKGROUND_LEVEL=  313,
	
	// eyesnip: 400 - 499
	Es_EYESNIP_BOOL_TEST_CARD_RAISE = 400,
	
	// multiengines: 1000 - 2000
	Es_TV_BOOL_SET_GESTURES_ACTIVITY = 1000,
	Es_PC_BOOL_SET_FINGER_ACTIVITY = 1001,
	Es_TV_BOOL_SET_GPU_ENABLE = 1002,
	Es_PC_BOOL_SET_GPU_ENABLE = 1003,
	Es_PC_INTEL_DEPTH_PTR = 1004,
	Es_PC_INTEL_UV_PTR = 1005,

	// engine manager: 2000 - 2499
	Es_ENGMAN_BOOL_SET_FACE_ACTIVITY = 2000,
	Es_ENGMAN_BOOL_GET_BENDING_STATUS = 2001,

	// user analysis: 2500 - 2599
	Es_USERANALYSIS_BOOL_RECOGNIZE_AGE = 2500,
	Es_USERANALYSIS_BOOL_RECOGNIZE_USER = 2501,
	Es_USERANALYSIS_BOOL_RECOGNIZE_GENDER = 2502,
	Es_USERANALYSIS_USHORT_USER_FV = 2503,
	Es_USERANALYSIS_CHAR_PTR_SET_FACES_DB = 2504,
	Es_USERANALYSIS_CHAR_PTR_GET_FACES_DB = 2505,

};

#define HD_NUM_OF_SIGNS 53

ENUM ClassifierSign
{
	// signs divided to left/right
	SignPalmLeft           = 0,
	SignPalmRight          = 1,	
	SignFistLeft           = 2,
	SignFistRight          = 3,	
	SignFingerLeft         = 4,	
	SignFingerRight        = 5,
	SignLowerFingerLeft    = 6,
	SignLowerFingerRight   = 7,
	SignThumbLeft          = 8,	
	SignThumbRight         = 9,
	SignMuteLeft           = 10,	
	SignMuteRight          = 11,
//	SignPinchLeft          = 12,	
//	SignPinchRight         = 13,
	SignArmLeft            = 14,	
	SignArmRight           = 15,
//	SignRotatedFingerLeft  = 16,
//	SignRotatedFingerRight = 17,
	SignFingerVsFistLeft  = 18,
	SignFingerVsFistRight = 19,
	SignVictoryLeft  = 20,
	SignVictoryRight = 21,
	SignFingerVsThumbLeft  = 22,
	SignFingerVsThumbRight = 23,
//	SignRotatedFingerVsFistLeft  = 24,
//	SignRotatedFingerVsFistRight = 25,
//	SignRotatedFingerVsThumbLeft  = 26,
//	SignRotatedFingerVsThumbRight = 27,
	SignExtendedFistLeft = 28,
	SignExtendedFistRight = 29,
//	SignFingerVsPinchLeft = 30,
//	SignFingerVsPinchRight = 31,
	SignPartialMuteLeft = 32,
	SignPartialMuteRight = 33,
	SignTentLeft = 34,
	SignTentRight = 35,
	SignUpperBodyFrontal = 36,
	SignUpperBodyProfile = 37,
	SignFingerVsExtFistLeft = 38,
	SignFingerVsExtFistRight = 39,
	SignHead = 40,
	SignMouthMute = 41,
	SignMuteContext = 42,
	SignPalmUpperLeft = 43,
	SignPalmUpperRight = 44,
	SignMouthMuteLeft = 45,
	SignMouthMuteRight = 46,
	SignPhoneLeft = 47,
	SignPhoneRight = 48,
	SignFingerVsVictoryLeft  = 49,
	SignFingerVsVictoryRight = 50,
	SignFingerLvsRLeft = 51,
	SignFingerLvsRRight = 52,
	// absolute (not divided yet to left/right) signs 
	SignInvalid					= 100,
	SignPalm					= 101,
	SignFist					= 102,
	SignFinger					= 103,
	SignLowerFinger				= 104,
	SignThumb					= 105,
	SignMute					= 106,
//	SignPinch					= 107,
	SignArm						= 108,
//	SignRotatedFinger			= 109,
	SignFingerVsFist			= 110,
	SignVictory					= 111,
//	SignFingerVsThumb			= 112,
//	SignRotatedFingerVsFist		= 113,
//	SignRotatedFingerVsThumb	= 114,
	SignExtendedFist			= 115,
//	SignFingerVsPinch			= 116,
	SignPartialMute				= 117,
	SignTent					= 118,
	SignUpperBody				= 119,
	SignFingerVsExtFist			= 120,
	SignPalmUpper				= 121,
	SignPhone				    = 122,
	SignFingerVsVictory         = 123,
	SignFingerVsThumb           = 124,
	SignFingerRightVsLeft           = 125
	
};

enum GROUP_TYPE{
	MAX_SUPPRESS = 0,
	WEIGHT_AVERAGE
};

ENUM CASC_CPU_MODE
{
	CPU_MODE_UNLIMITED		=       0,
	CPU_MODE_LOWEST			=   62500,
	CPU_MODE_VERY_VERY_LOW	=  125000,
	CPU_MODE_VERY_LOW		=  250000,
	CPU_MODE_LOW			=  500000,
	CPU_MODE_MEDIUM			= 1000000,
	CPU_MODE_HIGH			= 1500000,
	CPU_MODE_VERY_HIGH		= 2500000
};

ENUM USER_EXPRESSION
{
	EXP_INVALID		= -1,
	EXP_NEUTRAL		= 0,
	EXP_SMILE		= 1,
	EXP_DISGUST		= 2,
	EXP_SCREAM		= 3,
	EXP_SQUINT		= 4,
	EXP_SURPRISE	= 5,
};

#if MANAGED
}
#endif

#if defined(VS) && (defined(CORE_EXPORTS) || defined(CORE_IMPORTS))

	#ifdef CORE_EXPORTS
	#define CORE_API __declspec(dllexport)
	#else 
	#define CORE_API __declspec(dllimport)
	#endif

#else
#define CORE_API
#endif

#endif //__GlobalConst_H_
