#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact
{char name[15],pet_name[10],phno[15];
int day,month,yr; 
struct contact *next;
};

struct econtact
{char name[15],phno[15];
struct econtact *next;
};

typedef struct econtact node1;
typedef struct contact node;

node1 *emergency_call_list=NULL;
node1 *emergency_call_2=NULL;
node *contact_list=NULL;
node *recent_call_list=NULL;

int contact_counter=0;
int recent_call_counter=0;
int emergency_c1=0;
int emergency_c2=0;




node1* create1()
{node1 *new1;
new1=(node1 *)malloc(sizeof(node1));

if(new1==NULL)
{
printf("no memory space . node1 not created\n");
exit(0);
}
	reppno:
printf("enter phone number\n");
scanf("%s",new1->phno);
node1 *temp=emergency_call_list;
while(temp!=NULL)
{if(strcmp(temp->phno,new1->phno)==0)
{
return NULL;
}
temp=temp->next;
}

       
   int n=strlen(new1->phno);
   if(n!=8&&n!=10)
   {printf("invalid phone number . please re enter\n");
   goto reppno;
   }
   
   int i;
   int c=0;
   for(i=0;i<n;i++)
   {if(new1->phno[i]>='0'&&new1->phno[i]<='9')
     c++;
 }
	 if(c!=n)
	 printf("invalid phone number . please re-enter");
	 
	 

printf("enter contact name\n");
scanf("%s",new1->name);



new1->next=NULL;
return new1;
}

node1* create2()
{node1 *new1;
new1=(node1 *)malloc(sizeof(node1));

if(new1==NULL)
{
printf("no memory space . node1 not created\n");
exit(0);
}
	reppno:
printf("enter phone number\n");
scanf("%s",new1->phno);
node1 *temp=emergency_call_2;
while(temp!=NULL)
{if(strcmp(temp->phno,new1->phno)==0)
{
return NULL;
}
temp=temp->next;
}

       
   int n=strlen(new1->phno);
   if(n!=3)
   {printf("invalid phone number . please re enter\n");
   goto reppno;
   }
   
   int i;
   int c=0;
   for(i=0;i<n;i++)
   {if(new1->phno[i]>='0'&&new1->phno[i]<='9')
     c++;
 }
	 if(c!=n)
	 printf("invalid phone number . please re-enter");
	 
	 

printf("enter service name\n");
scanf("%s",new1->name);



new1->next=NULL;
return new1;
}


void display_social_emergency()
{node1 *temp=emergency_call_2;
if(emergency_call_2==NULL)
{printf("your social emergency list is empty");
return;
}
int i=1;
while(temp!=NULL)
{printf("%d ) %s %s\n",i,temp->name,temp->phno);
i++;
temp=temp->next;
}
}

void display_personal_emergency()
{node1 *temp=emergency_call_list;
if(emergency_call_list==NULL)
{printf("your personal emergency list is empty .Returning to main menu\n");
return;
}
int i=1;
while(temp!=NULL)
{printf("%d ) %s %s\n",i,temp->name,temp->phno);
i++;
temp=temp->next;
}
}

void insert_emergency()
{
int ch;	
	printf("enter \n 1.insert a personal emergency number(8 or 10 digit) \n 2.insert social emergency number(3 digit)");
scanf("%d",&ch);


if(ch==1)
{node1 *new1;
new1=create1();
if(new1==NULL)
{printf("contact already exists\n.Not inserting the contact");
free(new1);
return;
}
emergency_c1++;
node1 *temp=emergency_call_list;
if(emergency_call_list==NULL)
{emergency_call_list=new1;
}
else
{while(temp->next!=NULL)
{temp=temp->next;
}
temp->next=new1;
}
}
else if(ch==2)
{node1 *new1;
new1=create2();
if(new1==NULL)
{printf("contact already exists\n.Not inserting the contact");
free(new1);
return;
}
emergency_c2++;
node1 *temp=emergency_call_2;
if(emergency_call_2==NULL)
{emergency_call_2=new1;
}
else
{while(temp->next!=NULL)
{temp=temp->next;
}
temp->next=new1;
}
}
else
{printf("invalid entry . please try inserting again\n");
}
}

void call_placed(char entry[])
{	recent_call_counter++;
printf("call has been successfully placed to contact %s.\n",entry);
	call_end:
		printf("Press '1' to end call\n");
	int end;
	scanf("%d",&end);
	if(end==1)
	{printf("call has been ended.Have a nice day\n");
	}
	else
	{printf("invalid key entered. ");
	goto call_end;
	}
}





