#include "emath.h"

#include <cmath>

const mat4x4 mat4x4::zero = mat4x4(
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
);
const mat4x4 mat4x4::one = mat4x4(
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f
);
const mat4x4 mat4x4::identity = mat4x4(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
);

mat4x4 mat4x4::translation(float x, float y, float z) {
	return mat4x4(identity).setTranslation(x, y, z);
}
mat4x4 mat4x4::translation(const vec3& v) {
	return mat4x4(identity).setTranslation(v);
}
mat4x4 mat4x4::scale(float x, float y, float z) {
	return mat4x4(identity).setScale(x, y, z);
}
mat4x4 mat4x4::scale(const vec3& v) {
	return mat4x4(identity).setScale(v);
}
mat4x4 mat4x4::rotationX(float a) {
	return mat4x4(identity).setRotationX(a);
}
mat4x4 mat4x4::rotationY(float a) {
	return mat4x4(identity).setRotationY(a);
}
mat4x4 mat4x4::rotationZ(float a) {
	return mat4x4(identity).setRotationZ(a);
}
mat4x4 mat4x4::rotation(float x, float y, float z) {
	return rotationX(x) * rotationY(y) * rotationZ(z);
}
mat4x4 mat4x4::rotation(const vec3& v) {
	return rotation(v.x, v.y, v.z);
}
mat4x4 mat4x4::transform(const vec3& v, const vec3& u, const vec3& w) {
	return rotation(w).setScale(u).setTranslation(v);
}
mat4x4 mat4x4::perspective(float fov, float aspect, float znear, float zfar) {
	mat4x4 r;

	r._22 = 1.0f / tan(fov / 2.0f);
	r._11 = r._22 / aspect;
	r._33 = zfar / (zfar - znear);
	r._34 = 1.0f;
	r._43 = -znear * r._33;
	r._44 = 0.0f;

	return r;
}
mat4x4 mat4x4::ortho(float width, float height, float near_plane, float far_plane) {
	mat4x4 r;
	
	r._11 = 2.0f / width;
	r._22 = 2.0f / height;
	r._33 = 1.0f / (far_plane - near_plane);
	r._43 = -near_plane * r._33;
	r._44 = 1.0f;

	return r;
}

mat4x4::mat4x4() : mat4x4(zero) {}
mat4x4::mat4x4(
	float _11, float _12, float _13, float _14,
	float _21, float _22, float _23, float _24,
	float _31, float _32, float _33, float _34,
	float _41, float _42, float _43, float _44
) : _11(_11), _12(_12), _13(_13), _14(_14),
	_21(_21), _22(_22), _23(_23), _24(_24),
	_31(_31), _32(_32), _33(_33), _34(_34),
	_41(_41), _42(_42), _43(_43), _44(_44) {}
mat4x4::mat4x4(
		const vec4& _1, 
		const vec4& _2, 
		const vec4& _3, 
		const vec4& _4
) : mat4x4(
	_1.x, _1.y, _1.z, _1.w,
	_2.x, _2.y, _2.z, _2.w,
	_3.x, _3.y, _3.z, _3.w,
	_4.x, _4.y, _4.z, _4.w
) {}
mat4x4::mat4x4(
	const float _1[4], 
	const float _2[4], 
	const float _3[4], 
	const float _4[4]
) : mat4x4(
	_1[0], _1[1], _1[2], _1[3],
	_2[0], _2[1], _2[2], _2[3],
	_3[0], _3[1], _3[2], _3[3],
	_4[0], _4[1], _4[2], _4[3]
) {}
mat4x4::mat4x4(const mat4x4& m) : mat4x4(
	m._11, m._12, m._13, m._14, 
	m._21, m._22, m._23, m._24, 
	m._31, m._32, m._33, m._34, 
	m._41, m._42, m._43, m._44
) {}
mat4x4::mat4x4(const float mat[4][4]) : mat4x4(
	mat[0][0], mat[0][1], mat[0][2], mat[0][3], 
	mat[1][0], mat[1][1], mat[1][2], mat[1][3], 
	mat[2][0], mat[2][1], mat[2][2], mat[2][3], 
	mat[3][0], mat[3][1], mat[3][2], mat[3][3]
) {}
mat4x4::mat4x4(const float array[16]) : mat4x4(
	array[ 0], array[ 1], array[ 2], array[ 3],
	array[ 4], array[ 5], array[ 6], array[ 7],
	array[ 8], array[ 9], array[10], array[11],
	array[12], array[13], array[14], array[16]
) {}
mat4x4::mat4x4(const vec4 rows[4]) : mat4x4(
	rows[0].x, rows[0].y, rows[0].z, rows[0].w,
	rows[1].x, rows[1].y, rows[1].z, rows[1].w,
	rows[2].x, rows[2].y, rows[2].z, rows[2].w,
	rows[3].x, rows[3].y, rows[3].z, rows[3].w
) {}
mat4x4::~mat4x4() {}

