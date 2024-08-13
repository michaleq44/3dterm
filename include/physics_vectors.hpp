#include <cmath>
class vec2 {
    public:
    int64_t x, y;
    vec2(int64_t x = 0, int64_t y = 0) {
        this->x = x;
        this->y = y;
    }
};
class vec3 {
    public:
    int64_t x, y, z;
    vec3(int64_t x = 0, int64_t y = 0, int64_t z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    vec3& operator+=(const vec3& rhs);
    vec3& operator-=(const vec3& rhs);
    vec3& operator*=(const int& rhs);
    vec3& operator*=(const vec3& rhs);

    int64_t norm() {
        return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
    }
    vec3 cross(const vec3& x) {
        vec3 ret;
        ret.x = this->y * x.z - this->z * x.y;
        ret.y = this->z * x.x - this->x * x.z;
        ret.z = this->x * x.y - this->y * x.x;
        return ret;
    }
};
class vec4 {
    public:
    int64_t x, y, z, w;
    vec4(int64_t x = 0, int64_t y = 0, int64_t z = 0, int64_t w = 1) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
};

// operation operators {

bool operator==(const vec2& lhs, const vec2& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator==(const vec3& lhs, const vec3& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}
bool operator==(const vec4& lhs, const vec4& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
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

// operation changin operators {

vec3& vec3::operator+=(const vec3& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
}
vec3& vec3::operator-=(const vec3& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
}
vec3& vec3::operator*=(const int& rhs) {
    this->x *= rhs;
    this->y *= rhs;
    this->z *= rhs;
    return *this;
}
vec3& vec3::operator*=(const vec3& rhs) {
    this->x *= rhs.x;
    this->y *= rhs.y;
    this->z *= rhs.z;
    return *this;
}

// }

typedef int64_t int64;
typedef int64_t i64;