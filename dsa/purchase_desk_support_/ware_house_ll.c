#include"./0_include/my_header.h"


void main(){

    int option;
	war_SLL *headptr=0;

    //load data from saved binary 
    load_data(&headptr);
    
    while (1){
    printf("----------------------------------------------------------------\n");
    printf("\n>>>weclome<<<\n>>>choose your option \n0)exit\n1)update_item\n2)display all item \n>>>: \n");
    scanf("%d",&option);
    
        switch (option)
        {
        case 1 : if(add_item(&headptr))
                {
                        printf("item added successfuly\n\n");
                }else{
                        printf("item is not added\n\n");
                };
            break;
        case 2 : print_items(headptr) ;
                 break;
        default:
            printf(">>> please enter valid option\n");
            break;
        case 0 :
                 save_data(headptr);
                exit(0);
        }
////////////////////////////////////////////////////////////////////////  and entry save data 
  
/////////////////////////////////////////////////////////////////////////
    }

}
int add_item(war_SLL **headptr){
  char op;

    war_SLL *new= malloc(sizeof(war_SLL));
            if(new == 0){
                perror("malloc :");
                return -1;
            }

      printf("enter HSN number : ");
      scanf("%d",&new->HSN_code);
      printf("enter discription : ");
      scanf(" %99[^\n]",new->item_info);
      printf("enter price: ");
      scanf("%f",&new->MRP);
      printf("enter quantity  : ");
      scanf("%d",&new->quantity);

    new->next_warehouse_data = NULL;

      if(hsn_check(new->HSN_code,*headptr)){
              
            printf("HSN number already exist\ndo u want to modify value ? [Y/N] : ");
            scanf(" %c",&op);
            if(op == 'y' || op == 'Y'){
                update_data(headptr,new);  
                free(new) ; 
                return 1;
            }
            else if(op == 'n' || op == 'N'){
                free(new);
                   return 0 ;
            }
            else{
                printf("invalid option abourt adding data\n");
                free(new);
                return 1;
            }
        }


    if(*headptr==0){
        *headptr = new;
        new->next_warehouse_data = 0;
        return 1;
    }
    war_SLL *last= *headptr;

    while(last->next_warehouse_data){       
        last= last->next_warehouse_data;    
    }
    last->next_warehouse_data = new;
    new->next_warehouse_data = 0;

    return 1 ; 
} 
int hsn_check(int hsn_num,war_SLL *head){
      if(head == 0)
          return 0;
          
      while(1){
          if(head->HSN_code == hsn_num)
                return 1;
          if(head->next_warehouse_data ==0)
                break;
      
        head= head->next_warehouse_data;
      }
      return 0;
 }

 int update_data(war_SLL **headptr,war_SLL *new){
    if(*headptr==0){
        return 0;
    }

    war_SLL *temp;
        temp= *headptr;
        
        while(temp){
         
            if(temp->HSN_code == new->HSN_code){
               strcpy(temp->item_info,new->item_info);
               temp->MRP = new->MRP;
               temp->quantity = new->quantity ;
            }

            temp= temp->next_warehouse_data;         
        }
        return 1 ; 
}        

void print_items(war_SLL *head){
            printf("-----------------------------------------------------\n");

        if(head == 0){
            printf("no data present\n");
            return;
        }

        while(head){
            
            printf("%u | %s | %.2f | %d\n",head->HSN_code,head->item_info,head->MRP,head->quantity) ;
            head=head->next_warehouse_data ; //when 0 no item left 

        }
        

        printf("\n-----------------------------------------------------\n");
        return;
}

void  save_data(war_SLL *head){

    war_SLL *temp = head;
    FILE *fp = fopen("./bin/warehouse_binary.dat","wb");
                if(fp ==0){
                    perror("saving file:");
                }
    FILE *fp1 = fopen("./data.txt","w"); 
           if(fp ==0){
                    perror("saving file:");
                }
    while(temp){

        fwrite(&temp->HSN_code, sizeof(temp->HSN_code), 1, fp);
        fwrite(temp->item_info, sizeof(temp->item_info), 1, fp);
        fwrite(&temp->MRP, sizeof(temp->MRP), 1, fp);
        fwrite(&temp->quantity, sizeof(temp->quantity), 1, fp);
                fprintf(fp1, "%u | %s | %.2f | %d\n",
                temp->HSN_code,
                temp->item_info,
                temp->MRP,
                temp->quantity);

        temp = temp->next_warehouse_data;
    }

    fclose(fp);
    fclose(fp1);
}

void load_data(war_SLL **headptr)
{
    FILE *fp = fopen("./bin/warehouse_binary.dat", "rb");

    printf("load started !!\n");

    if (fp == NULL)
    {
        perror("loadig time \n");
        return;
    }
    war_SLL *new;
    war_SLL *last = NULL;
    while (1)
    {
        new = malloc(sizeof(war_SLL));
        if (new == NULL)        {
            perror("malloc");
            fclose(fp);
            return;
        }

        if (fread(&new->HSN_code,sizeof(new->HSN_code), 1, fp) != 1){
            free(new);
            break;
        }

        if (fread(new->item_info,sizeof(new->item_info), 1, fp) != 1){
            free(new);
            break;
        }
        if (fread(&new->MRP,sizeof(new->MRP), 1, fp) != 1){
            free(new);
            break;
        }
        if (fread(&new->quantity,sizeof(new->quantity), 1, fp) != 1){
            free(new);
            break;
        }
        new->next_warehouse_data = NULL;

        if (*headptr == NULL){
            *headptr = new;
            last = new;
        }
        else{
            last->next_warehouse_data = new;
            last = new;
        }
    }

    fclose(fp);

    printf("load success !!\n");
    return;
}
