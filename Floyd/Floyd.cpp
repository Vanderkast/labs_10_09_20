/*
    Задание 4
    Найти кратчайшее расстояние между двумя вершинами в графе. 
    Найти все возможные пути между этими двумя вершинами в графе не пересекающиеся по
        а) pебpам
        б) веpшинам
*/
#include <iostream>
#include <ctime>
#include <random>

#define MAX 10000

using namespace std;

void print(int**, int);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int n;
    cout << "Введите количество вершин: ";
    cin >> n;

    int** graph = new int* [n];
    for (int i = 0; i < n; ++i)
        graph[i] = new int[n];

    int** route = new int* [n];
    for (int i = 0; i < n; ++i)
        route[i] = new int[n];


    bool hand;
    cout << "Ручной ввод? ";
    cin >> hand;
    if (hand) {
        for (int i = 0; i < n; ++i) {
            graph[i][i] = 0;
            for (int j = i + 1; j < n; ++j) {
                cout << "Введите вес ребра (" << i + 1 << ';' << j + 1 << ") : ";
                cin >> graph[i][j];

                graph[j][i] = graph[i][j];
            }
        }
    }
    else {
        int box;
        for (int i = 0; i < n; ++i) {
            graph[i][i] = MAX;
            for (int j = i + 1; j < n; ++j) {
                graph[i][j] = rand() % 10 - 1;
                graph[j][i] = graph[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            route[i][j] = graph[i][j] == -1 ? MAX : graph[i][j];
            route[j][i] = route[i][j];
        }
        route[i][i] = MAX;
    }

    print(graph, n);
    cout << "\n\n";

    int c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (route[i][j] > (c = route[i][k] + route[k][j]))
                    route[i][j] = c;
            }
        }
    }

    print(route, n);
    cout << "\nКратчайший путь: " << route[0][n - 1];


    cout << "\n\n";  
}

void print(int** a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j)
                if (a[i][j] == MAX || a[i][j] == -1)
                    cout << "- ";
                else
                    cout << a[i][j] << " ";
            else
                cout << "\\ ";
        }
        cout << endl;
    }
}