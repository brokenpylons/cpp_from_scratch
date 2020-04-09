//
// Created by ziga on 4/9/20.
//

#ifndef VAJE4_POINT3_H
#define VAJE4_POINT3_H

#include "Point2.h"

/*
class Point3 : public Point2 {
public:
    Point3(double z);
    ~Point3();
    double getZ() const;
    void setZ(double z);
public:
    double z;
};
*/

struct Point3 {
    Point2 base;
    double z;
};

Point3 Point3_ctor(double, double, double);
void Point3_dtor(Point3 *);

double Point3_getZ(Point3 *);
void Point3_setZ(Point3 *, double);

void Point3_scale(Point3 *, double);

#endif //VAJE4_POINT3_H
