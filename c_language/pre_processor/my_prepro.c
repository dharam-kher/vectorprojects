#include "myheader.h"

void main(int c,char **v){
  if(c != 2){
      printf("USEAGE: ./pre_pro <FileName>\n");
      return;
  }
  FILE *fp = fopen(v[1],"r+");
      if(fp == 0){
          perror("fopen: ");
          return;
      }
      rm_single_cmt(fp);
      rm_multi_cmt(fp);
      replace_macro(fp);
        include_header(fp);
}
void rm_single_cmt(FILE *fp){
        char ch,i;
	while((ch= fgetc(fp)) != EOF){  //finding // in file i occurs
	    if(ch== '/'){
		if((ch= getc(fp)) == '/'){
	            fseek(fp,-2,SEEK_CUR);
		    while(fgetc(fp) != '\n'){
			fseek(fp,-1,SEEK_CUR);
			fputc(' ',fp);  //deleting upto \n
		    }
		}
	    }		
	}
	rewind(fp);
}
void rm_multi_cmt(FILE *fp){
//method 1 is find /* and */ in file store st en which is 0 at first 
//before remove see of en-st != 0 other wize error
//if en-st !=0  start from /* and stop if */
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
		printf("NOT PROPER IN MULTI-LINE COMMENT\n");
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
	rewind(fp);
}
void replace_macro(FILE *fp){
   char define[100],first[100],second[100],delete[100];
     int l,i,j;
   
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
void include_header(FILE *fp){
// h index for heads it will need and fopening heads and copying
// b index for backups 

	int i,j,flag,k,h,b;
	char c[100],*cp;//official required
	char heads[10][50];// dependenciy
	
	h=0;
	do{
		cp = fgets(c,100,fp);
		if(strstr(c,"#include")){
			
			for(i=0,j=0,flag=0;c[i];i++){
				if(flag)		
					heads[h][j++]= c[i];	//getting the headers in 2D array				
				if(c[i] == '<') 
					flag= 1;
				if(c[i+1] == '>')
					break;
			}
			heads[h][j] = '\0';
			h++;
		}
	}while(cp);
	
	rewind(fp);
//delet the # include files from program ,,save ftell where #include found for future purpose

char back[50][100]; //backup 2D buffer

	b=0;
	while(fgets(c,100,fp)){
		
		if(strstr(c,"#include")){
			fseek(fp,-strlen(c),SEEK_CUR); 
			for(i=0;c[i] != '\n';i++) //because c have '\n' in it 
				fputc(' ',fp);	
		continue;
		}
		strcpy(back[b++],c);//getting backups then deleting file PENDING still it will work
		//fseek(fp,-strlen(back[b-1]),SEEK_CUR);
		//	for(i=0; back[b-1][i] !='\n'; i++)
		//		fputc(' ',fp);
        }
	rewind(fp);

//open heads and copy it to opened file do it 
	FILE *hptr[h];

	for(i=0; i<h; i++){
		hptr[i] = fopen(heads[i],"r");
			if(hptr[i] == 0){
				printf("%s NOT FOUND",heads[i]);		
				return;
			}
		copy_file(fp,hptr[i]);
	}

//header file are copied so put back up back ;
	for(i=0;i<b;i++){		
		fputs(back[i],fp);
	}	
// all headers are copied at the top
rewind(fp);
}
void copy_file(FILE *p,FILE *q){
	char z[100];
	while(fgets(z,100,q))
	    fputs(z,p);
}






