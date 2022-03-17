#include <iostream>
#include <chrono> 
using namespace std;
void mergeSort(int arr[], int b, int e);
void printArray(int arr[], int arrSize);
int swapcount = 0, ifcount = 0;
int main()
{
	setlocale(0, "");
	int arrSize;
	cout << "Введите размер массива: ";
	cin >> arrSize;
	if (arrSize <= 0 || arrSize > pow(10, 6))
		return 1;

	int* randIntArr = new int[arrSize];
	srand((unsigned)time(NULL));
	for (int i = 0; i < arrSize; i++)
	{
		randIntArr[i] = rand() % 100 - 10;
	}
	auto start = chrono::high_resolution_clock::now();
	mergeSort(randIntArr, 0, arrSize - 1);
	auto end = chrono::high_resolution_clock::now();
	cout << "Время сортировки: " << ((chrono::duration_cast<chrono::microseconds>)(end - start)).count() << " (микросекунды)\n";
	cout << "Кол-во сравнений: " << ifcount << "\nКол-во перестановок: " << swapcount;

	if (arrSize <= 100)
		printArray(randIntArr, arrSize);
	delete[] randIntArr;
}
int partition(int arr[], int l, int h)
{
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++) {
		ifcount++;
		if (arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]);
			swapcount++;
		}
	}
	swap(arr[i + 1], arr[h]);
	swapcount++;
	return (i + 1);
}
void merge(int* A, int first, int last) {
	int middle, start, final, j;
	int* mas = new int[last + 1];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
			mas[j] = A[start];
			start++;
		}
		else {
			mas[j] = A[final];
			final++;
		}

	for (j = first; j <= last; j++)
		A[j] = mas[j];
	delete[] mas;
};
void mergeSort(int* A, int first, int last) {
	if (first < last) {
		mergeSort(A, first, (first + last) / 2);
		mergeSort(A, (first + last) / 2 + 1, last);
		merge(A, first, last);
	}
}
void printArray(int arr[], int arrSize) {
	cout << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\n";
	}
}