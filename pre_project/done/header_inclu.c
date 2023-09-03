// h index for heads it will need and fopening heads and copying
// b index for backups 

#include<stdio.h>
#include<string.h>

void copy_file(FILE *p,FILE *q);

void main(){
	
	FILE *fp= fopen("data.c","r+");
		if(fp == 0){
			perror("fopen: ");
			return;
		}
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

int f1; //store where first f1 found// doing that later
char back[50][100]; //backup 2D buffer

	b=0;
	do{
		cp = fgets(c,100,fp);
		if(strstr(c,"#include")){
			fseek(fp,-strlen(c),SEEK_CUR); 
			for(i=0;c[i] != '\n';i++) //because c have '\n' in it 
				fputc(' ',fp);	
		continue;
		}
		strcpy(back[b++],c);//getting backups then deleting file
		fseek(fp,-strlen(back[b-1]),SEEK_CUR);
			for(i=0; back[b-1][i] !='\n'; i++)
				fputc(' ',fp);

	}while(cp);
	rewind(fp);

//open heads and copy it to opened file do it 
	FILE *hptr[h];
	char z[100];

	for(i=0; i<h; i++){
		hptr[i] = fopen(heads[i],"r");
			if(hptr[i] == 0){
					perror("fopen ");		
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
	while(fgets(z,100,q))
	    fputs(z,p);
}








