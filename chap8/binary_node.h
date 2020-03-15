/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   binary_node.h
 * Author: Sean
 *
 * Created on March 15, 2020, 10:33 AM
 */

#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include "expr_node.h"
#include "expr.h"

class Binary_node : public Expr_node {
    friend class Expr;
    string op;
    Expr left;
    Expr right;

    Binary_node(const string& a, Expr b, Expr c) :
    op(a), left(b), right(c) {
    }

    void print(ostream& o) const {
        o << "(" << left << op << right << ")";
    };
    

    virtual int eval() const;


};


#endif /* BINARY_NODE_H */

