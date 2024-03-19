#include "eventNode.h"
#include <cassert> //Provides assert funciton
#include <iostream> //Provides cin, cout
#include <iomanip> //Provdes setw
#include <cmath>  //Provides log2
//Definitions for the node functions.
//Constructor
using namespace std;
//Prototypes:

/******************************************************************/
class EventQueue {
private:
    Node* head;     // Pointer to the first node in the list

public:
    // Constructor to initialize the linked list
    EventQueue() : head(nullptr) {}

    // Destructor to delete all nodes in the list
    ~EventQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Method to insert a new node at the beginning of the list
    void insert(int ID, double time, int type, double Ts = 0.0) {
        Node* newNode = new Node(ID, time, type, Ts);
        //Node* current = head;
        if (head == nullptr)
            head = newNode;
        else{
            //newNode->next = head;
            //head = newNode;
            Node* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        
    }

    // Method to display the contents of the list
    
    void display() {
        Node* current = head;
        cout << endl;
        while (current) {
            std::cout << "PID: " << current->processID << ", Process Type:  " << current->eventType 
            << ", Arrival Time: " << current->eventTime << ", Ts: " << current->burst << endl;
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node* get_head() {
        return head;
    }
};