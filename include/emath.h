#ifndef __ELEMENTARY_MATH_H__
#define __ELEMENTARY_MATH_H__

#include <cstdlib>
#include <iostream>

union vec2;
union vec3;
union vec4;

union vec2 {
	static const vec2 zero;
	static const vec2 one;
	static const vec2 right;
	static const vec2 left;
	static const vec2 up;
	static const vec2 down;

	struct { float x, y; };
	struct { float r, g; };
	struct { float s, t; };
	struct { float u, v; };
	struct { float i, j; };
	struct { float rad, phi; };
	struct { float ro, theta; };
	float array[2];

	vec2();
	vec2(float, float);
	vec2(const vec2&);
	vec2(const vec3&);
	vec2(const vec4&);
	vec2(const float array[2]);
	~vec2();

	float getMagnitude() const;
	vec2 getNormalized() const;

	const float& operator[](std::size_t) const;
	const float& operator* ()            const;
	const float* operator+ (std::size_t) const;
	float& operator[](std::size_t);
	float& operator* ();
	float* operator+ (std::size_t);

	vec2 operator+() const;
	vec2 operator-() const;

	vec2 operator+(const vec2&) const;
	vec3 operator+(const vec3&) const;
	vec4 operator+(const vec4&) const;

	vec2 operator-(const vec2&) const;
	vec3 operator-(const vec3&) const;
	vec4 operator-(const vec4&) const;

	vec2 operator*(float) const;
	vec2 operator/(float) const;

	vec2& operator+=(const vec2&);
	vec2& operator-=(const vec2&);

	vec2& operator*=(float);
	vec2& operator/=(float);
};

union vec3 {
	static const vec3 zero;
	static const vec3 one;
	static const vec3 right;
	static const vec3 left;
	static const vec3 up;
	static const vec3 down;
	static const vec3 forward;
	static const vec3 back;

	struct { float x, y, z; };
	struct { float r, g, b; };
	struct { float u, v; union { float w; float q; }; };
	struct { float i, j, k; };
	struct { float ro, theta, phi; };
	float rad;
	float array[3];
	vec2 xy;
	vec2 rg;
	vec2 st;
	vec2 uv;
	vec2 ij;
	vec2 radphi;
	vec2 rotheta;

	float getMagnitude() const;
	vec3 getNormalized() const;

	vec3();
	vec3(float, float);
	vec3(float, float, float);
	vec3(const vec2&);
	vec3(const vec3&);
	vec3(const vec4&);
	vec3(const float array[3]);
	~vec3();

	const float& operator[](std::size_t) const;
	const float& operator* ()            const;
	const float* operator+ (std::size_t) const;
	float& operator[](std::size_t);
	float& operator* ();
	float* operator+ (std::size_t);

	vec3 operator+() const;
	vec3 operator-() const;

	vec3 operator+(const vec2& b) const;
	vec3 operator+(const vec3& b) const;
	vec4 operator+(const vec4& b) const;

	vec3 operator-(const vec2& b) const;
	vec3 operator-(const vec3& b) const;
	vec4 operator-(const vec4& b) const;

	vec3 operator*(float) const;
	vec3 operator/(float) const;

	vec3& operator+=(const vec3&);
	vec3& operator-=(const vec3&);

	vec3& operator*=(float);
	vec3& operator/=(float);
};

union vec4 {
	static const vec4 zero;
	static const vec4 one;
	static const vec4 right;
	static const vec4 left;
	static const vec4 up;
	static const vec4 down;
	static const vec4 forward;
	static const vec4 back;
	static const vec4 wforward;
	static const vec4 wback;

	struct { float x, y, z, w; };
	struct { float r, g, b, a; };
	struct { float i, j, k, l; };
	float array[4];
	vec2 xy;
	vec2 rg;
	vec2 st;
	vec2 uv;
	vec2 ij;
	vec2 radphi;
	vec2 rotheta;
	vec3 xyz;
	vec3 rgb;
	vec3 uvw;
	vec3 uvq;
	vec3 ijk;
	vec3 rothetaz;
	vec3 radthetaphi;

	float getMagnitude() const;
	vec4 getNormalized() const;

	vec4();
	vec4(float, float);
	vec4(float, float, float);
	vec4(float, float, float, float);
	vec4(const vec2&);
	vec4(const vec3&);
	vec4(const vec4&);
	vec4(const float array[4]);
	~vec4();

	const float& operator[](std::size_t) const;
	const float& operator* ()            const;
	const float* operator+ (std::size_t) const;
	float& operator[](std::size_t idx);
	float& operator*();
	float* operator+(std::size_t idx);

	vec4 operator+() const;
	vec4 operator-() const;

	vec4 operator+(const vec2& b) const;
	vec4 operator+(const vec3& b) const;
	vec4 operator+(const vec4& b) const;

