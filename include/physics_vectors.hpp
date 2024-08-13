#include <cmath>
#include <iostream>

using namespace std;

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
    vec3& operator+=(vec3 rhs);
    vec3& operator-=(vec3 rhs);
    vec3& operator*=(int rhs);
    vec3& operator*=(vec3 rhs);
    vec3 operator+(vec3 rhs) {
        return {this->x + rhs.x, this->y + rhs.y, this->z + rhs.z};
    }
    vec3 operator-(vec3 rhs) {
        return {this->x - rhs.x, this->y - rhs.y, this->z - rhs.z};;
    }
    vec3 operator*(int rhs) {
        return {this->x * rhs, this->y * rhs, this->z * rhs};
    }
    vec3 operator*(vec3 rhs) {
        return {this->x * rhs.x, this->y * rhs.y, this->z * rhs.z};
    }

    int64_t norm() {
        return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
    }
    vec3 cross(vec3 x) {
        vec3 ret;
        ret.x = this->y * x.z - this->z * x.y;
        ret.y = this->z * x.x - this->x * x.z;
        ret.z = this->x * x.y - this->y * x.x;
        return ret;
    }
    int64_t dist(vec3 x) {
        vec3 y(this->x, this->y, this->z);
        return (x - y).norm();
    }

};
class vec4 {
    public:
    int64_t x, y, z, w;
    vec3 v;
    vec4(int64_t x = 0, int64_t y = 0, int64_t z = 0, int64_t w = 1) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        v = {x, y, z};
    }
};

// operation operators {

bool operator==(vec2& lhs, vec2& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator==(vec3 lhs, vec3 rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}
bool operator==(vec4& lhs, vec4& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
}

// }

// operation changin operators {

vec3& vec3::operator+=(vec3 rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
}
vec3& vec3::operator-=(vec3 rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
}
vec3& vec3::operator*=(int rhs) {
    this->x *= rhs;
    this->y *= rhs;
    this->z *= rhs;
    return *this;
}
vec3& vec3::operator*=(vec3 rhs) {
    this->x *= rhs.x;
    this->y *= rhs.y;
    this->z *= rhs.z;
    return *this;
}

// }

// print operators {

ostream &operator<<(ostream &os, vec2& x) {
    return os << x.x << ' ' << x.y;
}
ostream &operator<<(ostream &os, vec3 x) {
    return os << x.x << ' ' << x.y << ' ' << x.z;
}
ostream &operator<<(ostream &os, vec4& x) {
    return os << x.x << ' ' << x.y << ' ' << x.z << ' ' << x.w;
}

// }

typedef int64_t int64;
typedef int64_t i64;