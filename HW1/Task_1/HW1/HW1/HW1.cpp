#include <fstream>
#include <iostream>

int main() {
    std::ifstream fin("in.txt");
    int size;
    int size2;

    if (!fin.is_open()) {
        std::cout << "Не удалось открыть фаил!" << std::endl;
    }
    fin >> size; // чтение первого числа

    int* arr = new int[size];

    for (int i = 0; i < size;
        i++) { // чтение последующих чисел и запись в массив
        fin >> arr[i];
    }

    fin >> size2; // чтение первого числа

    int* arr2 = new int[size2];

    for (int i = 0; i < size2;
        i++) { // чтение последующих чисел и запись в массив
        fin >> arr2[i];
    }

    fin.close();

    std::ofstream fout("out.txt");

    if (!fout.is_open()) {
        std::cout << "Не удалось открыть фаил для записи!" << std::endl;
    }

        fout << size2 << std::endl;

        for (int i = size2 - 1; i >= 1 ; i--) {
            int temp = arr2[i - 1];
            arr2[i - 1] = arr2[i];
            arr2[i] = temp;
        }

        for (int i = 0; i < size2; i++) {
            fout << arr2[i] << " ";
        }

        fout << std::endl;

        fout << size << std::endl;

        for (int i = 1; i < size; i++) {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }

        for (int i = 0; i < size; i++) {
            fout << arr[i] << " ";
        }

        fout.close();

    delete[] arr2;
    arr2 = nullptr;

    delete[] arr;
    arr = nullptr;

    return 0;
}