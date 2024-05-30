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
	Artical** articalsOfResearcher;
	char** subject; ;


public:
	Researcher(const int numOfArticles, char* subject);
	Artical addArticle(const Artical* artical);
	~Researcher();
};

#endif // __RESEARCHER_H

