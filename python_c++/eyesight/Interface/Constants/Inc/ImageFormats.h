#if !defined(__ImageFormats__) || MANAGED

#if MANAGED
#define ENUM public enum struct
namespace MCore {
#else
#define __ImageFormats__
#define ENUM enum
#endif

ENUM TVideoFormat{		
	KYUV420Planar,
	KYUV420SemiPlanarVU,
	KBmpRGB,
	KBmpBGR,
	KYUV422_YUYV,
	KYUV422_YVYU,
	KYUV444,
	KBmpBGRA,
	KBmpRGBA,
	KGray,
	KBmpYYY,
	KYUV422_VYUY,
	KYUV422_UYVY,
	KYUV444Planar,
	KYUV420SemiPlanarUV,
	KTOF_USHORT, // *.dam
	KTOF_FLOAT // *.dir
};

#if MANAGED
}
#endif

#endif //__ImageFormats__
