#pragma once

#ifndef __PERSON_H
#define __PERSON_H
class Person
{
private:
	char* firstName;
	char* lastName;
	int id;
	Date dateOfBirth;
public:
	Person(const char* firstName, const char* lastName, const int id);
	Person(const Person& other);
	bool setFirstName(const char* n);
	bool setLastName(const char* n);
	char* getFirstName() const;
	char* getLastName() const;
	int getId() const;
	void printPerson() const;
	~Person();
};

#endif // __PERSON_H