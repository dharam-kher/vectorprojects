//1. remove in same file.
//2. copy it in another without comments(putc aslong as // happens )

#include<stdio.h>

void main(int argc,char **argv){
	if(argc < 2){
		printf("use: ./rmcmt <fileName>\n");
		return;
	}

	char ch,i;
	FILE *fp;

	for(i=1; i<argc; i++){

		fp= fopen(argv[i],"r+");
			if(fp == 0){
				perror("fopen: ");
				return;
			}

		while((ch= fgetc(fp)) != EOF){
			if(ch== '/'){
				if((ch= getc(fp)) == '/'){
					fseek(fp,-2,SEEK_CUR);
					while(fgetc(fp) != '\n'){
						fseek(fp,-1,SEEK_CUR);
						fputc(' ',fp);
					}
				}
			}	
		
		}
	}//first for loop end

}
