/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   expr.h
 * Author: Sean
 *
 * Created on March 15, 2020, 10:25 AM
 */

#ifndef EXPR_H
#define EXPR_H

#include <iostream>

#include "expr_node.h"
using namespace std;

class Expr {
    friend ostream& operator<<(ostream&, const Expr&);

    Expr_node* p;
    
public:
    Expr(int);
    Expr(const string&, Expr);
    Expr(const string&, Expr, Expr);

    Expr(const Expr& t) {
        p = t.p;
        ++p->use;
    };
    Expr& operator=(const Expr&);

    ~Expr() {
        if (--p->use == 0)
            delete p;
    };
};


#endif /* EXPR_H */

