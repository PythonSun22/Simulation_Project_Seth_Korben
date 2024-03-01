#ifndef EVENT_NODE_H
#define EVENT_NODE_H
//Header file for node funciton prototypes.
struct eventNode{
    double arrivalTime;
    int eventType;
    //Enum:
    //CPU Arrival = 1
    //CPU Depart = 2
    //Disk Arrival = 3
    //Disk Depart = 4

    //generated Ts
    double burst;
    //Time waiting in ready queue
    double waitTime;
    eventNode* next;
};
#endif