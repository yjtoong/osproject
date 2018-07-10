#include <stdio.h>
#include <string.h>

struct Person{
	char name[64];
	int ic;
	struct Address{
		char street[64];
		int postcode;
	}address;
};

void setData (char* n, int ic, char* st, int pc, struct Person*);
void printData (struct Person*);

int main () {
	struct Person a;
	struct Person b;

	strcpy(a.name,"Adam");
	a.ic = 223445;
	strcpy(a.address.street, "Jalan Inti");
	a.address.postcode = 66788;

	printData(&a);

	setData("Eve",556,"Jalan",778,&b);
	printData(&b);
}

void setData (char* n, int ic, char* st, int pc, struct Person* p){
	strcpy(p->name, n);
	p->ic = ic;
	strcpy(p->address.street, st);
	p->address.postcode = pc;
}

void printData (struct Person* p){
	printf("name: %s\n", p->name);
	printf("ic: %d\n", p->ic);
	printf("address.street: %s\n", p->address.street);
	printf("address.postcode: %d\n\n", p->address.postcode);
}
