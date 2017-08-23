#ifndef CR_MATH
#define CR_MATH

#include "..\Inc\CRGloble.h"

#ifndef PI
#define PI 3.14159265358979323846f
#endif

#ifndef e
#define e 2.718281828459f
#endif


#ifndef A2R
#define A2R PI/180.0f
#endif

#ifndef R2A
#define R2A 180.0f/PI
#endif

class float3;
class float4;
class Matrix3x3;
class Matrix4x4;
class Quaternion;

class float3
{
public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	float3();
	float3(float a);
	float3(float a, float b, float c);
	float3(FbxDouble3 a);
	float3(FbxDouble4 a);
	float3(float4 a);

	float3 normalize();

	void operator = (FbxDouble3 a);
	void operator = (FbxDouble4 a);
	void operator = (float3 a);
	void operator = (float4 a);
};

class float4
{
public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;

	float4();
	float4(float a, float b, float c, float d);
	float4(float3 a, float d);

	float4 normalize();

	void operator = (float4 a);
};

class Matrix3x3
{
public:
	float matrix[9] = { 0.0f };

	Matrix3x3();

	Matrix3x3(float a[9]);
	Matrix3x3(Matrix4x4 &mat);

	void operator = (float a[9]);
	void operator = (Matrix3x3 mat);
	void operator = (Matrix4x4 mat);
};

class Matrix4x4
{
public:
	float matrix[16] = {0.0f};

	Matrix4x4();

	Matrix4x4(float a[16]);

	void operator = (float a[16]);
	void operator = (Matrix4x4 mat);
};

class Quaternion
{
public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;

	Quaternion();
	Quaternion(float a, float b, float c, float d);

	Quaternion Normailze();
	Matrix4x4 ToMatrix();
};

Matrix4x4 operator * (Matrix4x4 m1, Matrix4x4 m2);
float4 operator * (float4 v, Matrix4x4 m);
float4 operator * (float4 v, Quaternion r);
float3 operator * (float3 v, float s);
float4 operator * (float4 v, float s);
float3 operator * (float3 v1, float3 v2);
float4 operator * (float4 v1, float4 v2);
float3 operator / (float3 v, float s);
float4 operator / (float4 v, float s);
float3 operator / (float3 v1, float3 v2);
float4 operator / (float4 v1, float4 v2);
float3 operator + (float a, float3 v);
float4 operator + (float a, float4 v);
float3 operator + (float3 v1, float3 v2);
float4 operator + (float4 v1, float4 v2);
float Dot(float3 a, float3 b);
float Dot(float4 a, float4 b);
float3 exp(float3 v);

Matrix4x4 Translate(float x, float y, float z);
Matrix4x4 Scale(float x, float y, float z);
Quaternion Rotate(float3 axis, float angle);
Matrix4x4 CalculateModelMatrix(float* localCoord, float3 trans, float3 rota, float3 scal);

float4 xyY2RGB(float3 xyY);
#endif
