#include "Vec3d.h"

Vec3d::Vec3d(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

double Vec3d::operator*(const Vec3d& vec) {
    return x * vec.x + y * vec.y + z * vec.z;
}

Vec3d Vec3d::operator&(const Vec3d& vec) {
    return Vec3d(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
}