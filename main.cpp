#include <iostream>
#include "emath.h"

int main() {
	vec2 u(1.0f, 2.0f);
	vec3 v(0.5f, 0.3f, 0.1f);
	vec3 w = v + u;
	std::cout << w.x << " " << w.y << " " << w.z << std::endl;
	std::cout << cross(v, w) << std::endl;
	return 0;
}
