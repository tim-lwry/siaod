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
struct stack {
	list<int> lst;
	int maxsize;
	stack(int size) {
		maxsize = size;
	}
	void push(int i) {
		if (cursize <= maxsize) {
			lst.push_back(i);
			cursize++;
		}
	}
	void pop() {
		if (cursize != 0) {
			lst.pop_back();
			cursize--;
		}
	}
	bool isEmpty() {
		return cursize == 0;
	}
	int getEl(int _i) {
		auto it = lst.begin();
		for (int i = 0; i < _i; i++)
		{
			++it;
		}
		return *it;
	}
private:
	int cursize = 0;
};
int getvisibleCount(stack* st) {
	int f = st->getEl(0);
	int count = 0, highest = f;
	for (int i = 1; i < st->maxsize; i++)
	{
		if (f < st->getEl(i) && highest < st->getEl(i)) {
			count++;
			highest = st->getEl(i);
		}
	}
	return count;
}
int main()
{
	setlocale(0, "");
	srand((unsigned)time(NULL));
	int maxsize;
	cin >> maxsize;
	auto st = stack(maxsize);
	for (int i = 0; i < maxsize; i++)
	{
		int newel;
		cin >> newel;
		st.push(newel);
	}
	cout << getvisibleCount(&st);
}