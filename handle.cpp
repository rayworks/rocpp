/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "handle.h"

Handle::Handle() : up(new UPoint) {

}

Handle::Handle(int x, int y) : up(new UPoint(x, y)) {

}

Handle::Handle(const Point& p) : up(new UPoint(p)) {

}

Handle& Handle::operator=(const Handle& h) {
    ++h.up->u;
    if (--up->u == 0)
        delete up;
    up = h.up;
    return *this;
}

Handle::Handle(const Handle& h) : up(h.up) {
    ++up->u;
}

Handle::~Handle() {
    if (--up->u == 0) {
        delete up;
    }
}

void Handle::makeSingleUPoint(){
    if (up->u != 1) { // copy on write
        --up->u;
        up = new UPoint(up->p);
    }
}

Handle& Handle::x(int x0) {
    makeSingleUPoint();
    up->p.x(x0);
    return *this;
}

Handle& Handle::y(int y0) {
    makeSingleUPoint();
    up->p.y(y0);
    return *this;
}

int Handle::x() const {
    return up->p.x();
}

int Handle::y() const {
    return up->p.y();
}

