#include"./0_include/my_header.h"

war_SLL *headptr_warehouse=0;
void main(){

    int option;
    cus_SLL *headptr_customer=0;

    //load data from saved binary 
    load_warehouse_data(&headptr_warehouse);
    load_old_customer(&headptr_customer);
    
    while (1){
    printf("----------------------------------------------------------------\n");
    printf("\n>>>weclome<<<\n>>>choose your option \n0)exit\n1)puschase\n2)print_customer_with_items\n3)show_remaining_items\n4)sale_report\n5)generate_customer_bill: \n>>>: \n");
    scanf("%d",&option);
    
        switch (option)
        {
        case 1 : if(add_purchase(&headptr_customer))
                {
                        printf("purchase successfuly\n\n");
                }else{
                        printf("somthing went wrongn\n");
                };
            break;
        case 2 : print_customer_and_items(headptr_customer);
                 break;
        case 3 : print_warehouse(headptr_warehouse);
                 break;
        case 4 : sales_report(headptr_customer);
                break;
        case 5: generate_all_customer_bill(headptr_customer);
                break;
        default:
            printf(">>> please enter valid option\n");
            break;
        case 0 :
           save_data_customer(headptr_customer);
            save_warhouse_data_update(headptr_warehouse);
               exit(0);
        }
////////////////////////////////////////////////////////////////////////  and entry save data 
   save_data_customer(headptr_customer);
   save_warhouse_data_update(headptr_warehouse);
/////////////////////////////////////////////////////////////////////////
    }

}
int add_purchase(cus_SLL **headptr){
  int op ;
  
    cus_SLL *new= malloc(sizeof(cus_SLL));
            if(new == 0){
                perror("malloc :");
                return 0;
            }
      
      printf("enter name : ");
      scanf(" %14[^\n]",new->customer_name);
      specific_customer_items(&new->item_list); //link list of customers items 
           
printf("----------------generate bill ?--0 for yes anyother for no-----------\n: ");
    scanf("%d",&op);
      if(op == 0)
            generate_bill(new);
        
    new->next_customer_data = NULL;

    if(*headptr==0){
        *headptr = new;
        new->next_customer_data = 0;
        return 1;
    }
    cus_SLL *last= *headptr;

    while(last->next_customer_data){       
        last= last->next_customer_data;    
    }
    last->next_customer_data = new;
    new->next_customer_data = 0;

    return 1 ; 
}       
void  specific_customer_items(struct bill **item_list){ //link list of customers items 
int op;
    *item_list = NULL;

    while(1){
        printf("\n>>>>>>>>>>>>>>>>>>>welcome to bill desk<<<<<<<<<<<<\n");
        while(1){
            printf("\npress\n1)add item \n2)warehouse_availibily\n0)checkout \n: ");
            scanf("%d",&op);
            switch (op)
            {
            case 1:add_cus_choice(item_list);
                break;
            case 0: return ;
            case 2: print_warehouse(headptr_warehouse);
            default:
                printf("invalid option !!");
                break;
            } 
            printf("----------------add next item-------------\n: ");

        }
    }
}
void add_cus_choice(struct bill **item_list){

war_SLL *temp =   headptr_warehouse;

    struct bill *new = malloc(sizeof(struct bill));
        if(new ==0){
            perror("malloc bill");
        }

    printf("enter hsn: ");
    scanf("%d",&new->hsn_number);    
     printf("add quantity: ");
    scanf("%d",&new->quantitty);

while(temp){
    if(new->hsn_number == temp->HSN_code){
        printf("description :  %s\n",temp->item_info);
        if(new->quantitty >  temp->quantity ){      
            printf("---------------------------------------------");
            printf("not enough quantity available quantity = %d\n",temp->quantity);
            printf("---------------------------------------------");
            printf("re-enter quantity: ");
            scanf("%d",&new->quantitty);
            if(new->quantitty >  temp->quantity){
                printf(">>>>>>>>>>>expected quanity is more than available aborting operation\n");
                free(new);
                return;
            }
              break;
        }
///////////////////////////////if everyting correct then purchase compeleted removing quantity  
            temp->quantity -= new->quantitty;
            break;
    }
    temp = temp->next_warehouse_data;
}
if(temp == NULL){
    printf("hsn number is not present in warehouse\n");
    free(new);
    return ;
}
    new->next_buy_item = NULL;

    if(*item_list == 0){
        *item_list = new;
        new->next_buy_item = 0;
        return ;
    }
    struct  bill *last= *item_list;

    while(last->next_buy_item){       
        last= last->next_buy_item;    
    }
    last->next_buy_item = new;
    new->next_buy_item = 0;

    return  ;
}


