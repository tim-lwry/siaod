/*
#include <cmath>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
*/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void printList(list<int> L) {
	for (auto i : L)
	{
		cout << i << endl;
	}

}
void fillList(list<int>* L, int q) {

	for (int i = q - 1; i >= 0; i--)
	{
		L->push_front(rand() % 10);
	}
}
int main()
{
	setlocale(0, "");
	srand((unsigned)time(NULL));
	list<int> L1, L2, L;
	fillList(&L1, 10);
	fillList(&L2, 10);
	for (auto i : L1)
	{
		if (find(L2.begin(), L2.end(), i) == L2.end() && find(L.begin(), L.end(), i) == L.end()) {
			L.push_front(i);
		}
	}
	for (auto i : L2)
	{
		if (find(L1.begin(), L1.end(), i) == L1.end() && find(L.begin(), L.end(), i) == L.end()) {
			L.push_front(i);
		}
	}
	cout << "L1 ------\n";
	printList(L1);
	cout << "\nL2 ------\n";
	printList(L2);
	cout << "\nL ------\n";
	printList(L);

}