#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev,*next;
}node;

void Display(node *);
node* getNode(int );
void SearchNode(node *);
node* InsertFront(node *);
node* InsertEnd(node *);
node* RemoveFront(node *);
node* RemoveRear(node *);
node* InsertPosition(node *);
node* DeletePos(node *);
node* InsertBeforeData(node *);
node* InsertAfterData(node *);
node* DeleteBeforeData(node *);
node* DeleteAfterData(node *);

int main()
{
    node *head,*current,*nw;
    int val,ch,ch1;
    while(1)
    {
        printf("\nEnter the data : ");
        scanf("%d",&val);
        nw=getNode(val);
        if(head==NULL)
            head=nw;
        else
        {
            current->next=nw;
            nw->prev=current;
        }
        current=nw;
        printf("\nYou want to continue press 1 otherwise 0 : ");
        scanf("%d",&ch);
        if(ch==0)
            break;
    }
    while(1)
    {
        printf("\n1.Display\n2.Search a node\n3.Insert at the Front\n4.Insert at the End\n5.Delete from the front\n6.Delete from the rare\n7.Insert at any position\n8.Delete from any position\n9.Insert before a given data\n10.Insert after a given data\n11.Delete before a given data\n12.Delete after a given data\n13.Exit\nEnter your choice : ");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1 : Display(head);
                     break;
            case 2 : SearchNode(head);
                     break;
            case 3 : head=InsertFront(head);
                     break;
            case 4 : head=InsertEnd(head);
                     break;
            case 5 : head=RemoveFront(head);
                     break;
            case 6 : head=RemoveRear(head);
                     break;
            case 7 : head=InsertPosition(head);
                     break;
            case 8 : head=DeletePos(head);
                     break;
            case 9 : head=InsertBeforeData(head);
                     break;
            case 10 :head=InsertAfterData(head);
                     break;
            case 11 :head=DeleteBeforeData(head);
                     break;
            case 12 :head=DeleteAfterData(head);
                     break;
            case 13: exit(0);
            default: printf("\nPlease enter a valid input !!");
                     break;
        }
    }
    return 0;
}
node* getNode(int val)
{
    node *nw;
    nw=(node *)malloc(sizeof(node));
    nw->data=val;
    nw->next=nw->prev=NULL;
    return nw;
}
void Display(node *head)
{
    node *ptr,*temp;
    ptr=head;
    printf("\nThe list is : ");
    while(ptr!=NULL)
    {
        printf("%d --> ",ptr->data);
        temp=ptr;
        ptr=ptr->next;
    }
    printf("\n");
    printf("\nThe Reverse list is : ");
    while(temp!=NULL)
    {
        printf("%d --> ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
void SearchNode(node *head)
{
    node *ptr;
    int pos=1,val;
    ptr=head;
    printf("\nEnter the data you want to search : ");
    scanf("%d",&val);
    while(ptr!=NULL)
    {
        if(ptr->data==val)
        {
            printf("\nData found at Position : %d\n",pos);
            return;
        }    
        pos++;
        ptr=ptr->next;
    }
    printf("\nData not found in the list !!\n");
    return ;
}
node* InsertFront(node *head)
{
    node *nw;
    int val;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    nw=getNode(val);
    if(head==NULL)
        head=nw;
    else
    {
        nw->next=head;
        head->prev=nw;
        head=nw;
    }
    printf("\nInserted Successfully at front!!\n");
    return head;
}
node* InsertEnd(node *head)
{
    node *nw,*ptr;
    int val;
    printf("\nEnter the value : ");
    scanf("%d",&val);
    nw=getNode(val);
    if(head==NULL)
    {
        head=nw;
        printf("\nInserted successfully at the end!!\n");
        return head;
    }
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=nw;
    nw->prev=ptr;
    printf("\nInserted successfully at the end!!\n");
    return head;
}
node* RemoveFront(node *head)
{
    if(head==NULL)
    {
        printf("\nList is already empty!!");
        return head;
    }
    if(head->next==NULL)
    {
        head=NULL;
    }
    else
    {
        head=head->next;
        head->prev=NULL;
    }
    printf("\nDeleted successfully from the front!!");
    return head;
}
node* RemoveRear(node *head)
{
    node *ptr;
    if(head==NULL)
    {
        printf("\nList is already empty!!\n");
        return head;
    }
    if(head->next==NULL)
        head=NULL;
    else
    {
        ptr=head;
        while(ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=NULL;
    }
    printf("\nDeleted successfully from the rear!!\n");
    return head;
}
node* InsertPosition(node *head)
{
    node *ptr,*temp,*nw;
    int pos,val,k=1;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    while(pos<1)
    {
        printf("\nEnter a valid position : ");
        scanf("%d",&pos);
    }
    printf("\nEnter the data : ");
    scanf("%d",&val);
    nw=getNode(val);
    if(pos==1)
    {
        nw->next=head;
        head->prev=nw;
        head=nw;
        printf("\nSuccessfully inserted!!");
        return head;
    }
    ptr=temp=head;
    while(k<pos)
    {
        ptr=temp;
        if(ptr==NULL)
        {
            printf("\nPosition is not found into the list!!\n");
            return head;
        }
        temp=temp->next;
        k++;
    }
    ptr->next=nw;
    nw->prev=ptr;
    nw->next=temp;
    if(nw->next!=NULL)
        temp->prev=nw;
    printf("\nSuccessfully inserted!!");
    return head;
}
node* DeletePos(node *head)
{
    node *ptr,*temp,*x;
    int val,pos,k=1;
    if(head==NULL)
    {
        printf("\nList is already empty!!\n");
        return head;
    }
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    while(pos<1)
    {
        printf("\nEnter a valid position : ");
        scanf("%d",&pos);   
    }
    ptr=temp=head;
    if(pos==1)
    {
        x=head;
        head=head->next;
        head->prev=NULL;
        free(x);
        printf("Successfully Deleted !!\n");
        return head;
    }
    while(k<pos)
    {
        ptr=temp;
        temp=temp->next;
        if(temp==NULL)
        {
            printf("\nPosition is not available..\n");
            return head;
        }
        k++;
    }
    ptr->next=temp->next;
    if(temp->next!=NULL)
        temp->next->prev=ptr;
    printf("Successfully Deleted !!\n");
    return head;
}
node* InsertBeforeData(node *head)
{
    node *ptr,*temp,*nw;
    int val,posVal;
    if(head==NULL)
    {
        printf("\nThe List is empty!!\n");
        return head;
    }
    printf("\nEnter the data whose before you insert : ");
    scanf("%d",&posVal);
    printf("\nEnter the data : ");
    scanf("%d",&val);
    nw=getNode(val);
    if(head->data==posVal)
    {
        nw->next=head;
        head->prev=nw;
        head=nw;
        printf("\nInserted successfully before given data.\n");
        return head;
    }
    ptr=temp=head;
    while(temp!=NULL)
    {
        if(temp->data==posVal)
        {
            ptr->next=nw;
            nw->prev=ptr;
            nw->next=temp;
            temp->prev=nw;
            printf("\nInserted successfully before given data.\n");
            return head;
        }
        ptr=temp;
        temp=temp->next;
    }
    printf("\nData is not present into the list.\n");
    return head;

}
node* InsertAfterData(node *head)
{
    node *temp,*nw;
    int val,posVal;
    if(head==NULL)
    {
        printf("\nThe List is empty!!\n");
        return head;
    }
    printf("\nEnter the data whose after you insert : ");
    scanf("%d",&posVal);
    printf("\nEnter the data : ");
    scanf("%d",&val);
    nw=getNode(val);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==posVal)
        {
            nw->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=nw;
            nw->prev=temp;
            temp->next=nw;
            printf("\nInserted successfully after given data.\n");
            return head;
        }
        temp=temp->next;
    }
    printf("\nData is not present into the list.\n");
    return head;

}
node* DeleteBeforeData(node *head)
{
    node *ptr,*temp,*nw;
    int val,posVal;
    if(head==NULL)
    {
        printf("\nThe List is empty!!\n");
        return head;
    }
    printf("\nEnter the data whose before's data you delete : ");
    scanf("%d",&posVal);
    nw=getNode(val);
    if(head->data==posVal)
    {
        printf("\nDelete is not possible.\n");
        return head;
    }
    if(head->next->data==posVal)
    {
        head=head->next;
        head->prev=NULL;
        printf("\nDeleted successfully before given data.\n");
        return head;
    }
    ptr=temp=head;
    while(temp->next!=NULL)
    {
        if(temp->next->data==posVal)
        {
            ptr->next=temp->next;
            temp->next->prev=ptr;
            printf("\nDeleted successfully before given data.\n");
            return head;
        }
        ptr=temp;
        temp=temp->next;
    }
    printf("\nData is not present into the list.\n");
    return head;

}
node* DeleteAfterData(node *head)
{
    node *ptr,*temp,*nw;
    int val,posVal;
    if(head==NULL)
    {
        printf("\nThe List is empty!!\n");
        return head;
    }
    printf("\nEnter the data whose after's data you delete : ");
    scanf("%d",&posVal);
    nw=getNode(val);
    ptr=temp=head;
    while(temp!=NULL)
    {
        if(temp->data==posVal && temp->next==NULL)
        {
            printf("\nNot Possible!!\n");
            return head;
        }
        if(temp->data==posVal)
        {
            if(temp->next->next==NULL)
                temp->next=NULL;
            else
            {
                temp->next=temp->next->next;
                temp->next->prev=temp;
            }
            printf("\nDeleted successfully after given data.\n");
            return head;
        }
        temp=temp->next;
    }
    printf("\nData is not present into the list.\n");
    return head;

}