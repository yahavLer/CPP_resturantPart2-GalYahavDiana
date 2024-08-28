#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H
#include "menuItem.h"
#include <string>

class Observer
{
public:
    virtual ~Observer() {}
    virtual void update(const MenuItem& mealName) = 0;  // Called when a new meal is added
};

#endif // OBSERVER_H