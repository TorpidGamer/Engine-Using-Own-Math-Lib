#pragma once
#include <cmath>

struct Vector3
{
	float x, y, z;

	Vector3() { x = 0; y = 0; z = 0; }

	Vector3(float a, float b, float c)
	{
		x = a;
		y = b;
		z = c;
	}

	float& operator [](int i)
	{
		return ((&x)[i]);
	}

	const float& operator [](int i) const
	{
		return ((&x)[i]);
	}

#pragma region ScalarOperators
	Vector3& operator += (Vector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return (*this);
	}

	Vector3& operator -= (Vector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return (*this);
	}

	Vector3& operator /= (Vector3& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		return (*this);
	}

	Vector3& operator *= (Vector3& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return (*this);
	}

	Vector3& operator *= (float s)
	{
		x *= s;
		y *= s;
		z *= s;
		return (*this);
	}

	Vector3& operator /= (float s)
	{
		s = 1.0f / s;
		x *= s;
		y *= s;
		z *= s;
		return (*this);
	}


};

#pragma region VectorOperators
inline Vector3 operator + (const Vector3& a, const Vector3& b)
{
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline Vector3 operator * (const Vector3& a, const Vector3& b)
{
	return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

inline Vector3 operator / (const Vector3& a, const Vector3& b)
{
	return Vector3(a.x / b.x, a.y / b.y, a.z / b.z);
}

inline Vector3 operator - (const Vector3& a, const Vector3& b)
{
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline Vector3 operator * (const Vector3& v, float s)
{
	return Vector3(v.x * s, v.y * s, v.z * s);
}

inline Vector3 operator / (const Vector3& v, float s)
{
	s = 1.0f / s;
	return Vector3(v.x * s, v.y * s, v.z * s);
}

inline Vector3 operator - (const Vector3& v)
{
	return Vector3(-v.x, -v.y, -v.z);
}

inline float Magnitude(const Vector3& v)
{
	return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline Vector3 Normalise(const Vector3& v)
{
	return (v / Magnitude(v));
}

#pragma endregion