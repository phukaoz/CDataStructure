#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void* swap(void* first_element_, void* second_element_, size_t size_of_element_){
    void* temp_ = malloc(size_of_element_);
    memcpy(temp_, first_element_, size_of_element_);
    memcpy(first_element_, second_element_, size_of_element_);
    memcpy(second_element_, temp_, size_of_element_);
    free(temp_);
}

#endif