float mat4x4::getDeterminant() const {
	return mat[0][0] * mat[1][1] * mat[2][2] * mat[3][3] -
		   mat[0][0] * mat[1][1] * mat[2][3] * mat[3][2] -
		   mat[0][0] * mat[1][2] * mat[2][1] * mat[3][3] +
		   mat[0][0] * mat[1][2] * mat[2][3] * mat[3][1] +
		   mat[0][0] * mat[1][3] * mat[2][1] * mat[3][2] -
		   mat[0][0] * mat[1][3] * mat[2][2] * mat[3][1] -
		   mat[0][1] * mat[1][0] * mat[2][2] * mat[3][3] +
		   mat[0][1] * mat[1][0] * mat[2][3] * mat[3][2] +
		   mat[0][1] * mat[1][2] * mat[2][0] * mat[3][3] -
		   mat[0][1] * mat[1][2] * mat[2][3] * mat[3][0] -
		   mat[0][1] * mat[1][3] * mat[2][0] * mat[3][2] +
		   mat[0][1] * mat[1][3] * mat[2][2] * mat[3][0] +

		   mat[0][2] * mat[1][0] * mat[2][1] * mat[3][3] -
		   mat[0][2] * mat[1][0] * mat[2][3] * mat[3][1] -
		   mat[0][2] * mat[1][1] * mat[2][0] * mat[3][3] +
		   mat[0][2] * mat[1][1] * mat[2][3] * mat[3][0] +
		   mat[0][2] * mat[1][3] * mat[2][0] * mat[3][1] -
		   mat[0][2] * mat[1][3] * mat[2][1] * mat[3][0] -
		   mat[0][3] * mat[1][0] * mat[2][1] * mat[3][2] +
		   mat[0][3] * mat[1][0] * mat[2][2] * mat[3][1] +
		   mat[0][3] * mat[1][1] * mat[2][0] * mat[3][2] -
		   mat[0][3] * mat[1][1] * mat[2][2] * mat[3][0] -
		   mat[0][3] * mat[1][2] * mat[2][0] * mat[3][1] +
		   mat[0][3] * mat[1][2] * mat[2][1] * mat[3][0];
}
float mat4x4::getMinor(const int rows[3], const int columns[3]) const {
	return mat[rows[0]][columns[0]] * mat[rows[1]][columns[1]] * mat[rows[2]][columns[2]] -
		   mat[rows[0]][columns[0]] * mat[rows[1]][columns[2]] * mat[rows[2]][columns[1]] -
		   mat[rows[0]][columns[1]] * mat[rows[1]][columns[0]] * mat[rows[2]][columns[2]] +
		   mat[rows[0]][columns[1]] * mat[rows[1]][columns[2]] * mat[rows[2]][columns[0]] +
		   mat[rows[0]][columns[2]] * mat[rows[1]][columns[0]] * mat[rows[2]][columns[1]] -
		   mat[rows[0]][columns[2]] * mat[rows[1]][columns[1]] * mat[rows[2]][columns[0]];
}
float mat4x4::getMinor2(const int rows[2], const int columns[2]) const {
	return mat[rows[0]][columns[0]] * mat[rows[1]][columns[1]] - mat[rows[0]][columns[1]] * mat[rows[1]][columns[0]];
}
mat4x4 mat4x4::getInverse() const {
	float det = getDeterminant();
	if (det < 0.001f && det > -0.001f)
		return mat4x4();
	
	mat4x4 ret;
	
	int cuts[4][4] = {
		{1, 2, 3},
		{0, 2, 3},
		{0, 1, 3},
		{0, 1, 2}
	};
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int sgn;
			if ((i + j) % 2 == 0)
				sgn = 1;
			else
				sgn = -1;
	
			ret[j][i] = sgn * getMinor(cuts[i], cuts[j]);
		}
	}
	
	ret /= det;
	
	return ret;
}

vec3 mat4x4::getXDirection() const {
	return rows[0];
}
vec3 mat4x4::getYDirection() const {
	return rows[1];
}
vec3 mat4x4::getZDirection() const {
	return rows[2];
}
vec3 mat4x4::getTranslation() const {
	return rows[3];
}

