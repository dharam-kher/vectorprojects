#include<stdio.h>

int count_line_length(FILE *p,int num){
   int i,max= max_line(p);
   char *cp,s[max+1],ch;
  
   cp = 0;
   for(i=0 ;i<num; i++)
     cp = fgets(s,max+1,p);
    
    rewind(p);
    
    if(cp != 0)
        return strlen(cp);
    else
        printf("LINE NOT AVAILABLE\n");
}
