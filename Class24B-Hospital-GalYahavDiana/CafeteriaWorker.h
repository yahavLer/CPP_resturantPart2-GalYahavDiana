#pragma once

#ifndef __CAFETERIAWORKER_H
#define __CAFETERIAWORKER_H
#include "Worker.h"
#include "Cafeteria.h"
class CafeteriaWorker : public Worker
{
private:
	Cafeteria* cafeteriaHeWork; 

public:
	CafeteriaWorker (const Cafeteria* cafeteriaHeWork);
	bool setCafeteria(Cafeteria* cafeteriaHeWork);
	Cafeteria* getCafeteria() const ;
	void printCafeteriaWorker() const;
	~CafeteriaWorker();
};

#endif // __CAFETERIAWORKER_H

