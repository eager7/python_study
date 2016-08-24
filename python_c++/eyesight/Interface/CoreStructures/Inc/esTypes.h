#ifndef __esTypes_H__
#define __esTypes_H__

#include "datatypes.h"

template <typename T = int> 
class CORE_API esPoint{
public:
	T x, y;
	esPoint() : x(0), y(0) {}
	esPoint(T _x, T _y) : x(_x), y(_y) {}
	void set(T _x, T _y) { x = _x; y = _y; };
}; 

template <typename T = int> 
class CORE_API esSize{
public:
	T width, height;
	esSize() : width(0), height(0) {}
	esSize(T _width, T _height) : width(_width), height(_height) {}
	void set(T _width, T _height) { width = _width; height = _height; };
	T area() const { return (width > 0 && height > 0) ? width * height : 0; };
	T maxDim() const { return (width > height) ? width : height; };
	T minDim() const { return (width < height) ? width : height; };
	operator int2() { return int2((int)width, (int)height); }
	esSize<T> operator +(T scalar) const { return esSize<T>((T)(width+scalar),(T)(height+scalar)); }
	esSize<T> operator -(T scalar) const { return esSize<T>((T)(width-scalar),(T)(height-scalar)); }
	esSize<T> operator -(esSize<T> other) const { return esSize<T>(width-other.width,height-other.height); }
	esSize<T> operator *(float scale) const { return esSize<T>((T)(width*scale),(T)(height*scale)); }
	esSize<T> operator *(int scale) const { return esSize<T>((T)(width*scale),(T)(height*scale)); }
	esSize<T> operator >>(int shift) const { return esSize<T>((T)(width>>shift),(T)(height>>shift)); }
	esSize<T> operator <<(int shift) const { return esSize<T>((T)(width<<shift),(T)(height<<shift)); }
	esSize<T> operator /(float scale) const { return esSize<T>((T)(width/scale),(T)(height/scale)); }
	esSize<T> operator /(int scale) const { return esSize<T>((T)(width/scale),(T)(height/scale)); }
	esSize<T> operator +(esSize<T> other) const { return esSize<T>((T)(width+other.width),(T)(height+other.height)); }
	esSize<T> operator *(esSize<T> other) const { return esSize<T>((T)(width*other.width),(T)(height*other.height)); }
	esSize<T> operator /(esSize<T> other) const { return esSize<T>((T)(width/other.width),(T)(height/other.height)); }
	esSize<T> operator =(esSize<T> other) { width = other.width; height = other.height; return other;}
	bool operator !=(esSize<T> other) { return width != other.width && height != other.height; }
	bool operator ==(esSize<T> other) { return width == other.width && height == other.height; }
	bool operator <(esSize<T> other) { return width < other.width && height < other.height; }
	bool operator >(esSize<T> other) { return width > other.width && height > other.height; }
	bool operator <=(esSize<T> other) { return width <= other.width && height <= other.height; }
	bool operator >=(esSize<T> other) { return width >= other.width && height >= other.height; }
	template <typename S> operator esSize<S>() const { return esSize<S>((S)width,(S)height); };
};

#define half_pi 1.5707963267948966192313216916398f
enum esRectAlignment { AL_UPPERLEFT, AL_CENTERED };
template <typename T = int, esRectAlignment A = AL_UPPERLEFT> 
class CORE_API esRect{
public:
	T x, y, width, height;
	float angle;
	esRect() : x(0), y(0), width(0), height(0), angle(half_pi) {}
	esRect(T _x, T _y, T _width, T _height, float _angle = half_pi) : x(_x), y(_y), width(_width), height(_height), angle(_angle) {}
	esRect(esPoint<T> _tl, esSize<T> _size, float _angle = half_pi) : x(_tl.x), y(_tl.y), width(_size.width), height(_size.height), angle(_angle) {}
	void set(T _x, T _y, T _width, T _height, float _angle = half_pi) { x = _x; y = _y; width = _width; height = _height; angle = _angle; };
	inline T area() const { return (width > 0 && height > 0) ? width * height : 0; }
	esRect<T> operator *(float scale) const { return esRect<T>(x*scale,y*scale,width*scale,height*scale,angle); }
	esRect<T> operator /(float scale) const { return esRect<T>(x/scale,y/scale,width/scale,height/scale,angle); }
	void operator /=(float scale) { x=x/scale;y=y/scale;width=width/scale;height=height/scale; }
	template <typename T_, esRectAlignment A_> operator esRect<T_,A_>() const;
	esSize<T> size() const { return esSize<T>(width,height); }
	ROI toROI() const;
};

class esTransformation {
public:
	esTransformation(float fTx = 0.0f, float fTy = 0.0f, float fSw = 1.0f, float fSh = 1.0f, float fTheta = 0.0f) 
		: m_fTx(fTx), m_fTy(fTy), m_fSw(fSw), m_fSh(fSh), m_fTheta(fTheta)
	{

	}

	template <typename T, esRectAlignment A> 
	esRect<T,A> transform(esRect<T,A> sRect)
	{
		if (m_fTx != -1 || m_fTy != -1 || m_fSw != -1 || m_fSh != -1)
		{
			sRect.x += m_fTx * sRect.width;
			sRect.y += m_fTy * sRect.height;
			sRect.width *= m_fSw;
			sRect.height *= m_fSh;
			sRect.angle += m_fTheta;
		}
		return sRect;
	}

	float	m_fTx;
	float	m_fTy;
	float	m_fSw;
	float	m_fSh;
	float	m_fTheta;
};

template <typename T = unsigned char> 
class esImage{
public:
	T* data; // pixel data
	esSize<int> size; // image size in pixels
	int stride; // bytes between the beginning of one row and the beginning of the next row
	static const int depth = sizeof(T); // number of bytes for each pixel in each channel

	esImage() 
		: data(NULL), stride(0), allocatedelements(0) {}
	esImage(T* _data, esSize<int> _size) 
		: data(_data), size(_size), stride(_size.width * sizeof(T)), allocatedelements(0) {}
	esImage(T* _data, esSize<int> _size, int _stride) 
		: data(_data), size(_size), stride(_stride), allocatedelements(0) {}
	esImage(esSize<int> _size, int _stride) 
		: data(NULL), size(_size), stride(_stride), allocatedelements(stride * size.height / sizeof(T)) { data = new T[allocatedelements]; }
	esImage(esSize<int> _size) 
		: data(NULL), size(_size), stride(_size.width * sizeof(T)), allocatedelements(stride * size.height / sizeof(T)) { data = new T[allocatedelements]; }
	esImage(const esImage<T> &other) 
		: allocatedelements(0) { *this = other; }
	void release() { if (allocatedelements > 0) {delete[] data;allocatedelements=0;} }

	bool islocal() const { return allocatedelements > 0; }
	inline T* getdata() const { return data; }
	void clear(T val) { memset(data, val, size.height * stride); }
	unsigned int allocatedElements() const { return allocatedelements; };
	
	bool setsize(esSize<> _size, int _stride);
	bool setsize(esSize<> _size) { return setsize(_size, _size.width * sizeof(T)); };
	bool setdata(T* _data) { return setdata(_data, size, stride); };
	bool setdata(T* _data, esSize<> _size) { return setdata(_data, _size, _size.width*sizeof(T)); };
	bool setdata(T* _data, esSize<> _size, int _stride);

	esImage<T> & operator =(const esImage<T> &other) 
	{ 
		setdata(other.data, other.size, other.stride); 
		return *this;
	};

private:
	unsigned int allocatedelements; // whether or not data was initialized internally
};


#endif // __esTypes_H__