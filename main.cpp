#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
int i=0;
struct node
{
int accno;
char name[50],phone[20];
int deposit;
char type;
struct node *next;
struct node *prev;
};
struct node1
{
int accno1;
char name1[50],phone1[20];
int deposit1;
char type1;
struct node1 *next1;
struct node1 *prev1;
};
struct node1 *top=NULL;
struct node2
{
    int amount;
    int account;
    char mode;
    struct node2 *prev2;
    struct node2 *next2;
};
struct node2 *front=NULL;
struct node2 *rear=NULL;
void enqueue(int acc,char mode,int amt,int b)
{
    if(b==1)
    {
        struct node2 *newnode=new node2;
        rear=newnode;
        rear->account=acc;
        rear->mode=mode;
        rear->amount=amt;
        rear->prev2=NULL;
        rear->next2=NULL;
        front=rear;
    }
    else
    {
        struct node2 *newnode=new node2;
        newnode->account=acc;
        newnode->mode=mode;
        newnode->amount=amt;
        newnode->next2=rear;
        rear->prev2=newnode;
        rear=newnode;
    }
}
void display1();
void dequeue()
{
    front=front->prev2;
    front->next2=NULL;
}
void display1()
{
    int count=0;
    char ch;
    cout<<"\n\t\t\tTRANSACTION HISTORY\n";
    struct node2 *temp=rear;
    while(temp!=NULL)
    {
        count++;
        cout<<"\n\t"<<count<<".";
        cout<<"\tAccount number : "<<temp->account;
        cout<<"\n\t\tType of account : "<<temp->mode;
        cout<<"\n\t\tAmount : "<<temp->amount<<"\n\n";
        temp=temp->next2;
    }
    if(front!=NULL)
    {
        cout<<"\n\t\tDo you want to remove transaction number "<<count<<" from history?\n\t\tPress Y or N : ";
        cin>>ch;
        system("cls");
        if(ch=='y' || ch=='Y')
        {
            dequeue();
            display1();
        }
    }
}
void push(int n,char name[],char type,int bal,char mob[],int a)
{
    if(a==1)
    {
        struct node1 *newnode=new node1;
        top=newnode;
        top->accno1=n;
        strcpy(top->name1,name);
        top->type1=type;
        top->deposit1=bal;
        strcpy(top->phone1,mob);
        top->prev1=NULL;
        top->next1=NULL;
    }
    else
    {
        struct node1 *newnode=new node1;
        newnode->accno1=n;
        strcpy(newnode->name1,name);
        newnode->type1=type;
        newnode->deposit1=bal;
        strcpy(newnode->phone1,mob);
        newnode->next1=top;
        top->prev1=newnode;
        top=newnode;
    }
}
void pop()
{
    top=top->next1;
    top->prev1=NULL;
}
void display()
{
    if(top==NULL)
    {
        cout<<"\n\n\t\tCLOSED ACCOUNT\n\n\t\tNONE...";
    }
    struct node1 *temp=top;
    char ch;
    cout<<"\n\n\t\t\tCLOSED ACCOUNTS\n";
    int count=0;
    while(temp!=NULL)
    {
        count++;
        cout<<"\n\t"<<count<<".";
        cout<<"\tAccount number : "<<temp->accno1;
        cout<<"\n\t\tAccount holder : "<<temp->name1;
        cout<<"\n\t\tAccount type : "<<temp->type1;
        cout<<"\n\t\tBalance : "<<temp->deposit1;
        cout<<"\n\t\tMobile number : "<<temp->phone1<<"\n\n";
        temp=temp->next1;
    }
    if(top!=NULL)
    {
        cout<<"\n\t\tDo you want to permanently delete 1st record ?\n\t\tPress Y or N : ";
        cin>>ch;
        system("cls");
        if(ch=='y' || ch=='Y')
        {
            pop();
            display();
        }
    }
}
class account
{
    struct node *head;
    char ch;
public:
    account()
    {
        head=NULL;
    }
void create_accountbeg();
void create_accountnext();
void create_accountprev();
void del_account();
void show_account();
void search_account();
void modify();
void deposit();
void draw();
void transfer();
void sort();
void display();
void online();
};
void account::create_accountbeg()
{
    node *newnode=new node;
cout<<"\n\t\tEnter The account No. :";
cin>>newnode->accno;
cout<<"\n\t\tEnter The Name of The account Holder : ";
cin.ignore();
cin.getline(newnode->name,50);
cout<<"\n\t\tEnter Type of The account (C/S) : ";
cin>>newnode->type;
cout<<"\n\t\tEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
cin>>newnode->deposit;
while(1)
    {
        if(newnode->type=='s' || newnode->type=='S')
        {
            if(newnode->deposit<500)
            {
                cout<<"\n\t\tEnter proper initial amount:";
                cin>>newnode->deposit;
            }
            else
            {
                break;
            }
        }
        else if(newnode->type=='c' || newnode->type=='C')
        {
            if(newnode->deposit<1000)
            {
                cout<<"\n\t\tEnter proper initial amount:";
                cin>>newnode->deposit;
            }
            else
            {
                break;
            }
        }
    }
    cout<<"\n\t\tEnter the phone number associated with the account :";
    cin>>newnode->phone;
    int l;
    l=strlen(newnode->phone);
    while(1)
    {
        if(l!=10)
        {
            cout<<"\n\t\tEnter proper phone number : ";
            cin>>newnode->phone;
            l=strlen(newnode->phone);
        }
        else
            break;
    }
    newnode->next=head;
    newnode->prev=NULL;
    if(head!=NULL)
    {
        head->prev=newnode;
    }
    head=newnode;
    cout<<"\n\n\n\t\tACCOUNT CREATED..";
}
void account::create_accountnext()
{
    if(head==NULL)
    {
        cout<<"\n\t\tList is empty\n";
        cout<<"\n\t\tAdd new record\nPress Y or N";
        cin>>ch;
        if((ch=='Y')||(ch=='y'))
        {
            create_accountbeg();
            return;
        }
        else
        {
            exit(1);
        }
    }
    else
    {
        int value;
        char ch,ph[20];
        cout<<"\n\t\tDo you know the account number after which you need to add?\n\t\tPress Y or N : ";
        cin>>ch;
        if(ch=='y'|| ch=='Y')
        {
            cout<<"\n\t\tEnter the account number after which you want to add a new record:";
            cin>>value;
        }
        else
        {
            cout<<"\n\t\tEnter the phone number associated with that account : ";
            cin>>ph;
        }
        system("cls");
        cout<<"\n\t\t\tYOUR ACCOUNT DETAILS\n";
        bool flag=false;
        node *temp=head;
        node *p;
        while(temp!=NULL)
        {
            if(temp->accno==value || strcmp(temp->phone,ph)==0)
            {
                node *newnode=new node;
                cout<<"\n\t\tEnter the account number:";
                cin>>newnode->accno;
                cout<<"\n\t\tEnter the name of the account holder:";
                cin.getline(newnode->name,50);
                cout<<"\n\t\tEnter Type of The account (C/S) : ";
                cin>>newnode->type;
                cout<<"\n\t\tEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
                cin>>newnode->deposit;
                while(1)
                {
                    if(newnode->type=='s' || newnode->type=='S')
                    {
                        if(newnode->deposit<500)
                        {
                            cout<<"\n\t\tEnter proper initial amount:";
                            cin>>newnode->deposit;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if(newnode->type=='c' || newnode->type=='C')
                    {
                        if(newnode->deposit<1000)
                        {
                            cout<<"\n\t\tEnter proper initial amount:";
                            cin>>newnode->deposit;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                cout<<"\n\t\tEnter phone number associated with this account : ";
                cin>>newnode->phone;
                int l;
                l=strlen(newnode->phone);
                while(1)
                {
                    if(l!=10)
                    {
                        cout<<"\n\t\tEnter proper phone number : ";
                        cin>>newnode->phone;
                        l=strlen(newnode->phone);
                    }
                    else
                        break;
                }
                if(temp->next!=NULL)
                {
                    newnode->next=temp->next;
                    newnode->prev=temp;
                    p=temp->next;
                    p->prev=newnode;
                    temp->next=newnode;
                }
                else
                {
                    newnode->next=temp->next;
                    newnode->prev=temp;
                    temp->next=newnode;
                }
                flag=true;
                cout<<"\n\n\n\t\tAccount created...";
            }
            temp=temp->next;
        }
        if(flag==false)
        {
            cout<<"\n\t\tID is not found\n";
        }
    }
}
void account::create_accountprev()
{
    if(head==NULL)
    {
        cout<<"\n\t\tList is empty.";
        cout<<"\n\t\tAdd a new record\n\tPress Y or N:";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            create_accountbeg();
            return;
        }
        else
        {
            exit(1);
        }
    }
    else
    {
        int value;
        char ch,ph[20];
        bool flag=false;
        cout<<"\n\t\tDo you know the account number before which you need to add?\n\t\tPress Y or N : ";
        cin>>ch;
        if(ch=='y'|| ch=='Y')
        {
            cout<<"\n\t\tEnter the account number before which you want to add a new record:";
            cin>>value;
        }
        else
        {
            cout<<"\n\t\tEnter the phone number associated with that account : ";
            cin>>ph;
        }
        system("cls");
        node *temp=head;
        cout<<"\n\t\t\tYOUR ACCOUNT DETAILS\n";
        if(temp->accno==value || strcmp(temp->phone,ph)==0)
        {
            create_accountbeg();
            return;
        }
        else
        {
            while(temp!=NULL)
            {
                if(temp->accno==value || strcmp(temp->phone,ph)==0)
                {
                    node *newnode=new node;
                    cout<<"\n\t\tEnter the account number:";
                    cin>>newnode->accno;
                    cout<<"\n\t\tEnter the name of the account holder:";
                    cin.getline(newnode->name,50);
                    cout<<"\n\t\tEnter Type of The account (C/S) : ";
                    cin>>newnode->type;
                    cout<<"\n\t\tEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
                    cin>>newnode->deposit;
                    while(1)
                    {
                        if(newnode->type=='s' || newnode->type=='S')
                        {
                            if(newnode->deposit<500)
                            {
                                cout<<"\nEnter proper initial amount:";
                                cin>>newnode->deposit;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else if(newnode->type=='c' || newnode->type=='C')
                        {
                            if(newnode->deposit<1000)
                            {
                                cout<<"\nEnter proper initial amount:";
                                cin>>newnode->deposit;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    cout<<"\n\t\tEnter phone number associated with this account : ";
                    cin>>newnode->phone;
                    int l;
                    l=strlen(newnode->phone);
                    while(1)
                    {
                        if(l!=10)
                        {
                            cout<<"\n\t\tEnter proper phone number : ";
                            cin>>newnode->phone;
                            l=strlen(newnode->phone);
                        }
                        else
                            break;
                    }
                    newnode->next=temp;
                    newnode->prev=temp->prev;
                    node *p;
                    p=temp->prev;
                    p->next=newnode;
                    temp->prev=newnode;
                    flag=true;
                    cout<<"\n\n\nAccount created...";
                }
                temp=temp->next;
            }
            if(flag==false)
                cout<<"\n\t\tRecord is not found...";
        }
    }
}
void account::del_account()
{
    if(head==NULL)
    {
        cout<<"\n\t\tList is empty\n";
        cout<<"\n\t\tAdd a new record\n\tPress Y or N";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            create_accountbeg();
            return;
        }
        else
        {
            exit(1);
        }

    }
    else
    {
        int value;
        char ch,ph[20];
        cout<<"\n\t\tDo you know the account number you want to close?\n\t\tPress Y or N : ";
        cin>>ch;
        if(ch=='y' ||ch=='Y')
        {
            cout<<"\n\t\tEnter the account number you want to close:";
            cin>>value;
        }
        else
        {
            cout<<"\n\t\tEnter phone number associated with this account : ";
            cin>>ph;
        }
        node *temp=head;
        bool flag=false;
        if(temp->accno==value || strcmp(temp->phone,ph)==0)
        {
            i++;
            push(temp->accno,temp->name,temp->type,temp->deposit,temp->phone,i);
            head=temp->next;
            head->prev=NULL;
            flag=true;
            delete temp;
            if(flag==true)
            {
                cout<<"\n\t\tAccount has been closed successfully";
            }
        }
        else
        {
            while(temp!=NULL)
            {
                if(temp->accno==value || strcmp(temp->phone,ph)==0)
                {
                    i++;
                    push(temp->accno,temp->name,temp->type,temp->deposit,temp->phone,i);
                    node *p,*q;
                    if(temp->next==NULL)
                    {
                        p=temp->prev;
                        p->next=NULL;
                        flag=true;
                        delete temp;
                        if(flag==true)
                            cout<<"\nAccount has been closed successfully.";
                    }
                    else
                    {
                        p=temp->prev;
                        q=temp->next;
                        p->next=q;
                        q->prev=p;
                        flag=true;
                        delete temp;
                        if(flag==true)
                            cout<<"\nAccount has been closed successfully";
                    }
                }
                temp=temp->next;
            }
            if(flag==false)
            {
                cout<<"\nValue is not found";
            }
        }
    }
}

void account::show_account()
{
    if(head==NULL)
    {
        cout<<"\n\t\tList is empty";
        cout<<"\n\t\tAdd a new record\n\t\tPress Y or N";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            create_accountbeg();
            return;
        }
        else
        {
            exit(1);
        }
    }
    else
    {
        node *temp=head;
        cout<<"\n\t\tDETAILS OF ALL ACCOUNTS:\n";
        while(temp!=NULL)
        {
            cout<<"\n\n";
            cout<<"\n\t\tAccount Number:"<<temp->accno;
            cout<<"\n\t\tAccount holder Name:"<<temp->name;
            cout<<"\n\t\tType of account:"<<temp->type;
            cout<<"\n\t\tDeposited  amount:"<<temp->deposit;
            cout<<"\n\t\tMobile number:"<<temp->phone;
            temp=temp->next;
        }
    }
}
void account::search_account()
{
    if(head==NULL)
    {
        cout<<"\n\t\tList is empty\n";
        cout<<"\n\t\tAdd a new record\n\tPress Y or N";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            create_accountbeg();
            return;
        }
        else
        {
            exit(1);
        }

    }
    else
    {
        int value;
        char ch,ph[20];
        cout<<"\n\t\tDo you know the account number you want to search?\n\t\tPress Y or N : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            cout<<"\n\t\tEnter the account number you want to search:";
            cin>>value;
        }
        else
        {
            cout<<"\n\t\tEnter the phone number associated with this account : ";
            cin>>ph;
        }
        node *temp=head;
        while(temp!=NULL)
        {
            if(temp->accno==value || strcmp(temp->phone,ph)==0)
            {
                cout<<"\n\t\tDetails of account:\n";
                cout<<"\n\t\tAccount Number:"<<temp->accno;
                cout<<"\n\t\tAccount holder Name:"<<temp->name;
                cout<<"\n\t\tType of account:"<<temp->type;
                cout<<"\n\t\tDeposited  amount:"<<temp->deposit;
                cout<<"\n\t\tMobile number:"<<temp->phone;
            }
            temp=temp->next;
        }
    }
}
void account::modify()
{
    if(head==NULL)
    {
        cout<<"\n\t\tList is empty\n";
        cout<<"\n\t\tAdd a new record\n\tPress Y or N";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            create_accountbeg();
            return;
        }
        else
        {
            exit(1);
        }

    }
    else
    {
        int value;
        char ch,ph[20];
        cout<<"\n\t\tDo you know the account number you want to modify?\n\t\tPress Y or N : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            cout<<"\n\t\tEnter the account number you want to modify:";
            cin>>value;
        }
        else
        {
            cout<<"\n\t\tEnter the phone number associated with this account : ";
            cin>>ph;
        }
        node *temp=head;
        if(temp->accno==value || strcmp(temp->phone,ph)==0)
        {
            int choice;
            cout<<"\nWhich detail would you like to modify?";
            cout<<"\n1.Account number\t2.Account holder name\t3.Account type\t4.Mobile number";
            cin>>choice;
            fflush(stdin);
            system("cls");
            switch(choice)
            {
            case 1:
                cout<<"\n\t\tEnter the account number:";
                cin>>temp->accno;
                fflush(stdin);
                break;
            case 2:
                cout<<"\n\t\tEnter the name of the account holder:";
                cin.getline(temp->name,50);
                fflush(stdin);
                break;
            case 3:
                cout<<"\n\t\tEnter Type of The account (C/S) : ";
                cin>>temp->type;
                fflush(stdin);
                cout<<"\n\t\tEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
                while(1)
                {
                    if(temp->type=='s' || temp->type=='S')
                    {
                        cin>>temp->deposit;
                        if(temp->deposit<500)
                        {
                            cout<<"\n\t\tEnter proper initial amount : ";
                            cin>>temp->deposit;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if(temp->type=='c' || temp->type=='C')
                    {
                        cin>>temp->deposit;
                        if(temp->deposit<1000)
                        {
                            cout<<"\n\t\tEnter proper initial amount:";
                            cin>>temp->deposit;
                       }
                        else
                        {
                            break;
                        }
                    }
                    fflush(stdin);
                }
                break;
            case 4:

            default:
                cout<<"\n\t\tEnter proper choice.";
                break;
            }
            temp=temp->next;
        }
        cout<<"\n\t\tRecord has been updated successfully";
    }
}

void account::deposit()
{
if(head==NULL)
    {
        cout<<"\n\t\tList is empty\n";
        cout<<"\n\t\tAdd a new record\n\tPress Y or N";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            create_accountbeg();
            return;
        }
        else
        {
            exit(1);
        }

    }
    else
    {
        int value;
        char ch,ph[20],deposit,amount;
        cout<<"\n\t\tDo you know the account number in which you want to deposit?\n\t\tPress Y or N : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            cout<<"\n\t\tEnter the account number in which you want to deposit:";
            cin>>value;
        }
        else
        {
            cout<<"\n\t\tEnter the phone number associated with this account : ";
            cin>>ph;
        }
        system("cls");
        node *temp=head;
        while(temp!=NULL)
        {
            if(temp->accno==value || strcmp(temp->phone,ph)==0)
            {
                cout<<"\n\t\tEnter the amount to be deposited:";
                cin>>deposit;
                amount=temp->deposit+deposit;
                temp->deposit=amount;
            }
            temp=temp->next;
        }
    }
}

void account::draw()
{
if(head==NULL)
    {
        cout<<"\n\t\tList is empty\n";
        cout<<"\n\t\tAdd a new record\n\tPress Y or N";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            create_accountbeg();
            return;
        }
        else
        {
            exit(1);
        }
    }
    else
    {
        int value,deposit,amount;
        char ch,ph[20];
        cout<<"\n\t\tDo you know the account number from which you want to withdraw?\n\t\tPress Y or N : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            cout<<"\n\t\tEnter the account number from which you want to withdraw:";
            cin>>value;
        }
        else
        {
            cout<<"\n\t\tEnter the phone number associated with this account : ";
            cin>>ph;
        }
        system("cls");
        node *temp=head;
        while(temp!=NULL)
        {
            if(temp->accno==value || strcmp(temp->phone,ph)==0)
            {
                cout<<"\n\t\tEnter the amount to be withdrawn:";
                cin>>deposit;
                amount=temp->deposit-deposit;
                temp->deposit=amount;
            }
            temp=temp->next;
        }
    }
}
void account::transfer()
{
    if(head==NULL)
    {
        cout<<"\n\t\tList is empty\n";
        cout<<"\n\t\tAdd a new record\n\tPress Y or N";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            create_accountbeg();
            return;
        }
        else
        {
            exit(1);
        }

    }
    else
    {
        int value;
        int deposit,amount;
        cout<<"\n\t\tEnter the account number from which you would like to transfer : ";
        cin>>value;
        node *temp=head;
        while(temp!=NULL)
        {
            if(temp->accno==value)
            {
                cout<<"\n\t\tEnter the amount to be transferred:";
                cin>>deposit;
                amount=temp->deposit-deposit;
                temp->deposit=amount;
            }
            temp=temp->next;
        }
        value=0;
        cout<<"\n\t\tEnter the account number to which you would like to transfer : ";
        cin>>value;
        node *temp1=head;
        while(temp1!=NULL)
        {
            if(temp1->accno==value)
            {
                amount=temp1->deposit+deposit;
                temp1->deposit=amount;
            }
            temp1=temp1->next;
        }
    }
}
void account::sort()
{
    if(head==NULL)
    {
        cout<<"\n\t\tList is empty\n";
        cout<<"\n\t\tAdd a new record\n\tPress Y or N";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            create_accountbeg();
            return;
        }
        else
        {
            exit(1);
        }

    }
    else
    {
        int choice;
        int tempo,balance;
        char aname[30],acctype,mobile[20];
        cout<<"\n\t\t\t\tSORT\n1.Account number wise\t2.Account holder wise\t3.Balance in account"<<"\n";
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:
        {
            node *temp=head,*temp1=head;
            while(temp->next!=NULL)
            {
                temp1=temp->next;
                if(temp->accno>temp1->accno)
                {
                    tempo=temp->accno;
                    temp->accno=temp1->accno;
                    temp1->accno=tempo;
                    balance=temp->deposit;
                    temp->deposit=temp1->deposit;
                    temp1->deposit=balance;
                    acctype=temp->type;
                    temp->type=temp1->type;
                    temp1->type=acctype;
                    strcpy(aname,temp->name);
                    strcpy(temp->name,temp1->name);
                    strcpy(temp1->name,aname);
                    strcpy(mobile,temp->phone);
                    strcpy(temp->phone,temp1->phone);
                    strcpy(temp1->phone,mobile);
                }
                temp=temp->next;
            }
            cout<<"\n\n\t\tThe records have been sorted based on account number...";
            break;
        }
        case 2:
        {
            node *temp=head,*temp1=head;
            while(temp->next!=NULL)
            {
                temp1=temp->next;
                if(strcmp(temp->name,temp1->name)>0)
                {
                    tempo=temp->accno;
                    temp->accno=temp1->accno;
                    temp1->accno=tempo;
                    balance=temp->deposit;
                    temp->deposit=temp1->deposit;
                    temp1->deposit=balance;
                    acctype=temp->type;
                    temp->type=temp1->type;
                    temp1->type=acctype;
                    strcpy(aname,temp->name);
                    strcpy(temp->name,temp1->name);
                    strcpy(temp1->name,aname);
                    strcpy(mobile,temp->phone);
                    strcpy(temp->phone,temp1->phone);
                    strcpy(temp1->phone,mobile);
                }
                temp=temp->next;
            }
            cout<<"\n\n\t\tThe records have been sorted based on account holder...";
            break;
        }
        case 3:
        {
            node *temp=head,*temp1=head;
            while(temp->next!=NULL)
            {
                temp1=temp->next;
                if(temp->deposit<temp1->deposit)
                {
                    tempo=temp->accno;
                    temp->accno=temp1->accno;
                    temp1->accno=tempo;
                    balance=temp->deposit;
                    temp->deposit=temp1->deposit;
                    temp1->deposit=balance;
                    acctype=temp->type;
                    temp->type=temp1->type;
                    temp1->type=acctype;
                    strcpy(aname,temp->name);
                    strcpy(temp->name,temp1->name);
                    strcpy(temp1->name,aname);
                    strcpy(mobile,temp->phone);
                    strcpy(temp->phone,temp1->phone);
                    strcpy(temp1->phone,mobile);
                }
                temp=temp->next;
            }
            cout<<"\n\n\t\tThe records have been sorted based on highest balance...";
            break;
        }
        default:
        {
            cout<<"\n\n\t\tYou did not enter proper choice...";
            break;
        }
        }
    }
}

