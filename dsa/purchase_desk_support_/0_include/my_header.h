/*so the flow for ware_house will be to when executed
should ask for new entries 
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define description_size 100 
#define customer_name_size 15

typedef struct ware_house
{
    //HSN Code, Product Description, Quantity, MRP
    
    unsigned int HSN_code;
    char item_info[description_size];
    unsigned int quantity;
    float MRP;

    struct ware_house *next_warehouse_data ;
    
}war_SLL;


typedef struct customer
{
    //HSN Code, Product Description, Quantity, MRP
    
    char customer_name[customer_name_size];
    struct bill *item_list;
    
    struct customer *next_customer_data ;
    
}cus_SLL;

struct bill{
    int hsn_number;
    int quantitty ;
    struct bill *next_buy_item; 
};


int add_item(war_SLL **);
int hsn_check(int ,war_SLL *);

int update_data(war_SLL **,war_SLL *);
void print_items(war_SLL *);
void  save_data(war_SLL *);
void load_data(war_SLL **);
void load_warehouse_data(war_SLL **);
void print_warehouse(war_SLL *);
void  save_warhouse_data_update(war_SLL *);


int add_purchase(cus_SLL **);
void  specific_customer_items(struct bill **); //link list of customers items 
void add_cus_choice(struct bill **);
void print_customer_and_items(cus_SLL *);
void   save_data_customer(cus_SLL *);
void load_old_customer(cus_SLL **);
void generate_bill(cus_SLL *);
void sales_report(cus_SLL *);
void generate_all_customer_bill(cus_SLL *);