void call_emergency()
{int ch;
printf("please relax . we will get your call connected ASAP");

printf("Enter \n 1.To call Number 112-Indian emergency number \n 2.Other social service number(3 digit)\n 3.personal emergency number \n");
scanf("%d",&ch);
if(ch==1)
{char em[35]="Indian Emergency number-112";
call_placed(em);
}
else if(ch==2)
{int ch1;
flag:
display_social_emergency();
if(emergency_call_2==NULL)
{return;
}
printf("This is your social emergency list . Press:\n0 to return to main menu . \n Number adjacent to list to call the contact\n");
scanf("%d",&ch1);
if(ch1==0)
{return;
}
else if(ch1>0&&ch1<=emergency_c2)
{node1 *temp=emergency_call_2;
for(int i=1;i<ch1;i++)
{temp=temp->next;
}
call_placed(temp->name);
}
else
{printf("invalid entry . please re-enter\n");
goto flag;
}
}
else if(ch==3)
{
int ch2;
flag1:
display_personal_emergency();
if(emergency_call_list==NULL)
{return;
}
printf("This is your personal emergency list . Press:\n0 to return to main menu . \n Number adjacent to list to call the contact\n");
scanf("%d",&ch2);
if(ch2==0)
{return;
}
else if(ch2>0&&ch2<=emergency_c1)
{node1 *temp1=emergency_call_list;
for(int i=1;i<ch2;i++)
{temp1=temp1->next;
}
call_placed(temp1->name);
}
else
{printf("invalid entry . please re-enter\n");
goto flag1;
}
}
else
{printf("invalid entry . please try calling again\n");
return;
}
}

node *edit(node * contact_list,int contact_counter, char Name[])
{
    char no[20];
      node * curr = contact_list;//current traversing node
    node * prev;//pointer for node prevous to traversing node
    int check=0;//check flag , whether contact is present or not
    if(curr == NULL){
        printf("No contacts to edit\n");
        return NULL;
    }
    else
    {
    while(curr != NULL){
        prev = curr;
        //strcmp returns 0 when both strings are same
        if(!strcmp(curr->name , Name)){//contacted to be deleted is present in the created list
            prev->next = curr->next;
            printf("\nEdit the contact with name: %s \n", curr->name);
            contact_counter--;
            check=1;
            printf("Enter changed no:");
            scanf("%s",&no);
            strcpy(curr->phno,no);
            
           // free(curr);
           // insert();
            return contact_list;
        }
    }
        curr = curr->next;
        
        
    }
        
        
}

void search(char Name[20],int id)
{
     node * curr = contact_list;//current traversing node
    //pointer for node prevous to traversing node
    int check=0;
    //check flag , whether contact is present or not
    if(id==1)
    {
        if(curr == NULL)
        {
             printf("No contacts \n");
             return;
        }
          else
          {
             while(curr != NULL)
             {
                  
                  //strcmp returns 0 when both strings are same
                  if(strcmp(curr->name , Name)==0)
                  {   //contacted to be deleted is present in the created list
                      
                      printf("\nThe contact with name: %s is found\n", curr->name);
                      printf("\n Name: %s ( %s )\n  contact number: +91%s\n  DOB: %d/%d/%d\n", curr->name,curr->pet_name,curr->phno,curr->day,curr->month,curr->yr);
                      check++;
                    return;
                  }
                  curr = curr->next;
             }
               
         } if(check==0)
    printf("\nContact not found");
    }
    else
    {
        if(curr == NULL)
        {
             printf("No contacts \n");
             return;
        }
          else
          {
             while(curr != NULL)
             {
                  
                  //strcmp returns 0 when both strings are same
                  if(!strcmp(curr->phno, Name))
                  {   //contacted to be deleted is present in the created list
                      
                      printf("\nThe contact with number: %s is found\n", curr->phno);
                      printf("\n Name: %s ( %s )\n  contact number: +91%s\n  DOB: %d/%d/%d\n", curr->name,curr->pet_name,curr->phno,curr->day,curr->month,curr->yr);
                      check=1;
                    return;
                  }
                  curr = curr->next;
             }
               
         }
    }
    
    if(check==0)
    printf("\nContact not found");
    
}






