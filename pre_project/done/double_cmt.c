//method 1 is find /* and */ in file store st en which is 0 at first 
//before remove see of en-st != 0 other wize error
//if en-st !=0  start from /* and stop if */

#include<stdio.h>
#include<string.h>

void main(){
	FILE *fp= fopen("data.c","r+");	
	int st,i,en,flag;	
	char ch;
	
	st=0;en=0;flag=0;
	while((ch = fgetc(fp)) != EOF){
		if(flag == 0){	
			if(ch == '/'){
				if(fgetc(fp) == '*'){
					st++;
					flag=1;
				}
			}
		}
		if(flag){
			if(ch == '*'){
				if(fgetc(fp) == '/'){
					en++;
					flag=0;
				}

			}
		}
	}
	if((st-en) != 0){
		printf("NOT PROPER COMMENT\n");
		return;
	}
	rewind(fp);
	
	while((ch = fgetc(fp)) != EOF){
		if(ch == '/'){
			if(fgetc(fp) == '*'){
				fseek(fp,-2,SEEK_CUR);
				fputc(' ',fp);fputc(' ',fp);

			do{
				if(fgetc(fp) == '*'){
					if(fgetc(fp) == '/'){
						fseek(fp,-2,SEEK_CUR);
						fputc(' ',fp);fputc(' ',fp);
						break;
					}				
				}
				else
					fseek(fp,-1,SEEK_CUR);

				fputc(' ',fp);
			}while(1);
			
			}
		}
	
	}
	
}	
	
	
	










