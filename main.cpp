#include "eventQueue.cpp"
#include "readyQueue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    double lambda = 0;
    EventQueue eventQueue;

    eventQueue.insert(11, 0.0, 1, 3.3);
    eventQueue.insert(12, 3.3, 1, 3.0);
    eventQueue.insert(13, 4.0, 1, 3.0);
    eventQueue.insert(14, 6.2, 1, 2.9);

    eventQueue.display();
}