node *create()
{node *new1;
new1=(node *)malloc(sizeof(node));

if(new1==NULL)
{
printf("no memory space . node not created\n");
exit(0);
}
	reppno:
printf("enter phone number\n");
scanf("%s",new1->phno);
node *temp=contact_list;
while(temp!=NULL)
{if(strcmp(temp->phno,new1->phno)==0)
{
return NULL;
}
temp=temp->next;
}

       
   int n=strlen(new1->phno);
   if(n!=8&&n!=10)
   {printf("invalid phone number . please re enter\n");
   goto reppno;
   }
   
   int i;
   int c=0;
   for(i=0;i<n;i++)
   {if(new1->phno[i]>='0'&&new1->phno[i]<='9')
     c++;
 }
	 if(c!=n)
	 printf("invalid phone number . please re-enter");
	 
	 

printf("enter name\n");
scanf("%s",new1->name);


printf("enter pet name\n");
scanf("%s",new1->pet_name);

repeat:
printf("enter date of birth in DD/MM/YYYY formaat\n");
printf("enter day");
scanf("%d",&new1->day);
printf("enter month");
scanf("%d",&new1->month);
printf("enter year");
scanf("%d",&new1->yr);

int check=0;
if(new1->day>0&&new1->day<=31&&new1->month>0&&new1->month<=12&&new1->yr>0)
check=1;
if(check==0)
{printf("wrong format of date of birth . plz re-enter\n");
goto repeat;
}
new1->next=NULL;
return new1;
}
void insert()
{node *new1;
new1=create();
if(new1==NULL)
{printf("contact already exists\n.Not inserting the contact");
free(new1);
return;
}
node *temp=contact_list;
contact_counter++;
if(contact_list==NULL)
{contact_list=new1;
}

else if(contact_list->next==NULL)
{
if(strcmp(new1->name,temp->name)>0)
{
contact_list->next=new1;
new1->next=NULL;
}
else
{new1->next=contact_list;
contact_list=new1;
}
}
else
{
node *temp2=contact_list;
while(strcmp(new1->name,temp->name)>0&&temp!=NULL)
{temp2=temp;
temp=temp->next;
}

temp2->next=new1;
new1->next=temp;
}
}

void display_contact()
{int i=1;
    node * curr = contact_list;//current traversing node
    if(contact_list == NULL){//check if no contacts
        printf("\n no contacts to display\n");
        return;
    }
    printf("you have %d contacts\n",contact_counter);
    printf("Your contact list\n %d contacts", contact_counter);
    while(curr != NULL){
        //serial number
        //Name:contact_name (pet_name)
        //contact number: +911234567890
        //DOB: 00/00/00
        printf("\n %d) Name: %s ( %s )\n  contact number: +91%s\n  DOB: %d/%d/%d\n",i, curr->name,curr->pet_name,curr->phno,curr->day,curr->month,curr->yr);
        curr = curr->next;
        i=i+1;
    }
    return;
}


node* insert_recent_call_contact(node *new1)
{
	  
	   node *temp1=recent_call_list;
	   node *prev;
	   node *temp=recent_call_list; 
         if(recent_call_list==NULL)
        {
            recent_call_list=new1;
          recent_call_counter++;
          
        }
        else
        {
            while(temp1->next!=NULL)
            temp1=temp1->next;
            temp1->next=new1;
            recent_call_counter++;
          
        }
    
      
     if(recent_call_counter==10)
     {
        
        recent_call_list=recent_call_list->next;
        free(temp);
     }
     return new1;
}


void display_recent_call()
{int i=1;
    node *temp=recent_call_list;
    if(recent_call_list==NULL)
    {
        printf("you havent called anyone yet \n");
        return;
    }
    while(temp!=NULL)
    {
        printf("\n %d) %s %s %s ",i,temp->name,temp->pet_name,temp->phno);
        temp=temp->next;
        i++;
    }
}

void delet()
{flag:
node *temp=contact_list;
display_contact();
if(contact_list==NULL)
{printf("Returning back to main menu\n");
return;
}
int ch;
printf("this is your entire contact list.Press :0 to return to main menu\n1:number adjacent to contact to delete it");
scanf("%d",&ch);
if(ch==0)
{printf("Returning back to main menu...\n");
return;
}
else if(contact_counter==1&&ch==1)
{free(contact_list);
contact_list=NULL;
}
else if(ch>0&&ch<=contact_counter)
{int i;
for(i=1;i<ch-1;i++)
{temp=temp->next;
}
node* temp1=temp->next;
printf("The contact\n %s %s %s %d /%d /%d \n is successfully deleted . Going to main menu\n",temp1->name,temp1->phno,temp1->pet_name,temp1->day,temp1->month,temp1->yr);
temp->next=temp1->next;
temp1->next=NULL;
free(temp1);
contact_counter--;
}
else
{printf("incorrect entry . Please try again\n");
goto flag;
}
}

