#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

#define type int

type* vector;
size_t size;
size_t capacity;

void push(type value){
    if(size >= capacity){
        capacity = capacity << 1;
        vector = (type*)realloc(vector,capacity);
    }
    vector[size++] = value;
}

void pop(){
    if(size <= 0){
        fprintf(stderr,"Can't pop, vector is empty.");
        return;
    }
    size--;
}

type back(){
    return vector[size-1];
}

type* begin(){
    return vector;
}

type* end(){
    return &(vector[size]);
}

type* find(type target){
    type* it = begin();
    while(it != end()){
        if(*it == target){
            break;
        }
        it++;
    }
    return it;
}

void delete(size_t index){
    if(index < 0 || index >= size){
        fprintf(stderr,"Invalid index for delete.");
        return;
    }
    for(size_t i = index+1;index<size;i++){
        vector[i-1] = vector[i];
    }
    size--;
}

int main(void){
    return 0;
}