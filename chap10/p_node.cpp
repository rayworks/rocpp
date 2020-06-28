/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <string.h>

#include "p_node.h"
#include "picture2.h"

P_Node::P_Node() : use(1) {
}

P_Node::~P_Node() {
}

int P_Node::max(int x, int y) {
    return x > y ? x : y;
}

String_Pic::String_Pic(const char* const* p, int n) :
data(new char* [n]), size(n) {
    for (int i = 0; i < n; i++) {
        data[i] = new char[strlen(p[i]) + 1];
        strcpy(data[i], p[i]);
    }
}

String_Pic::~String_Pic() {
    for (int i = 0; i < size; i++) {
        delete data[i];
    }

    delete[] data;
}

int String_Pic::height() const {
    return size;
}

int String_Pic::width() const {
    int n = 0;
    for (int i = 0; i < size; i++) {
        n = max(n, strlen(data[i]));
    }
    return n;
}

void String_Pic::display(std::ostream& os, int row, int width) const {
    int start = 0;
    if (row >= 0 && row < height()) {
        os << data[row];
        start = strlen(data[row]);
    }
    pad(os, start, width);
}

Picture2 String_Pic::reframe(char c, char s, char t) {
    use++;
    return this; // private ctor
}

Frame_Pic::Frame_Pic(const Picture2& pt, char c, char s, char t) : p(pt),
corner(c), sideborder(s), topborder(t) {
}

Picture2 frame2(const Picture2& pic) {
    return new Frame_Pic(pic); //  Picture2()
}

int Frame_Pic::height() const {
    return p.height() + 2;
}

int Frame_Pic::width() const {
    return p.width() + 2;
}

Picture2 Frame_Pic::reframe(char c, char s, char t) {
    return new Frame_Pic(P_Node::reframe(p, c, s, t), c, s, t);
}

void Frame_Pic::display(std::ostream& os, int row, int wd) const {
    if (row < 0 || row >= height()) { // out of boundary
        pad(os, 0, wd);
    } else {
        if (row == 0 || row == height() - 1) {
            // top | bottom
            os << corner; //"+";
            int i = p.width();
            while (--i >= 0)
                os << topborder; //"-";
            os << corner;
        } else {// internal
            os << sideborder;
            p.display(os, row - 1, p.width());
            os << sideborder;
        }
        pad(os, width(), wd);
    }
}

VCat_Pic::VCat_Pic(const Picture2& t, const Picture2& b) : top(t), bottom(b) {
}

int VCat_Pic::height() const {
    return top.height() + bottom.height();
}

int VCat_Pic::width() const {
    return max(top.width(), bottom.width());
}

Picture2 VCat_Pic::reframe(char c, char s, char t) {
    return new VCat_Pic(P_Node::reframe(top, c, s, t),
            P_Node::reframe(bottom, c, s, t));
}

void VCat_Pic::display(std::ostream& os, int row, int wd) const {
    if (row >= 0 && row < top.height()) {
        top.display(os, row, wd);
    } else if (row < top.height() + bottom.height()) {
        bottom.display(os, row - top.height(), wd);
    } else {
        pad(os, 0, wd);
    }
}

Picture2 operator&(const Picture2& t, const Picture2& b) {
    return Picture2(new VCat_Pic(t, b));
}

HCat_Pic::HCat_Pic(const Picture2& l, const Picture2& r) : left(l), right(r) {
}

int HCat_Pic::height() const {
    return max(left.height(), right.height());
}

int HCat_Pic::width() const {
    return left.width() + right.width();
}

Picture2 HCat_Pic::reframe(char c, char s, char t) {
    return new HCat_Pic(P_Node::reframe(left, c, s, t), P_Node::reframe(right, c, s, t));
}

void HCat_Pic::display(std::ostream& os, int row, int wd) const {
    left.display(os, row, left.width());
    right.display(os, row, right.width());
    pad(os, width(), wd);
}

Picture2 operator|(const Picture2& l, const Picture2& r) {
    return Picture2(new HCat_Pic(l, r));
}

Picture2 P_Node::reframe(const Picture2& pic, char corner, char side, char top) {
    return pic.p -> reframe(corner, side, top);
}