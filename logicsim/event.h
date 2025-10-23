#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;

    private:

};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        uint64_t operator()(const Event* lhs, const Event* rhs) {
            return rhs->time > lhs->time;
        }
} EventLess;
	
#endif
