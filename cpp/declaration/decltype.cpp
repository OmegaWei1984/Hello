int main()
{
    int x = 0;
    decltype(x) x1;
    decltype(x) &x2 = x;
    decltype(x) *x3 = &x;
    // int *
    decltype(&x) x4 = &x;
    // int **
    decltype(&x)*x5 = &x4;
    // int &
    decltype(x2) x6 = x;

    int y = 0;
    // int &
    decltype(auto) y1 = (y);
    // int *
    decltype(auto) y2 = &y;
    // int &
    decltype(auto) y3 = y1;
}