#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct st{
	int roll;
	char name[10];
	float mark;
	struct st *next;
}sll;

void reverse_link(sll **);
void reverse_data(sll **);
void delete_all(sll **);
int count_node(sll *);
void delete_node(sll **);
void add_begin(sll **);
void print_data(sll *);
void add_middle(sll **);
void add_end (sll **);
void save_data(sll *);
void scan_data(sll **);
void print_reverse(sll *);
void print_rec(sll *);
void rev_rec(sll *);


void main(){
    system("clear");  
sll *headptr;
int op;
while(1){
	printf("\t1)add_begin \t2)add_middle \t3)add_end \t4)print_data\n\t5)save_data \t6)scan_data \t7)delete_data \t8)print_reverse\n\t9)print_rec \t10)rev_rec \t11)delete all\t12)reverse data\n\t13)reverse_link\t14)serch_node\t15)sort_data\t16)clear screen\n");
	        
        scanf("%d",&op);
	switch(op){
		case 1:add_begin(&headptr);break;
		case 2:add_middle(&headptr);break;
	    case 3:add_end(&headptr);break;

		case 4:print_data(headptr);break;

		case 5:save_data(headptr);break;
        case 6:scan_data(&headptr);break;
        case 7:delete_node(&headptr);break;
        case 11:delete_all(&headptr);break;
        case 8:print_reverse(headptr);break;
        case 9:print_rec(headptr);break;
        case 10:rev_rec(headptr);break;
        case 12:reverse_data(&headptr);break;
		case 16:system("clear");break;
		case 13:reverse_link(&headptr);break;
	}
}
}
void reverse_link(sll **headptr){
	if(*headptr == 0){
		printf("no data\n");
		return;
	}
	sll *p=*headptr,*q=0,*r=0;
		while(p){
			q=p;
			p=p->next;
			q->next = r;
			r=q;
		}
		*headptr = r;
}
void reverse_data(sll **headptr){
	if(headptr == 0){
		printf("no dat\n");
		return;
	}
	sll *last,*first;
	int i,j,c=count_node(*headptr);
	char t[10];

	for(i=1,first = *headptr;i<=c/2;i++){
		for(j=i,last = *headptr;j<c;j++)
			last = last->next;
		(first)->roll = (first)->roll + (last)->roll- ((last)->roll =(first)->roll);
		(first)->mark = (first)->mark + (last)->mark- ((last)->mark =(first)->mark);
		strcpy(t,first->name);	
		strcpy(first->name,last->name);	
		strcpy(last->name,t);

		first= first->next;
	}
}
void delete_all(sll **headptr){
	if(*headptr == 0){
		printf("no data");
		return;
	}
	sll *del;
	while(*headptr){
		del = *headptr;
		*headptr = del->next;
		free(del);
	}

}
void print_rec(sll *head){
	if(head == 0){
		return;
	}
	printf("%d %s %f\n",head->roll,head->name,head->mark);
	print_rec(head->next);
}
void rev_rec(sll *head){
	if(head == 0){
		return;
	}
	rev_rec(head->next);
	printf("%d %s %f\n",head->roll,head->name,head->mark);


}
void print_reverse(sll *head){
	if(head == 0){
		printf("no data\n");
		return;
	}
	sll *last;
	int i,j,c= count_node(head);

	for(i=1;i<=c;i++){
		for(j=i,last=head;j<c;j++)
			last =last->next;
		printf("%d %s %f\n",last->roll,last->name,last->mark);
	}

}
int count_node(sll *head){
	int c=1;
	if(head == 0){
		printf("no data\n");
		return 0;
	}
	while(head->next){
		head= head->next;
		c++;
	}
	return c;
}

void delete_node(sll **headptr){
	if(*headptr == 0){
		printf("no data\n");
		return;
	}
	int pos,i,c=count_node(*headptr);
	//printf("count = %d\n",c);
		printf("enter roll >> ");
		scanf("%d",&pos);
	
	sll *last= *headptr,*prev;
		
	for(i=1;i<=c;i++){
		if(last->roll == pos){
			if(i ==1 )
				*headptr = last->next;
			else
				prev->next = last->next;	
		free(last);	
		return;
		}
		prev = last;
		last =last->next;
	}
	printf("roll not found\n");
}
void scan_data(sll **headptr){
	FILE *fp = fopen("data.txt","r");
	
	sll *new;
	while(1){
		new = malloc(sizeof(sll));
		if(fscanf(fp,"%d%s%f",&new->roll,new->name,&new->mark) == EOF)
			break;
		new->next = 0;
		if(*headptr == 0){
			*headptr = new;
		}
		else{
			sll *last = *headptr;
			while(last->next)
				last = last->next;
			last->next = new;
		}
	}
}
void add_end(sll **headptr){
        sll *new = malloc(sizeof(sll));
          printf("Enter data\n");
  	scanf("%d%s%f",&new->roll,new->name,&new->mark);
        
        if(*headptr == 0){
           new->next = *headptr;
           *headptr = new;
        }
        else{
            sll *last= *headptr;
            while(last->next)
                last= last->next;
            new->next = 0;
            last->next = new;
        }
}
void add_begin(sll **headptr){
	sll *new = malloc(sizeof(sll));
	printf("Enter data\n");
	scanf("%d%s%f",&new->roll,new->name,&new->mark);

	new->next = *headptr;
	*headptr = new;
}
void add_middle(sll **headptr){ //according to rollno
   sll *new = malloc(sizeof(sll));
   printf("Enter data\n");
   scanf("%d%s%f",&new->roll,new->name,&new->mark);
   
      if(*headptr == 0 || ((*headptr)->roll) > new->roll){ //if node is not there
        new->next = *headptr;
        *headptr = new;
      } 
      else{
        sll *last = *headptr;        
        while((last->next != 0) && last->next->roll < new->roll)
            last = last->next;
      
        new->next = last->next;
        last->next = new;
      }
}
void print_data(sll *head){
	if(head == 0){
		printf("no data\n");
		return;
	}
	while(head){
		printf("%d %s %f\n",head->roll,head->name,head->mark);
		head= head->next;
	}
}
void save_data(sll *head){
	if(head == 0){
		printf("no data\n");
		return;
	}
	FILE *fp;
	int r;
			fp = fopen("result.txt","w");
	
	while(head){
		fprintf(fp,"%d %s %f\n",head->roll,head->name,head->mark);
		head = head->next;
		//printf("r= %d\n",r);
	}
}
