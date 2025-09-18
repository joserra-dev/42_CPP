#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base(); // solo declaración, implementación en .cpp
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