void account::display()
{
    int choice;
    cout<<"\n\n\t\tACCOUNT TYPE\n\n\t1.Saving\t2.Current\n";
    cin>>choice;
    system("cls");
    node *temp=head;
    switch(choice)
    {
    case 1:
        cout<<"\n\t\t\tSAVINGS";
        while(temp!=NULL)
        {
            if(temp->type=='s')
            {
                cout<<"\n\n\t\tAccount number : "<<temp->accno;
                cout<<"\n\t\tAccount holder name : "<<temp->name;
                cout<<"\n\t\tAccount balance : "<<temp->deposit;
                cout<<"\n\t\tMobile Number : "<<temp->phone;
            }
            temp=temp->next;
        }
        break;
    case 2:
        cout<<"\n\t\t\tCURRENT";
        while(temp!=NULL)
        {
            if(temp->type=='c')
            {
                cout<<"\n\n\t\tAccount number : "<<temp->accno;
                cout<<"\n\t\tAccount holder name : "<<temp->name;
                cout<<"\n\t\tAccount balance : "<<temp->deposit;
                cout<<"\n\t\tMobile number : "<<temp->phone;
            }
            temp=temp->next;
        }
        break;
    default:
        cout<<"\n\t\tYou did not enter proper choice...";
        break;
    }
}

