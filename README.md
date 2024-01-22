# vector.h
C header library for dynamic array (using macros in C).\
**dyanmic array** is an array that automatically resize.

- ## how to use
  first, define your vector name through ```name_``` macro.
  ```c
  #define name_ vector_name
  ```
  define your vector's data type through ```type_``` macro.
  ```c
  #define type_ data_type
  ```
  include vector.h libary.
  ```c
  #include "vector.h"
  ```
  now, you can access method-like functions.\
  you can call a function with ```vector's name``` ```_``` ```function's name```
  
- ## feature and sample
  ```c
  /* declare */
  #define name_ vec
  #define type_ int
  #include "vector.h"
  ```
  ### init( )
  initialize your vector.
  ```c
  vec_init();
  ```

  ### push_back( value )
  insert a value in the end of your vector.
  ```c
  vec_push_back(5);
  ```

  ### pop_back( )
  delete the last element in your vector.
  ```c
  vec_pop_back();
  ```

  ### back( )
  return a value of the last element in your vector.
  ```c
  if( vec_back() == 5 ){
    /*
      do something...
    */
  }
  ```

  ### begin( )
  return a pointer pointing to the first element in your vector.
  ```c
  int* ptr = vec_begin();
  int first_element = *ptr;
  ```

  ### end( )
  return a pointer pointing to the end of your vector (**not last element**).
  ```c
  while( ptr != vec_end()){
    /*
      do something...
    */
    ptr++;
  }
  ```