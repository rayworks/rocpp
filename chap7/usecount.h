/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   usecount.h
 * Author: Sean
 *
 * Created on March 14, 2020, 8:50 PM
 */

#ifndef USECOUNT_H
#define USECOUNT_H

class UseCount {
public:
    UseCount();
    UseCount(const UseCount&);
    ~UseCount();
    
    // ...
    bool only();
    bool reattach(const UseCount&);
    
    bool makeonly();
    
private:
    UseCount& operator=(const UseCount&);
    int* p;
};



#endif /* USECOUNT_H */

