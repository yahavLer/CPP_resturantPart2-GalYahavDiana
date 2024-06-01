#pragma once

#ifndef __ARTICAL_H
#define __ARTICAL_H

class Artical
{
private:
	char* nameOfArtical;
	//__DATE__ publishDate;
	Researcher** researchersOfArtical;

public:
	Artical(char* nameOfArtical);
	Artical(const Artical& other);
	bool setNameOfArtical(const char* nameOfArtical);
	char* getNameOfArtical()const;
	bool addResearcher(const Researcher& researcher);
	Researcher** getResearchersOfArtical()const;
	void printArtical() const;
	~Artical();
};

#endif // __ARTICAL_H