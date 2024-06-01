#pragma once
#pragma once

#ifndef __RESEARCHER_H
#define __RESEARCHER_H
#include "Worker.h"
#include "Artical.h"
//#define ID_SIZE 9
class Researcher : public Worker
{
private:
	int numOfArticles;
	Artical* articalsOfResearcher; //array of articles

public:
	Researcher();
	bool addArticle(const Artical* artical);
	Artical* getArticals() const;
	int getNumOfArticles() const;
	void printResearcher() const;
	~Researcher();
};

#endif // __RESEARCHER_H

