#pragma once

#ifndef __ARTICAL_H
#define __ARTICAL_H

class Artical
{
private:
	char* nameOfArtical;
	Date publishDate;
	Researcher** researchersOfArtical;
	int numOfResearchersOfArtical;

public:
	Artical(char* nameOfArtical);
	Artical(const Artical& other);
	bool setNameOfArtical(const char* nameOfArtical);
	char* getNameOfArtical()const;
	bool addResearcher(const Researcher& researcher);
	Researcher** getResearchersOfArtical()const;
	int getNumOfResearchersOfArtical()const;
	void printArtical() const;
	~Artical();
};

#endif // __ARTICAL_H