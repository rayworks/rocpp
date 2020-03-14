/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Test.h
 * Author: Sean
 *
 * Created on April 1, 2019, 8:44 AM
 */

#ifndef TEST_H
#define TEST_H

#include <iostream>

class Test {
public:
    Test();
    Test(const Test&);
    ~Test();
    Test& operator = (const Test&);
private:
    static int count;
    int id;
};

#endif /* TEST_H */

