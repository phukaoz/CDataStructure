#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

#define type int

int compare(const type *a, const type *b){
    return *a>=*b;
}

typedef struct{
    size_t size;
    size_t capacity;
    type *array;
}priority_queue;

priority_queue* priority_queue_create(){
    priority_queue* new_queue = (priority_queue*)malloc(sizeof(priority_queue));
    new_queue->capacity = 8;
    new_queue->array = (type*)malloc(sizeof(type) * new_queue->capacity);
    new_queue->size = 0;
    return new_queue;
}

void priority_queue_free(priority_queue* queue){
    free(queue->array);
    free(queue);
}

void push(priority_queue* queue, type value){
    if(queue->size >= queue->capacity){
        queue->capacity = queue->capacity << 1; //double capacity
        queue->array = (type*)realloc(queue->array, queue->capacity*sizeof(type));
    }
    queue->array[queue->size++] = value;
    size_t index = queue->size-1;
    while(index > 0 && compare(&(queue->array[index]),&(queue->array[(index-1)/2]))){
        type temp = queue->array[index];
        queue->array[index] = queue->array[(index-1)/2];
        queue->array[(index-1)/2] = temp;
        index = (index-1)/2;
    }
}

int empty(priority_queue* queue){
    return (queue->size == 0);
}

void pop(priority_queue* queue){
    if(empty(queue)){
        fprintf(stderr,"Can't pop, priority_queue is empty.");
        exit(EXIT_FAILURE);
    }
}

void delete(priority_queue* queue,size_t position){
    if(position >= queue->size){
        fprintf(stderr,"Invalid positon for delete().");
        exit(EXIT_FAILURE);
    }
    for(size_t i = position+1;i<queue->size;i++){
        queue->array[i-1] = queue->array[i];
    }
    queue->size--;
}

type top(priority_queue* queue){
    return queue->array[0];
}

size_t size(priority_queue* queue){
    return queue->size;
}

int main(){
    priority_queue* pq = priority_queue_create();
    printf("%d",top(pq));
}