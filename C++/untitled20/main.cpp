#include <iostream>
#include <cstdlib>  // Dla funkcji rand()

// Bubble Sort
template <typename T>
void bubble_sort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Shell Sort with Bubble Sort
template <typename T>
void shell_sort_with_bubble(T arr[], int n) {
    int gap = n / 2;

    while (gap > 0) {
        for (int i = gap; i < n; ++i) {
            T temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
        gap /= 2;
    }
}

// Insertion Sort for almost sorted data
template <typename T>
void custom_sort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template <typename T>
void print_array(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    const int size = 10;

    // Integer data
    int int_array[size];
    for (int i = 0; i < size; ++i) {
        int_array[i] = rand() % 100;
    }

    std::cout << "Original Integer Data: ";
    print_array(int_array, size);

    bubble_sort(int_array, size);
    std::cout << "Sorted with Bubble Sort: ";
    print_array(int_array, size);

    shell_sort_with_bubble(int_array, size);
    std::cout << "Sorted with Shell Sort: ";
    print_array(int_array, size);

    custom_sort(int_array, size);
    std::cout << "Sorted with Custom Sort: ";
    print_array(int_array, size);

    // Double data
    double double_array[size];
    for (int i = 0; i < size; ++i) {
        double_array[i] = static_cast<double>(rand()) / RAND_MAX * 100.0;
    }

    std::cout << "\nOriginal Double Data: ";
    print_array(double_array, size);

    bubble_sort(double_array, size);
    std::cout << "Sorted with Bubble Sort: ";
    print_array(double_array, size);

    shell_sort_with_bubble(double_array, size);
    std::cout << "Sorted with Shell Sort: ";
    print_array(double_array, size);

    custom_sort(double_array, size);
    std::cout << "Sorted with Custom Sort: ";
    print_array(double_array, size);

    // Char data
    char char_array[size];
    for (int i = 0; i < size; ++i) {
        char_array[i] = 'a' + rand() % 26;
    }

    std::cout << "\nOriginal Char Data: ";
    print_array(char_array, size);

    bubble_sort(char_array, size);
    std::cout << "Sorted with Bubble Sort: ";
    print_array(char_array, size);

    shell_sort_with_bubble(char_array, size);
    std::cout << "Sorted with Shell Sort: ";
    print_array(char_array, size);

    custom_sort(char_array, size);
    std::cout << "Sorted with Custom Sort: ";
    print_array(char_array, size);

    return 0;
}
