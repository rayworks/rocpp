/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   unary_node.h
 * Author: Sean
 *
 * Created on March 15, 2020, 10:30 AM
 */

#ifndef UNARY_NODE_H
#define UNARY_NODE_H

#include "expr_node.h"
#include "expr.h"

class Unary_node : public Expr_node {
    friend class Expr;
    string op;
    Expr opnd;

    Unary_node(const string& a, Expr b) : op(a), opnd(b) {
    }

    void print(ostream& o) const {
        o << "(" << op << opnd << ")";
    };

    virtual int eval() const;
};


#endif /* UNARY_NODE_H */

