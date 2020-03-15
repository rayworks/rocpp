/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "unary_node.h"

int Unary_node ::eval() const {
    if(op == "-") {
        return -opnd.eval();
    }
    
    throw "error, bad op" + op + " in UnaryNode";
}