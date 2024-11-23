#include<stdio.h>
#include<string.h>

int max_word(FILE *p);
int max_line(FILE *p);

void main(){
  FILE *fp = fopen("data.c","r+");
  int maxw= max_word(fp),maxl= max_line(fp),flag,l,i;
  char fd[maxw+1],rd[50],sd[maxw+1],rem[maxl];

      printf("find: ");
      scanf("%s",fd);
      l= strlen(fd);
      printf("replace: ");
      scanf("%s",rd);
      
  flag =1;
  while(fscanf(fp,"%s",sd) > 0){
      if(strcmp(sd,fd) == 0){
          flag= 0;    
      fseek(fp,-l,SEEK_CUR);
      for(i=0; fd[i];i++)
          fputc(' ',fp);
   
      fgets(rem,maxl,fp);
      fseek(fp,-(l + strlen(rem)),SEEK_CUR);
      fprintf(fp,"%s%s",rd,rem);
      }
  }
  if(flag)
      printf("WORD NOT FOUND\n");
  
}
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
int max_word(FILE *p){
  int i=0,max=0;
  char ch;
  do{
      i++;
      ch= fgetc(p);
      if(ch == ' ' || ch== '\n' ||ch == EOF){
          if(i > max)
              max= i;
      i=0;   
      }
  }while(ch != EOF);
  rewind(p);
  return max;
}

