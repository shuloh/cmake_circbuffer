#ifndef __CIRCULAR_BUFFER_IMPL__
#define __CIRCULAR_BUFFER_IMPL__
#include "ds_circularbuffer.h"
template <typename T>
void circular_buffer<T>::clear()
{
    head_ = tail_;
    full_ = false;
}

template <typename T>
bool circular_buffer<T>::empty() const
{
    return (!full_ && (head_ == tail_));
}

template <typename T>
bool circular_buffer<T>::full() const
{
    return full_;
}

template <typename T>
size_t circular_buffer<T>::capacity() const
{
    return full_;
}

template <typename T>
size_t circular_buffer<T>::size() const
{
    if (full)
    {
        return max_size_;
    }
    else if (head_ >= tail_)
    {
        return head_ - tail_;
    }
    //writes have wrapped to the front of the array
    //size is the tail index to the end of array + write index
    else
    {
        return max_size_ - tail_ + head_;
    }
}

template <typename T>
void circular_buffer<T>::put(T item)
{
    if (full_)
    {
        tail_ = (tail_ + 1) % max_size_;
    }
    buf_[head_] = item;
    head_ = (head_ + 1) % max_size_;
    full_ = head_ == tail_;
}

template <typename T>
T circular_buffer<T>::get()
{
    if (empty())
    {
        return T();
    }
    T result = buf_[tail_];
    tail_ = (tail_ + 1) % max_size_;
    //if tail_ == head_ then the buffer is empty (after read) -- will never be full
    full_ = false;
    return result;
}
#endif