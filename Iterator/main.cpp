#include <iostream>

class MyIterator {
private:
    int* ptr_;
public:
    MyIterator(int* ptr) : ptr_(ptr) {}

    int& operator*() { return *ptr_; }

    MyIterator& operator++() {
        ++ptr_;
        return *this;
    }

    MyIterator operator++(int) {
        MyIterator temp = *this;
        ++*this;
        return temp;
    }

    bool operator!=(const MyIterator& other) const { return ptr_ != other.ptr_; }
};

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    MyIterator begin(arr);
    MyIterator end(arr + sizeof(arr) / sizeof(int));

    for (MyIterator it = begin; it != end; ++it) {
        std::cout << *it << " ";
    }

    return 0;
}