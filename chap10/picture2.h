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

#include "p_node.h"

using namespace std;
class P_Node;

class Picture2 {
    friend ostream& operator<<(ostream&, const Picture2&);

    friend Picture2 frame(const Picture2& p);
    friend Picture2 operator&(const Picture2&, const Picture2&);
    friend Picture2 operator|(const Picture2&, const Picture2&);
    
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
    
//    Picture2(const Ptr<P_Node>&);
    Picture2(P_Node* );
    
private:
   
    int height() const;
    int width() const;
    void display(ostream&, int, int) const;
    //Ptr<P_Node> p;
    P_Node* p;
};

#endif /* PICTURE2_H */

