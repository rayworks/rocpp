/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   picture.h
 * Author: Sean
 *Ï
 * Created on June 27, 2020, 6:53 PM
 */

#ifndef PICTURE2_H
#define PICTURE2_H
#include <iostream>

using namespace std;

// class forward declaration
class P_Node;

class Picture2 {
    friend ostream& operator<<(ostream&, const Picture2&);

    friend Picture2 frame2(const Picture2& p);
    
    friend Picture2 reframe(const Picture2& pic, char, char, char);
    
    friend Picture2 operator&(const Picture2&, const Picture2&);
    friend Picture2 operator|(const Picture2&, const Picture2&);
    
    friend class P_Node;
    friend class String_Pic;
    friend class Frame_Pic;
    friend class HCat_Pic;
    friend class VCat_Pic;
public:
    Picture2();
    Picture2(const char* const*, int);
    Picture2(const Picture2&);
    ~Picture2();

    Picture2& operator=(const Picture2&);
    
    Picture2(P_Node* );
    
private:
   
    int height() const;
    int width() const;
    void display(ostream&, int, int) const;
    P_Node* p;
};

#endif /* PICTURE2_H */

