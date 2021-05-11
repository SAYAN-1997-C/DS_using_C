#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* getNode(int );
void Display(node *);
void SearchAnode(node *);
void FindMinMax(node *);
node* InsertFront(node *);
node* InsertEnd(node *);
node* DeleteFront(node *);
node* DeleteRear(node *);
node* InsertAtPos(node *);
node* DeletePos(node *);
node* InsertBeforeData(node *);
node* InsertAfterData(node *);
node* DeleteBeforeData(node *);
node* DeleteAfterData(node *);


int main()
{
    node *head=NULL,*current,*nw;
    int val,ch,ch1;
    while(1)
    {
        printf("\nEnter the data : ");
        scanf("%d",&val);
        nw=getNode(val);
        if(head==NULL)
            head=nw;
        else
            current->next=nw;
        current=nw;
        printf("\nDo you want to continue press 1 otherwise 0 : ");
        scanf("%d",&ch);
        if(ch==0)
            break;
    }
    while(1)
    {
        printf("\n1.Display the list\n2.Search a node\n3.Find Min and Max\n4.Insert at the front\n5.Insert at end\n6.Delete from the front\n7.Delete from the rear\n8.Insert at any position\n9.Delete from any position\n10.Insert before a given data\n11.Insert after a given data\n12.Delete before a given data\n13.Delete after a given data\n99.Exit\nEnter your choice : ");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1 :Display(head);
                    break;
            case 2 :SearchAnode(head);
                    break;
            case 3 :FindMinMax(head);
                    break;
            case 4 :head=InsertFront(head);
                    break;
            case 5 :head=InsertEnd(head);
                    break;
            case 6 :head=DeleteFront(head);
                    break;
            case 7 :head=DeleteRear(head);
                    break;
            case 8 :head=InsertAtPos(head);
                    break;
            case 9 :head=DeletePos(head);
                    break;
            case 10:head=InsertBeforeData(head);
                    break;
            case 11:head=InsertAfterData(head);
                    break;
            case 12:head=DeleteBeforeData(head);
                    break;
            case 13:head=DeleteAfterData(head);
                    break;
            case 99:exit(0);
            default:printf("\nEnter a valid input.Please check....");
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
    nw->next=NULL;
    return nw;
}
void Display(node *head)
{
    node *ptr;
    ptr=head;
    printf("\nThe list is : ");
    while(ptr!=NULL)
    {
        printf("%d --> ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
void SearchAnode(node *head)
{
    node *ptr;
    int val,pos=1;
    printf("\nEnter the data do you want to search : ");
    scanf("%d",&val);
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data==val)
        {
            printf("\nThe position of the data is : %d\n",pos);
            return;
        }
        ptr=ptr->next;
        pos++;
    }
    printf("\nData is not present into the list..\n");
    return;   
}
void FindMinMax(node *head)
{
    node *ptr;
    int min,max;
    ptr=head;
    min=max=head->data;
    while(ptr!=NULL)
    {
        if(ptr->data>max)
            max=ptr->data;
        if(ptr->data<min)
            min=ptr->data;
        ptr=ptr->next;
    }
    printf("\nThe max value is : %d",max);
    printf("\nThe min value is : %d\n",min);
    return;
}
node* InsertFront(node *head)
{
    node *nw;
    int val;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    nw=getNode(val);
    nw->next=head;
    head=nw;
    printf("\nInsert at front successfully!!\n");
    return head;
}
node* InsertEnd(node *head)
{
    node *nw,*ptr;
    int val;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    nw=getNode(val);
    ptr=head;
    if(head==NULL)
    {
        head=nw;
        printf("\nInsert at end successfully!!\n");
        return head;
    }
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=nw;
    printf("\nInsert at end successfully!!\n");
    return head;
}
node* DeleteFront(node *head)
{
    node *x;
    if(head==NULL)
    {
        printf("\nList is already empty!!\n");
        return head;
    }
    x=head;
    head=head->next;
    free(x);
    printf("\nSuccessfully!!Deleted from the front.\n");
    return head;
}
node* DeleteRear(node *head)
{
    node *x,*ptr,*temp;
    if(head==NULL)
    {
        printf("\nList is already empty!!\n");
        return head;
    }
    temp=ptr=head;
    if(head->next==NULL)
    {
        head=NULL;
        printf("\nSuccessfully!!Deleted from the rear.\n");
        return head;
    }
    while(ptr->next!=NULL)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
    free(ptr);
    printf("\nSuccessfully!!Deleted from the rear.\n");
    return head;
}
node* InsertAtPos(node *head)
{
    node *ptr,*temp,*nw;
    int val,pos,k=1;
    printf("\nEnter the data : ");
    scanf("%d",&val);
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    while(pos<1)
    {
        printf("\nEnter a valid position : ");
        scanf("%d",&pos);   
    }
    nw=getNode(val);
    ptr=temp=head;
    if(pos==1)
    {
        nw->next=head;
        head=nw;
        printf("Successfully Inserted !!\n");
        return head;
    }
    while(k<pos)
    {
        ptr=temp;
        if(ptr==NULL)
        {
            printf("\nPosition is not available..\n");
            return head;
        }
        temp=temp->next;
        k++;
    }
    nw->next=temp;
    ptr->next=nw;
    printf("Successfully Inserted !!\n");
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
            nw->next=temp;
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
        printf("\nDeleted successfully before given data.\n");
        return head;
    }
    ptr=temp=head;
    while(temp->next!=NULL)
    {
        if(temp->next->data==posVal)
        {
            ptr->next=temp->next;
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
                temp->next=temp->next->next;
            printf("\nDeleted successfully after given data.\n");
            return head;
        }
        temp=temp->next;
    }
    printf("\nData is not present into the list.\n");
    return head;

}
