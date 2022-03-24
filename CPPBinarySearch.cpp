#include <iostream> 
#include <algorithm>
using namespace std;
int* generateRandomArray(int arrSize);
int binarySearch(int arr[], int left, int right, int key);
int comparisonsCount = 0;
void printArray(int arr[], int arrSize) {
	cout << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\n";
	}
}
int main()
{
	setlocale(0, "");
	cout << "Введите размер массива: ";
	int size;
	cin >> size;
	if (size <= 0 || size > pow(10, 6))
		return 1;
	int* a = generateRandomArray(size);
	sort(a, a + size);
	if (size <= 100)
		printArray(a, size);
	cout << "Введите искомый элемент: ";
	int sv;
	cin >> sv;
	cout << "Номер элемента в массиве: " << binarySearch(a, 0, size, sv) << endl;
	cout << "Кол-во сравнений: " << comparisonsCount;
	delete[] a;
}
int binarySearch(int arr[], int left, int right, int key) {
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (key < arr[midd]) {
			comparisonsCount++;
			right = midd - 1;
		}
		else if (key > arr[midd]) {
			left = midd + 1;
			comparisonsCount++;
		}
		else
			return midd;

		if (left > right) {
			comparisonsCount++;
			return -1;
		}
	}
}
int* generateRandomArray(int as) {
	int* arr = new int[as];
	srand((unsigned)time(NULL));
	for (int i = 0; i < as; i++)
	{
		arr[i] = rand() % 100 - 10;
	}
	return arr;
}