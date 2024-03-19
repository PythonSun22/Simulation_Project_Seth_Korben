#ifndef EVENT_NODE_H
#define EVENT_NODE_H
//Header file for queue function prototypes.
struct ReadyNode{
    int processID;
    ReadyNode* next;

    //Constructor:
    explicit ReadyNode(int PID){
        processID = PID;
        next = nullptr;
    }
};

#endif 