void calling()
{int ch;
display_recent_call();
if(recent_call_list==NULL)
{ch=0;
}
else
{
printf("here is a list of people you recently called.");

flag_2:
printf("\nPress\n-0 to call from your contact list\n-number adjacent to contact to call the person\n");

scanf("%d",&ch);
}
if(ch==0)
{
		display_contact();
		if(contact_list==NULL)
		{return;
		}
		printf("\n This is your entire contact list.");
		flag_1:
		printf("Press \nIf person is not in contact press 0 to create contact and call \n else press 1\n");
		int c;
		scanf("%d",&c);
		if(c==0)
		{printf("Please create the contact \n");
		node *new1;
		new1=create();
		
		if(new1==NULL)
{printf("contact already exists\n.Not inserting the contact . Please try calling again\n");
free(new1);
return;
}
contact_counter++;
node *temp=contact_list;
if(contact_list==NULL)
{contact_list=new1;
}

else if(contact_list->next==NULL)
{if(strcmp(new1->name,temp->name)>0)
{
contact_list->next=new1;
new1->next=NULL;
}
else
{new1->next=contact_list;
contact_list=new1;
}
}
else
{
node *temp2=contact_list;
while(strcmp(new1->name,temp->name)>0&&temp!=NULL)
{temp2=temp;
temp=temp->next;
}

temp2->next=new1;
new1->next=temp;
}
flag:
printf("contact successfully created.\n");
printf("Press 1 to call him now and 0 to go back to main menu\n");
int r;
scanf("%d",&r);
if(r==1)
{node *tempo=new1;
tempo->next=NULL;
insert_recent_call_contact(tempo);
call_placed(tempo->name);
return;
}
else if(r==0)
{printf("Call not placed. Have a nice day");
return;
}
else
{printf("invalid key entered\n");
goto flag;
}
}
else if(c==1)
{printf("enter the name of contact to be called\n");
char nam[15];
scanf("%s",nam);
int q=0;
node *temp1=contact_list;
while(temp1!=NULL&&q!=1)
{if(strcmp(nam,temp1->name)==0)
{q=1;
insert_recent_call_contact(temp1);
call_placed(nam);
return;
}
temp1=temp1->next;
}
if(q==0)
{printf("Sorry but contact does not exist . please try calling again \n");
return;
}
}			
else
{printf("invalid key entered . please re-enter\n");			
goto flag_1;
}
}

else if(ch>=1&&ch<=recent_call_counter)
{
	int i;
	
	node *tempr=recent_call_list;
	for(i=1;i<ch;i++)
	tempr=tempr->next;
	insert_recent_call_contact(tempr);
	call_placed(tempr->name);
}
	
else
{
printf("invalid input .please re-enter \n");
         goto flag_2;
}
}



int main()
{
   // insert();
 // insert();
   // insert();
 //   calling();
//    calling();
  //  display_contact(contact_list);
    //int main()

       // insert_emergency();
    int ch,i;
    char n[20];
    while(1)
    {
        printf("Enter your choice:\n1.Create new contact\n2.Call contact\n3.delete contact\n4.Search contact\n5.Edit\n6.Insert emergency contact\n7.call emergency contact\n8.display emergency contact\n9.display Recent Calls\n10.Display All Contacts \n 11.Exit\n:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
            break;
            
            case 2:calling();
            break;
            
            case 3:delet();
            break;
            
            case 4:printf("Search by 1.name or 2.number:");
           scanf("%d",&i);
           if(i==1)
           {
                printf("\nEnter name:");
                scanf("%s",&n);
                search(n,i);
                break;
           }
           else 
           {
               printf("\nEnter number:");
                scanf("%s",&n);
                search(n,i);
                break;
           }
            case 5:printf("\nEnter the contact name :");
            scanf("%s",&n);
            edit(contact_list,contact_counter,n);
            break;
            
            case 6:insert_emergency();
            break;
            
            case 7:call_emergency();
            break;
            
            case 8:
			if(emergency_call_2!=NULL)
			printf("This is your social emergency list\n");
            display_social_emergency();
            
            	if(emergency_call_list!=NULL)
			printf("This is your personal emergency list\n");
            display_personal_emergency();
            break;
            
            case 9:display_recent_call();
            break;
            
            case 10:display_contact();
            break;
            
            case 11:exit(0);break;
        }
        
    }
   

    return 0;
}
