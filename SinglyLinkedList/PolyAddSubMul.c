#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coef,exp;
    struct node *next;
}node;

node* getNode(int ,int );
node* CreatePoly(node *);
void Display(node *);
void Addition(node *,node *);
void Subtraction(node *,node *);
void Multiplication(node *,node *);

int main()
{
    node *poly1=NULL,*poly2=NULL;
    int ch;
    while(1)
    {
        printf("\n1.Create a polynomial\n2.Display\n3.Addition\n4.Subtraction\n5.Multiplication\n6.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :printf("\nEnter the first polynomial : ");
                    poly1=CreatePoly(poly1);
                    printf("\nEnter the second polynomial : ");
                    poly2=CreatePoly(poly2);
                    break;
            case 2 :printf("\nFirst Polynomial is : ");
                    Display(poly1);
                    printf("\nSecond Polynomial is : ");
                    Display(poly2);
                    break;
            case 3 :Addition(poly1,poly2);
                    break;
            case 4 :Subtraction(poly1,poly2);
                    break;
            case 5 :Multiplication(poly1,poly2);
                    break;
            case 6 :exit(0);
            default:("\nPlease enter a valid input...");
                    break;
        }
    }
    return 0;  
}
node* getNode(int coef,int exp)
{
    node *nw;
    nw=(node *)malloc(sizeof(node));
    nw->coef=coef;
    nw->exp=exp;
    nw->next=NULL;
    return nw;
}

node* CreatePoly(node *head)
{
    node *nw,*current;
    int ch,coef,exp;
    head=NULL;
    while(1)
    {
        printf("\nEnter the co-efficient with sign : ");
        scanf("%d",&coef);
        printf("\nEnter the exponent with sign : ");
        scanf("%d",&exp);
        nw=getNode(coef,exp);
        if(head==NULL)
            head=nw;
        else
            current->next=nw;
        current=nw;
        printf("\nTo continue insertion press 1 otherwise 0 : ");
        scanf("%d",&ch);
        if(ch==0)
            break;
    }
    return head;
}
void Display(node *head)
{
    node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->coef>0)
            printf(" + %d(x^%d)",ptr->coef,ptr->exp);
        else
            printf(" %d(x^%d) ",ptr->coef,ptr->exp);
        ptr=ptr->next;
    }
    printf("\n");
    return ;
}
void Addition(node *poly1,node *poly2)
{
    node *head=NULL,*ptr1,*ptr2,*nw,*current;
    ptr1=poly1;
    ptr2=poly2;
    int co,ex;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->exp > ptr2->exp)
        {
            co=ptr1->coef;
            ex=ptr1->exp;
            ptr1=ptr1->next;
        }
        else if(ptr2->exp > ptr1->exp)
        {
            co=ptr2->coef;
            ex=ptr2->exp;
            ptr2=ptr2->next;
        }
        else
        {
            co=ptr1->coef+ptr2->coef;
            ex=ptr1->exp;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        nw=getNode(co,ex);
        if(head==NULL)
            head=nw;
        else    
            current->next=nw;
        current=nw;
    }
    while(ptr1!=NULL)
    {
        co=ptr1->coef;
        ex=ptr1->exp;
        ptr1=ptr1->next;
        nw=getNode(co,ex);
        if(head==NULL)
            head=nw;
        else    
            current->next=nw;
        current=nw;
    }
     while(ptr2!=NULL)
    {
        co=ptr2->coef;
        ex=ptr2->exp;
        ptr2=ptr2->next;
        nw=getNode(co,ex);
        if(head==NULL)
            head=nw;
        else    
            current->next=nw;
        current=nw;
    }
    printf("\nAfter addition : ");
    Display(head);
    return ;
}
void Subtraction(node *poly1,node *poly2)
{
    node *head=NULL,*ptr1,*ptr2,*nw,*current;
    ptr1=poly1;
    ptr2=poly2;
    int co,ex;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->exp > ptr2->exp)
        {
            co=ptr1->coef;
            ex=ptr1->exp;
            ptr1=ptr1->next;
        }
        else if(ptr2->exp > ptr1->exp)
        {
            co=(-1*ptr2->coef);
            ex=ptr2->exp;
            ptr2=ptr2->next;
        }
        else
        {
            co=ptr1->coef-ptr2->coef;
            ex=ptr1->exp;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        nw=getNode(co,ex);
        if(head==NULL)
            head=nw;
        else    
            current->next=nw;
        current=nw;
    }
    while(ptr1!=NULL)
    {
        co=ptr1->coef;
        ex=ptr1->exp;
        ptr1=ptr1->next;
        nw=getNode(co,ex);
        if(head==NULL)
            head=nw;
        else    
            current->next=nw;
        current=nw;
    }
     while(ptr2!=NULL)
    {
        co=ptr2->coef;
        ex=ptr2->exp;
        ptr2=ptr2->next;
        nw=getNode(co,ex);
        if(head==NULL)
            head=nw;
        else    
            current->next=nw;
        current=nw;
    }
    printf("\nAfter subtraction : ");
    Display(head);
    return;
}
void Multiplication(node *poly1,node *poly2)
{
    node *head=NULL,*nw,*ptr1,*ptr2,*current,*prevtemp,*temp;
    ptr1=poly1;
    int co,ex;
    while(ptr1!=NULL)
    {
        ptr2=poly2;
        while(ptr2!=NULL)
        {
            co=ptr1->coef*ptr2->coef;
            ex=ptr1->exp+ptr2->exp;
            nw=getNode(co,ex);
            if(head==NULL)
                head=nw;
            else    
                current->next=nw;
            current=nw;
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    ptr1=head;
    while(ptr1!=NULL)
    {
        prevtemp=ptr1;
        temp=ptr1->next;
        while(temp!=NULL)
        {
            if(temp->exp==ptr1->exp)
            {
                ptr1->coef=ptr1->coef+temp->coef;
                prevtemp->next=temp->next;
                temp=prevtemp;
            }
            prevtemp=temp;
            temp=temp->next;
        }
        ptr1=ptr1->next;
    }
    printf("\nAfter multiplication : ");
    Display(head);
    return;
}