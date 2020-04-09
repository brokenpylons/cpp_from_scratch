//
// Created by ziga on 4/9/20.
//

#include "Point2.h"
#include <iostream>

VTable Point2_vtable = {
    /*scale = */reinterpret_cast<void(*)(void *, double)>(Point2_scale),
    /*getY = */reinterpret_cast<double(*)(void *)>(Point2_getY),
    /*getZ = */reinterpret_cast<double(*)(void *)>(0),
    /*dtor = */reinterpret_cast<void(*)(void *)>(Point2_dtor)
};

/*
Point2::Point2(const double x, const double y)
    : x(x), y(y) {
    std::cout << "Constructor Point2" << std::endl;
}
*/
Point2 Point2_ctor(const double x, const double y) {
    Point2 self = {&Point2_vtable, x, y};
    std::cout << "Constructor Point2" << std::endl;
    return self;
}

/*
Point2::~Point2() {
    std::cout << "Destructor Point2" << std::endl;
}
*/
void Point2_dtor(Point2 *const) {
    std::cout << "Destructor Point2" << std::endl;
}

void Point2_dtor_virtual(Point2 *const self) {
    self->vptr->dtor(self);
}

/*
double Point2::getX() const {
    return this->x;
}
*/
double Point2_getX(Point2 *const self) {
    return self->x;
}

/*
void Point2::setX(const double x) {
    this->x = x;
}
*/
void Point2_setX(Point2 *const self, const double x) {
    self->x = x;
}

/*
double Point2::getY() const {
    return y;
}
*/
double Point2_getY(Point2 *const self) {
    return self->y;
}

double Point2_getY_virtual(Point2 *const self) {
    return self->vptr->getY(self);
}

/*
void Point2::setY(const double y) {
    this->y = y;
}
*/
void Point2_setY(Point2 *const self, const double y) {
    self->y = y;
}


double Point2_getZ_virtual(Point2 *const self) {
    return self->vptr->getZ(self);
}

/*
void Point2::scale(const double s) {
    this->x *= s;
    this->y *= s;
}
*/
void Point2_scale(Point2 *const self, const double s) {
    self->x *= s;
    self->y *= s;
}

void Point2_scale_virtual(Point2 *const self, double s) {
    self->vptr->scale(self, s);
}
