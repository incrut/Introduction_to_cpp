#include <iostream>

template<class T>
class MyArray {
public:
    MyArray(): content(nullptr), size(0) {}
    MyArray(const MyArray& a): content(new T[a.size]), size(a.size) {
        for (unsigned int i = 0; i < size; i++) {
            content[i] = a.content[i];
        }
    }
    MyArray& operator=(const MyArray& a) {
        if (this != &a) {
            T* tmp = new T[a.size];
            for (unsigned int i = 0; i < a.size; i++) {
                tmp[i] = a.content[i];
            }
            delete[] content;
            content = tmp;
            size = a.size;
        }
        return *this;
    }
    ~MyArray() {
        delete[] content;
    }
    unsigned int getSize() const {
        return size;
    }
    void addElement(T element) {
        T* tmp = new T[size + 1];
        for (unsigned int i = 0; i < size; i++) {
            tmp[i] = content[i];
        }
        tmp[size++] = element;
        delete[] content;
        content = tmp;
    }
    T& elementAt(unsigned int i) const {
        if (i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return content[i];
    }

private:
    T* content;
    unsigned int size;
};

int main()
{
    MyArray<int> numbers;
    numbers.addElement(5);
    numbers.addElement(11);
    
    std::cout << "Array size: " << numbers.getSize() << std::endl;
    std::cout << "First element: " << numbers.elementAt(0) << std::endl;
    std::cout << "Second element: " << numbers.elementAt(1) << std::endl;
    
    MyArray<int> copy = numbers;
    copy.addElement(13);
    
    std::cout << "Copy size: " << copy.getSize() << std::endl;
    std::cout << "First element of original array: " << numbers.elementAt(0) << std::endl;
    std::cout << "First element of copy: " << copy.elementAt(0) << std::endl;
    std::cout << "Last element of copy: " << copy.elementAt(2) << std::endl;
    
    return 0;
}