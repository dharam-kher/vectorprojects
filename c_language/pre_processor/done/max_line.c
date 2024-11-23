#include<stdio.h>

int max_line(FILE *p){
	int max,i;
	char ch;
	
	i=0;max = 0;
	do{	
	    i++;
	    ch = fgetc(p);
	    	if(ch == '\n' || ch == EOF){
		  if(i > max)
		  max = i;
		i=0;
		}
	}while(ch != EOF);

	rewind(p);
	return max;
}
