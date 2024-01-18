#include "lib/common.hpp"

#ifdef __GNUG__
    #define forceinline __attribute__((always_inline))
#endif

#define mult(a, b) a * b
#define sqr(a) ((a) * (a))

class Account
{
private:
    double m_balance;

public:
    Account(double init)
    {
        m_balance = init;
    }
    inline double GetBalace()
    {
        return m_balance;
    }
    inline double Deposit(double amount)
    {
        return (m_balance += amount);
    }
    inline double Withdraw(double amount)
    {
        return (m_balance -= amount);
    }
};

inline int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

class Point
{
private:
    unsigned m_x;
    unsigned m_y;

public:
    unsigned &x();
    unsigned &y();
};

inline unsigned &Point::x()
{
    return m_x;
}

inline unsigned &Point::y()
{
    return m_y;
}

inline int multiply(int a, int b)
{
    return a * b;
}

forceinline int bar()
{

}

int main()
{
    // 5 + 5 * 1 + 9 = 19
    assert(mult(5 + 5, 1 + 9) == 19);
    // (5 + 5) * (1 + 9) = 10 * 10 = 100
    assert(multiply(5 + 5, 1 + 9) == 100);
    assert(mult(3, 3.14) == 9.42);
    assert(multiply(3, 3.14) == 9);
    int num = 3;
    // 3 * 4 = 12
    assert(sqr(num++) == 12);
    assert(num == 5);

    return 0;
}