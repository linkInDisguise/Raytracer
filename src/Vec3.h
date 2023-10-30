#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class Vec3 {
public:
  double e[3];
  Vec3() : e{0, 0, 0} {}
  Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

  [[nodiscard]] double x() const { return e[0]; }
  [[nodiscard]] double y() const { return e[1]; }
  [[nodiscard]] double z() const { return e[2]; }

  Vec3 operator-() const { return {-x(), -y(), -z()}; }
  double operator[](int i) const { return e[i]; }
  double& operator[](int i) { return e[i]; }

  Vec3& operator+=(const Vec3 &v) {
    e[0] += v.x();
    e[1] += v.y();
    e[2] += v.z();
    return *this;
  }

  Vec3& operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
  }

  Vec3& operator/=(const double t) {
    return *this *= 1/t;
  }

  double length() const {
    return sqrt(lengthSquared());
  }

  double lengthSquared() const {
    return x() * x() + y() * y() + z() * z();
  }
};

using Point3 = Vec3;
using Color = Vec3;

inline std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
  return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline Vec3 operator+(const Vec3 &u, const Vec3 &v) {
  return {u.x() + v.x(), u.y() + v.y(), u.z() + v.z()};
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v) {
  return {u.x() - v.x(), u.y() - v.y(), u.z() - v.z()};
}

inline Vec3 operator*(const double t, const Vec3 &v) {
  return {t * v.x(), t * v.y(), t * v.z()};
}

inline Vec3 operator*(const Vec3 &u, const Vec3 &v) {
  return {u.x() * v.x(), u.y() * v.y(), u.z() * v.z()};
}

inline Vec3 operator/(Vec3 v, double t) {
  return (1 / t) * v;
}

inline double dot(const Vec3 &u, const Vec3 &v) {
  return u.x() * v.x() +
         u.y() * v.y() +
         u.z() * v.z();
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v) {
  return {u.y() * v.z() - u.z() * v.y(),
              u.z() * v.x() - u.x() * v.z(),
              u.x() * v.y() - u.y() * v.x()};
}

inline Vec3 unitVector(Vec3 v) {
  return v / v.length();
}
#endif //VEC3_H
