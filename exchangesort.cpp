#include <chrono> 
#include <iostream>
using namespace std;
void printArray(int arr[], int arrSize) {
	cout << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\n";
	}
}
void sortArray(int arr[], int arrSize) {
	auto start = chrono::high_resolution_clock::now();
	unsigned long long comparisonsCount = 0, swapCount = 0;
	int temp;
	for (int i = 0; i < (arrSize); i++)
	{
		for (int j = (i); j < arrSize; j++)
		{
			comparisonsCount++;
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				swapCount += 3;
			}
		}
	}
	auto finish = chrono::high_resolution_clock::now();
	cout << "Время сортировки: " << ((chrono::duration_cast<chrono::microseconds>)(finish - start)).count() << " (микросекунды)\nКол-во перестановок: " << swapCount << "\nКол-во сравнений: " << comparisonsCount << "\nСф + Мф = " << (comparisonsCount + swapCount) << "\n";
}
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
	sortArray(randIntArr, arrSize);
	if(arrSize<=100)
	printArray(randIntArr, arrSize);
	delete[] randIntArr;
}
