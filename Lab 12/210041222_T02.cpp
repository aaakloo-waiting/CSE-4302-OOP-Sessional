#include <iostream>
using namespace std;
template <typename T, size_t N>
void arrayMultiplication(const T (&array1)[N], const T (&array2)[N], T (&result)[N]) {
    for (size_t i = 0; i < N; ++i) {
        result[i] = array1[i] * array2[i];
    }
}

template <typename T, size_t N>
void printArray(const T (&array)[N]) {
    for (size_t i = 0; i < N; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int intArray1[] = {1, 2, 3, 4};
    int intArray2[] = {5, 6, 7, 8};
    int intResult[4];
    arrayMultiplication(intArray1, intArray2, intResult);

    cout << "Integer Result: ";
    printArray(intResult);

    double doubleArray1[] = {1.1, 2.2, 3.3, 4.4};
    double doubleArray2[] = {5.5, 6.6, 7.7, 8.8};
    double doubleResult[4];
    arrayMultiplication(doubleArray1, doubleArray2, doubleResult);

    cout << "Double Result: ";
    printArray(doubleResult);

    return 0;
}
