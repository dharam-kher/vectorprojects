#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class STRING{
char *p;
    public:
    STRING();
    STRING(const char *);
    STRING(STRING &object);
    ~STRING();
//insertion extractions
    friend ostream& operator << (ostream &, STRING &); 
//    friend istream& operator >> (istream &, STRING &); 
//operator overloding 
    STRING operator + (const STRING &);
    STRING operator + (const char *);
    STRING operator =(const STRING &) ;
    char operator [] (int);
    int operator == (const STRING &);
    int operator == (const char *);
    int operator != (const STRING &);
    int operator != (const char *);
    int operator > (const STRING &);
    int operator > (const char *);
    int operator < (const STRING &);
    int operator < (const char *);
    int operator >= (const STRING &);
    int operator >=(const char *);
    int operator <= (const STRING &);
    int operator <= (const char *);
//string operations
   friend unsigned int _strlen(const STRING&);
   friend char * _strcpy(STRING &,const STRING &,int) ; 
   friend char * _strcpy(STRING &,const char *,int);
   friend char * _strcat(STRING &,const STRING &,int);
   friend char *  _strcat(STRING &,const char *,int);
   friend char * _strupper(STRING &) ;
   friend char * _strlower(STRING &) ;
   friend char * _strrev(STRING &) ;
   friend char * _strchr(const STRING &,char );
   friend char * _strrchr(const STRING &,char);
   friend char * _strstr(const STRING &,const STRING &) ;
   friend char * _strstr(const STRING &,const char *sub);
  
};
char * _strcat(STRING &,const STRING &,int n=0);
char *  _strcat(STRING &,const char *,int n=0);
char * _strcpy(STRING &,const STRING &,int n=0) ; 
char * _strcpy(STRING &,const char *,int n=0);