#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;

void swap_count(int &a, int &b, int &swap_counter)
{
    int tmp = a;
    a = b;
    b = tmp;
    swap_counter++;
}

void print_results(int comparisons, int swaps, duration<double> elapsed_time)
{
    cout << fixed << setprecision(6);
    cout << "Ilosc porownan: " << comparisons << ", Ilosc Zamian: " << swaps<<", Laczna ilosc operacji: "<<comparisons+swaps
         << ", Czas: " << elapsed_time.count() << " sekundy" << endl;
}

void bubble_sort(int arr[], int x)
{
    int arr2[x];
    for (int i = 0; i < x; i++) {
        arr2[i] = arr[i];
    }

    int comparisons = 0, swaps = 0;
    auto start_time = high_resolution_clock::now();

    bool swapped;
    for (int i = 0; i < x - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < x - i - 1; j++)
        {
            comparisons++;
            if (arr2[j] > arr2[j + 1])
            {
                swap_count(arr2[j], arr2[j + 1], swaps);
                swapped = true;
            }
        }
        if (!swapped) { break; }
    }

    auto end_time = high_resolution_clock::now();
    auto elapsed_time = duration_cast<duration<double>>(end_time - start_time);

    cout << "Bubble Sort - ";
    print_results(comparisons, swaps, elapsed_time);
}

void insert_sort(int arr[], int x) {
    int arr2[x];
    for (int i = 0; i < x; i++) {
        arr2[i] = arr[i];
    }

    int comparisons = 0, swaps = 0;
    auto start_time = high_resolution_clock::now();

    int key, j;
    for (int i = 1; i < x; i++)
    {
        key = arr2[i];
        j = i - 1;
        while (j >= 0 && arr2[j] > key)
        {
            comparisons++;
            swap_count(arr2[j + 1], arr2[j], swaps);
            j = j - 1;
        }
        arr2[j + 1] = key;
    }

    auto end_time = high_resolution_clock::now();
    auto elapsed_time = duration_cast<duration<double>>(end_time - start_time);

    cout << "Insertion Sort - ";
    print_results(comparisons, swaps, elapsed_time);
}

void select_sort(int arr[], int x)
{
    int arr2[x];
    for (int i = 0; i < x; i++) {
        arr2[i] = arr[i];
    }

    int comparisons = 0, swaps = 0;
    auto start_time = high_resolution_clock::now();

    int i, j, min_idx;
    for (i = 0; i < x - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < x; j++)
        {
            comparisons++;
            if (arr2[j] < arr2[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            swap_count(arr2[min_idx], arr2[i], swaps);
    }

    auto end_time = high_resolution_clock::now();
    auto elapsed_time = duration_cast<duration<double>>(end_time - start_time);

    cout << "Selection Sort - ";
    print_results(comparisons, swaps, elapsed_time);
}

int newGap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}

void comb_sort(int arr[], int x) {
    int arr2[x];
    for (int i = 0; i < x; i++) {
        arr2[i] = arr[i];
    }

    int comparisons = 0, swaps = 0;
    auto start_time = high_resolution_clock::now();

    int gap = x;
    bool swapped = true;

    while (gap != 1 || swapped == true) {
        gap = newGap(gap);
        swapped = false;

        for (int i = 0; i < x - gap; i++) {
            comparisons++;
            if (arr2[i] > arr2[i + gap]) {
                swap_count(arr2[i], arr2[i + gap], swaps);
                swapped = true;
            }
        }
    }

    auto end_time = high_resolution_clock::now();
    auto elapsed_time = duration_cast<duration<double>>(end_time - start_time);

    cout << "Comb Sort - ";
    print_results(comparisons, swaps, elapsed_time);
}

void shell_sort(int arr[], int x) {
    int arr2[x];
    for (int i = 0; i < x; i++) { arr2[i] = arr[i]; }

    int comparisons = 0, swaps = 0;
    auto start_time = high_resolution_clock::now();

    int h, i, j, z;
    int N = x;

    for (h = 1; h < N; h = 3 * h + 1);
    h /= 9;
    if (!h) h++;
    for (; h > 0; h /= 3) {
        for (j = h; j < N; ++j) {
            z = arr2[j];
            for (i = j - h; i >= 0 && z < arr2[i]; i -= h) {
                comparisons++;
                swap_count(arr2[i + h], arr2[i], swaps);
            }
            arr2[i + h] = z;
        }
    }

    auto end_time = high_resolution_clock::now();
    auto elapsed_time = duration_cast<duration<double>>(end_time - start_time);
    cout << "Shell Sort - ";
    print_results(comparisons, swaps, elapsed_time);
}
void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    srand(time(NULL));
    int counter = 10000;
    int arr[counter];

    for (int i = 0; i < counter; i++) {
        arr[i] = rand() % 100;
    }
cout<<"Wyniki sortowan dla 10000-elementowej tablicy"<<endl<<endl;
    bubble_sort(arr, counter);
    insert_sort(arr, counter);
    select_sort(arr, counter);
    comb_sort(arr, counter);
    shell_sort(arr, counter);

    int counter2 = 1000;
    int arr2[counter2];

    for (int i = 0; i < counter2; i++) {
        arr2[i] = rand() % 100;
    }

    cout<<endl<<endl<<"Wyniki sortowan dla 1000-elementowej tablicy"<<endl<<endl;
    bubble_sort(arr2, counter2);
    insert_sort(arr2, counter2);
    select_sort(arr2, counter2);
    comb_sort(arr2, counter2);
    shell_sort(arr2, counter2);
    return 0;
}