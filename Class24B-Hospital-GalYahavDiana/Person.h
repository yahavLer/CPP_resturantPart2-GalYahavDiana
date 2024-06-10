#pragma once

#ifndef __PERSON_H
#define __PERSON_H
#include "Date.h"
class Person
{
private:
	char* firstName;
	char* lastName;
	int id;
	Date dateOfBirth;
public:
	Person(const char* firstName, const char* lastName, const int id, Date dateOfBirth);
	Person(const Person& other);
	bool setFirstName(const char* n);
	bool setLastName(const char* n);
	char* getFirstName() const;
	char* getLastName() const;
	int getId() const;
	Date getDateOfBirth();
	void printPerson() const;
	~Person();
};

#endif // __PERSON_H