#include<iostream>

template<class T>
class MyVector {
public:
    int capacity, size;
    T* array;

    MyVector() {
        this->array = NULL;
        capacity = 0;
        size = 0;
    }

    void resize(int new_size){
        if(new_size == 0) {
            delete [] array;
            size = 0;
        } else if (array == NULL) {
            array = new T[new_size];
        } else {
            T* new_array = new T[new_size];
            for(int i = 0; i < size; i++)
               new_array[i] = array[i];
            delete [] array;
            array = new_array;
        }
    } 


    void push_back(T item) {
        if(size+1 > capacity) {
            resize(2*(size+1)); 
        }
        array[size] = item;
        size++;
    }
};


int main() {
    MyVector<int> a;
    std::cout << a.size << std::endl;
    a.push_back(5);
    a.push_back(6);
    std::cout << a.size << std::endl;
    return 0;
}
