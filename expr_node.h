/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   expr_node.h
 * Author: Sean
 *
 * Created on March 15, 2020, 10:16 AM
 */

#ifndef EXPR_NODE_H
#define EXPR_NODE_H

#include <iostream>
using namespace std;

class Expr;

class Expr_node {
    friend class Expr;
    friend ostream& operator<<(ostream& o, const Expr& t);

    int use;
protected:

    Expr_node() : use(1) {
    };

    virtual ~Expr_node() {
    };

    virtual void print(ostream&) const = 0;
    virtual int eval() const = 0;
};

#endif /* EXPR_NODE_H */

