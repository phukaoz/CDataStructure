# vector
***vector.h*** is a C header library for dynamic array.\
Essentially, this is a resizable array of elements of your choosing that is automatically.

- ## how to use
  define ***TYPE*** for data type of vector.
   ```c
   #define TYPE type_name
   ```
  define ***CONTROLLER*** for name vector's controller.
   ```c
   #define TYPE controller_name
   ```
  include ***vector.h*** and declare vector.
   ```c
   #include "vector.h"
   vector vector_name;
   ```
- ## feature
  You have access to all the following functions.
  - ### init( )
    initialize the vector.
    ```c
    controller.init(vector_name);
    ```
  - ### push_back( data )
    add a element at the end of a vector.
    ```c
    controller.push_back(vector_name, data);
    ```
  - ### pop_back( )
    pop the last element in a vector.
    ```c
    controller.pop_back(vector_name);
    ```
  - ### back( )
    get the value of the last element in a vector.
    ```c
    controller.back(vector_name);
    ```
  - ### get( index )
    get the value of element in a vector at specific index.
    ```c
    controller.get(vector_name, index);
    ```
  - ### set( index, value )
    set the value of element in a vector at specific index.
    ```c
    controller.set(vector_name, index, value);
    ```
  - ### begin( )
    get a pointer pointing to the first element of a vector.
    ```c
    controller.begin(vector_name);
    ```
  - ### end( )
    get a pointer pointing to to end of a vector.
    ```c
    controller.end(vector_name);
    ```
  - ### empty( )
    check if a vector is empty.
    ```c
    controller.empty(vector_name);
    ```

- ## sample
  ```c
  #include <stdio.h>
  #define TYPE int
  #define CONTROLLER fn
  #include "vector.h"
  vector v;
  
  int main(){
  	vector_controller_init();
  	fn.init(v);
  
  	for(int i=0;i<10;i++){
  		fn.push_back(v,i);
  	}
  	while(!vcontrol.empty(v)){
  		printf("%d ",fn.back(v));
  		fn.pop_back(v);
  	}
  }
  ```

# queue.h
