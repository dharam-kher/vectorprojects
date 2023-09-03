//in replace any word in given file 
//method 1 scan string line by line and then do relpace a word in string and 
//then again put back that in file.

#include<stdio.h>
#include<string.h>

void main(){
	char s[50],w1[20],w2[20];
	int i,k,j,ls,lw1,lw2;

		printf("enter string: ");
		scanf("%[^\n]",s);
			ls= strlen(s);
	
		printf("enter word1: ");
		scanf(" %s",w1);
			lw1= strlen(w1);
		
		printf("enter word2: ");
		scanf(" %s",w2);
			lw2= strlen(w2);
	
		char *find;
			find= strstr(s,w1);
				if(find == 0){
					printf("word not found\n");
					return;
				}
//use index oprations so find still points at where is found
	for(i=0;w1[i];i++)
		for(j=0;find[j];j++)
			find[j]= find[j+1];
//word got deleted now and word of anylength
	
	for(i=0;w2[i];i++){
			for(j=strlen(find);j>=i;j--)
				find[j+1]=find[j];

		find[i]= w2[i];
	}
	printf("%s \n",s);
	
}










