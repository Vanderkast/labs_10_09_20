/*
    Задание 42
    Задан набор записей следующей структуры:
    {номер телефона, ФИО, адрес}
    По номеру найти остальные сведения.
*/

#include <iostream>
#include <ctime>
#include <random>

#include "Person.h"
#include "PersonTable.h"

using namespace std;

Person input();
void print(Person&);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int n;
    cout << "Введите количество записей (макс. 32): ";
    cin >> n;

    PersonTable table;
    for (int i = 0; i < n; ++i) {
        table.insert(input());
    }

    long phone = 1;
    while (phone != -1) {
        cout << "\nВведите номер телефона для поиска: ";
        cin >> phone;

        Person p = table.find(phone);
        if (p.phone == -1)
            cout << "\nЧеловека с таким номером нет в базе";
        else
            print(p);
    }

    cout << "\n\n";
}

Person input() {
    Person person;
    cout << "\nВведите номер телефона: ";
    cin >> person.phone;
    cout << "\nВведите ФИО:";
    cin.ignore();
    getline(cin, person.fullName);
    cout << "\nВведите адрес:";
    cin.ignore();
    getline(cin, person.address);
    return person;
}

void print(Person& p) {
    cout << "\nТелефон: " << p.phone << " ФИО: " << p.fullName << " Адрес: " << p.address;
}