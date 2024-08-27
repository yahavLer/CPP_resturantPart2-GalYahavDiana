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
    MenuItemInOrder(const MenuItem &menuItem, int quantity, const  std::string& comment);
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
    bool setComment(const std::string& comment);

    void print() const;
};