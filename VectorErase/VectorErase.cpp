/*
    Задача 14
    Из вектора удалить все элементы, значение которых меньше х, но оставить элементы,
        предшествующие последнему вхождению значения, не меньшего у
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

void print(int i) {
    cout << i << ' ';
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    vector<int> v;
    int n = rand() % 21 + 10;
    for (int i = 0; i < n; ++i) {
        v.push_back(rand() % 10);
        cout << v[i] << ' ';
    }

    int x, y;
    cout << "\nВведите x: ";
    cin >> x;
    cout << "\nВведите y: ";
    cin >> y;

    auto it = v.end();

    while (it != v.begin() && *it < y)
        --it;
    
    while (it != v.end()) {
        if (*it < x)
            v.erase(it);
        else
            ++it;
    }

    cout << endl;
    for_each(v.begin(), v.end(), print);
}
