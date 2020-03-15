/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>

#include "usecount.h"

UseCount::UseCount() : p(new int(1)) {

}

UseCount::UseCount(const UseCount& u) : p(u.p) {
    ++*p;
}

UseCount::~UseCount() {
    if (--*p == 0)
        delete p;
}

bool UseCount::only() {
    return *p == 1;
}

bool UseCount::reattach(const UseCount& u) {
    ++*u.p;
    if (--*p == 0) {
        delete p;
        p = u.p;
        return true;
    }

    p = u.p;
    return false;
}

bool UseCount::makeonly() {
    if (*p == 1)
        return false;
    --*p;
    p = new int(1);
    return true;
}