	vec4 operator-(const vec2& b) const;
	vec4 operator-(const vec3& b) const;
	vec4 operator-(const vec4& b) const;

	vec4 operator*(float) const;
	vec4 operator/(float) const;

	vec4& operator+=(const vec4&);
	vec4& operator-=(const vec4&);

	vec4& operator*=(float);
	vec4& operator/=(float);
};

float dot(const vec4&, const vec4&);
vec3 cross(const vec3&, const vec3&);
vec4 point(float, float, float);
vec4 point(const vec3&);

vec2 operator*(float, const vec2&);
vec3 operator*(float, const vec3&);
vec4 operator*(float, const vec4&);

std::ostream& operator<<(std::ostream&, const vec2&);
std::ostream& operator<<(std::ostream&, const vec3&);
std::ostream& operator<<(std::ostream&, const vec4&);
std::wostream& operator<<(std::wostream&, const vec2&);
std::wostream& operator<<(std::wostream&, const vec3&);
std::wostream& operator<<(std::wostream&, const vec4&);

std::istream& operator>>(std::istream&, vec2&);
std::istream& operator>>(std::istream&, vec3&);
std::istream& operator>>(std::istream&, vec4&);
std::wistream& operator>>(std::wistream&, vec2&);
std::wistream& operator>>(std::wistream&, vec3&);
std::wistream& operator>>(std::wistream&, vec4&);

union mat4x4 {
	static const mat4x4 zero;
	static const mat4x4 one;
	static const mat4x4 identity;

	static mat4x4 translation(float, float, float);
	static mat4x4 translation(const vec3&);
	static mat4x4 scale      (float, float, float);
	static mat4x4 scale      (const vec3&);
	static mat4x4 rotationX  (float);
	static mat4x4 rotationY  (float);
	static mat4x4 rotationZ  (float);
	static mat4x4 rotation   (float, float, float);
	static mat4x4 rotation   (const vec3&);
	static mat4x4 transform  (const vec3& translation, const vec3& scale, const vec3& rotation);
	static mat4x4 perspective(float fov, float aspect, float znear, float zfar);
	static mat4x4 ortho      (float width, float height, float near_plane, float far_plane);

	struct {
		float _11, _12, _13, _14,
			  _21, _22, _23, _24,
			  _31, _32, _33, _34,
			  _41, _42, _43, _44;
	};
	float mat[4][4];
	float array[16];
	vec4 rows[4];

	mat4x4();
	mat4x4(
		float, float, float, float,
		float, float, float, float,
		float, float, float, float,
		float, float, float, float
	);
	mat4x4(const vec4&,       const vec4&,       const vec4&,       const vec4&);
	mat4x4(const float _1[4], const float _2[4], const float _3[4], const float _4[4]);
	mat4x4(const mat4x4&);
	mat4x4(const float mat[4][4]);
	mat4x4(const float array[16]);
	mat4x4(const vec4 rows[4]);
	~mat4x4();

	float getDeterminant() const;
	float getMinor (const int rows[3], const int columns[3]) const;
	float getMinor2(const int rows[2], const int columns[2]) const;
	mat4x4 getInverse() const;

	vec3 getXDirection() const;
	vec3 getYDirection() const;
	vec3 getZDirection() const;
	vec3 getTranslation() const;

	mat4x4& setTranslation(float, float, float);
	mat4x4& setTranslation(const vec3&);
	mat4x4& setScale      (float, float, float);
	mat4x4& setScale      (const vec3&);
	mat4x4& setRotationX  (float);
	mat4x4& setRotationY  (float);
	mat4x4& setRotationZ  (float);

	const float* operator[](std::size_t) const;
	const float& operator* ()            const;
	const float* operator+ (std::size_t) const;
	float* operator[](std::size_t idx);
	float& operator* ();
	float* operator+ (std::size_t idx);

	mat4x4 operator+() const;
	mat4x4 operator-() const;

	mat4x4 operator+(const mat4x4&) const;
	mat4x4 operator-(const mat4x4&) const;

	mat4x4 operator*(const mat4x4&) const;
	vec3   operator*(const vec3&) const;
	vec4   operator*(const vec4&) const;
	mat4x4 operator*(float)       const;
	mat4x4 operator/(float)       const;

	mat4x4& operator+=(const mat4x4&);
	mat4x4& operator-=(const mat4x4&);

	mat4x4& operator*=(const mat4x4&);
	mat4x4& operator*=(float);
	mat4x4& operator/=(float);
};

vec3   operator*(const vec3&, const mat4x4&);
vec4   operator*(const vec4&, const mat4x4&);
mat4x4 operator*(float,       const mat4x4&);

std::ostream& operator<<(std::ostream&, const mat4x4&);
std::wostream& operator<<(std::wostream&, const mat4x4&);

std::istream& operator>>(std::istream&, mat4x4&);
std::wistream& operator>>(std::wistream&, mat4x4&);

#endif
