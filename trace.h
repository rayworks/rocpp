/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   trace.h
 * Author: Sean
 *
 * Created on March 12, 2020, 9:45 PM
 */

#ifndef TRACE_H
#define TRACE_H

#include <stdio.h>

class Trace {
public:
    Trace() {
        noisy = 0;
        f = stdout;
    }

    Trace(FILE* ff) {
        noisy = 0;
        f = ff;
    }

    void print(char* s) {
        if (noisy)
            fprintf(f, "%s", s);
    }

    void on() {
        noisy = 1;
    }

    void off() {
        noisy = 0;
    }

private:
    int noisy;
    FILE* f;
};



#endif /* TRACE_H */

