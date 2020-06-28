/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "./picture2.h"
#include "p_node.h"

Picture2::Picture2() {
    p = NULL;
}

Picture2::Picture2(const Picture2& org) : p(org.p) {
    org.p->use++;
}

Picture2::Picture2(const char* const* str, int n) :
p(new String_Pic(str, n)) {
}

Picture2::~Picture2() {
    if (--p->use == 0)
        delete p;
}

Picture2& Picture2::operator=(const Picture2& rhv) {
    rhv.p->use++;
    if (--p->use == 0)
        delete p;
    p = rhv.p;
    return *this;
}

Picture2::Picture2(P_Node* p_node) : p(p_node) {
}

int Picture2::height() const {
    return p->height();
}

int Picture2::width() const {
    return p-> width();
}

void Picture2::display(ostream& o, int x, int y) const {
    p-> display(o, x, y);
}

ostream& operator<<(ostream& os, const Picture2& picture) {
    int ht = picture.height();
    for (int i = 0; i < ht; i++) {
        picture.display(os, i, 0);
        os << endl;
    }

    return os;

}

Picture2 reframe(const Picture2& pic, char corner, char side, char top) {
    return pic.p -> reframe(corner, side, top);
}
