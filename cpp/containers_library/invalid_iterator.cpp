#include <algorithm>
#include <cassert>
#include <deque>
#include <list>
#include <vector>
#include <map>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    auto it = find(v.begin(), v.end(), 4);
    auto it_rm = find(v.begin(), v.end(), 3);
    // {1, 2, 4, 5, 6}
    v.erase(it_rm);
    assert(*it == 5);
    // {2, 4, 5, 6}
    v.erase(v.begin());
    // {4, 5, 6}
    v.erase(v.begin());
    assert(*it == 6);
    // {5, 6}
    v.erase(v.begin());
    assert(*it == 6);
    // {6}
    v.erase(v.begin());
    assert(*it == 6);
    // {}
    v.erase(v.begin());
    assert(*it == 6);
    // {1}
    v.push_back(1);
    v.push_back(2);
    it = find(v.begin(), v.end(), 2);
    v.erase(v.begin());
    assert(it != v.begin());
    it = find(v.begin(), v.end(), 2);
    v.insert(v.begin(), 1);
    auto it_ = find(v.begin(), v.end(), 2);
    assert(it != it_);
    v.insert(v.end(), 3);
    it = find(v.begin(), v.end(), 1);
    it_rm = find(v.begin(), v.end(), 2);
    v.erase(it_rm);
    it_ = find(v.begin(), v.end(), 1);
    assert(it == it_);
    // std::vector of length 2, capacity 6 = {1, 3}
    // {1, 3, 4, 5, 6, 7, 8}
    v.insert(v.end(), {4, 5, 6, 7, 8});
    // std::vector of length 7, capacity 7 = {1, 3, 4, 5, 6, 7, 8}
    it_ = find(v.begin(), v.end(), 1);
    assert(it != it_);

    list<int> l = {1, 2, 3, 4, 5, 6};
    auto it2 = find(l.begin(), l.end(), 4);
    auto it2_rm = find(l.begin(), l.end(), 3);
    l.erase(it2_rm);
    // {1 <-> 2 <-> 4 <-> 5 <-> 6}
    assert(*it2 == 4);
    auto it2_ = find(l.begin(), l.end(), 4);
    assert(it2 == it2_);
    // {2 <-> 4 <-> 5 <-> 6}
    l.erase(l.begin());
    // {4 <-> 5 <-> 6}
    l.erase(l.begin());
    // {5 <-> 6}
    l.erase(l.begin());
    assert(*it2 == 4);
    assert(*(l.begin()) == 5);
    // {6}
    l.erase(l.begin());
    // {}
    l.erase(l.begin());
    assert(l.empty());
    assert(*it2 == 4);
    l.insert(l.begin(), {1, 2, 3, 4});
    it2 = find(l.begin(), l.end(), 2);
    l.erase(l.begin());
    it2_ = find(l.begin(), l.end(), 2);
    assert(it2 == it2_);
    l.remove(3);
    it2_ = find(l.begin(), l.end(), 2);
    assert(it2 == it2_);

    deque<int> q = {1, 2, 3, 4, 5};
    auto it3 = find(q.begin(), q.end(), 3);
    q.push_front(0);
    auto it3_ = find(q.begin(), q.end(), 3);
    assert(it3 == it3_);
    q.pop_front();
    it3_ = find(q.begin(), q.end(), 3);
    assert(it3 == it3_);
    q.push_back(6);
    it3_ = find(q.begin(), q.end(), 3);
    assert(it3 == it3_);
    q.pop_back();
    it3_ = find(q.begin(), q.end(), 3);
    assert(it3 == it3_);
    auto it3_begin = q.begin();
    q.insert(it3_begin, {-2, -1});
    q.insert(it3_begin, 0);

    map<int, char> m;
    m.insert({1, 'a'});
    m.insert({2, 'b'});
    auto it4 = m.find(1);
    m.erase(2);
    auto it4_ = m.find(1);
    assert(it4 == it4_);

    return 0;
}