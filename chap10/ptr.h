/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ptr.h
 * Author: Sean
 *
 * Created on June 27, 2020, 10:36 PM
 */

#ifndef PTR_H
#define PTR_H

template <class T> class Ptr {
public:

    //    void make_unique() {
    //        if (*refptr != 1) {
    //            --*refptr;
    //            refptr = new size_t(1);
    //            p = p? p->clone() : 0;
    //        }
    //    }

    Ptr() : p(0), refptr(new size_t(1)) {
    }

    Ptr(T* t) : p(t), refptr(new size_t(1)) {
    }

    Ptr(const Ptr& h) : p(h.p), refptr(h.refptr) {
        ++*refptr;
    }

    Ptr& operator=(const Ptr& rhv) {
        ++*rhv.refptr;

        if (--*refptr == 0) {
            delete refptr;
            delete p;
        }

        refptr = rhv.refptr;
        p = rhv.p;
        return *this;
    }

    ~Ptr() {
        if (--*refptr == 0) {
            delete refptr;
            delete p;
        }
    }

    operator bool() const {
        return p;
    }

    T& operator*() const {
        if (p) return *p;
        throw std::runtime_error("Unbound ref");
    }

    T* operator->() const {
        if (p) return p;
        throw std::runtime_error("Unbound ref");
    }

private:
    T* p;
    std::size_t* refptr;
};


#endif /* PTR_H */

