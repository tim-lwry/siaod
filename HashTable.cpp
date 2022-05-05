#include <iostream>
#include <list>
using namespace std;

class HashTable
{
    int capacity;
    list<int>* chair;

public:
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);

    int checkPrime(int n)
    {
        int i;
        if (n == 1 || n == 0)
        {
            return 0;
        }
        for (i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    int getPrime(int n)
    {
        if (n % 2 == 0)
        {
            n++;
        }
        while (!checkPrime(n))
        {
            n += 2;
        }
        return n;
    }

    int hashFunction(int key)
    {
        return (key % capacity);
    }
    void displayHash();
};
HashTable::HashTable(int c)
{
    int size = getPrime(c);
    this->capacity = size;
    chair = new list<int>[capacity];
}
void HashTable::insertItem(int key, int data)
{
    int index = hashFunction(key);
    chair[index].push_back(data);
}

void HashTable::deleteItem(int key)
{
    int index = hashFunction(key);

    list<int>::iterator i;
    for (i = chair[index].begin();
        i != chair[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    if (i != chair[index].end())
        chair[index].erase(i);
}

void HashTable::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "Chair[" << i << "]";
        for (auto x : chair[i])
            cout << " --> " << x;
        cout << endl;
        cout << "Table[" << i << "]";
        for (auto x : chair[i])
            cout << " --> " << x;
        cout << endl;
    }
}
int main()
{
    setlocale(0, "");

    int key[] = { 6, 5, 4, 3, 2, 1 };
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(key) / sizeof(key[0]);

    HashTable h(n);

    for (int i = 0; i < n; i++)
        h.insertItem(key[i], data[i]);

    h.deleteItem(12);
    h.displayHash();
}