void account::online()
{
    char mode;
    int amount,acc,j=0;
    char ch='y';
    cout<<"\n\t\t\tONLINE TRANSACTIONS\n";
    while(ch=='y' || ch=='Y')
    {
        j++;
        cout<<"\n\t\tEnter your account number : ";
        cin>>acc;
        cout<<"\n\t\tEnter the type of account : ";
        cin>>mode;
        cout<<"\n\t\tEnter the amount withdrawn : ";
        cin>>amount;
        enqueue(acc,mode,amount,j);
        cout<<"\n\t\tDo you want to do another transaction ?\n\t\tPress Y or N : ";
        cin>>ch;
    }
    system("cls");
    display1();
}

void intro()
{
cout<<"\n\n\n\t  BANK";
cout<<"\n\n\tMANAGEMENT";
cout<<"\n\n\t  SYSTEM";
cin.get();
}
int main()
{
    account a;
int ch;
intro();
do
{
system("cls");
cout<<"\n\n\n\tMAIN MENU";
cout<<"\n\n\t01. CREATE NEW ACCOUNT IN THE BEGINNING";
cout<<"\n\n\t02. CREATE NEW ACCOUNT AFTER GIVEN RECORD";
cout<<"\n\n\t03. CREATE NEW ACCOUNT BEFORE GIVEN RECORD";
cout<<"\n\n\t04. CLOSE ANY ACCOUNT";
cout<<"\n\n\t05. SHOW ACCOUNT";
cout<<"\n\n\t06. SEARCH ACCOUNT";
cout<<"\n\n\t07. MODIFY ACCOUNT";
cout<<"\n\n\t08. DEPOSIT IN ANY ACCOUNT";
cout<<"\n\n\t09. DRAW FROM ANY ACCOUNT";
cout<<"\n\n\t10. TRANFER FROM ANY ACCOUNT TO ANY ACCOUNT";
cout<<"\n\n\t11. SORT THE GIVEN RECORDS";
cout<<"\n\n\t12. DISPLAY BASED ON TYPES";
cout<<"\n\n\t13. DISPLAY CLOSED ACCOUNTS";
cout<<"\n\n\t14. ONLINE TRANSACTION";
cout<<"\n\n\t15. EXIT";
cout<<"\n\n\tSelect Your Option (1-15) ";
cin>>ch;
system("cls");
switch(ch)
{
case 1:
a.create_accountbeg();
            break;
case 2:
a.create_accountnext();
break;
        case 3:
a.create_accountprev();
break;
case 4:
a.del_account();
break;
case 5:
a.show_account();
break;
case 6:
a.search_account();
break;
case 7:
a.modify();
break;
case 8:
a.deposit();
break;
         case 9:
            a.draw();
            break;
         case 10:
            a.transfer();
            break;
         case 11:
            a.sort();
            break;
         case 12:
            a.display();
            break;
         case 13:
            display();
            break;
         case 14:
            a.online();
            break;
case 15:
            cout<<"\n\n\n\n\n******************************** THANK YOU ********************************\n\n\n\n";
            break;
}
cin.get();
cin.ignore();
}while(ch!=15);
return 0;
}
