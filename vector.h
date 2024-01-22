#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#ifndef name_
    #define name_ v
#endif
#ifndef type_
    #define type_ int
#endif

#define str_concat(x, y) x ## _ ## y
#define concat(x, y) str_concat(x, y)
#define capacity concat(name_, capacity)
#define size concat(name_, size)
#define push_back concat(name_, push_back)
#define init concat(name_, init)
#define pop_back concat(name_, pop_back)
#define back concat(name_, back)
#define begin concat(name_, begin)
#define end concat(name_, end)
#define find concat(name_, find)

size_t capacity;
size_t size;
type_ *name_;

void init(void){
    size = 0;
    capacity = 8;
    name_ = (type_*)malloc(capacity*sizeof(type_));
}

void push_back(type_ value){
    if(size == capacity){
        capacity = capacity<<1;
        name_ = (type_*)realloc(name_, capacity*sizeof(type_));
    }
    name_[size++] = value;
}

void pop_back(void){
    if(size == 0){
        fprintf(stderr,"vector is empty.");
        exit(-1);
    }
    size--;
}

type_ back(void){
    if(size == 0){
        fprintf(stderr,"vector is empty.");
        exit(-1);
    }
    return name_[size-1];
}

type_* begin(void){
    return name_;
}

type_* end(void){
    return &(name_[size]);
}

type_* find(type_ target){
    type_ *ptr_ = begin();
    for(ptr_ = begin();ptr_ != end();ptr_++){
        if(*ptr_ == target){
            break;
        }
    }
    return ptr_;
}

#undef name_
#undef type_
#undef size
#undef capacity
#undef pop_back
#undef push_back
#undef begin
#undef end
#undef back
#undef init