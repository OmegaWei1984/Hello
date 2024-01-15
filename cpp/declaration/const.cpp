#include "lib/common.hpp"
#include <string>

const int MAX = 1024;
const std::string HELLO = "hello";

class Foo
{
private:
    const int MAX = 1;
    int m_value;
public:
    int get() const
    {
        return m_value;
    }
};

int main()
{
    int num = 42;
    const int &ref_num = num;
    // ref_num++; //  error: increment of read-only reference ‘ref_num’
    const int *p_num = &num;
    // *p_num = 43; // error: assignment of read-only location ‘* p_num’
    int *const p2_num = &num;
    (*p2_num)++;
    assert(num == 43);
    const int *const p3_num = &num;
    // (*p3_num)++; // error: increment of read-only location ‘*(const int*)p3_num’

    return 0;
}