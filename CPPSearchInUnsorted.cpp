#include <iostream> 
using namespace std;
int* generateRandomArray(int arrSize);
int findItemInArray(int item, int* arr, int as);
int comparisonsCount = 0;
int main()
{
	setlocale(0, "");
	cout << "������� ������ �������: ";
	int size;
	cin >> size;
	if (size <= 0 || size > pow(10, 6))
		return 1;
	int* a = generateRandomArray(size);
	cout << "������� ������� �������: ";
	int sv;
	cin >> sv;
	cout << "����� �������� � �������: " << findItemInArray(sv, a, size) << endl;
	cout << "���-�� ���������: " << comparisonsCount;
	delete[] a;
}
int findItemInArray(int item, int* arr, int as) {
	for (int i = 0; i < as; i++)
	{
		comparisonsCount++;
		if (arr[i] == item) {
			return i;
		}
	}
	return -1;
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