#include "eventQueue.cpp"
#include "readyQueue.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void handle_ARR(double, bool, Node*, EventQueue);
void handle_DEP(Node*);


int main(){
    double lambda = 0;
    double clock = 0.0;
    bool CPU_idle = true;
    int eventID = 0;
    EventQueue eventQueue;
    ReadyQueue readyQueue_CPU;
    ReadyQueue readyQueue_Disk;

    eventQueue.insert(11, 0.0, 1, 3.3);
    eventQueue.insert(12, 3.3, 1, 3.0);
    eventQueue.insert(13, 4.0, 1, 3.0);
    eventQueue.insert(14, 6.2, 1, 2.9);
    readyQueue_CPU.insert(20);

    //create a loop that creates events. must create arrivals with poisson distributions.
    while(!(eventID == 10000)) {
        //begin running the simulation processes on the CPU and each time a process starts
        //create a departure event, time = clock + Ts, calculate probability of exit vs. disk
        Node* event = eventQueue.get_head(); //returns head of event queue
        clock = event->eventTime;
        switch(event->eventType) {
            case 1:
                handle_ARR(clock, CPU_idle, event, eventQueue);
            case 2:
                handle_DEP(event);
        }
    }


    //eventQueue.display();
}

void handle_ARR(double clock, bool &idle, Node* event, EventQueue &queue,  ReadyQueue &rqCPU){
    bool CPU_idle = idle;
    EventQueue eventQueue = queue;
    ReadyQueue readyQueue_CPU = rqCPU;
    int pID = event->processID;
    double time = event->eventTime;
    double burst = event->burst;

    if(CPU_idle){
        eventQueue.insert(pID, clock + burst, 2);
        CPU_idle = false;
        idle = CPU_idle;
    }
    else
        //enqueue PID into ready queue
        readyQueue_CPU.insert(pID)

    eventQueue.insert(100, random, 1, clock + burst);
}

void handle_DEP(double clock, bool &idle, Node* event, EventQueue &queue, ReadyQueue &rqCPU){
    bool CPU_idle = idle;
    EventQueue eventQueue = queue;
    ReadyQueue readyQueue_CPU = rqCPU;
    int pID = event->processID;
    double time = event->eventTime;
    double burst = event->burst;

    if (readyQueue_CPU.isEmpty()) {
        CPU_idle = true;
        idle = CPU_idle;
    }
    else{
        //pop pid from ReadyQueue
        //...^^
        eventQueue.insert(pID, clock + burst, 2);
    }
}