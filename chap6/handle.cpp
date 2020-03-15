/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "handle.h"

Handle::Handle() : p(new Point) {

}

Handle::Handle(int x, int y) : p(new Point(x, y)) {

}

Handle::Handle(const Point& p) : p(new Point(p)) {

}

Handle& Handle::operator=(const Handle& h) {
    if (u.reattach(h.u))
        delete p;
    p = h.p;
    return *this;
}

Handle::Handle(const Handle& h) : u(h.u), p(h.p) {
}

Handle::~Handle() {
    if (u.only()) {
        delete p;
    }
}

Handle& Handle::x(int x0) {
    if (u.makeonly()) {
        p = new Point(*p);
    }
    p->x(x0);
    return *this;
}

Handle& Handle::y(int y0) {
    if (u.makeonly()) {
        p = new Point(*p);
    }
    p->y(y0);
    return *this;
}

int Handle::x() const {
    return p->x();
}

int Handle::y() const {
    return p->y();
}

