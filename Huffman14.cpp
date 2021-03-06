#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;
struct nachalo_spisik {
	char ch;
	int freq;
	nachalo_spisik* left, * right;
};
nachalo_spisik* getnachalo_spisik(char ch, int freq, nachalo_spisik* left, nachalo_spisik* right) {
	nachalo_spisik* node = new nachalo_spisik();
	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;
	return node;
}

struct comp {
	bool operator()(nachalo_spisik* l, nachalo_spisik* r) {
		return l->freq > r->freq;
	}
};

void encode(nachalo_spisik* root, string str,
	unordered_map<char, string>& code_by_Haff) {
	if (root == nullptr)
		return;
	if (!root->left && !root->right) {
		code_by_Haff[root->ch] = str;
	}
	encode(root->left, str + "0", code_by_Haff);
	encode(root->right, str + "1", code_by_Haff);
}
void decode(nachalo_spisik* root, int& index, string str) {
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right) {
		cout << root->ch;
		return;
	}
	index++;
	if (str[index] == '0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}
void stroim_tree_Haff(string text) {
	unordered_map<char, int> freq;
	for (char ch : text) {
		freq[ch]++;
	}
	priority_queue<nachalo_spisik*, vector<nachalo_spisik*>, comp> pq;
	for (auto pair : freq) {
		pq.push(getnachalo_spisik(pair.first, pair.second, nullptr, nullptr));
	}
	while (pq.size() != 1) {
		nachalo_spisik* left = pq.top(); pq.pop();
		nachalo_spisik* right = pq.top();	pq.pop();
		int sum = left->freq + right->freq;
		pq.push(getnachalo_spisik('\0', sum, left, right));
	}
	nachalo_spisik* root = pq.top();
	unordered_map<char, string> code_by_Haff;
	encode(root, "", code_by_Haff);
	cout << "??? ????????:" << '\n';
	for (auto pair : code_by_Haff) {
		cout << pair.first << "=" << pair.second << '\n';
	}
	cout << "?????:\n" << text << '\n';
	string str = "";
	for (char ch : text) {
		str += code_by_Haff[ch];
	}
	cout << "?????????:\n" << str << "\n\n";
	int index = -1;
	while (index < (int)str.size() - 2) {
		decode(root, index, str);
	}
}
int main()
{
	setlocale(0, "");
	cout << "??????? ?????:\n";
	string text;
	getline(cin, text);
	map<char, int> charCount;
	for (unsigned int i = 0; i < text.size(); i++)
		charCount[text[i]]++;
	cout << "?????????? ????????:" << endl;

	for (map<char, int>::iterator it = charCount.begin(); it != charCount.end(); ++it)
		cout << it->first << "=" << it->second << "  ";
	cout << endl;
	stroim_tree_Haff(text);

	return 0;
}