/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "binary_node.h"

int Binary_node::eval() const {
    int op1 = left.eval();
    int op2 = right.eval();
    
    if(op == "-") return op1 - op2;
    if(op == "+") return op1 + op2;
    if(op == "*") return op1 * op2;
    if(op == "/" && op2 != 0) return op1 / op2;
    
    throw "error, bad op " + op + " in BinaryNode";
}