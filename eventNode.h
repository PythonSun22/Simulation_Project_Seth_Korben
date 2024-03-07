#ifndef EVENT_NODE_H
#define EVENT_NODE_H
//Header file for node funciton prototypes.
struct Node{
    int processID;
    double arrivalTime;
    int eventType;
    //Enum:
    //CPU Arrival = 1
    //CPU Depart = 2
    //Disk Arrival = 3
    //Disk Depart = 4

    //generated Ts
    double burst;//created on construction or upon entering Q?
    //Time waiting in ready queue
    double waitTime;
    Node* next;

    //Constructor:
    Node(int ID, double arrival, int type, double Ts){
        processID = ID;
        arrivalTime = arrival;
        eventType = type;
        burst = Ts;
        waitTime = 0;
        next = nullptr;
        
    }
};

#endif