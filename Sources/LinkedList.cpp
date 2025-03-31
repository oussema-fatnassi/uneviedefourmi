#include "Headers/LinkedList.hpp"

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    Ant *current = head;
    Ant *next;
    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Add an ant at the end of the linked list
void LinkedList::addAntAtEnd(int data)
{
    Ant *newAnt = new Ant();
    newAnt->data = data;
    newAnt->next = nullptr;

    if (head == nullptr)
    {
        head = newAnt;
        return;
    }
    Ant *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newAnt;
}

// Delete an ant by its value
void LinkedList::deleteByValue(int data)
{
    Ant *current = head;
    Ant *previous = nullptr;
    while (current != nullptr)
    {
        if (current->data == data)
        {
            if (previous == nullptr)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Print the linked list
void LinkedList::printList()
{
    Ant *current = head;
    while (current != nullptr)
    {
        if (current->next == nullptr)
        {
            cout << current->data;
            break;
        }
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << endl;
}

// Get the ant at a specific position in the linked list
Ant &LinkedList::getAnt(int data)
{
    Ant *current = head;
    while (current != nullptr)
    {
        if (current->data == data)
        {
            return *current;
        }
        current = current->next;
    }
    // This is problematic - returning reference to temporary
    // Better to throw an exception or return a pointer
    static Ant dummy;
    return dummy;
}

// Get the size of the linked list
int LinkedList::size()
{
    int count = 0;
    Ant *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}
