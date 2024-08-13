#include "physics_vectors.hpp"

int main() {
    vec2 x;
    vec3 y;
    vec4 z;

    cout << x << endl << y << endl << z << endl;
    vec3 a(1, 2);
    a *= 4;
    cout << a;

    return 0;
}