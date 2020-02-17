#ifndef __CIRCULAR_BUFFER__
#define __CIRCULAR_BUFFER__

#include <memory>
template <typename T>
class circular_buffer
{
public:
    explicit circular_buffer(size_t size) : buf_{std::make_unique<T[]>(size)},
                                            max_size_{size} {

                                            };

    void put(T item);
    void put(T &&item);
    T get();
    void clear();
    bool empty() const;
    bool full() const;
    size_t capacity() const;
    size_t size() const;

private:
    std::unique_ptr<T[]> buf_;
    size_t head_ = 0;
    size_t tail_ = 0;
    const size_t max_size_;
    bool full_{false};
};
#include "ds_circularbuffer.cpp"
#endif