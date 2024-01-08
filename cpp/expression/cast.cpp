#include <cassert>
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

class D
{
private:
    int value{0};

public:
    void setVal(int val)
    {
        value = val;
    }
    void test() const
    {
        cout << "before: " << value << endl;
        // value--; // error: decrement of member ‘D::value’ in read-only object
        const_cast<D*>(this)->value--;
        cout << "after: " << value << endl;
    }
};

int main()
{
    A *pa = new B();
    A *pa2 = new A();
    A &ref_a = *pa;
    A &ref_a2 = *pa2;
    B *pb = dynamic_cast<B *>(pa);
    B *pb2 = new B();

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

    C *pc = static_cast<C *>(pb);
    // virtual void B::test()
    pc->test();
    // void C::testtest()
    pc->testtest();
    A *pa3 = static_cast<A *>(pb);
    // virtual void B::test()
    pa3->test();
    // void A::testtest()
    pa3->testtest();

    D d;
    d.setVal(42);
    d.test();

    int i = 42;
    const int &ref_i = i;
    const_cast<int&>(ref_i) = 1;
    assert(ref_i == 1);
    assert(i != 42 && i == 1);

    delete pb;
    delete pb2;
    // delete pc; // free(): double free detected in tcache 2

    return 0;
}