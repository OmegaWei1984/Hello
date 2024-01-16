#include <cstdarg>
#include <cstdio>

union printable
{
    int i;
    float f;
    char c;
    char *s;
};

void show(char *types, ...)
{
    va_list vl;
    va_start(vl, types);
    for (int i = 0; types[i] != '\0'; ++i)
    {
        printable pt;
        switch (types[i])
        {
        case 'i':
            pt.i = va_arg(vl, int);
            printf("%i\n", pt.i);
            break;
        case 'f':
            pt.f = va_arg(vl, double);
            printf("%f\n", pt.f);
            break;
        case 'c':
            pt.c = va_arg(vl, int);
            printf("%c\n", pt.c);
            break;
        case 's':
            pt.s = va_arg(vl, char *);
            printf("%s\n", pt.s);
            break;
        default:
            break;
        }
    }
    va_end(vl);
}

int main()
{
    char str[] = {'h', 'e', 'l', 'l' , 'o'};
    show("scccfi", str, 'c', '+', '+', 3.14f, 42);
    return 0;
}