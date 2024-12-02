#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct dll{
	struct bank *prev;
		char name[20];	
		int accno;
		float bal;
	struct bank *next;
}dll;

void open_begin(void);

