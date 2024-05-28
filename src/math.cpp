#include "emath.h"

float dot(const vec4& a, const vec4& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}
vec3 cross(const vec3& a, const vec3& b) {
	return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
vec4 point(float x, float y, float z) {
	return vec4(x, y, z, 1.0f);
}
vec4 point(const vec3& vec) {
	return vec4(vec.x, vec.y, vec.z, 1.0f);
}

vec2 operator*(float a, const vec2& b) {
	return b * a;
}
vec3 operator*(float a, const vec3& b) {
	return b * a;
}
vec4 operator*(float a, const vec4& b) {
	return b * a;
}

std::ostream& operator<<(std::ostream& a, const vec2& b) {
	a << "(" << b.x << ", " << b.y << ")";
	return a;
}
std::ostream& operator<<(std::ostream& a, const vec3& b) {
	a << "(" << b.x << ", " << b.y << ", " << b.z << ")";
	return a;
}
std::ostream& operator<<(std::ostream& a, const vec4& b) {
	a << "(" << b.x << ", " << b.y << ", " << b.z << ", " << b.w << ")";
	return a;
}
std::wostream& operator<<(std::wostream& a, const vec2& b) {
	a << "(" << b.x << ", " << b.y << ")";
	return a;
}
std::wostream& operator<<(std::wostream& a, const vec3& b) {
	a << "(" << b.x << ", " << b.y << ", " << b.z << ")";
	return a;
}
std::wostream& operator<<(std::wostream& a, const vec4& b) {
	a << "(" << b.x << ", " << b.y << ", " << b.z << ", " << b.w << ")";
	return a;
}

std::istream& operator>>(std::istream& a, vec2& b) {
	a >> b.x >> b.y;
	return a;
}
std::istream& operator>>(std::istream& a, vec3& b) {
	a >> b.x >> b.y >> b.z;
	return a;
}
std::istream& operator>>(std::istream& a, vec4& b) {
	a >> b.x >> b.y >> b.z >> b.w;
	return a;
}
std::wistream& operator>>(std::wistream& a, vec2& b) {
	a >> b.x >> b.y;
	return a;
}
std::wistream& operator>>(std::wistream& a, vec3& b) {
	a >> b.x >> b.y >> b.z;
	return a;
}
std::wistream& operator>>(std::wistream& a, vec4& b) {
	a >> b.x >> b.y >> b.z >> b.w;
	return a;
}

vec3 operator*(const vec3& a, const mat4x4& b) {
	return point(a) * b;
}
vec4 operator*(const vec4& a, const mat4x4& b) {
	return vec4(
		b._11 * a.x + b._21 * a.y + b._31 * a.z + b._41 * a.w,
		b._12 * a.x + b._22 * a.y + b._32 * a.z + b._42 * a.w,
		b._13 * a.x + b._23 * a.y + b._33 * a.z + b._43 * a.w,
		b._14 * a.x + b._24 * a.y + b._34 * a.z + b._44 * a.w
	);
}
mat4x4 operator*(float a, const mat4x4& b) {
	return b * a;
}

std::ostream& operator<<(std::ostream& a, const mat4x4& b) {
	a << "[" << b._11 << ", " << b._12 << "," << b._13 << ", " << b._14 << ",\n "
			 << b._21 << ", " << b._22 << "," << b._23 << ", " << b._24 << ",\n "
			 << b._31 << ", " << b._32 << "," << b._33 << ", " << b._34 << ",\n "
			 << b._41 << ", " << b._42 << "," << b._43 << ", " << b._44 << ",\n " << "]";
	return a;
}
std::wostream& operator<<(std::wostream& a, const mat4x4& b) {
	a << "[" << b._11 << ", " << b._12 << "," << b._13 << ", " << b._14 << ",\n "
			 << b._21 << ", " << b._22 << "," << b._23 << ", " << b._24 << ",\n "
			 << b._31 << ", " << b._32 << "," << b._33 << ", " << b._34 << ",\n "
			 << b._41 << ", " << b._42 << "," << b._43 << ", " << b._44 << ",\n " << "]";
	return a;
}

std::istream& operator>>(std::istream& a, mat4x4& b) {
	a >> b._11 >> b._12 >> b._13 >> b._14
	  >> b._21 >> b._22 >> b._23 >> b._24
	  >> b._31 >> b._32 >> b._33 >> b._34
	  >> b._41 >> b._42 >> b._43 >> b._44;
	return a;
}
std::wistream& operator>>(std::wistream& a, mat4x4& b) {
	a >> b._11 >> b._12 >> b._13 >> b._14
	  >> b._21 >> b._22 >> b._23 >> b._24
	  >> b._31 >> b._32 >> b._33 >> b._34
	  >> b._41 >> b._42 >> b._43 >> b._44;
	return a;
}
