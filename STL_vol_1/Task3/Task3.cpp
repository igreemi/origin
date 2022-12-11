#include <iostream>

template <typename T>
class vector
{
private:
    T* arr = nullptr;
    size_t size_v;
    size_t capacity_v;
    int i = 0;
public:
    vector()
    {
        arr = new T[1]();
        capacity_v = 1;
    }

    vector& operator=(const vector& other)
    {

        if (&other != this)
        {
            delete[] arr;

            arr = new T[other.size_v];

            for (int i = 0; i < other.size_v; i++)
            {
                arr[i] = other.arr[i];
            }
            size_v = other.size_v;

        }

        return *this;
    }

    vector(const vector& other)

    {
        delete[] arr;

        arr = new T[other.size_v];

        for (int i = 0; i < other.size_v; i++)
        {
            arr[i] = other.arr[i];
        }
        size_v = other.size_v;
        i = other.i;

    }

    ~vector()
    {
        if (arr != nullptr)
        {
            delete[] arr;
        }
    }
    bool isEmpty() const
    {
        return size_v == 0;
    }

    int size() const
    {
        return size_v;
    }

    int capacity() const
    {
        return capacity_v;
    }

    void addNewMemory()
    {
        capacity_v = (size_v * 2);
        T* tmpArr = arr;
        arr = new T[capacity_v];
        for (int i = 0; i < size_v; ++i)
        {
            arr[i] = tmpArr[i];
        }
        delete[] tmpArr;
    }

    void push_back(const T& value)
    {
        if (size_v >= capacity_v)
        {
            addNewMemory();
        }
        arr[size_v++] = value;
    }

    void remove(size_t index) {
        for (size_t i = index + 1; i < size_v; ++i) {
            arr[i - 1] = arr[i];
        }
        --size;
    }

    T& operator[](size_t index) {
        return arr[index];
    }

    const T& operator[](size_t index) const {
        return arr[index];
    }

    T& at(size_t index)
    {
        if (index >= size_v)
        {
            throw std::out_of_range("Bad index");
        }
        return arr[index];
    }

    T* begin() {
        return &arr[0];
    }

    const T* begin() const {
        return &arr[0];
    }

    T* end() {
        return &arr[size_v];
    }

    const T* end() const {
        return &arr[size_v];
    }

};

int main()
{
    vector<int> arr_v;
    arr_v.push_back(1);
    arr_v.push_back(3);
    arr_v.push_back(5);
    arr_v.push_back(2);
    arr_v.push_back(4);
    arr_v.push_back(6);
    arr_v.at(4) = 22;

    for (auto& i : arr_v)
    {
        std::cout << i << std::endl;
    }

    std::cout << std::endl;
    
    std::cout << "at(4): " << arr_v.at(4) << std::endl;
    std::cout << "size(): " << arr_v.size() << std::endl;
    std::cout << "capacity(): " << arr_v.capacity() << std::endl;

    vector<int> arr_v2 = arr_v;
    arr_v2.push_back(99);
    arr_v2.push_back(88);
    arr_v2.push_back(77);
    arr_v2.at(6) = 123;

    std::cout << std::endl;
    for (auto& i : arr_v2)
    {
        std::cout << i << std::endl;
    }

    std::cout << std::endl;
    std::cout << "at(6): " << arr_v2.at(6) << std::endl;
    std::cout << "size(): " << arr_v2.size() << std::endl;
    std::cout << "capacity(): " << arr_v2.capacity() << std::endl;

    return 0;
}
