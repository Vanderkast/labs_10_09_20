#include <random>
#include <vector>

#include "PersonTable.h"
#include "Person.h"

PersonTable::PersonTable() {
	this->a = rand() % P;
	this->b = rand() % P;
}

int PersonTable::hash(long key) {
	return ((a * key + b) % P) % M;
}

void PersonTable::insert(Person person) {
	int h = hash(person.phone);
	if(list[h].empty())
		list[h].push_back(Person(person.phone, person.fullName, person.address));
	else {
		for (int i = 0; i < list[h].size(); ++i) {
			if (list[h][i].phone == person.phone) {
				list[h][i] = person;
				return;
			}
			list[h].push_back(person);
		}
	}
}

Person PersonTable::find(long phone) {
	vector<Person> v = list.at(hash(phone));
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].phone == phone)
			return v[i];
	}
	return Person();
}
