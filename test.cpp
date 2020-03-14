/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "test.h"

int Test::count = 0;

Test::Test() {
    id = ++count;
    std::cout << "Test " << id << " default constructor" << std::endl;
}

Test::Test(const Test& t) {
    id = ++count;
    std::cout << "Test " << id
            << " copied from " << t.id << std::endl;
}

Test& Test::operator=(const Test& t) {
    std::cout << "Test " << id
            << " assigned from " << t.id << std::endl;
    return *this;
}

Test::~Test() {
    std::cout << "Test " << id << " destroyed" << std::endl;
}
