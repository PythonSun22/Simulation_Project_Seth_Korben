#include "readyQueue.h"
//Definitions for the Ready Queue, Disk Queue,
#include <iostream>
using namespace std;

class ReadyQueue{
private:
    ReadyNode* head;

public:
    ReadyQueue() : head(nullptr) {}

    ~ReadyQueue() {
        while (head) {
            ReadyNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int PID){
        ReadyNode* newNode = new ReadyNode(PID);
        if (head == nullptr)
            head = newNode;
        else{
            //newNode->next = head;
            //head = newNode;
            ReadyNode* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void pop(){}

    bool isEmpty() {
        return (head == nullptr);
    }
};
