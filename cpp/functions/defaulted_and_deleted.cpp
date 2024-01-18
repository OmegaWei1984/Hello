#include <cstddef>

struct noncopyable
{
    noncopyable() = default;
    noncopyable(const noncopyable &) = delete;
    noncopyable &operator=(const noncopyable &) = delete;
};

struct widget
{
    widget() = default;

    inline widget &operator=(const widget &);

    void *operator new(std::size_t) = delete;

    template <typename T>
    void call_with_true_double_only(T) = delete;
    void call_with_true_double_only(double param) { return; }
};

inline widget &widget::operator=(const widget &) = default;

int main()
{
    widget w;
    w.call_with_true_double_only(1.1);
    return 0;
}