#pragma once

#ifndef __ARTICAL_H
#define __ARTICAL_H

class Artical
{
private:
	char* nameOfArtical;
	//__DATE__ publishDate;
	Researcher** ResearchersWriteArtical;

public:
	Artical(char* nameOfArtical);
	Artical(const Artical& other);
	void setNameOfArtical(const char* nameOfArtical);
	bool addResearcher(const Researcher& researcher);
	void print() const;
	~Artical();
};

#endif // __ARTICAL_H