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
	Artical* articalsOfResearcher;

public:
	Researcher();
	Artical addArticle(const Artical* artical);
	void printResearcher() const;
	Artical* getArticals() const;
	Artical* getNumOfArticles() const;
	~Researcher();
};

#endif // __RESEARCHER_H

