#if !defined(__customerConfiguration_H) || MANAGED

#if MANAGED
#define ENUM public enum struct
namespace MCore {
#else
#define __customerConfiguration_H
#define ENUM enum
#endif

ENUM EsCustomers{
	TOSHIBA_TV				= 1001,
	TPV_TV					= 1002,
	HISENSE_TV				= 1003,
	TCL_TV					= 1004,
	TOSHIBA_PC				= 1005,
	THINKPAD_PC				= 1006,
	THINKPAD_TABLET			= 1007,
	EYESIGHT_PC	    		= 1008,
	AMD_PC	    			= 1009,
	DELL_PC	    			= 1010,
	TONGFUNG_PC   			= 1011,
	IDEAPAD_PC	    		= 1012,
	ANALYSISTOOL_PC			= 1013,
	LENOVO_TENT_YOGA		= 1014,
	THINKPAD_PC_GUINNESS	= 1015,
	AMD_PC_GPU				= 1016,
	OPPO_MOBILE				= 1017,
	EYEGLASS_DEMO_PC		= 1018,
	AMD_NANO				= 1019,
	EYESIGHT_PC_V6			= 1020,
	THINKPAD_YOGA			= 1021,
	HOLMES_AIO				= 1022,
	EYESIGHT_TV_V4			= 1023,
	TPVISION_TV				= 1024,
	EYESIGHT_AIO			= 1025,
	EYESIGHT_MOBILE			= 1026,
	EYESIGHT_TV				= 1027,
	FINGER_DYN_CROP			= 1028,
	LE_TV_FINGER			= 1029,
	LE_TV_HAND				= 1030,
	EYESIGHT_PC_HAND 		= 1031,
	LENOVO_TABLET			= 1032,
	QA_TESTS_EsTV			= 1033,
	QA_TESTS_EsPC			= 1034,
	QA_TESTS_EsMobile		= 1035,
	QA_TESTS_EsAIO			= 1036,
	QA_TESTS_EsTVFinger		= 1037,
	QA_TESTS_EsPCFinger		= 1038,
	QA_TESTS_EsMobileFinger	= 1039,
	QA_TESTS_EsAIOFinger	= 1040,
	QA_TESTS_PRD_1			= 1041,
	QA_TESTS_PRD_2			= 1042,
	QA_TESTS_PRD_3			= 1043,
    SDK_MOBILE              = 1044,
    EYESIGHT_MAC            = 1045,
	LOW_COST_TV_HAND		= 1046,
	SNAPI					= 1047,
	VR_WFC_MOBILE			= 1048,
	ONECUE					= 1049,
	NAVDY                   = 1050,
	NAVDY_DEMO              = 1051,
	EsTVBlitzDemo			= 1052,
	SNAPI_LANDSCAPE			= 1053,
	SNAPI_PORTRAIT			= 1054,
	AMD_CONTROLLER_DEMO		= 1055,
	NAVDY_FLICK_TILES       = 1056,
	NAVDY_FLICK_MAPPING     = 1057,
	LIBERTY					= 1058,
	ONECUE_HD               = 1059,
	LIBERTY_HD				= 1060,
	SC_ANALYTICS			= 1061,
	ONECUE_LOCK				= 1062,
	ONECUE_HD_LOCK          = 1063,
	CONTINENTAL_DEMO		= 1064,
	XIAOYI					= 1065,
	DRIVER_AWARENESS		= 1066,
	PHONE_DETECTION			= 1067,
	RECOGNITION_ANALYTICS	= 1068,
	IMAGENET_DEMO			= 1069,
	CONTINENTAL_TOF			= 1070,
	KC_HAND_WAVE			= 1071,
	KC_USER_ANALYSIS		= 1072,
	SC_FINGER_HAND			= 1073,
	SC_DRAG_AND_DROP		= 1074,
	CONTINENTAL_TOF_Dist	= 1075,
	CONTINENTAL_TOF_Undist  = 1076,
	MULTI_SIGN_DEMO			= 1077,
	JOIN_IN_ANALYTICS		= 1078,
	IRIS_LOCALIZATION		= 1079,
	TWO_HANDS_FINGER_PALM	= 1080,
	CONTI_TOF_UndistNoFinger= 1081,
};

enum SliderType {Horizontal, Vertical, Depth, Rotation};





#if MANAGED
}
#endif

#endif //__customerConfiguration_H