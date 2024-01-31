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
    if(initial_capacity >= 1){
        vector* new_vector = malloc(sizeof(vector));
        new_vector->capacity = initial_capacity;
        new_vector->array = malloc(sizeof(type) * new_vector->capacity);
        new_vector->size = 0;
        return new_vector;
    }else{
        fprintf(stderr,"Invalid initial capacity in vector_create().");
        exit(EXIT_FAILURE);
    }
}

void vector_free(vector* vect){
    free(vect->array);
    free(vect);
}

void push_back(vector* vect, type value){
    if(vect->size >= vect->capacity){
        vect->capacity = vect->capacity << 1; //double capacity
        vect->array = realloc(vect->array, vect->capacity);
    }
    vect->array[vect->size++] = value;
}

int empty(vector* vect){
    return (vect->size == 0);
}

void pop_back(vector* vect){
    if(!is_empty(vect)){
        vect->size--;
    }else{
        fprintf(stderr,"Can't pop, vector is empty.");
        exit(EXIT_FAILURE);
    }
}

type* begin(vector* vect){
    return vect->array;
}

type* end(vector* vect){
    return &(vect->array[vect->size]);
}

int main(void){

    return 0;
}