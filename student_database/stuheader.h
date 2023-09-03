#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct student{
	int roll;
	char name[1];
	float mark;
	struct student *next;
}sll;


