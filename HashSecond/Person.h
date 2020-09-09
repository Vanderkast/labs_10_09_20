#pragma once

#include <string>

using namespace std;

#ifndef PERSON_H
#define PERSON_H

struct Person {
	long phone;
	string fullName;
	string address;

	Person(){
		phone = -1;
		fullName = "";
		address = "";
	}

	Person(long p, string n, string a) {
		phone = p;
		fullName = n;
		address = a;
	}

	bool equal(Person& to) {
		return this->phone == to.phone
			&& this->fullName == to.fullName
			&& this->address == to.address;
	}
};

#endif // !PERSON_H

