/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Int_node.h
 * Author: Sean
 *
 * Created on March 15, 2020, 10:23 AM
 */

#ifndef INT_NODE_H
#define INT_NODE_H

#include "expr_node.h"


class Int_node : public Expr_node {
    friend class Expr;
    
    int n;
    Int_node(int k) : n(k){}
    
    void print(ostream& o) const {o << n;}
    virtual int eval() const {return n;}

};



#endif /* INT_NODE_H */

