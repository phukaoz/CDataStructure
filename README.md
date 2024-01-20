# vector.h
C header library for dynamic array.\
Essentially, this is a resizable array of elements of your choosing that is automatically.

# how to use

# sample
```
#include <stdio.h>
#define TYPE int
#define CONTROLLER fn
#include "vector.h"
vector v;

int main(){
	vector_controller_init();
	vcontrol.init(&v);
	
	for(int i=0;i<10;i++){
		vcontrol.push_back(&v,i);
	}

	while(!vcontrol.empty(&v)){
		printf("%d ",vcontrol.back(&v));
		vcontrol.pop_back(&v);
	}
}
```
