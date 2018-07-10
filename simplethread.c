#include <stdio.h>
#include <pthread.h>
#include <string.h>

struct data {
	int id;
	char name [64];
};

void* tafx (void *arg){ //arg = argument
	struct data *mydata = arg;
	int myid = mydata->id;
	
	char myname [64];
	strcpy(myname, mydata->name);

	printf ("I am child, my id: %d, my name: %s\n",myid,myname);
}

void* tbfx (void *arg){ //arg = argument
	struct data *mydata = arg;
	int myid = mydata->id;
	printf ("I am child, my id: %d\n",myid);
}

int main (){

	pthread_t ta, tb; // struct data type, ta stands for "thread a"
	struct data tadata, tbdata; //tbdata: send data to thread b
	tadata.id = 12;
	tbdata.id = 79;

	strcpy(tadata.name, "Adam");
	strcpy(tbdata.name, "Eve");

	if(pthread_create(&ta,NULL,&tafx,&tadata)!=0){
		printf("error creating thread ta\n");
	}
	// come from the library <pthread.h> 
	// after create a thread, have a child called ta 
	// null: things to share, here does not have anything to share from parent to child
	// tafx: call by function, what the child will do
	// declare a struct data, create an instance called tadata, initialise the id of the tadata as 12
	
	if(pthread_create(&tb,NULL,&tafx,&tbdata)!=0){
		printf("error creating thread tb\n");
	}
	
	pthread_join(ta,NULL);
	// join: wait for the child ta
	
	pthread_join(tb,NULL);
	
	return 0;
}
