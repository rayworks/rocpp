/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   comp_base.h
 * Author: rayworks
 *
 * Created on August 23, 2020, 3:10 PM
 */

#ifndef COMP_BASE_H
#define COMP_BASE_H

template<typename X, typename Y> class Comp_base {
public:
    virtual Y operator()(X) const = 0;
    virtual Comp_base* clone() const = 0;

    virtual ~Comp_base() {
    };
};

template<typename F, typename G, typename X, typename Y>
class Comp : public Comp_base<X, Y> {
public:
    Comp(F f0, G g0) : f(f0), g(g0) {

    }

    Y operator()(X x) const {
        return f(g(x));
    }

    Comp_base<X, Y>* clone() const {
        return new Comp(*this);
    }

    virtual ~Comp() {
    };

private:
    F f;
    G g;
};

template<typename X, typename Y> class Composition {
public:

    template<typename F, typename G>
    Composition(F f, G g) {
        p = new Comp< F, G, X, Y>(f, g);
    }

    Composition(const Composition& c) {
        p = c.p->clone();
    }

    Composition& operator=(const Composition& c) {
        if (this != &c) {
            delete p;
            p = c.p->clone();
        }
        return *this;
    }

    ~Composition() {
        delete p;
    }

    inline Y operator()(X x) const {
        return (*p)(x);
    }
private:
    Comp_base<X, Y>* p;
};


#endif /* COMP_BASE_H */

