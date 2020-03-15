/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "expr.h"
#include "int_node.h"
#include "unary_node.h"
#include "binary_node.h"

Expr::Expr(int n) {
    p = new Int_node(n);
}

Expr::Expr(const string& op, Expr t) {
    p = new Unary_node(op, t);
}

Expr::Expr(const string& op, Expr left, Expr right) {
    p = new Binary_node(op, left, right);
}

Expr& Expr::operator =(const Expr& rhs) {
    rhs.p->use++;
    if(--p->use == 0) {
        delete p;
    }
    p = rhs.p;
    return *this;
}

ostream& operator<<(ostream& o, const Expr& t) {
    t.p->print(o);
    return o;
}
