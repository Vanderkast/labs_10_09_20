// Задание 17
// Имеется N городов. Для каждой пары городов можно построить дорогу, соединяющую эти два города напрямую, и известна ее стоимость.
// Найти самую дешевую сеть дорог. позволяющая попасть из любого города в любой другой.

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

bool hasFalse(bool*, int);
int minPosFalse(int*, bool*, int);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand((int) time(0));

    int n;
    cout << "Введите количество городов: ";
    cin >> n;

    int** graph = new int* [n]; 
    int* priceToPoint = new int[n];
    int** lowestRoadTo = new int*[n];
    bool* flags = new bool[n];

    bool** net = new bool* [n];
    for(int i = 0; i < n; ++i) {
        graph[i] = new int[n];
        net[i] = new bool[n];
        flags[i] = false;
        priceToPoint[i] = INT_MAX;
        for (int j = 0; j < n; ++j)
            net[i][j] = false;
    }

    bool hand = false;
    cout << "\nРучной ввод? ";
    cin >> hand;

    if (hand) {
        for (int i = 0; i < n; ++i) {
            graph[i][i] = -1;
            for (int j = i + 1; j < n; ++j) {
                cout << "\nВведите стоимость дорого (" << i + 1 << ';' << j + 1 << ") : ";
                cin >> graph[i][j];
                graph[j][i] = graph[i][j];
            }
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            graph[i][i] = -1;
            for (int j = i + 1; j < n; ++j) {
                 graph[i][j] = rand() % 9 + 1;
                 graph[j][i] = graph[i][j];
            }
        }
    }

    priceToPoint[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }

    int box, handle;
    while (hasFalse(flags, n)) {
        handle = minPosFalse(priceToPoint, flags, n);
        if (handle == -1)
            break;
        for (int i = 0; i < n; ++i) {
            box = priceToPoint[handle] + graph[handle][i];
            if (i != handle 
                && !flags[i] 
                && priceToPoint[i] > box) 
            {
                lowestRoadTo[i] = &(graph[handle][i]);
                priceToPoint[i] = box;
            }
        }
        flags[handle] = true;
    }

    cout << "\n\n";
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!net[i][j]) {
                net[i][j] = (lowestRoadTo[i] == &(graph[i][j])) || (lowestRoadTo[i] == &(graph[j][i]));
                net[j][i] = net[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                cout << "\\ ";
            else
                cout << (net[i][j] ? "X " : "- ");
        }
        cout << endl;
    }

    cout << "\n\n";
    system("pause");
}

bool hasFalse(bool* a, int n) {
    for (int i = 0; i < n; ++i)
        if (!a[i]) return true;
    return false;
}

int minPosFalse(int* a, bool* flags, int n) {
    int mPos = -1; int min = INT_MAX;
    bool set = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1 && a[i] < min && !flags[i]) {
            mPos = i;
            min = a[i];
            set = true;
        }
    }
    return set ? mPos : -1;
}