#ifndef EVENT_NODE_H
#define EVENT_NODE_H
//Header file for node function prototypes.
struct Node{
    int processID;
    double eventTime;
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
    Node(int ID, double time, int type, double Ts){
        processID = ID;
        eventTime = time;
        eventType = type;
        burst = Ts;
        waitTime = 0;
        next = nullptr;
        
    }
};

#endif