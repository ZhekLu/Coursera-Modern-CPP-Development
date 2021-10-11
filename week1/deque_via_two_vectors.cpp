#include <vector>
#include <stdexcept>

template<typename T>
class Deque {
public:
    Deque() {}

    bool Empty() const {
        return !Size();
    }

    size_t Size() const {
        return front.size() + back.size();
    }

    void PushFront(T value) {
        front.push_back(value);
    }

    void PushBack(T value) {
        back.push_back(value);
    }

    T& operator[](size_t index) {
        return index < front.size() ? front[front.size() - 1 - index] : back[index - front.size()];
    }

    const T& operator[](size_t index) const {
        return index < front.size() ? front[front.size() - 1 - index] : back[index - front.size()];
    }

    T& At(size_t index) {
        if (index >= Size())
            throw std::out_of_range("Index is out of range");
        return index < front.size() ? front[front.size() - 1 - index] : back[index - front.size()];
    }

    const T& At(size_t index) const {
        if (index >= Size())
            throw std::out_of_range("Index is out of range");
        return index < front.size() ? front[front.size() - 1 - index] : back[index - front.size()];
    }

    T& Front() {
        return front.empty() ? back.front() : front.back();
    }

    const T& Front() const {
        return front.empty() ? back.front() : front.back();
    }

    T& Back() {
        return back.empty() ? front.front() : back.back();
    }

    const T& Back() const {
        return back.empty() ? front.front() : back.back();
    }

private:
    std::vector<T> back;
    std::vector<T> front;
};