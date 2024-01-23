# algorithm.h
C header library that defines a bunch of functions.\
designed to help make work more convenient.

- ## how to use
  include algorithm.h libary.
  ```c
  #include "algorithm.h"
  ```

- ## feature and sample
  ### swap( first , second , element_size )
  exchange values of two objects.
  ```c
  int a = 10;
  int b = 25;
  swap(&a, &b, sizeof(int));
  ```

# priority_queue.h
C header library for binary heap.\
**binary heap** is a tree which obeys the property that the root of any tree has priority over all its children.\

- ## how to use
  first, define your queue's name through ```name_``` macro.
  ```c
  #define name_ priority_queue_name
  ```
  define your queue's data type through ```type_``` macro.
  ```c
  #define type_ data_type
  ```
  include **priority_queue.h** library.
  ```c
  #include "priority_queue.h"
  ```
  then, you need a compare function for initialize your queue.\
  for example, if you want your queue to be a **max heap**, you need a function like this.
  ```c
  int greater_equal(int a, int b){
    return a >= b;
  }
  ``` 
  fortunately, we've already provided those functions.\
  you can include ```functional.h``` library. (this library need ```type_``` macro)
  ```c
  #include "functional.h"
  ```
  now you can access all following compare functions.\
  ```greater_equal_{type}``` ```greater_{type}```  ```less_{type}``` ```less_equal_{type}``` ```equal_{type}``` ```not_equal_{type}```  
  initialize your priority queue through init( ) function.
  ```c
  /* in main */
  priority_queue_name_init( compare_function );
  ```
  note that you can only include ```functional.h``` once per ```type_```

- ## feature and sample
  ```c
  /* declare */
  #define name_ pq
  #define type_ int
  #include "priority_queue.h"
  #include "functional.h"
  ```
  ### init( function )
  initialize your priority queue with compare function.
  ```c
  /* max heap */
  pq_init(greater_equal_int);
  ```

  ### push( value ) 
  insert a value in your priority queue.
  ```c
  pq_push(5);
  ```
  time complexity : O(log n)

  ### pop( )
  delete a element with the highest priority in your priority queue.
  ```c
  pq_pop();
  ```
  time complexity : O(log n)

  ### top( )
  return a value of the element with the highest priority in your priority queue.
  ```c
  int max_value = pq_top();
  ```
  time complexity : O(1)

# vector.h
C header library for dynamic array (using macros in C).\
**dyanmic array** is an array that automatically resize.\
\
currently, my vector is not support 2D vector.\
I'm looking to make it as simple and easy to use as possible.

- ## how to use
  first, define your vector's name through ```name_``` macro.
  ```c
  #define name_ vector_name
  ```
  define your vector's data type through ```type_``` macro.
  ```c
  #define type_ data_type
  ```
  include **vector.h** library.
  ```c
  #include "vector.h"
  ```
  use init( ) function to initialize your vector.
  ```c
  /* in main */
  vector_name_init();
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