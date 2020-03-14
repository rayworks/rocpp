/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   point.h
 * Author: Sean
 *
 * Created on March 13, 2020, 10:49 PM
 */

#ifndef POINT_H
#define POINT_H

class Point {
public:

    Point() : xval(0), yval(0) {
    }

    Point(int x, int y) : xval(x), yval(y) {
    }

    int x() const {
        return xval;
    }

    int y() const {
        return yval;
    }

    Point& x(int xv) {
        xval = xv;
        return *this;
    }

    Point& y(int yv) {
        yval = yv;
        return *this;
    }

private:
    int xval, yval;
};

#endif /* POINT_H */

