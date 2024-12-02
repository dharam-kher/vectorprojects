// headptr is taken as formal argument if call by reference;
// head is taken as formal argument if call by value ;

#include"header.h"

void main(){
	char op;
	int c;
	SLL *headptr=0;
	
	printf("enter the choice\n");
	while(1){
	    
	printf("\n\
	       1)add_begin 2)add_end 3)add_middle 4)print_data 5)count_node\n\
	       6)save_file 7)reverse_print 8)print_rec 9)reverse_rec 10)delete_all\n\
	       11)delete_node 12)delete_pos 13)reverse_data 14)reverse_link 15)search_node\n\
	       16)sort_data 17)read_file 0)exit \nenter >> ");
	
	scanf("%d",&op);

	switch(op){
	case 1:add_begin(&headptr);break; //call by reference 
	case 2:add_end(&headptr);break; 
	case 3:add_middle(&headptr);break;
	case 4:print_data(headptr);break; //call by value >>headptr is safe
	case 5:c= count_node(headptr);
	       printf("\033[34m total count= %d \033[0m\n",c); break; 
	case 6:save_file(headptr);break;
	case 7:reverse_print(headptr);break;
	case 8:print_rec(headptr);break;
	case 9:reverse_rec(headptr);break;
	case 10:delete_all(&headptr);break;
	case 11:delete_node(&headptr);break;
	case 12:delete_pos(&headptr);break;
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 0:exit(0);
	  
	default:
	        printf("\033[31m invalid option \033[0m \n");
	}
	}
}
void add_begin(SLL **headptr){
  SLL *new = malloc(sizeof(SLL)); //creating node
      printf("enter the roll no, name, marks\n");
    
      int c=0;
      l:
      scanf("%d%s%f",&new->rollno,new->name,&new->marks); //scanning data
  
          if(rollno_check(new->rollno,*headptr)){
              printf("\033[31m ROLL NUMBER EXIST: TRY AGAIN \n>> \033[0m");
              c++;
              if(c<3){
                  if(c==2)
                       printf("\033[31m THIS IS LAST CHANCE\033[0m \n");
                  goto l;
              }
          printf("\033[31m DATA NOT ADDED !!\033[0m \n");
          return;
          }
  
  
      new->next= *headptr; //update 0 from headptr 
      *headptr= new; //upoining headptr two new created node.

      printf("\033[32m DATA ADDED SUCCESSFULY \033[0m \n");
}

void add_end(SLL **headptr){
  
    SLL *new= malloc(sizeof(SLL)); 
        printf("enter rollno,name and mark\n");  
       
      int c=0;
      l:
      scanf("%d%s%f",&new->rollno,new->name,&new->marks); //scanning data printf("\033[32m DATA ADDED SUCCESSFULY \033[0m \n");
  
          if(rollno_check(new->rollno,*headptr)){
              printf("\033[31m ROLL NUMBER EXIST: TRY AGAIN \n>> \033[0m");
              c++;
              if(c<3){
                  if(c==2)
                       printf("\033[31m THIS IS LAST CHANCE\033[0m \n");
                  goto l;
              }
          printf("\033[31m DATA NOT ADDED !!\033[0m \n");
          return;
          }
        
    if(*headptr==0){
        *headptr = new;
    }
    new->next = 0;
    SLL *last= *headptr;
    
    while(last->next){       
        last= last->next;    
    }
    last->next = new;
    printf("\033[32m ADDED SUCCESSFULLY \033[0m\n");
} 
void add_middle(SLL **headptr){
    SLL *new= malloc(sizeof(SLL));
         printf("enter rollno,name and mark\n");
         
       
      int c=0;
      l:
      scanf("%d%s%f",&new->rollno,new->name,&new->marks); //scanning data
  
          if(rollno_check(new->rollno,*headptr)){
              printf("\033[31m ROLL NUMBER EXIST: TRY AGAIN \n>> \033[0m");
              c++;
              if(c<3){
                  if(c==2)
                       printf("\033[31m THIS IS LAST CHANCE\033[0m \n");
                  goto l;
              }
          printf("\033[31m DATA NOT ADDED !!\033[0m \n");
          return;
          }
    
    if(*headptr == 0 || new->rollno < (*headptr)->rollno){    //if new rollno < first element , headptr will hold new 
                                                              // and new will hold who was previously last.
        new->next = *headptr;
        *headptr= new;
    }
    else{
        SLL *last= *headptr;
        
        while((last->next != 0 ) && last->next->rollno < new->rollno)
            last = last->next;
        
        new->next = last->next;
        last->next = new;
    }  
    printf("\033[32m DATA ADDED SUCCESSFULY \033[0m \n");
}
void print_data(SLL *head){
  //this will print from first to last all records.
  if(head == 0){
        printf("\033[33m no recard found\033[0m \n");
        return;
    }
  while(head){
    
    printf("\033[34m %d %s %f\033[0m \n",head->rollno,head->name,head->marks);
    head= head->next;
  }
  
}
int count_node(SLL *head){
  int count;
  if(head == 0){
      printf("033[33m no recard found\033[0m \n");
      return 0;
  }
  
  count=0;
  while(head){
    count++;
    head= head->next;  
  } 
  return count;
}
void save_file(SLL *head){
 
  if(head == 0){
      printf("\033[33m no recard found \033[0m \n");
      return ;
    }
    
    char filename[10];
    int op;
    
    FILE *fp;
        printf("\033[34m enter file name >> \033[0m");
        scanf("%s",filename);
        
          fp= fopen(filename,"r");
            if(fp==0){
                fp = fopen(filename,"w");
            }
            else{
                printf("\033[33m file exists with same name\n>>enter\n1)clear file \n2)append data \n3)close file\n>> \033[0m ");
                scanf("%d",&op);
                
                  if(op == 1){
                    fp = fopen(filename,"w");
                        if(fp == 0){
                            perror("\033[33m fopen in writemode: \033[0m ");
                            return;
                        }
                  }
                  else if(op == 2){
                    fp= fopen(filename,"a");
                        if(fp == 0){
                            perror("\033[33m fopen in read: \033[0m");
                            return;
                        }
                  }
                  else if(op == 3){
                    fclose(fp);
                    return;
                  }
            }
            
            while(head){
               if(fprintf(fp,"%d  %s  %f\n",head->rollno,head->name,head->marks) < 0 )
                  perror("fprintf: ");
  
                head= head->next;
            }
            
            printf("\033[32m OPERATION SUCCESSFULLY \033[0m\n");
            fclose(fp);
            
}
void delete_all(SLL **headptr){
    if (*headptr == 0){
        printf("\033[33m no recard found \033[0m \n");
        return ;
    }
   
    SLL *del;
    del= *headptr;
    
    while(del){
        *headptr= del->next;
          free(del);
        del= *headptr;
    }
    printf("\033[32m DELETATION SUCCESSFULLY \033[0m\n");
}

