#ifndef type_
    #define type_ int
#endif

#define str_concat(x, y) x ## _ ## y
#define concat(x, y) str_concat(x, y)
#define greater concat(greater, type_)
#define greater_equal concat(greater_equal, type_)
#define less concat(less, type_)
#define less_equal concat(less_equal, type_)
#define equal concat(equal, type_)
#define not_equal concat(not_equal, type_)

int greater(type_ *first_element_, type_ *second_element_){return *first_element_ > *second_element_;}
int greater_equal(type_ *first_element_, type_ *second_element_){return *first_element_ >= *second_element_;}
int less(type_ *first_element_, type_ *second_element_){return *first_element_ < *second_element_;}
int less_equal(type_ *first_element_, type_ *second_element_){return *first_element_ <= *second_element_;}
int equal(type_ *first_element_, type_ *second_element_){return *first_element_ == *second_element_;}
int not_equal(type_ *first_element_, type_ *second_element_){return *first_element_ != *second_element_;}

#undef str_concat
#undef concat
#undef greater
#undef greater_equal
#undef less
#undef less_equal
#undef equal
#undef not_equal
