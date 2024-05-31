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
	Cafeteria(const Cafeteria* cafeteriaHeWork);
	bool setCafeteria(const Cafeteria* cafeteriaHeWork);
	Cafeteria* getCafeteria()const ;
	void printCafeteria()const;
	~Cafeteria();
};

#endif // __CAFETERIAWORKER_H