mat4x4& mat4x4::setTranslation(float x, float y, float z) {
	_41 = x;
	_42 = y;
	_43 = z;

	return *this;
}
mat4x4& mat4x4::setTranslation(const vec3& v) {
	_41 = v.x;
	_42 = v.y;
	_43 = v.z;

	return *this;
}
mat4x4& mat4x4::setScale(float x, float y, float z) {
	rows[0] *= x;
	rows[1] *= y;
	rows[2] *= z;

	return *this;
}
mat4x4& mat4x4::setScale(const vec3& v) {
	for (int i = 0; i < 3; i++)
		rows[i] *= v[i];

	return *this;
}
mat4x4& mat4x4::setRotationX(float a) {
	_22 =  _22 * cos(a) + _32 * sin(a);
	_23 =  _23 * cos(a) + _33 * sin(a);
	_32 = -_22 * sin(a) + _32 * cos(a);
	_33 = -_23 * sin(a) + _33 * cos(a);

	return *this;
}
mat4x4& mat4x4::setRotationY(float a) {
	_33 =  _33 * cos(a) + _13 * sin(a);
	_31 =  _31 * cos(a) + _11 * sin(a);
	_13 = -_33 * sin(a) + _31 * cos(a);
	_11 = -_31 * sin(a) + _11 * cos(a);

	return *this;
}
mat4x4& mat4x4::setRotationZ(float a) {
	_11 =  _11 * cos(a) + _21 * sin(a);
	_12 =  _12 * cos(a) + _22 * sin(a);
	_21 = -_11 * sin(a) + _21 * cos(a);
	_22 = -_12 * sin(a) + _22 * cos(a);

	return *this;
}

const float* mat4x4::operator[](std::size_t idx) const {
	return &mat[idx][0];
}
const float& mat4x4::operator*() const {
	return _11;
}
const float* mat4x4::operator+(std::size_t idx) const {
	return &_11 + idx;
}
float* mat4x4::operator[](std::size_t idx) {
	return &mat[idx][0];
}
float& mat4x4::operator*() {
	return _11;
}
float* mat4x4::operator+(std::size_t idx) {
	return &_11 + idx;
}

mat4x4 mat4x4::operator+() const {
	return *this;
}
mat4x4 mat4x4::operator-() const {
	return mat4x4(-_11, -_12, -_13, -_14, -_21, -_22, -_23, -_24, -_31, -_32, -_33, -_34, -_41, -_42, -_43, -_44);
}

mat4x4 mat4x4::operator+(const mat4x4& b) const {
	return mat4x4(rows[0] + b.rows[0], rows[1] + b.rows[1], rows[2] + b.rows[2], rows[3] + b.rows[3]);
}
mat4x4 mat4x4::operator-(const mat4x4& b) const {
	return mat4x4(rows[0] - b.rows[0], rows[1] - b.rows[1], rows[2] - b.rows[2], rows[3] - b.rows[3]);
}

mat4x4 mat4x4::operator*(const mat4x4& b) const {
	mat4x4 r;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			r[i][j] = mat[i][0] * b[0][j] + mat[i][1] * b[1][j] + mat[i][2] * b[2][j] + mat[i][3] * b[3][j];
	return r;
}
vec3 mat4x4::operator*(const vec3& b) const {
	return *this * point(b);
}
vec4 mat4x4::operator*(const vec4& b) const {
	return vec4(
		_11 * b.x + _12 * b.y + _13 * b.z + _14 * b.w,
		_21 * b.x + _22 * b.y + _23 * b.z + _24 * b.w,
		_31 * b.x + _32 * b.y + _33 * b.z + _34 * b.w,
		_41 * b.x + _42 * b.y + _43 * b.z + _44 * b.w
	);
}
mat4x4 mat4x4::operator*(float b) const {
	return mat4x4(
		_11 * b, _12 * b, _13 * b, _14 * b,
		_21 * b, _22 * b, _23 * b, _24 * b,
		_31 * b, _32 * b, _33 * b, _34 * b,
		_41 * b, _42 * b, _43 * b, _44 * b
	);
}
mat4x4 mat4x4::operator/(float b) const {
	return mat4x4(
		_11 / b, _12 / b, _13 / b, _14 / b,
		_21 / b, _22 / b, _23 / b, _24 / b,
		_31 / b, _32 / b, _33 / b, _34 / b,
		_41 / b, _42 / b, _43 / b, _44 / b
	);
}

mat4x4& mat4x4::operator+=(const mat4x4& b) {
	return *this = *this + b;
}
mat4x4& mat4x4::operator-=(const mat4x4& b) {
	return *this = *this - b;
}

mat4x4& mat4x4::operator*=(const mat4x4& b) {
	return *this = *this * b;
}
mat4x4& mat4x4::operator*=(float b) {
	return *this = *this * b;
}
mat4x4& mat4x4::operator/=(float b) {
	return *this = *this / b;
}
