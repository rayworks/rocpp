/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ternary_node.h"

void Ternary_node::print(ostream& o) const {
    o << "(" << left << " ? " << middle
            << " : " << right << ")";
}

int Ternary_node::eval() const {
    if (left.eval())
        return middle.eval();
    else
        return right.eval();
}