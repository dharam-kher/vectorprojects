#include "header.h"

unsigned int _strlen(const STRING &obj){
    if(obj.p == 0)
        return 0;

    int i;
    for(i =0 ; obj.p[i]; i++);

    return i;
}
//////////////strcpy
char * _strcpy(STRING &dest,const STRING &src,int n){
    if(dest.p != 0)
        delete []dest.p ;

        dest.p = new char [strlen(src.p) + 1] ;
        if(n == 0)
            strcpy(dest.p,src.p);
        else{
            strncpy(dest.p,src.p,n);
        }
    return dest.p;

}
char * _strcpy(STRING &dest,const char *text,int n){
    if(dest.p != 0)
        delete [] dest.p;

        dest.p = new char [strlen(text) + 1] ;
        if(n==0)
            strcpy(dest.p,text);
        else
            strncpy(dest.p,text,n);

    return dest.p;
}
//////////////strcat
char * _strcat(STRING &dest,const STRING &src,int n){
    STRING temp;
    if(dest.p != 0){
        temp.p = new char [_strlen(dest)+ 1]; 
        strcpy(temp.p,dest.p) ;
    delete [] dest.p ;
    }
    
    if(n==0){
    dest.p = new char[_strlen(temp) + _strlen(src) + 2] ;
    strcpy(dest.p,temp.p);
    strcat(dest.p,src.p);
    }
    else{
        dest.p = new char[_strlen(temp) + n + 1];
        strcpy(dest.p,temp.p);
        strncat(dest.p,src.p,n);
    }
    return dest.p ;
}
char *  _strcat(STRING &dest,const char *text,int n){
    STRING temp;
    if(dest.p != 0){ 
        temp.p = new char [_strlen(dest)+ 1]; 
        strcpy(temp.p,dest.p) ;
        delete [] dest.p ;
    }
    if(n != 0){
    dest.p = new char[_strlen(temp) + _strlen(text) + 2] ;
    strcpy(dest.p,temp.p);
    strcat(dest.p,text);
    }
    else{
        dest.p = new char[_strlen(temp) + n + 1];
        strcpy(dest.p,temp.p);
        strncat(dest.p,text,n);
    }
    return dest.p ;
}
///////////// strchr
char * _strchr(const STRING &obj,char ch){
    if(obj.p == 0)
        return 0;
    char *temp = strchr(obj.p,ch);

        return temp;
}
char * _strrchr(const STRING &obj,char ch){
    if(obj.p == 0)
        return 0;
    char *temp = strrchr(obj.p,ch);

        return temp;
}
////////////upper lower
char * _strupper(STRING &obj) {
    if(obj.p == 0)
        return 0;

    for(int i=0;obj.p[i];i++)
        if(obj.p[i] >= 'a' && obj.p[i] <= 'z')
            obj.p[i] ^= 32 ; 

    return obj.p;
 }
char * _strlower(STRING &obj) {
    if(obj.p == 0)
        return 0;
    for(int i=0;obj.p[i];i++)
        if(obj.p[i] >= 'A' && obj.p[i] <= 'Z')
            obj.p[i] ^= 32 ; 

    return obj.p;
 }
char * _strrev(STRING &obj){
    if(obj.p == 0)
        return 0;

    int i,j,l = _strlen(obj) ;

    for(i=0,j=l-1 ;j > i ; i++,j--)
        obj.p[i] = obj.p[i] + obj.p[j] - (obj.p[j]=obj.p[i] ) ;
    
    return obj.p ;
 }
 //////////////////////////strstr
char * _strstr(const STRING &main,const STRING &sub){
    if(main.p == 0)
        return 0; 
    char *temp = strstr(main.p,sub.p);
    return temp;
}

char * _strstr(const STRING &main,const char *sub){
    if(main.p == 0)
        return 0; 
    char *temp = strstr(main.p,sub);
    return temp;
}