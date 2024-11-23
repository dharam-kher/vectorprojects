#include "bankheader.h"
dll *headptr;

void main(){
while(1){
	int op;
	printf("\t1)add_acc_beg\t2)add_acc_middle\t3)add_acc_last\t4)print_data\n\
		\t5)creadit_amount\t6)withdraw_amount\t7)transfer_amount\t8)save_data\t\n\
		\t9)scan_from_file(reopen)\t10)sort_data\t11)close_acc\t0)exit\n");
		
	printf("\033[31m enter option\033[0m\n");
	scanf("%d",&op);	
	switch(op){
	case 1:open_begin();break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 0:exit(0);
	}
}
}
void open_begin(void){
    dll *new = malloc(sizeof(dll));
        if(new == 0){
          perror("malloc: ");
          return;
        }
    printf("\033[31menter name, accno, inittial balance\033[0m\n");
    scanf("%s%d%f",new->name,&new-accno,&new->bal);
    if(headptr == 0){
        new->next = headptr;
        new->prev = headptr;
        headptr= new;
        return;
    }
    //pending 
}
