#pragma once
#pragma once

#ifndef __RESEARCHER_H
#define __RESEARCHER_H
#include "Worker.h"
class Artical;
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

