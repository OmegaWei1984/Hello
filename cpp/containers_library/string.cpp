#include <string>
#include <cassert>
// #include <cstring>

using namespace std;

char *strncpy(char *destination, const char *source, size_t num)
{
    char *tmp = destination;
    while (num > 0)
    {
        if ((*tmp = *source) == '\0')
        {
            break;
        }
        source++;
        tmp++;
        num--;
    }
    return destination;
}

int main()
{
    string s;
    assert(s.capacity() == 15);
    string s2 = "";
    assert(s2.capacity() == 15);
    string s3(6, '0');
    assert(s3.capacity() == 15);
    char *h = "hello";
    char h2[6];
    strncpy(h2, h, 6);
    return 0;
}
