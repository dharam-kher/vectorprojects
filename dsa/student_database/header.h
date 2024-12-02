#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

typedef	struct student{
	int rollno;
	char name[20];
	float marks;
	struct student *next;
}SLL;

void add_begin(SLL **);
void add_end(SLL **);
void print_data(SLL *);
int count_node(SLL *);
void save_file(SLL *);
void delete_all(SLL **);
void add_end(SLL **);
void add_middle(SLL **);
int rollno_check(int,SLL *);
void reverse_print(SLL *);
void print_rec(SLL *);
void reverse_rec(SLL *);
void delete_node(SLL **);
void delete_pos(SLL **);
