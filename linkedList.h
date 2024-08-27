#pragma once
#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>       //template class that can work with any data type
class LinkedList {
private:
    struct Node
    {
        T data;                 // the data
        Node* next;             // the pointer
        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    
    LinkedList() : head(nullptr), tail(nullptr) {}      // Initializes an empty list
    ~LinkedList();
    void addToEnd(const T& value);          // Adds a new element to the end of the list
    void deleteElement(const T& value);     // Removes the first occurrence of a given element
    void print() const;
    void clear() const;              // Delete all the elemants fron the list
 

    Node* getHead() const { return head; }
    int size() const;

    friend class Department;

    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}
        T& operator*() { return current->data; }
        Iterator& operator++() { current = current->next; return *this; }
        bool operator!=(const Iterator& other) { return current != other.current; }
    };

    class ConstIterator {
    private:
        const Node* current;
    public:
        ConstIterator(const Node* node) : current(node) {}
        const T& operator*() const { return current->data; }
        ConstIterator& operator++() { current = current->next; return *this; }
        bool operator!=(const ConstIterator& other) const { return current != other.current; }
        bool operator==(const ConstIterator& other) const { return current == other.current; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
    ConstIterator begin() const { return ConstIterator(head); }
    ConstIterator end() const { return ConstIterator(nullptr); }
};


template <typename T>
LinkedList<T>::~LinkedList()                //  Deletes all nodes to prevent memory leaks
{
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::addToEnd(const T& value)
{
    Node* newNode = new Node(value);
    if (!head)
    {
        head = tail = newNode;      // tail = newNode   -> head = tail
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::deleteElement(const T& value)
{
    if (!head) return; // Check if the list is empty

    if (head->data == value) // Check if the first node should be deleted
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head)          // if the head id null -> empty list
            tail = nullptr;
        return;
    }

    Node* current = head;
    while (current->next && !(current->next->data == value)) // Find the node to delete
    {
        current = current->next;
    }

    if (current->next) // Delete the node if found
    {
        Node* temp = current->next;         // the node to delete
        current->next = temp->next;         // current pointer - point to the node after the node to delete
        if (temp == tail)       // if delete the last element - tail is the one before
            tail = current;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::print() const
{
    Node* current = head;

    while (current)
    {
        cout << "\t" << current->data;  // Use Item's operator<<
        current = current->next;
    }
}

template <typename T>
void LinkedList<T>::clear() const
{
    Node* current = head;

    while (current)
    {
        deleteElement(current);
    }

} 

template <typename T>


int LinkedList<T>::size() const
{
    int count = 0;
    Node* current = head;
    while (current)
    {
        ++count;
        current = current->next;
    }
    return count;
}

#endif// __LINKRDLIST_H