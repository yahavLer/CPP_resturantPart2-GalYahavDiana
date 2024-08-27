#pragma once

#include "menuItem.h"

class MenuItemInOrder
{
private:
    MenuItem *menuItem; // ����� ������ �����
    int quantity;
    std::string comment;

public:
    MenuItemInOrder();
    MenuItemInOrder(const MenuItem &menuItem, int quantity, const  std::string& newComment);
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
    const std::string getComment() const;

    bool setQuantity(int quantity);
    bool setComment(const std::string& newComment);

    void print() const;
};