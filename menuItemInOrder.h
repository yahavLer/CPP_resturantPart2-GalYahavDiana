#pragma once

#include "menuItem.h"

class MenuItemInOrder
{
private:
    MenuItem* menuItem; // מצביע למחלקת הבסיס
    int quantity;
    char comment[20];

public:
    MenuItemInOrder();
    MenuItemInOrder(MenuItem* menuItem, int quantity, const  char* comment);
    MenuItemInOrder(MenuItem* menuItem, int quantity);
    ~MenuItemInOrder(); // Destructor to clean up

    MenuItemInOrder& operator+=(int num);
    MenuItemInOrder& operator-=(int num);
    MenuItemInOrder& operator++();
    // MenuItemInOrder operator++(int); // ניתן לשקול לממש את זה גם אם צריך

    MenuItem* getMenuItem() const;
    int getQuantity() const;
    const char* getComment() const;

    bool setQuantity(int quantity);
    bool setComment(const char* comment);

    void print() const;
};