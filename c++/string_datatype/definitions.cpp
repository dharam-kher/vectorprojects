#include "header.h"

//CONSTRUCTORS
STRING  :: STRING (){
    //cout << "default" <<endl ;
    this->p = 0;
}
STRING :: STRING(const char *text){
    // cout << "para" <<endl ;
    this-> p = new char[strlen(text) + 1] ;
    strcpy(this->p,text); 
}
STRING :: STRING(STRING &object){
    // cout << "copy" <<endl ;
    this->p = new char [strlen(object.p) + 1] ;
    strcpy(this->p , object.p) ; 
}
STRING :: ~STRING(){
    if(this->p == 0)
        return ;
    delete [] p ;
}
//INSERSION EXTRACTION
ostream& operator << (ostream &left_operand, STRING &obj){
    if(obj.p == 0){
        cout << "string is empty" << endl ;
        return left_operand ;
    }
    for(int i=0; obj.p[i]; i++)
        cout << obj.p[i] ;
    return left_operand;
}

// //operator overolading
STRING STRING :: operator + (const STRING &right_operand){
     STRING temp;
     temp.p = new char[strlen(this->p) + strlen(right_operand.p) + 1] ;
     strcat(temp.p,this->p);
     strcat(temp.p,right_operand.p) ; 
     return temp ;
}
STRING STRING :: operator + (const char *text){
    STRING temp;
    temp.p = new char[strlen(text) + strlen(this->p) + 1] ;
    strcat(temp.p,this->p);
    strcat(temp.p,text) ; 
    return temp ;
}
STRING STRING :: operator =(const STRING &right_operand){
    _strcpy(*this,right_operand);
    return *this ;
}
char STRING :: operator [] (int i){
    return this->p[i];
}
int STRING :: operator == (const STRING &obj){
    int i;
    for(i=0; this->p[i] ;i++)
        if(this->p[i] != obj.p[i])
            break;
        if(this->p[i] == obj.p[i])
            return 1;
        else
            return 0;

}
int STRING :: operator == (const char *text){
        int i;
    for(i=0; this->p[i] ;i++)
        if(this->p[i] != text[i])
            break;
        if(this->p[i] == text[i])
            return 1;
        else
            return 0;
}
int STRING :: operator != (const STRING &obj){
        int i;
    for(i=0; this->p[i] ;i++)
        if(this->p[i] != obj.p[i])
            break;
        if(this->p[i] == obj.p[i])
            return 0;
        else
            return 1;
}
int STRING :: operator != (const char *text){
        int i;
    for(i=0; this->p[i] ;i++)
        if(this->p[i] != text[i])
            break;
        if(this->p[i] == text[i])
            return 0;
        else
            return 1;
}
/////////////////////////////////////// > or >=
int STRING :: operator > (const STRING &obj){
    int i=0;
    for(i=0;this->p[i]; i++)
        if(this->p[i] != obj.p[i])
        break;
    if(this->p[i] > obj.p[i])
        return 1;
    else
        return 0;
}
int STRING :: operator >= (const STRING &obj){
    int i=0;
    for(i=0;this->p[i]; i++)
        if(this->p[i] != obj.p[i])
        break;
    if(this->p[i] >= obj.p[i])
        return 1;
    else
        return 0;
}
int STRING :: operator > (const char *text){
    int i=0;
    for(i=0;this->p[i]; i++)
        if(this->p[i] != text[i])
        break;
    if(this->p[i] > text[i])
        return 1;
    else
        return 0;
}
int STRING :: operator >= (const char *text){
    int i=0;
    for(i=0;this->p[i]; i++)
        if(this->p[i] != text[i])
        break;
    if(this->p[i] >= text[i])
        return 1;
    else
        return 0;
}
/////////////////////////////////////// < or <=

int STRING :: operator < (const STRING &obj){
    int i=0;
    for(i=0;this->p[i]; i++)
        if(this->p[i] != obj.p[i])
        break;
    if(this->p[i] < obj.p[i])
        return 1;
    else
        return 0;
}
int STRING :: operator < (const char *text){
    int i=0;
    for(i=0;this->p[i]; i++)
        if(this->p[i] != text[i])
        break;
    if(this->p[i] < text[i])
        return 1;
    else
        return 0;
}
int STRING :: operator <= (const STRING &obj){
    int i=0;
    for(i=0;this->p[i]; i++)
        if(this->p[i] != obj.p[i])
        break;
    if(this->p[i] <= obj.p[i])
        return 1;
    else
        return 0;
}
int STRING :: operator <= (const char *text){
    int i=0;
    for(i=0;this->p[i]; i++)
        if(this->p[i] != text[i])
        break;
    if(this->p[i] <= text[i])
        return 1;
    else
        return 0;
}