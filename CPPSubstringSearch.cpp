#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int KMPSearch(string haystack, string needle);
int main()
{
	setlocale(0, "");
	cout << "Введите адрес файла: ";
	string path;
	getline(cin, path);
	ifstream ifs(path);
	string content((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
	cout << "Текст файла:\n";
	printf(content.c_str());
	cout << endl;
	cout << "Введите подстроку для поиска: ";
	getline(cin, path);
	cout << KMPSearch(content, path);
	ifs.close();
}

int KMPSearch(string haystack, string needle) {
	int indx = -1;
	for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
		bool succ = true;
		for (int j = 0; j < needle.length(); j++)
		{
			if (needle[j] != haystack[i + j]) {
				succ = false;
				break;
			}
			if (succ)
			{
				indx = i;
				break;
			}
		}
	}
	return indx;
}