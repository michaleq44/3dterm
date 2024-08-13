#include <cmath>
#include <iostream>

using namespace std;

typedef int64_t int64;
typedef int64_t i64;
typedef float float32;
typedef float f32;
typedef double float64;
typedef double f64;

class vec2 {
    public:
    f64 x, y;
    vec2(f64 x = 0, f64 y = 0) {
        this->x = x;
        this->y = y;
    }
};
class vec3 {
    public:
    f64 x, y, z;
    vec3(f64 x = 0, f64 y = 0, f64 z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    vec3& operator+=(vec3 rhs);
    vec3& operator-=(vec3 rhs);
    vec3& operator*=(f64 rhs) {
        this->x *= rhs;
        this->y *= rhs;
        this->z *= rhs;
        return *this;
    }
    vec3& operator/=(f64 rhs) {
        this->x /= rhs;
        this->y /= rhs;
        this->z /= rhs;
        return *this;
    }
    vec3 operator+(vec3 rhs) {
        return {this->x + rhs.x, this->y + rhs.y, this->z + rhs.z};
    }
    vec3 operator-(vec3 rhs) {
        return {this->x - rhs.x, this->y - rhs.y, this->z - rhs.z};;
    }
    vec3 operator*(f64 rhs) {
        return {this->x * rhs, this->y * rhs, this->z * rhs};
    }
    f64 operator*(vec3 rhs) {
        return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
    }

    vec3 operator/(f64 rhs) {
        return {this->x / rhs, this->y / rhs, this->z / rhs};
    }

    f64 norm() {
        return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
    }
    vec3 cross(vec3 x) {
        vec3 ret;
        ret.x = this->y * x.z - this->z * x.y;
        ret.y = this->z * x.x - this->x * x.z;
        ret.z = this->x * x.y - this->y * x.x;
        return ret;
    }
    f64 dist(vec3 x) {
        vec3 y(this->x, this->y, this->z);
        return (x - y).norm();
    }
    f64 angle(vec3 y) {
        vec3 x(this->x, this->y, this->z);
        return acos((x*y)/(x.norm()*y.norm())) * 57.296;
    }
};
class vec4 {
    public:
    f64 x, y, z, w;
    vec3 v;
    vec4(f64 x = 0, f64 y = 0, f64 z = 0, f64 w = 1) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        this->v = {x, y, z};
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

// }

// prf64 operators {

ostream &operator<<(ostream &os, vec2 x) {
    return os << x.x << ' ' << x.y;
}
ostream &operator<<(ostream &os, vec3 x) {
    return os << x.x << ' ' << x.y << ' ' << x.z;
}
ostream &operator<<(ostream &os, vec4 x) {
    return os << x.x << ' ' << x.y << ' ' << x.z << ' ' << x.w;
}

// }