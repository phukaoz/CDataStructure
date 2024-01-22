#include "algorithm.h"

#ifndef name_
    #define name_ pq
#endif
#ifndef type_
    #define type_ int
#endif

#define str_concat(x, y) x ## _ ## y
#define concat(x, y) str_concat(x, y)
#define capacity concat(name_, capacity)
#define size concat(name_, size)
#define init concat(name_, init)
#define push concat(name_, push)
#define top concat(name_, top)
#define compare concat(name_, compare)
#define empty concat(name_, empty)
#define pop concat(name_, pop)

size_t capacity_;
size_t size_;
type_ *name_;
int (*compare)(type_*, type_*);

void init(int (compare_function_)(type_*, type_*)){
    capacity_ = 8;
    size_ = 0;
    name_ = (type_*)malloc(capacity_*sizeof(type_));
    compare = compare_function_;
}

void push(type_ value_){
    if(size_ == capacity_){
        capacity_ = (capacity_<<1);
        name_ = (type_*)realloc(name_,capacity_*sizeof(type_));
    }
    name_[size_] = value_;
    size_t index_ = size_++;
    while(index_ > 0){
        if((*compare)(&(name_[index_]), &(name_[(index_-1)/2]))){
            swap(&(name_[index_]), &(name_[(index_-1)/2]), sizeof(type_));
        }else{
            break;
        }
        index_ = (index_ - 1)/2;
    }
}

int empty(void){
    return (size_ == 0);
}

type_ top(void){
    return name_[0];
}

void pop(void){
    if(size_ == 0){
        fprintf(stderr, "queue is empty.");
        exit(-1);
    }
    name_[0] = name_[--size_];
    size_t index_ = 0;
    size_t child_;
    while((child_ = index_*2+1) < size_){
        if(child_+1 < size_ && !( (*compare)(&name_[child_], &name_[child_ + 1]  ) )){
            child_++;
        }
        if( !((*compare)(&name_[child_],&name_[index_])) ){
            break;
        }
        swap(&name_[index_],&name_[child_],sizeof(type_));
        index_ = child_;
    }
}


#undef str_concat
#undef concat
#undef capacity
#undef size
#undef init
#undef push
#undef top
#undef empty