/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   p_node.h
 * Author: Sean
 *
 * Created on June 27, 2020, 6:56 PM
 */

#ifndef P_NODE_H
#define P_NODE_H

#include "picture2.h"

class P_Node {
    friend class Picture2;
    
    // Picture2's friend function 'reframe' marked as 'friend'
    friend Picture2 reframe(const Picture2& pic, char, char, char);
    
    virtual Picture2 reframe(char, char, char) = 0;

public:
    // The utility function to make it compile
    static Picture2 reframe(const Picture2& pic, char, char, char);
    
    virtual ~P_Node();
protected:
    P_Node();

    virtual int height() const = 0;
    virtual int width() const = 0;

    virtual void display(std::ostream&, int, int) const = 0;

    static int max(int, int);

    static void pad(std::ostream& os, int x, int y) {
        for (int i = x; i < y; i++) {
            os << " ";
        }
    }
//private:
    int use;
};

class String_Pic : public P_Node {
    friend class Picture2;
    String_Pic(const char* const*, int);
    ~String_Pic();
    int height() const;
    int width() const;
    void display(std::ostream&, int, int) const;
    Picture2 reframe(char, char, char);


    char **data;
    int size;
};

class Frame_Pic : public P_Node {
    friend Picture2 frame2(const Picture2& p);
    

public:
    Frame_Pic(const Picture2& t, char = '+', char = '|', char = '-');

    int height() const;
    int width() const;
    void display(std::ostream&, int, int) const;
    Picture2 reframe(char, char, char);
    
    Picture2 p;
    char corner;
    char sideborder;
    char topborder;
};

class VCat_Pic : public P_Node {
    friend Picture2 operator&(const Picture2& t, const Picture2& b);
    VCat_Pic(const Picture2& t, const Picture2& b);
    int height() const;
    int width() const;

    void display(std::ostream&, int, int) const;
    Picture2 reframe(char, char, char);
    Picture2 top, bottom;
};

class HCat_Pic : public P_Node {
    friend Picture2 operator|(const Picture2& l, const Picture2& r);
    HCat_Pic(const Picture2& l, const Picture2& r);
    int height() const;
    int width() const;

    void display(std::ostream&, int, int) const;
    Picture2 reframe(char, char, char);
    Picture2 left, right;
};
#endif /* P_NODE_H */

