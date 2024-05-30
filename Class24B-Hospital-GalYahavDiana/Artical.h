#pragma once

#ifndef __ARTICAL_H
#define __ARTICAL_H

class Artical
{
private:
	char* nameOfArtical;
	//__DATE__ publishDate;
	Researcher** ResearchersWriteArtical;
	Worker** staffOfDepartment;

public:
	Artical(char* nameOfArtical);
	Artical(const Artical& other);
	void setNameOfArtical(const char* nameOfArtical);
	void print() const;
	~Artical();
};

#endif // __ARTICAL_H