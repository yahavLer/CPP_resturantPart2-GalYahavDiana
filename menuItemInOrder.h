#pragma once

#include "menuItem.h"
using namespace std;


class MenuItemInOrder
{
private:
    MenuItem *menuItem; // מצביע לאובייקט MenuItem
    int quantity;
    string comment;

public:
    MenuItemInOrder();
    MenuItemInOrder(const MenuItem &menuItem, int quantity, const  string& newComment);
    MenuItemInOrder(MenuItem *menuItem, int quantity);
    ~MenuItemInOrder(); // Destructor to clean up

    MenuItemInOrder &operator+=(int num);
    MenuItemInOrder &operator-=(int num);
    MenuItemInOrder operator+(int num) const;
    MenuItemInOrder operator-(int num) const;
    MenuItemInOrder &operator++();
    // MenuItemInOrder operator++(int); // ���� ����� ���� �� �� �� �� ����

    MenuItem *getMenuItem() const;
    int getQuantity() const;
    const string& getComment() const;

    bool setQuantity(int quantity);
    bool setComment(const string& newComment);

    void print() const;
};