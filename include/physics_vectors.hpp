typedef struct vec2 {
    int x, y;
};
typedef struct vec3 {
    int x, y, z;
};
typedef struct vec4 {
    int x, y, z, w;
};

bool operator==(const vec2& lhs, const vec2& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator==(const vec3& lhs, const vec3& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}
bool operator==(const vec4& lhs, const vec4& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
}