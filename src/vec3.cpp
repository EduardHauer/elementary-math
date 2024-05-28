#include "emath.h"

#include <cmath>

const vec3 vec3::zero    = vec3( 0.0f,  0.0f,  0.0f);
const vec3 vec3::one     = vec3( 1.0f,  1.0f,  1.0f);
const vec3 vec3::right   = vec3( 1.0f,  0.0f,  0.0f);
const vec3 vec3::left    = vec3(-1.0f,  0.0f,  0.0f);
const vec3 vec3::up      = vec3( 0.0f,  1.0f,  0.0f);
const vec3 vec3::down    = vec3( 0.0f, -1.0f,  0.0f);
const vec3 vec3::forward = vec3( 0.0f,  0.0f,  1.0f);
const vec3 vec3::back    = vec3( 0.0f,  0.0f, -1.0f);

vec3::vec3()                          : x(0.0f)    , y(0.0f)    , z(0.0f)     {}
vec3::vec3(float x, float y)          : x(x)       , y(y)       , z(0.0f)     {}
vec3::vec3(float x, float y, float z) : x(x)       , y(y)       , z(z)        {}
vec3::vec3(const vec2& src)           : x(src.x)   , y(src.y)   , z(0.0f)     {}
vec3::vec3(const vec3& src)           : x(src.x)   , y(src.y)   , z(src.z)    {}
vec3::vec3(const vec4& src)           : x(src.x)   , y(src.y)   , z(src.z)    {}
vec3::vec3(const float array[3])      : x(array[0]), y(array[1]), z(array[2]) {}
vec3::~vec3()                                                                 {}

float vec3::getMagnitude() const {
	return std::sqrt(x * x + y * y + z * z);
}
vec3 vec3::getNormalized() const {
	return *this / this->getMagnitude();
}

const float& vec3::operator[](std::size_t idx) const {
	return array[idx];
}
const float& vec3::operator*() const {
	return x;
}
const float* vec3::operator+(std::size_t idx) const {
	return &x + idx;
}
float& vec3::operator[](std::size_t idx) {
	return array[idx];
}
float& vec3::operator*() {
	return x;
}
float* vec3::operator+(std::size_t idx) {
	return &x + idx;
}

vec3 vec3::operator+() const {
	return vec3(x, y, z);
}
vec3 vec3::operator-() const {
	return vec3(-x, -y, -z);
}

vec3 vec3::operator+(const vec2& b) const {
	return vec3(x + b.x, y + b.y, z);
}
vec3 vec3::operator+(const vec3& b) const {
	return vec3(x + b.x, y + b.y, z + b.z);
}
vec4 vec3::operator+(const vec4& b) const {
	return vec4(x + b.x, y + b.y, z + b.z, b.w);
}

vec3 vec3::operator-(const vec2& b) const {
	return vec3(x - b.x, y - b.y, z);
}
vec3 vec3::operator-(const vec3& b) const {
	return vec3(x - b.x, y - b.y, z - b.z);
}
vec4 vec3::operator-(const vec4& b) const {
	return vec4(x - b.x, y - b.y, z - b.z, -b.w);
}

vec3 vec3::operator*(float b) const {
	return vec3(x * b, y * b, z * b);
}
vec3 vec3::operator/(float b) const {
	return vec3(x / b, y / b, z / b);
}

vec3& vec3::operator+=(const vec3& b) {
	return *this = *this + b;
}
vec3& vec3::operator-=(const vec3& b) {
	return *this = *this - b;
}

vec3& vec3::operator*=(float b) {
	return *this = *this * b;
}
vec3& vec3::operator/=(float b) {
	return *this = *this / b;
}
