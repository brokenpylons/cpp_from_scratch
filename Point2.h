//
// Created by ziga on 4/9/20.
//

#ifndef VAJE4_POINT2_H
#define VAJE4_POINT2_H

/*
class Point2 {
public:
    Point2(double, double);
    virtual ~Point2();

    double getX() const;
    void setX(double);
    virtual double getY() const;
    void setY(double);

    virtual void scale(double);

    virtual double getZ() const = 0;
private:
    double x;
    double y;
};
*/

struct VTable {
    void (*scale)(void *, double);
    double (*getY)(void *);
    double (*getZ)(void *);
    double (*dtor)(void *);
};

struct Point2 {
    VTable *vptr;
    double x;
    double y;
};

Point2 Point2_ctor(double, double);
void Point2_dtor(Point2 *);
void Point2_dtor_virtual(Point2 *);

double Point2_getX(Point2 *);
void Point2_setX(Point2 *, double);

double Point2_getY(Point2 *);
double Point2_getY_virtual(Point2 *);
void Point2_setY(Point2 *, double);

double Point2_getZ_virtual(Point2 *);

void Point2_scale(Point2 *, double);
void Point2_scale_virtual(Point2 *, double);

#endif //VAJE4_POINT2_H
