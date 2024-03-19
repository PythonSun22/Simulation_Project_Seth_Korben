#include "eventQueue.cpp"
#include "readyQueue.h"
#include "readyQueue.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//prototypes
void handle_arrival(bool, Node*);
void handle_departure(Node*);

int main(){
    int end_cond = 0;
    double lambda = 0;
    bool CPU_idle = true;
    double clock = 0.0;
    EventQueue eventQueue;
    ReadyQueue readyqueue_CPU;
    ReadyQueue readyqueue_DISK;

//    eventQueue.insert(11, 0.0, 1, 3.3);
//    eventQueue.insert(12, 3.3, 1, 3.0);
//    eventQueue.insert(13, 4.0, 1, 3.0);
//    eventQueue.insert(14, 6.2, 1, 2.9);


    while(end_cond != 10000){
    Node* event = eventQueue.get_event();
    clock = event->eventTime;
    switch(event->eventType){
        case 1:
            handle_arrival(CPU_idle,event);
        case 2:
            handle_departure(event);
        }

    }
}
//function for handle arrival
void handle_arrival(double clock,bool &idle, Node* event, EventQueue &queue, ReadyQueue &rqueue){
    bool CPU_idle = idle;
    int pID = event->processID;
    double arrival = event->eventTime;
    double burst = event->burst;
    EventQueue eventqueue = queue;
    ReadyQueue readyqueue_CPU = rqueue;
    if(CPU_idle){
        eventqueue.insert(pID, 2, clock + burst);
        CPU_idle = false;
        idle = CPU_idle;
    }
    else{
        rqueue.push(pID);
    }
    eventqueue.insert(pID, clock + burst, 1);
}

//funtion for handle departure
void handle_departure(double clock, bool &idle, Node* event, EventQueue &queue, ReadyQueue &rqueue){
    bool CPU_idle = idle;
    EventQueue eventQueue = queue;
    ReadyQueue readyqueue_CPU = rqueue;
    int pID = event->processID;
    double time = event->eventTime;
    double burst = event->burst;

    if(readyqueue_CPU.isEmpty()) {
        CPU_idle = true;
        idle = CPU_idle;
    }
    else{
        //pop pid from ready queue
        rqueue.pop();
        eventQueue.insert(pID, clock + burst, 2);
    }
}
