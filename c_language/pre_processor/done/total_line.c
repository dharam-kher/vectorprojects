#include<stdio.h>

int total_line(FILE *p){
	int line=1;
	char ch;	
	do{
		ch= fgetc(p);
		if(ch == '\n')
			line++;
	}while(ch != EOF);
	
	rewind(p);
	
	return line;
}
