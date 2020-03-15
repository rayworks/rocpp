/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ternary_node.h
 * Author: Sean
 *
 * Created on March 15, 2020, 3:58 PM
 */

#ifndef TERNARY_NODE_H
#define TERNARY_NODE_H

#include "expr_node.h"
#include "expr.h"


class Ternary_node : public Expr_node {
    friend class Expr;
    
    string op;
    Expr left;
    Expr middle;
    Expr right;
    
    Ternary_node(const string& a, Expr b, Expr c, Expr d):
    op(a),left(b),middle(c),right(d){}
    
    void print(ostream&) const;
    int eval() const;
};

#endif /* TERNARY_NODE_H */