void print_warehouse(war_SLL *temp){
            printf("-----------------------------------------------------\n");
war_SLL *head = temp;
        if(temp == 0){
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
void print_customer_and_items(cus_SLL *head){

    if(head == 0){
        printf("no item present\n");
        return;
    }

    while(head){
    printf("\n------------------------------------\n");

        printf("name = %s \n",head->customer_name);
        printf("\n");
        struct bill *temp_ptr = head->item_list;
                while(temp_ptr){

                    printf("hsn no:  %d : quantity %d\n",temp_ptr->hsn_number,temp_ptr->quantitty);
                    temp_ptr = temp_ptr->next_buy_item;
                }
        head = head->next_customer_data;
    printf("\n------------------------------------\n");
    }

}

void generate_all_customer_bill(cus_SLL *head){

    FILE * fp = fopen("./report/all_customer_bill_report.txt","w");
        if(fp == 0 ){
            perror("bill genration: ");
            return;
    }
    
    war_SLL *temp_ware=headptr_warehouse;

while(head){

 //   fprintf(fp,",\n---------------------------------------------\n");
  //  fprintf(fp,"date :    time: \n");
  //  fprintf(fp,"\n---------------------------------------------\n");
    fprintf(fp,"customer name : %s\n",head->customer_name);
     //fprintf("hsn--------------quantiy-------------------------price-----------total\n");
    
    float total =0;
    struct bill *temp_cus= head->item_list  ;
    while(temp_cus){
        
        temp_ware=headptr_warehouse;
        while(temp_ware){
            if(temp_cus->hsn_number == temp_ware->HSN_code)
                break;
            temp_ware=temp_ware->next_warehouse_data;
        }
        fprintf(fp,"hsn : %d -------quantity %d-----------price %f----------total  %f-------\n",temp_cus->hsn_number,temp_cus->quantitty,temp_ware->MRP,(float)(temp_cus->quantitty*temp_ware->MRP));
        total += (float)(temp_cus->quantitty*temp_ware->MRP);
        temp_cus=temp_cus->next_buy_item;
    }
    fprintf(fp,"grand total------------------------------%f----\n",total);

    head = head->next_customer_data;
}
    fclose(fp);
    printf("\n------------------------------------\n");

    printf("report generated \n");
    printf("\n------------------------------------\n");

}
void generate_bill(cus_SLL *head){

    war_SLL *temp_ware=headptr_warehouse;

    if(head->item_list == 0){
    printf("\n------------------------------------\n");
        printf("dint purchase \n") ; 
    printf("\n------------------------------------\n");
        return;
    }

    printf("\n---------------------------------------------\n");
    printf("date :    time: \n");
    printf("\n---------------------------------------------\n");
    printf("customer name : %s\n",head->customer_name);
     //printf("hsn--------------quantiy-------------------------price-----------total\n");
    
    float total =0;
    struct bill *temp_cus= head->item_list  ;
    while(temp_cus){
        
        temp_ware=headptr_warehouse;
        while(temp_ware){
            if(temp_cus->hsn_number == temp_ware->HSN_code)
                break;
            temp_ware=temp_ware->next_warehouse_data;
        }
        printf("hsn : %d -------quantity %d-----------price %f----------total  %f-------\n",temp_cus->hsn_number,temp_cus->quantitty,temp_ware->MRP,(float)(temp_cus->quantitty*temp_ware->MRP));
        total += (float)(temp_cus->quantitty*temp_ware->MRP);
        temp_cus=temp_cus->next_buy_item;
    }
    printf("\n---------------------------------------------\n");
    printf("grand total------------------------------%f----\n",total);

}



// data related func
void save_data_customer(cus_SLL *head)
{
    FILE *fp = fopen("./bin/customerlist.dat", "wb");
    FILE *fp1 = fopen("./customer.txt", "w");

    if(fp == NULL || fp1 == NULL)
    {
        perror("fopen");
        return;
    }

    cus_SLL *new = head;

    while(new)
    {
       
        fwrite(new->customer_name,sizeof(new->customer_name), 1, fp);
        fprintf(fp1,"customer name = %s\n",new->customer_name);

      
        int count = 0;
        struct bill *item = new->item_list;//so that temp poitern incrementsss

        while(item) //counting item
        {
            count++;
            item = item->next_buy_item;
        }
        fwrite(&count, sizeof(count), 1, fp);
       
        item = new->item_list; 

        while(item)
        {
            fwrite(&item->hsn_number,sizeof(item->hsn_number), 1, fp);
            fprintf(fp1,"HsnNO = %d : quantity : %d \n",item->hsn_number,item->quantitty);

            fwrite(&item->quantitty,sizeof(item->quantitty), 1, fp);
            item = item->next_buy_item;
        }

        new = new->next_customer_data;
    }
    fclose(fp1);
    fclose(fp);
}

void load_old_customer(cus_SLL **headptr)
{
    FILE *fp = fopen("./bin/customerlist.dat", "rb");

    if(fp == NULL){
        printf("No old customer data found\n");
        return;
    }

    cus_SLL *last_node = NULL;//

    while(1)
    {
        cus_SLL *new = malloc(sizeof(cus_SLL));

        if(new == NULL)
        {
            perror("malloc");
            fclose(fp);
            return;
        }
        if(fread(new->customer_name,
                 sizeof(new->customer_name), 1, fp) != 1)
        {
            free(new);
            break;
        }
        int count;

        if(fread(&count, sizeof(count), 1, fp) != 1)
        {
            free(new);
            break;
        }

        new->item_list = NULL;
        new->next_customer_data = NULL;


        struct bill *last_item = NULL;

        for(int i = 0; i < count; i++)
        {
            struct bill *item = malloc(sizeof(struct bill));

            if(item == NULL)
            {
                perror("malloc");
                fclose(fp);
                return;
            }

            fread(&item->hsn_number,
                  sizeof(item->hsn_number), 1, fp);

            fread(&item->quantitty,
                  sizeof(item->quantitty), 1, fp);

            item->next_buy_item = NULL;

            /* first item */
            if(new->item_list == NULL)
            {
                new->item_list = item;
                last_item = item;
            }
            else
            {
                /* next item */
                last_item->next_buy_item = item;
                last_item = item;
            }
        }

        /* add customer to customer list */
        if(*headptr == NULL)
        {
            *headptr = new;
            last_node = new;
        }
        else
        {
            last_node->next_customer_data = new;
            last_node = new;
        }
    }

    fclose(fp);

    printf("Customer data loaded successfully\n");
}


void load_warehouse_data(war_SLL **headptr)
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

void  save_warhouse_data_update(war_SLL *head){

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

void sales_report(cus_SLL *head)
{
    FILE *fp = fopen("./report/salesReport.txt","w");
        if(fp == NULL){
            return ;
        }
    
    float grand_total = 0;
    if(head == NULL) {
        printf("\nNo sales data available.\n");
        return;
    }

    fprintf(fp,"\n----------------------------------------------------------\n");
    fprintf(fp,"sales report\n");
    fprintf(fp,"-------------------------------------------------------------\n");

    while(head)    {
        fprintf(fp,"\nCustomer Name : %s\n", head->customer_name);
        fprintf(fp,"------------------------------------------------------------\n");

        struct bill *item = head->item_list;
        float customer_total = 0;

        while(item)        {
            war_SLL *warehouse = headptr_warehouse;
           
            while(warehouse)            {
                if(item->hsn_number == warehouse->HSN_code)
                    break;
                warehouse = warehouse->next_warehouse_data;
            }

            if(warehouse != NULL)            {
                float item_total = item->quantitty * warehouse->MRP;

                fprintf(fp,"hsn:%d qauntity %d mrp %f totalitems %f",item->hsn_number,item->quantitty,warehouse->MRP,item_total);

                customer_total += item_total;
            }

            item = item->next_buy_item;
        }

        fprintf(fp,"-------------------------------------------------\n");
        fprintf(fp,"Customer Total : %.2f\n", customer_total);

        grand_total += customer_total;

        head = head->next_customer_data;
    }

    fprintf(fp,"\n---------------------------------------------------------------------------\n");
    fprintf(fp,"grand total of sales : %.2f\n", grand_total);
    fprintf(fp,"-----------------------------------------------------------------\n");
    fclose(fp);

    printf("---------------------------------------------------------------------------\n");
    printf("report  generateted");
    printf("---------------------------------------------------------------------------\n");


}
