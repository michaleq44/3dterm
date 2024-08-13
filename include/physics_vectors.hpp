#include <cmath>
typedef struct vec2 {
    int64_t x, y;
};
typedef struct vec3 {
    int64_t x, y, z;
};
typedef struct vec4 {
    vec3 v;
    int64_t w;
};

// operation operators {

bool operator==(const vec2& lhs, const vec2& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator==(const vec3& lhs, const vec3& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}
bool operator==(const vec4& lhs, const vec4& rhs) {
    return lhs.v == rhs.v && lhs.w == rhs.w;
}
vec3 operator+(const vec3& lhs, const vec3& rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}
vec3 operator-(const vec3& lhs, const vec3& rhs) {
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};;
}
vec3 operator*(const vec3& lhs, const int& rhs) {
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}
vec3 operator*(const int& lhs, const vec3& rhs) {
    return {rhs.x * lhs, rhs.y * lhs, rhs.z * lhs};
}
vec3 operator*(const vec3& lhs, const vec3& rhs) {
    return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
}

// }

// operation functions {

int _vec3norm(const vec3& x) {
    return sqrt(x.x*x.x + x.y*x.y + x.z*x.z);
}
vec3 _vec3cross(vec3& x, vec3& y) {
    return {x.y*y.z - x.z*y.y, x.z*y.x - x.x*y.z, x.x*y.y - x.y*y.x};
}

// }