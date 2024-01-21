#include "utility.h"
#ifndef TYPE
    #define TYPE int
#endif
#ifndef CONTROLLER
    #define CONTROLLER vcontrol
#endif

#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef struct{
    size_t size;
    size_t capacity;
    TYPE *array;
    size_t data_size;
} vector_struct;

typedef vector_struct vector[1];

void vector_init(vector vector_name){
    vector_name->size = 0;
    vector_name->capacity = 4;
    vector_name->data_size = sizeof(TYPE);
    vector_name->array = (TYPE*)malloc(vector_name->capacity*vector_name->data_size);
}

void vector_push_back(vector vector_name,TYPE value){
    if(vector_name->size == vector_name->capacity){
        vector_name->capacity = (vector_name->capacity << 1);
        vector_name->array = (TYPE*)realloc(vector_name->array,vector_name->capacity*vector_name->data_size);
    }
    vector_name->array[vector_name->size++] = value;
}

void vector_pop_back(vector vector_name){
    if(vector_name->size != 0){
        vector_name->size--;
    }else{
        fprintf(stderr, "index out of bound.");
        exit(-1);
    }
}

TYPE vector_back(vector vector_name){
    if(vector_name->size == 0){
        fprintf(stderr, "index out of bound.");
        exit(-1);
    }
    return vector_name->array[vector_name->size-1];
}

bool vector_empty(vector vector_name){
    return (vector_name->size == 0 ? true : false);
}

TYPE vector_get(vector vector_name,size_t index){
    if(index >= vector_name->size){
        fprintf(stderr, "index out of bound.");
        exit(-1);
    }
    if(index < 0){
        fprintf(stderr, "invalid index.");
        exit(-1);
    }
    return vector_name->array[index];
}

TYPE* vector_begin(vector vector_name){
    return &(vector_name->array[0]);
}

TYPE* vector_end(vector vector_name){
    return &(vector_name->array[vector_name->size]);
}

typedef struct{
    void (*init)(vector);
    void (*push_back)(vector, TYPE);
    void (*pop_back)(vector);
    TYPE (*back)(vector);
    TYPE (*get)(vector, size_t);
    bool (*empty)(vector);
    TYPE* (*begin)(vector);
    TYPE* (*end)(vector);
}vector_controller;

vector_controller CONTROLLER;

void vector_controller_init(){
    CONTROLLER.init = vector_init;
    CONTROLLER.push_back = vector_push_back;
    CONTROLLER.pop_back = vector_pop_back;
    CONTROLLER.back = vector_back;
    CONTROLLER.get = vector_get;
    CONTROLLER.empty = vector_empty;
    CONTROLLER.begin = vector_begin;
    CONTROLLER.end = vector_end;
}


#endif
#undef TYPE
#undef CONTROLLER