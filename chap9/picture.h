/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   picture.h
 * Author: Sean
 *
 * Created on June 27, 2020, 2:33 PM
 */

#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
using namespace std;

class Picture {
    friend ostream& operator<<(ostream&, const Picture&);

    friend Picture frame(const Picture& p);
    friend Picture operator&(const Picture&, const Picture&);
    friend Picture operator|(const Picture&, const Picture&);

private:
    int height, width;
    char* data;

    char& position(int row, int col) {
        return data[row * width + col];
    }

    char position(int row, int col) const {
        return data[row * width + col];
    }
    static int max(int m, int n);

    void init(int h, int w);

    void copyblock(int, int, const Picture&);

    void clear(int r1, int c1, int r2, int c2);
public:
    Picture();
    Picture(const char* const*, int);
    Picture(const Picture&);
    ~Picture();

    Picture& operator=(const Picture&);
};

#endif /* PICTURE_H */

