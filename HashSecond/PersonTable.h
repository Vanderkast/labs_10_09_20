#pragma once

#include <array>
#include <vector>

#include "Person.h"

using namespace std;

#define P 10000000019
#define M 32

#ifndef PERSONTABLE_H
#define PERSONTABLE_H

class PersonTable
{
private:
	long a, b;
	array<vector<Person>, M> list;

	int hash(long key);
public:
	PersonTable();

	void insert(Person);

	Person find(long phone);
};

#endif 
