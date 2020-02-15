#include <memory>
template <typename T>
class circular_buffer
{
public:
    explicit circular_buffer(size_t size) : buf_(std::unique_ptr<T[]>(new T[size])){};
    void test();

private:
    std::unique_ptr<T[]> buf_;
};