#include <string>
#include <cassert>

using namespace std;

int main()
{
    string s;
    assert(s.capacity() == 15);
    string s2 = "";
    assert(s2.capacity() == 15);
    string s3(6, '0');
    assert(s3.capacity() == 15);
    return 0;
}
