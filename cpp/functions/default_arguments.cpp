// note: ...following parameter 1 which has a default argument
// void foo(int a = 0, int b)
// {
// }

void foo(int a, int b = 0) {}

// error: redefinition of ‘void foo(int, int)’
// void foo(int a, int b) {}

int main()
{
    foo(42);
    /**
     * Default arguments are only allowed
     * in the parameter lists of function declarations  and lambda-expressions,
     * (since C++11) and are not allowed in the declarations of pointers to functions,
     * references to functions, or in typedef declarations.
     * Template parameter lists use similar syntax for their default template arguments.
     */
    // void (*fp)(int a = 41, int b = 1);
    void (*fp)(int a, int b);
    fp = foo;
    return 0;
}