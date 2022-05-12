#include <iostream>
using namespace std;

int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	return min;
}

int main()
{
	setlocale(0, "");
	int arr[] = { 5,10,3,12,5 };//, 5, 50, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "ћинимальное количество скал€рных умножений = "
		<< MatrixChainOrder(arr, 1, n - 1);
}