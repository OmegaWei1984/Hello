struct A
{
    A(int) {}
    A(int, int) {}
    operator bool() const { return true; }
};

struct B
{
    explicit B(int) {}
    explicit B(int, int) {}
    explicit operator bool() const { return true; }
};

int main()
{
    A a1 = 1; // copy-init A::A(int)
    A a2(2);  // direct-init A::A(int)
    A a3{1, 2}; // direct-list-init A::A(int, int)
    A a4 = {1, 2}; // copy-list-init A::A(int, int)
    A a5 = (A)1; // explicit cast performs static_cast
    if (a1) {} // A::operator bool()
    bool na1 = a1; // copy-init A::operator bool()
    bool na2 = static_cast<bool>(a1); // static_cast performs direct-init

    // B b1 = 1; //  error: conversion from ‘int’ to non-scalar type ‘B’ requested
    B b2(2); // direct-init B::B(int)
    B b3{1, 2}; // direct-list-init B::B(int, int)
    // B b4 = {1, 2}; // error: converting to ‘B’ from initializer list would use explicit constructor ‘B::B(int, int)’
    B b5 = (B)1; // explicit cast performs static_cast
    if (b2) {} // B::operator bool()
    // bool nb1 = b2; //  error: cannot convert ‘B’ to ‘bool’ in initialization
    bool nb2 = static_cast<bool>(b2); // static_cast performs direct-initialization
    [](...){}(a4, a5, na1, na2, b5, nb2);

    return 0;
}