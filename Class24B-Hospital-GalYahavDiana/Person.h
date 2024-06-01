#pragma once

#ifndef __PERSON_H
#define __PERSON_H
//#define ID_SIZE 9
class Person
{
private:
	char* firstName;
	char* lastName;
	//char id[ID_SIZE];
	int id; 

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