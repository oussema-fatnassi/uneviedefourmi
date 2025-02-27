#include "Headers/LinkedList.hpp"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Ant* current = head;
    Ant* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

void LinkedList::addAntAtEnd(int data) {
    Ant* newAnt = new Ant();
    newAnt->data = data;
    newAnt->next = nullptr; 
    
    if (head == nullptr) {
        head = newAnt;
        return;
    }
    Ant* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newAnt;
}

void LinkedList::deleteByValue(int data) {
    Ant* current = head;
    Ant* previous = nullptr;
    while (current != nullptr) {
        if (current->data == data) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void LinkedList::printList() {
    Ant* current = head;
    while (current != nullptr) {
        if(current->next == nullptr) {
            cout << current->data;
            break;
        }
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << endl;
}

Ant& LinkedList::getAnt(int data) {
    Ant* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return *current;
        }
        current = current->next;
    }
    // This is problematic - returning reference to temporary
    // Better to throw an exception or return a pointer
    static Ant dummy;
    return dummy;
}

int LinkedList::size() {
    int count = 0;
    Ant* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
