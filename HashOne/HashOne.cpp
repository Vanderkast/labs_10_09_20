/**
    Задание 25
    Приведите содержимое хеш-таблицы, образованной вставками элементов с ключами E A S Y Q U T I O N в указанном порядке 
    в первоначально пустую таблицу размером  M = 16, использующую линейное опробование. 
    Для преобразования k-ой буквы алфавита в индекс таблицы используйте хеш-функцию 11k mod М.
*/

#include <iostream>

#define M 16
#define S 2

using namespace std;

int _hash(char, int);
void insert(int*, char, int);
void insert(int*, char);
 
int main()
{
    int* table = new int[M];
    
    for (int i = 0; i < M; ++i) {
        table[i] = 0;
    }
    
    insert(table, 'E');
    insert(table, 'A'); 
    insert(table, 'S'); 
    insert(table, 'Y'); 
    insert(table, 'Q'); 
    insert(table, 'U'); 
    insert(table, 'T'); 
    insert(table, 'I'); 
    insert(table, 'O'); 
    insert(table, 'N'); 

    for (int i = 0; i < M; ++i) {
        cout << (char)(table[i] == 0 ? '_' : table[i]) << "   ";
    }

    cout << endl;
}

int _hash(char key, int i) {
    return  11 * (key - ((int)'A')) % M + S * i;
}

void insert(int* table, char key, int i) {
    int pos = _hash(key, i); 
    if (pos > M)
        return;
    if (table[pos] == 0)
        table[pos] = key;
    else insert(table, key, ++i);
}

void insert(int* table, char key) {
    insert(table, key, 0);
}