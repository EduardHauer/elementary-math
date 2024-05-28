#include "emath.h"

#include <cmath>

const vec4 vec4::zero     = vec4( 0.0f,  0.0f,  0.0f,  0.0f);
const vec4 vec4::one      = vec4( 1.0f,  1.0f,  1.0f,  1.0f);
const vec4 vec4::right    = vec4( 1.0f,  0.0f,  0.0f,  0.0f);
const vec4 vec4::left     = vec4(-1.0f,  0.0f,  0.0f,  0.0f);
const vec4 vec4::up       = vec4( 0.0f,  1.0f,  0.0f,  0.0f);
const vec4 vec4::down     = vec4( 0.0f, -1.0f,  0.0f,  0.0f);
const vec4 vec4::forward  = vec4( 0.0f,  0.0f,  1.0f,  0.0f);
const vec4 vec4::back     = vec4( 0.0f,  0.0f, -1.0f,  0.0f);
const vec4 vec4::wforward = vec4( 0.0f,  0.0f,  0.0f,  1.0f);
const vec4 vec4::wback    = vec4( 0.0f,  0.0f,  0.0f, -1.0f);

vec4::vec4()                                   : x(0.0f),     y(0.0f),     z(0.0f),     w(0.0f)     {}
vec4::vec4(float x, float y)                   : x(x),        y(y),        z(0.0f),     w(0.0f)     {}
vec4::vec4(float x, float y, float z)          : x(x),        y(y),        z(z),        w(0.0f)     {}
vec4::vec4(float x, float y, float z, float w) : x(x),        y(y),        z(z),        w(w)        {}
vec4::vec4(const vec2& src)                    : x(src.x),    y(src.y),    z(0.0f),     w(0.0f)     {}
vec4::vec4(const vec3& src)                    : x(src.x),    y(src.y),    z(src.z),    w(0.0f)     {}
vec4::vec4(const vec4& src)                    : x(src.x),    y(src.y),    z(src.z),    w(src.w)    {}
vec4::vec4(const float array[4])               : x(array[0]), y(array[1]), z(array[2]), w(array[3]) {}
vec4::~vec4()                                                                                       {}

float vec4::getMagnitude() const {
	return std::sqrt(x * x + y * y + z * z + w * w);
}
vec4 vec4::getNormalized() const {
	return *this / this->getMagnitude();
}

const float& vec4::operator[](std::size_t idx) const {
	return array[idx];
}
const float& vec4::operator*() const {
	return x;
}
const float* vec4::operator+(std::size_t idx) const {
	return &x + idx;
}
float& vec4::operator[](std::size_t idx) {
	return array[idx];
}
float& vec4::operator*() {
	return x;
}
float* vec4::operator+(std::size_t idx) {
	return &x + idx;
}

vec4 vec4::operator+() const {
	return vec4(x, y, z, w);
}
vec4 vec4::operator-() const {
	return vec4(-x, -y, -z, -w);
}

vec4 vec4::operator+(const vec4& b) const {
	return vec4(x + b.x, y + b.y, z + b.z, w + b.w);
}
vec4 vec4::operator+(const vec3& b) const {
	return vec4(x + b.x, y + b.y, z + b.z, w);
}
vec4 vec4::operator+(const vec2& b) const {
	return vec4(x + b.x, y + b.y, z, w);
}

vec4 vec4::operator-(const vec2& b) const {
	return vec4(x - b.x, y - b.y, z, w);
}
vec4 vec4::operator-(const vec3& b) const {
	return vec4(x - b.x, y - b.y, z - b.z, w);
}
vec4 vec4::operator-(const vec4& b) const {
	return vec4(x - b.x, y - b.y, z - b.z, w - b.w);
}

vec4 vec4::operator*(float b) const {
	return vec4(x * b, y * b, z * b, w * b);
}
vec4 vec4::operator/(float b) const {
	return vec4(x / b, y / b, z / b, w / b);
}

vec4& vec4::operator+=(const vec4& b) {
	return *this = *this + b;
}
vec4& vec4::operator-=(const vec4& b) {
	return *this = *this - b;
}

vec4& vec4::operator*=(float b) {
	return *this = *this * b;
}
vec4& vec4::operator/=(float b) {
	return *this = *this / b;
}
