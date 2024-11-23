//in replace any word in given file 
//method 1 scan string line by line and then do relpace a word in string and 
//then again put back that in file.
#include<stdio.h>
#include<string.h>

void main(){
  FILE *fp = fopen("data.c","r+");
      if(fp == 0){
        perror("fopen: ");
        return;
      }
  //fscanf words if you find #define then next two words will be important
   int l,i,j;
   char define[100],first[100],second[100],delete[100];
   
    while(fscanf(fp,"%s",define) > 0){
      if(strcmp(define,"#define") == 0){
         fscanf(fp,"%s",first);
         fscanf(fp,"%s",second);
         break;
       }
    }
    rewind(fp);
    //delete that line #define
    while(fgets(delete,100,fp)){
        if(strstr(delete,"#define")){
            fseek(fp,-strlen(delete),SEEK_CUR);
            for(i=0;delete[i] != '\n';i++)
                fputc(' ',fp);
                break;
        }
    }
   //now first and second hold the values and first will replaced by second
  char line[200];
  while(fgets(line,100,fp)){//-----------> replacng macros
        l = strlen(line);
        char *find;
	    find= strstr(line,first);
	    if(find != 0){
	      //if word found remove whole line from file
	        fseek(fp,-l,SEEK_CUR);
	        for(i=0;line[i];i++) //because line contanin \n
	            fputc(' ',fp);
	        fseek(fp,-l,SEEK_CUR);
	      //remove that word use index oprations so find still points at where is found
	        for(i=0;first[i];i++)
		  for(j=0;find[j];j++)
  		      find[j]= find[j+1];
              //word got deleted now and word of anylength
	        for(i=0;second[i];i++){
		  for(j=strlen(find);j>=i;j--)
			find[j+1]=find[j];
		find[i]= second[i];
	        }
	      //second word is succesfully replaced in line string put back in file
	        fputs(line,fp);
	    }
  }//<----------------
        rewind(fp); //ahgain start at first to relace next maro;
}