int rollno_check(int roll,SLL *head){
      if(head == 0)
          return 0;
          
      while(1){
          if(head->rollno == roll)
                return 1;
          if(head->next ==0)
                break;
      
        head= head->next;
      }
      return 0;
 }
void reverse_print(SLL *head){
  if(head==0){
    printf("\033[33m no recard found \033[0m \n");
    return ;
  }
  SLL *last;
  int i,j,c= count_node(head);
    
  for(i=c;i>0;i--){
      for(j=i,last= head ; j>1; j--)
          last= last->next;
        
       printf("\033[34m %d %s %f\033[0m \n",last->rollno,last->name,last->marks);
  }  
  
}
void print_rec(SLL *head){
    if(head){
      printf("\033[34m %d %s %f\033[0m \n",head->rollno,head->name,head->marks);
      print_rec(head->next);
   }
   else
      return;
}
void reverse_rec(SLL *head){
    if(head){
      reverse_rec(head->next);
      printf("\033[34m %d %s %f\033[0m \n",head->rollno,head->name,head->marks);
   }
   else
      return;

}
void delete_node(SLL **headptr){
    if(*headptr==0){
        printf("\033[33m no recard found \033[0m \n");
        return ;
    }
  
    int op;
     printf("\033[32m delet node according to \n1)rollno \n2)name \n3)marks\n>> \033[0m");
     scanf("%d",&op);
    
    SLL *del,*pre_del;
    if(op==1){
        del= *headptr;
        int roll;
        printf("\033[34m enter roll no \033[0m \n>>");
        scanf("%d",&roll);
        while(del){
         
            if(del->rollno == roll){
                if(del == *headptr)
                    *headptr = del->next;
                else
                    pre_del->next = del->next;
              
                free(del);
                return;
            }
            pre_del = del;
            del= del->next;         
        }        
         printf("\033[33m ROLLNO NOT FOUND \033[0m \n");
    }
    
    else if(op== 2){
         del= *headptr;
         char s[20];
         printf("\033[34m enter name \033[0m \n>>");
         scanf("%s",s);
         
          while(del){
         
            if(strcmp(s,del->name) == 0){
                if(del == *headptr)
                   *headptr = del->next;
                else
                    pre_del->next = del->next;
              
                free(del);
                return;
            }
            pre_del = del;
            del= del->next;         
        }       
        printf("\033[33m NAME NOT FOUND \033[0m \n");
    }
    else if(op==3){
        del= *headptr;
        float m;
          printf("\033[34m enter marks \033[0m \n>>");
          scanf("%f",m);
         
          while(del){
          
            if(del->marks == m){
                if(del == *headptr)
                   *headptr = del->next;
                else if(*headptr==0){
        printf("\033[33m no recard found \033[0m \n");
        return ;
    }
                    pre_del->next = del->next;
              
                free(del);
                return ;
            }
            pre_del = del;
            del= del->next;         
        }       
         printf("\033[33m MARKS NOT FOUND \033[0m \n");
    }
    else{     
         printf("\033[33m INVALDE OPTION \033[0m \n");
    }
}
void delete_pos(SLL **headptr){
    if(*headptr==0){
        printf("\033[33m no recard found \033[0m \n");
        return ;
    }
    int c= count_node(*headptr),pos,i;
    
    printf("\033[34m %d nodes found \033[0m \n",c);
    printf("\033[34m enter position \033[0m \n>>");
    scanf("%d",&pos);

    SLL *last = *headptr ,*prev_node= *headptr;
    if(pos >=1 && pos<=c){
        for(i=0; i<=c; i++){
            if(pos == i){
              if(pos == 1)
                  *headptr ==last->next;
              else
                  prev_node->next = last->next;
                  
              free(last);
              return;
            }
            prev_node = last;
            last = last->next;
        }        
    }
    else{
        printf("\033[33m NODE OUT OF RANGE \033[0m \n");
    }
} 
 













