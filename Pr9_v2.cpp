/*
#include <cmath>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
*/
#include <chrono>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
struct appl {
	static int globnmbr;
	int priority = 0;
	int nmbr;
	float time = 0;
	bool state = false;
	appl(int p) {
		priority = p;
		appl::globnmbr++;
		nmbr = appl::globnmbr;
	}
};
int appl::globnmbr = 0;
auto start = chrono::high_resolution_clock::now();
struct stack {
	vector<appl> lst;
	int maxsize;
	stack(int size) {
		maxsize = size;
	}
	void servePr(int pr) {
		if (pr > 4 || pr < 1)
			return;
		for (int i = 0; i < maxsize; i++)
		{
			if (lst[i].priority == pr && lst[i].state == false) {
				lst[i].state = true;
				auto finish = chrono::high_resolution_clock::now();
				lst[i].time = (float)(((chrono::duration_cast<chrono::microseconds>)(finish - start)).count())/ 60000000;

			}
		}
	}
	void push(appl i) {
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
	/*	int getEl(int _i) {
			auto it = lst.begin();
			for (int i = 0; i < _i; i++)
			{
				++it;
			}
			return *it;*/
			//}
private:
	int cursize = 0;
};
/*int getvisibleCount(stack* st) {
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
}*/
int main()
{
	setlocale(0, "");
	srand((unsigned)time(NULL));
	int maxsize;
	cin >> maxsize;
	auto st = stack(maxsize);
	for (int i = 0; i < maxsize; i++)
	{
		//int newel;
		//cin >> newel;
		st.push(appl(rand()%3+1));
	}
	for (auto& j : st.lst) {
		cout << "Приоритет: " << j.priority << " Номер: " << j.nmbr << "\n";
	}
	cout << "\n---------------------------------------\n";
	st.servePr(1);
	st.servePr(2);
	st.servePr(3);
	for (auto& j : st.lst) {
		cout << "Приоритет: " << j.priority << " Номер: " << j.nmbr << " Время выполнения: " << j.time << " мин.\n";
	}
	//cout << getvisibleCount(&st);
}