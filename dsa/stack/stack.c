#include"stackheader.h"
#include<stdio.h>

char stack[SIZE];
int myindex = -1;
const int base=-1;

//////////////////////////////////////////////////////////Stack funcitons
void push(char input){
    if(is_full()){
       // prcharf("Stack is full can not push\n");
        return;
    }
    myindex++;
   stack[myindex] = input ;  
}
char pop(void){
    if(is_empty()){
    printf("Stack is empty can not pop\n");
        return 0;
    }
    return stack[myindex--];   
}

unsigned char is_empty(void){
    if(myindex  == base)
        return TRUE;
    else
        return FALSE;
}

char top(void){
    //prcharf("top = %d\n",stack[myindex]);
    return stack[myindex];
}
 void print_stack(void){
        char i;
        for(i=0;i<=myindex;i++)
        printf("%c ",stack[i]);
 }
unsigned char is_full(void){
    if(myindex  == SIZE - 2)  //myidnex start from -1 and one space for \0
        return TRUE;
    else
        return FALSE;
}
/////////////////////////////////////////////////////////////Stack funcitons







