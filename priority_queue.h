#include "utility.h"
#ifndef TYPE
    #define TYPE int
#endif
#ifndef CONTROLLER
    #define CONTROLLER vcontrol
#endif

typedef struct{
    size_t size;
    size_t capacity;
    TYPE *array;
}priority_queue_struct;