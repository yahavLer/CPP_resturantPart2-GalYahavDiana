#ifndef __MENUITEMINORDER_H
#define __MENUITEMINORDER_H

#pragma once

#include "menuItem.h"

class MenuItemInOrder
{
private:
    MenuItem *menuItem; // ����� ������ �����
    int quantity;
    char comment[20];

public:
    MenuItemInOrder();
    MenuItemInOrder(const MenuItem &menuItem, int quantity, const char *comment);
    MenuItemInOrder(MenuItem *menuItem, int quantity);
    ~MenuItemInOrder(); // Destructor to clean up

    MenuItemInOrder &operator+=(int num);
    MenuItemInOrder &operator-=(int num);
    MenuItemInOrder operator+(int num);
    MenuItemInOrder operator-(int num);
    MenuItemInOrder &operator++();
    // MenuItemInOrder operator++(int); // ���� ����� ���� �� �� �� �� ����

    MenuItem *getMenuItem() const;
    int getQuantity() const;
    const char *getComment() const;

    bool setQuantity(int quantity);
    bool setComment(const char *comment);

    void print() const;
};

#endif // __MENUITEMINORDER_H