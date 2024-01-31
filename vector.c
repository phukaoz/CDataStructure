#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

#define type int

typedef struct{
    size_t size;
    size_t capacity;
    type *array;
}vector;

vector* vector_create(size_t initial_capacity){
    vector* new_vector = (vector*)malloc(sizeof(vector));
    new_vector->capacity = initial_capacity;
    new_vector->array = (type*)malloc(sizeof(type) * new_vector->capacity);
    new_vector->size = 0;
    return new_vector;
}

void vector_free(vector* vect){
    free(vect->array);
    free(vect);
}

void push_back(vector* vect, type value){
    if(vect->size >= vect->capacity){
        if(vect->capacity == 0){
            vect->capacity = 1;
        }else{
            vect->capacity = vect->capacity << 1; //double capacity
        }
        vect->array = (type*)realloc(vect->array, vect->capacity*sizeof(type));
    }
    vect->array[vect->size++] = value;
}

int empty(vector* vect){
    return (vect->size == 0);
}

void pop_back(vector* vect){
    if(empty(vect)){
        fprintf(stderr,"Can't pop, vector is empty.");
        exit(EXIT_FAILURE);
    }
    vect->size--;
}

type* begin(vector* vect){
    return vect->array;
}

type* end(vector* vect){
    return &(vect->array[vect->size]);
}

void delete(vector* vect,size_t position){
    if(position >= vect->size){
        fprintf(stderr,"Invalid positon for delete().");
        exit(EXIT_FAILURE);
    }
    for(size_t i = position+1;i<vect->size;i++){
        vect->array[i-1] = vect->array[i];
    }
    vect->size--;
}

size_t size(vector* vect){
    return vect->size;
}

type vget(vector* vect,size_t position){
    if(position >= vect->size){
        fprintf(stderr,"Invalid position for vget().");
        exit(EXIT_FAILURE);
    }
    return vect->array[position];
}

int main(void){
    vector* v = vector_create(0);
    for(int i=0;i<20;i++){
        push_back(v,i+1);
    }
    delete(v,12);printf("\n");
    return 0;
}