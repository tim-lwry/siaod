#include <vector>
#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;

struct element {
	int number;
	string name;
	string address;
	element() {
		number = 1 + rand() % 9999999;
		name = "Name_" + to_string(number);
		address = "Address_" + to_string(number);
	}
};
class bankAcc {
public:
	element arr[10000];
	int max_move = 0;
	bankAcc() {
		for (int i = 0; i < 10000; i++) {
			arr[i].number = 0;
			arr[i].name = "";
			arr[i].address = "";
		}
		max_move = 0;
	}
	int hashFunc(int num) {
		int hash;
		num = num / 10;
		if (num % 2) {
			hash = num / 2;
		}
		else {
			hash = 10000 - num / 2;
		}
		return hash;
	}
	void add(element A) {
		int h = hashFunc(A.number);
		int place = 0;
		if (arr[h].name == "")
		{
			arr[h] = A;
		}
		else {
			for (int i = 1; i < 10000; i++) {
				if (h + i < 10000) {
					if (arr[h + i].name == "") {
						arr[h + i] = A;
						max_move = i;
						break;
					}
				}
				else {
					if (arr[h + i].name == "") {
						arr[h + i - 10000] = A;
						max_move = i;
						break;
					}
				}
			}
		}
	}
	void print_list() {
		for (int i = 0; i < 10000; i++) {
			if (arr[i].name != "") {
				cout << "Элемент: " << i << " " << "\tНомер: " << arr[i].number << "\tИмя: " << arr[i].name << "\tАдрес: " << arr[i].address << endl;
			}
		}
	}
	void rem(int num) {
		int h = hashFunc(num);
		arr[h].number = 0; arr[h].name = ""; arr[h].address = "";
	}
	void find(int num) {
		int h = hashFunc(num);
		cout << "Элемент: " << h << " " << "\tНомер: " << arr[h].number << "\tИмя: " << arr[h].name << "\tАдрес: " << arr[h].address << endl;	 //Удаляем элемент используя хэш сумму для прямого доступа ко множеству
	}

	void clean() {
		for (int i = 0; i < 10000; i++)
		{
			arr[i].number = 0;
			arr[i].name = "";
			arr[i].address = "";
		}
		max_move = 0;
	}
};

int main()
{
	setlocale(0, "");
	srand((unsigned)time(NULL));
	bankAcc bnkacc;
	element el1, el2, el3;
	bnkacc.add(el1);
	bnkacc.add(el2);
	bnkacc.add(el3);

	bnkacc.print_list();

	ofstream fout;
	fout.open("bank.txt");


	for (int i = 0; i < 10000; i++) {
		if (bnkacc.arr[i].name != "") {
			fout << i << " " << bnkacc.arr[i].number << " " << bnkacc.arr[i].name << " " << bnkacc.arr[i].address << endl;
		}
	}
	fout.close();

	ifstream in("bank.txt");
	ofstream out("out.b", ios::out | ios::binary);
	element* accs = bnkacc.arr;
	cout << bnkacc.arr[0].name << endl<< endl;
	string d;
	for (int i = 0; i < 10000; i++) {
		if (accs[i].name != "") {
			out.write((char*)&accs[i], sizeof(element));
			//fout << i << " " << bnkacc.arr[i].number << " " << bnkacc.arr[i].name << " " << bnkacc.arr[i].address << endl;
		}
	}
	//for (int i = 0; i < 3; i++) {
		//out.write((char*)&accs[i], sizeof(element));
	//}
	//accs = new element[3];
	in.close();
	out.close();
	element* accs2 = new element[3];
	cout << endl;
	ifstream inb("out.b", ios::out | ios::binary);
	for (size_t i = 0; i < 3; i++)
	{
		inb.read((char*)&accs2[i], sizeof(element));
	}
	for (size_t i = 0; i < 3; i++)
	{
		cout << accs2[i].name << " " << accs2[i].number << " " << accs2[i].address << "\n";
	}
	//bnkacc.print_list();
	
	inb.close();
	return 0;
}