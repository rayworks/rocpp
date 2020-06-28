/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sean
 *
 * Created on April 1, 2019, 8:38 PM
 */

#include <cstdlib>
#include <iostream>

#include "chap32/test.h"
#include "chap0/trace.h"
#include "chap6/handle.h"
#include "chap8/expr.h"

//#include "chap9/picture.h"
#include "chap10/picture2.h"
#include "chap10/p_node.h"

using namespace std;

void testByteOrder() {
    unsigned long x;
    unsigned char *p;
    int i;

    x = 0x11223344;
    p = (unsigned char *) &x;
    for (i = 0; i < sizeof (long); i++) {
        printf("%x ", *p++);
    }
    printf("\n");

}

void printExp() {
    Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
    cout << t << " = " << t.eval() << endl;
    t = Expr("*", t, t);
    cout << t << " = " << t.eval() << endl;

    t = Expr("*", Expr(0), Expr("+", 3, 4), Expr("*", 6, 7));
    cout << t << " = " << t.eval() << endl;
}

char* init[] = {"Paris", "in the", "Spring"};

int main(int argc, char** argv) {
    Trace tc(stdout);
    tc.on();

    tc.print((char*) string("begin main()\n").c_str());

    Test s;
    Test t(s);
    s = t;

    //testByteOrder(); // little-endian : 44 33 22 11 00 00 00 00

    Handle h(3, 4);
    Handle h2 = h;

    h2.x(5);
    int n = h2.x();
    printf(">>>Handle x result : %d\n", n);

    printExp();

    //    Picture p(init, 3);         
    //    cout<< p << endl;
    //    Picture q = frame(p);
    //    cout<< frame(q & (p | q)) << endl;

    Picture2 pct2(init, 3);
    Picture2 framed = frame2(pct2);
    cout << frame2(framed & (pct2 | framed)) << endl;


    tc.print((char*) string("end main()\n").c_str());
    return 0;
}

