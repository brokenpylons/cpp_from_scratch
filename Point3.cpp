//
// Created by ziga on 4/9/20.
//

#include "Point3.h"
#include <iostream>

VTable Point3_vtable = {
    /*scale = */reinterpret_cast<void(*)(void *, double)>(Point3_scale),
    /*getY = */reinterpret_cast<double(*)(void *)>(Point2_getY),
    /*getZ = */reinterpret_cast<double(*)(void *)>(Point3_getZ),
    /*dtor = */reinterpret_cast<void(*)(void *)>(Point3_dtor)
};

/*
Point3::Point3(const double x, const double y, const double z)
    : Point2(x, y), z(z) {
    std::cout << "Constructor Poin3" << std::endl;
}
*/
Point3 Point3_ctor(const double x, const double y, const double z) {
    Point2 base = Point2_ctor(x, y);
    base.vptr = &Point3_vtable;
    Point3 self = {base, z};

    std::cout << "Constructor Poin3" << std::endl;
    return self;
}

/*
Point3::Point3() {
    std::cout << "Destructor Poin3" << std::endl;
}
*/
void Point3_dtor(Point3 *const self) {
    std::cout << "Destructor Point3" << std::endl;
    Point2_dtor(reinterpret_cast<Point2 *>(self));
}

/*
double Point3::getZ() const {
    return this->z;
}
*/
double Point3_getZ(Point3 *const self) {
    return self->z;
}

/*
void Point3::setZ(const double z) {
    this->z = z;
}
*/
void Point3_setZ(Point3 *const self, const double z) {
    self->z = z;
}

/*
void Point3::scale(const double s) {
    Point2::scale(s);
    z *= s;
}
*/
void Point3_scale(Point3 *const self, const double s) {
    Point2_scale(reinterpret_cast<Point2 *>(self), s);
    self->z *= s;
}
