#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(0, "");
	double delta;
	cout << "Введите дельту: ";
	cin >> delta;
	double x1 = 0, x2 = 0;
	while (x1 + x2 <= 2 && x1 >= 0 && x2 >= 0) {
		if (-2 * x1 - 2 * x2 <= -10) {
			cout << "-2x1 - 2x2 <= -10 = true; x1 = " << x1 << ", x2 = " << x2 <<"  Задача решима" << endl;
			return 0;
		}
		else if (delta > 0.001) 
			cout << "-2x1 - 2x2 <= -10 = false; x1 = " << x1 << ", x2 = " << x2 << endl;
		x1 += delta;
		x2 += delta;
	}
	cout << "\n=>Задача нерешима";
}