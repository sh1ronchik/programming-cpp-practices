#ifndef VEC3D_H
#define VEC3D_H

class Vec3d {
public:
    double x, y, z;

    Vec3d(double x_ = 0, double y_ = 0, double z_ = 0);
    double operator*(const Vec3d& vec);
    Vec3d operator&(const Vec3d& vec);
};

#endif 