#ifndef __DATATYPES_H__
#define __DATATYPES_H__

#include "ImageFormats.h"
#include <string.h>
#include "GlobalConst.h"

class CORE_API int2 {
public:
	int x;
	int y;
	int2(int xx, int yy);
	int2(float xx, float yy);
	int2() : x(0), y(0) {};
	void set(int xx, int yy);
	void set(float xx, float yy);
	void Max(int2 n2Max);
	void Min(int2 n2Min);
	int sqrmag();
	int prod();
	int dist(int2 val);
	int dist(int xx, int yy);
	int2 operator *(int val);
	int2 operator *(float val);
	int2 operator *(double val);
	int2 operator /(int val);
	int2 operator -(int val);
	void operator /=(int val);
	int2 operator +(int2 val);
	int2 operator -(int2 val);
	int2 operator +(int val);
	void operator +=(int2 val);
	void operator *=(int val);
	void operator *=(float val);
	bool operator ==(int2 val);
	bool operator !=(int2 val);
} ;

class CORE_API float2 {
public:
	float x;
	float y;
	float2(int2 val);
	float2(double xx, double yy);
	float2(float xx, float yy);
	float2(int xx, int yy);
	float2() : x(0.0f), y(0.0f) {};

	void set(float xx, float yy);
	void set(int xx, int yy);
	void set(double xx, double yy);
	void Max(float2 f2Max);
	void Min(float2 f2Min);
	float sqrmag();
	float cross(float2 val);
	float dot(float2 val);
	float dist(float2 val);
	float2 perpendicular();
	float2 rotate(float angle) const;
	float2 rotate(float2 dir) const;

	void Round();
	void Round2Half();
	float2 operator *(float val);
	float2 operator /(float val);
	float2 operator /(int val);

	float2 operator +(float2 val);
	float2 operator +(float val);
	float2 operator -(float2 val);
	float2 operator -(float val);
	void operator +=(float2 val);
	void operator -=(float2 val);
	void operator *=(float val);
	void operator /=(float val);
	void operator /=(int val);
	bool operator ==(float2 val);
	bool operator !=(float2 val);
};

struct ROI {
  float angle;
  float2 dir;
  float width, height;
  float2 com;

  ROI(){
	  angle = 0;
	  dir.set(0,1);
	  width = height = 0;
	  com.set(-1.f,-1.f);
  }
};

template <typename T, const unsigned int LEN> 
struct cArray{
	static const unsigned int length = LEN;
	T data[LEN];
};

#endif