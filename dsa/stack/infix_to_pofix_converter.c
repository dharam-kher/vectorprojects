#include"infix_to_pofix_converter.h"
#include"stackheader.h"


/*
    add funtion to check that user expression is valid infix expression 
    ->func : parenthesis are in correct order
    ->func : every operator is placed in between two operators
    ->new add :  curly brakets and squar brakets are also used in expression  
*/

void main (void){
    printf("please enter your expression :  ");
    scanf("%[^\n]",user_string);
    
    printf("%s\n",user_string);
    Convet_to_posfix(user_string);
    printf("%s\n",expression);

}

void Convet_to_posfix(char *user_string) {
      int i=0,j=0;

        for(i=0,j=0;user_string[i];i++){  

            if(which_operator(user_string[i])){              //only operator will get in if
            
                /////////////////////////////////////////////////////parenthesis
                switch(user_string[i]){
                    case '(':   push('(');
                    break;
                    case ')':   while(top() != '(')
                                    expression[j++] = pop();
                                pop();
                    break;
                 /////////////////////////////////////////////////////multiplication and divition
                    case '/':
                    case '*':   if(is_empty() == 1 || top() == '(' || top() == '-' || top() == '+'){
                                    push(user_string[i]);
                                    break;
                                }   
                                else{
                                    while(is_empty() == 0 ){
                                        if(top() == '-' || top() == '+' || top() == '('){
                                            break;
                                        }
                                        expression[j++] = pop();
                                    }
                                    push(user_string[i]);
                                }
                    break;
                     /////////////////////////////////////////////////////addition and subtraction
                    case '+':
                    case '-':   if(is_empty()==1 || top()=='('){
                                    push(user_string[i]) ;
                                    break;
                                }
                                else{
                                    while(is_empty() == 0){
                                        if( top() == '(' || top() == '+'||top() == '-'){
                                            if( top() == '(' ){
                                                break;        //we dont want to add ( in expression)
                                            }

                                            expression[j++] = pop();
                                            break;
                                        }
                                        expression[j++] = pop();
                                    }
                                    push(user_string[i]);
                                }
                    break;
                    ///////////////////////////////////////////////////////////////// carrot or power or raise to 2^c
                    case '^':   while(top() == '^'){
                                    if(top() != '^')
                                        break;
                                    expression[j++] = pop();                                        
                                }
                                push(user_string[i]);
                    break ;            
                }
            }
             else {
                expression[j++] = user_string[i];           //operator will not get in else      
            }
        }
        ////////////////////////////poping all elements untile stack is empty
        while(is_empty() == 0)
            expression[j++] = pop();   
}
char which_operator(char ch){
    switch(ch){
        case '+':
        case '-': 
        case '/':
        case '*': 
        case '^': 
        case ')': 
        case '(':

        return 1;
    }
    return 0;
}




