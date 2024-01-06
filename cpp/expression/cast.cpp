#include <iostream>
#include <string>

using namespace std;

class A
{
public:
    virtual void test()
    {
        cout << "virtual void A::test()" << endl;
    }

    void testtest()
    {
        cout << "void A::testtest()" << endl;
    }
};

class B : public A
{
public:
    virtual void test()
    {
        cout << "virtual void B::test()" << endl;
    }

    void testtest()
    {
        cout << "void B::testtest()" << endl;
    }
};

class C : public B
{
public:
    virtual void test()
    {
        cout << "virtual void C::test()" << endl;
    }

    void testtest()
    {
        cout << "void C::testtest()" << endl;
    }
};

int main()
{
    A *pa = new B();
    A *pa2 = new A();
    A &ref_a= *pa;
    A &ref_a2 = *pa2;
    B *pb = dynamic_cast<B *>(pa);

    // virtual void B::test()
    pa->test();
    // void A::testtest()
    pa->testtest();
    // virtual void B::test()
    pb->test();
    // void B::testtest()
    pb->testtest();

    B &ref_b = dynamic_cast<B &>(ref_a);

    // virtual void B::test()
    ref_b.test();
    // void B::testtest()
    ref_b.testtest();

    try
    {
        B &ref_b2 = dynamic_cast<B &>(ref_a);
        ref_b2.test();
        ref_b2.testtest();
    }
    catch (bad_cast b)
    {
        cout << b.what() << endl;
    }

    delete pb;
    // delete pc; // free(): double free detected in tcache 2

    return 0;
}