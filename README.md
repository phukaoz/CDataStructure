# vector.h
C header library for dynamic array (using macros in C).\
**dyanmic array** is an array that automatically resize.\
\
currently, my vector is not support 2D vector.\
I'm looking to make it as simple and easy to use as possible.

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
  now, you can access your vector and method-like functions.\
  you can access your vector like normal array ```vector[index]```\
  you can also call a function with ```vector's name``` ```_``` ```function's name```
  

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

  ### find( target )
  return a pointer pointing to the first element that its value is the same as the target.\
  if not found the returned pointer points to the end of your vector.
  ```c
  int* ptr = vec_find(5);
  ```

  ### resize( new_size )
  set the size of your vector to new size.
  ```c
  int n = 15;
  vec_resize(n);
  ```