#include <iostream>
#include <vector>
#include "Point2.h"
#include "Point3.h"

int main() {
    std::cout << "-- Point2" << std::endl;
    Point2 p2 = Point2_ctor(1, 2);
    std::cout << Point2_getX(&p2) << std::endl;
    std::cout << Point2_getY(&p2) << std::endl;
    Point2_setX(&p2, 3);
    std::cout << Point2_getX(&p2) << std::endl;
    std::cout << Point2_getY(&p2) << std::endl;
    Point2_scale(&p2, 2);
    std::cout << Point2_getX(&p2) << std::endl;
    std::cout << Point2_getY(&p2) << std::endl;

    std::cout << "-- Point3" << std::endl;
    Point3 p3 = Point3_ctor(1, 2, 3);
    std::cout << Point2_getX(reinterpret_cast<Point2 *>(&p3)) << std::endl;
    std::cout << Point2_getY(reinterpret_cast<Point2 *>(&p3)) << std::endl;
    std::cout << Point3_getZ(&p3) << std::endl;

    std::cout << "-- Point2 * -> Point3" << std::endl;
    Point2 *ptr = reinterpret_cast<Point2 *>(&p3);
    std::cout << Point2_getX(ptr) << std::endl;
    std::cout << Point2_getY(ptr) << std::endl;

    Point2_scale_virtual(ptr, 2);
    std::cout << Point2_getX(ptr) << std::endl;
    std::cout << Point2_getY_virtual(ptr) << std::endl;
    std::cout << Point2_getZ_virtual(ptr) << std::endl;

    //Point2 *ptr2 = reinterpret_cast<Point2 *>(&p2);
    //std::cout << Point2_getZ_virtual(ptr2) << std::endl; SEGFAULT

    Point2_dtor(&p2);
    Point2_dtor_virtual(ptr);
}

