#include<stdio.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<ctime>
#include<chrono>
//BUBBLE SORT
void babelkowe(int* tab, int rozmiar)
{

	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 1; j < rozmiar - i; j++)
		{
			if (tab[j - 1] > tab[j]) {

				std::swap(tab[j - 1], tab[j]);
			}
		}
	}






	/*
	for(int i=0;i<1000;i++){
			std::  cout<<tab[i]<<" ";
	}
*/

}


//QUICK SORT
int partition(int* arr, int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}


	int pivotIndex = start + count;
	std::swap(arr[pivotIndex], arr[start]);


	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			std::swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int* arr, int start, int end)
{


	if (start >= end)
		return;


	int p = partition(arr, start, end);


	quickSort(arr, start, p - 1);


	quickSort(arr, p + 1, end);
}

//HEAP SORT

void heapify(int* arr, int N, int i)
{


	int largest = i;


	int l = 2 * i + 1;


	int r = 2 * i + 2;


	if (l < N && arr[l] > arr[largest])
		largest = l;


	if (r < N && arr[r] > arr[largest])
		largest = r;


	if (largest != i) {
		std::swap(arr[i], arr[largest]);


		heapify(arr, N, largest);
	}
}


void heapSort(int* arr, int N)
{

	// Build heap (rearrange array)
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	// One by one extract an element
	// from heap
	for (int i = N - 1; i > 0; i--) {

		// Move current root to end
		std::swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}




//SELECTION SORT
void selectionsort(int* tab, int size)
{
	int k;
	for (int i = 0; i < size; i++)
	{
		k = i;
		for (int j = i + 1; j < size; j++)
			if (tab[j] < tab[k])
				k = j;

		std::swap(tab[k], tab[i]);
	}
}

int main()
{
	//system("color a");
	srand(time(NULL));
	int* a1 = new int[1000];
	int* a2 = new int[1000];
	int* a3 = new int[1000];
	int* a4 = new int[1000];
	for (int i = 0; i < 1000; i++)
	{
		a1[i] = rand() % 1000 + 1;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
	}

	std::cout << "\nTablica 1 000 elemntow.\n";
	auto starta1 = std::chrono::high_resolution_clock::now();
	babelkowe(a1, 1000);
	auto stopa1 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Bubble Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopa1 - starta1).count() << " milisekund.";
	delete[] a1;
	auto starta2 = std::chrono::high_resolution_clock::now();
	quickSort(a2, 0, 999);
	auto stopa2 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Quick Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopa2 - starta2).count() << " milisekund.";
	delete[] a2;
	auto starta3 = std::chrono::high_resolution_clock::now();
	heapSort(a3, 1000);
	auto stopa3 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Heap Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopa3 - starta3).count() << " milisekund.";
	delete[] a3;
	auto starta4 = std::chrono::high_resolution_clock::now();
	selectionsort(a4, 1000);
	auto stopa4 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Selection Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopa4 - starta4).count() << " milisekund.";
	delete[]a4;


	int* b1 = new int[10000];
	int* b3 = new int[10000];
	int* b2 = new int[10000];
	int* b4 = new int[10000];
	for (int i = 0; i < 10000; i++)
	{
		b1[i] = rand() % 1000 + 1;
		b2[i] = b1[i];
		b3[i] = b1[i];
		b4[i] = b1[i];
	}
	std::cout << "\n\nTablica 10 000 elemntow.\n";


	auto startb1 = std::chrono::high_resolution_clock::now();
	babelkowe(b1, 10000);
	auto stopb1 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Bubble Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopb1 - startb1).count() << " milisekund.";
	delete[]b1;
	auto startb2 = std::chrono::high_resolution_clock::now();
	quickSort(b2, 0, 9999);
	auto stopb2 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Quick Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopb2 - startb2).count() << " milisekund.";
	delete[]b2;
	auto startb3 = std::chrono::high_resolution_clock::now();
	heapSort(b3, 10000);
	auto stopb3 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Heap Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopb3 - startb3).count() << " milisekund.";
	delete[]b3;
	auto startb4 = std::chrono::high_resolution_clock::now();
	selectionsort(b4, 10000);
	auto stopb4 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Selection Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopb4 - startb4).count() << " milisekund.";
	delete[]b4;

	int* c1 = new int[30000];
	int* c2 = new int[30000];
	int* c3 = new int[30000];
	int* c4 = new int[30000];
	for (int i = 0; i < 30000; i++)
	{
		c1[i] = rand() % 1000 + 1;
		c2[i] = c1[i];
		c3[i] = c1[i];
		c4[i] = c1[i];
	}
	std::cout << "\n\nTablica 30 000 elemntow.\n";
	auto startc1 = std::chrono::high_resolution_clock::now();
	babelkowe(c1, 30000);
	auto stopc1 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Bubble Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopc1 - startc1).count() << " milisekund.";
	delete[]c1;
	auto startc2 = std::chrono::high_resolution_clock::now();
	quickSort(c2, 0, 29999);
	auto stopc2 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Quick Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopc2 - startc2).count() << " milisekund.";
	delete[]c2;
	auto startc3 = std::chrono::high_resolution_clock::now();
	heapSort(c3, 30000);
	auto stopc3 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Heap Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopc3 - startc3).count() << " milisekund.";
	delete[]c3;
	auto startc4 = std::chrono::high_resolution_clock::now();
	selectionsort(c4, 30000);
	auto stopc4 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Selection Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopc4 - startc4).count() << " milisekund.";
	delete[]c4;
	int* d1 = new int[60000];
	int* d2 = new int[60000];
	int* d3 = new int[60000];
	int* d4 = new int[60000];
	for (int i = 0; i < 60000; i++)
	{
		d1[i] = rand() % 1000 + 1;
		d2[i] = d1[i];
		d3[i] = d1[i];
		d4[i] = d1[i];
	}
	std::cout << "\n\nTablica 60 000 elemntow.\n";
	auto startd1 = std::chrono::high_resolution_clock::now();
	babelkowe(d1, 60000);
	auto stopd1 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Bubble Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopd1 - startd1).count() << " milisekund.";
	delete[]d1;
	auto startd2 = std::chrono::high_resolution_clock::now();
	quickSort(d2, 0, 59999);
	auto stopd2 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Quick Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopd2 - startd2).count() << " milisekund.";
	delete[]d2;
	auto startd3 = std::chrono::high_resolution_clock::now();
	heapSort(d3, 60000);
	auto stopd3 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Heap Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopd3 - startd3).count() << " milisekund.";
	delete[]d3;
	auto startd4 = std::chrono::high_resolution_clock::now();
	selectionsort(d4, 60000);
	auto stopd4 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Selection Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stopd4 - startd4).count() << " milisekund.";
	delete[]d4;
	int* e1 = new int[100000];
	int* e2 = new int[100000];
	int* e3 = new int[100000];
	int* e4 = new int[100000];
	for (int i = 0; i < 100000; i++)
	{
		e1[i] = rand() % 1000 + 1;
		e2[i] = e1[i];
		e3[i] = e1[i];
		e4[i] = e1[i];
	}
	std::cout << "\n\nTablica 100 000 elemntow.\n";

	auto starte1 = std::chrono::high_resolution_clock::now();
	babelkowe(e1, 100000);
	auto stope1 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Bubble Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stope1 - starte1).count() << " milisekund.";
	delete[]e1;
	auto starte2 = std::chrono::high_resolution_clock::now();
	quickSort(e2, 0, 999999);
	auto stope2 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Quick Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stope2 - starte2).count() << " milisekund.";
	delete[]e2;
	auto starte3 = std::chrono::high_resolution_clock::now();
	heapSort(e3, 100000);
	auto stope3 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Heap Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stope3 - starte3).count() << " milisekund.";
	delete[]e3;
	auto starte4 = std::chrono::high_resolution_clock::now();
	selectionsort(e4, 100000);
	auto stope4 = std::chrono::high_resolution_clock::now();
	std::cout << "\nCzas sortowania Selection Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(stope4 - starte4).count() << " milisekund.";
	delete[]e4;



}