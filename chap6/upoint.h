/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   upoint.h
 * Author: Sean
 *
 * Created on March 13, 2020, 10:57 PM
 */

#ifndef UPOINT_H
#define UPOINT_H

#include "point.h"

class UPoint {
    friend class Handle;
    Point p;
    int u;

    UPoint() : u(1) {
    }

    UPoint(int x, int y) : p(x, y), u(1) {
    }

    UPoint(const Point& p0) : p(p0), u(1) {
    }

};



#endif /* UPOINT_H */

