/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   handle.h
 * Author: Sean
 *
 * Created on March 13, 2020, 10:54 PM
 */

#ifndef HANDLE_H
#define HANDLE_H

#include "point.h"
#include "upoint.h"

class Handle {
public:
    Handle();
    Handle(int, int);
    Handle(const Point&);
    Handle(const Handle&);

    Handle& operator=(const Handle&);
    ~Handle();

    int x()const;
    Handle& x(int);
    

    int y()const;
    Handle& y(int);
private:
    void makeSingleUPoint();
    //
    UPoint * up;
};


#endif /* HANDLE_H */

