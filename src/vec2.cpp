#include "emath.h"

#include <cmath>

const vec2 vec2::zero  = vec2( 0.0f,  0.0f);
const vec2 vec2::one   = vec2( 1.0f,  1.0f);
const vec2 vec2::right = vec2( 1.0f,  0.0f);
const vec2 vec2::left  = vec2(-1.0f,  0.0f);
const vec2 vec2::up    = vec2( 0.0f,  1.0f);
const vec2 vec2::down  = vec2( 0.0f, -1.0f);

vec2::vec2()                     : x(0.0f)    , y(0.0f)     {}
vec2::vec2(float x, float y)     : x(x)       , y(y)        {}
vec2::vec2(const vec2& src)      : x(src.x)   , y(src.y)    {}
vec2::vec2(const vec3& src)      : x(src.x)   , y(src.y)    {}
vec2::vec2(const vec4& src)      : x(src.x)   , y(src.y)    {}
vec2::vec2(const float array[2]) : x(array[0]), y(array[1]) {}
vec2::~vec2()                                               {}

float vec2::getMagnitude() const {
	return std::sqrt(x * x + y * y);
}
vec2 vec2::getNormalized() const {
	return *this / this->getMagnitude();
}

const float& vec2::operator[](std::size_t idx) const {
	return array[idx];
}
const float& vec2::operator*() const {
	return x;
}
const float* vec2::operator+(std::size_t idx) const {
	return &x + idx;
}
float& vec2::operator[](std::size_t idx) {
	return array[idx];
}
float& vec2::operator*() {
	return x;
}
float* vec2::operator+(std::size_t idx) {
	return &x + idx;
}

vec2 vec2::operator+() const {
	return vec2(x, y);
}
vec2 vec2::operator-() const {
	return vec2(-x, -y);
}

vec2 vec2::operator+(const vec2& b) const {
	return vec2(x + b.x, y + b.y);
}
vec3 vec2::operator+(const vec3& b) const {
	return vec3(x + b.x, y + b.y, b.z);
}
vec4 vec2::operator+(const vec4& b) const {
	return vec4(x + b.x, y + b.y, b.z, b.w);
}

vec2 vec2::operator-(const vec2& b) const {
	return vec2(x - b.x, y - b.y);
}
vec3 vec2::operator-(const vec3& b) const {
	return vec3(x - b.x, y - b.y, -b.z);
}
vec4 vec2::operator-(const vec4& b) const {
	return vec4(x - b.x, y - b.y, -b.z, -b.w);
}

vec2 vec2::operator*(float b) const {
	return vec2(x * b, y * b);
}
vec2 vec2::operator/(float b) const {
	return vec2(x / b, y / b);
}

vec2& vec2::operator+=(const vec2& b) {
	return *this = *this + b;
}
vec2& vec2::operator-=(const vec2& b) {
	return *this = *this - b;
}

vec2& vec2::operator*=(float b) {
	return *this = *this * b;
}
vec2& vec2::operator/=(float b) {
	return *this = *this / b;
}
