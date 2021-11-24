#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<process.h>

struct node
{
    char info[30];
    char group[5];
    char contact[13];
    struct node *link;
}*start;

void Create_List()
{
    struct node *q,*tmp;
    char a[40],b[7],c[15];
    tmp= (struct node*)malloc(sizeof(struct node));
    getchar();
    printf("Enter donor's name: ");
    gets(a);
    printf("Enter blood group: ");
    gets(b);
    printf("Enter contact number: ");
    gets(c);
    strcpy(tmp->info,a);
    strcpy(tmp->group,b);
    strcpy(tmp->contact,c);
    tmp->link=NULL;
    if(start==NULL)
        start=tmp;
    else
    {
        q=start;
        while(q->link!=NULL)
            q=q->link;
        q->link=tmp;
    }
}



void insertLast(int data)
{
    struct node *q=start,*tmp;
    char a[40],b[7],c[15];
    while(q!=NULL && q->link!=NULL)
    {
        q=q->link;
    }
    tmp=(struct node*)malloc(sizeof(struct node));
    getchar();
    printf("\nEnter donor's name: ");
    gets(a);
    printf("Enter blood group: ");
    gets(b);
    printf("Enter contact number: ");
    gets(c);
    strcpy(tmp->info,a);
    strcpy(tmp->group,b);
    strcpy(tmp->contact,c);
    tmp->link=NULL;
    if(q!=NULL)
    {
        q->link=tmp;
    }
    else
    {
        start=tmp;
    }
}

void Display()
{
    struct node *q;
    if(start == NULL)
    {
        printf ("\n\nList is empty");
        return;
    }
    q=start;
    printf("\n");
    printf("SL.\t            Name\t   Blood group\t\t  Contact");
    printf("\n===================================================================");
    int i=1;
    while(q!=NULL)
    {
        printf("\n %d\t\t%s\t\t%s\t\t%s\n", i++,q->info,q->group,q->contact);
        q=q->link;
    }
    printf ("\n");
    getch();
}

int getFirst()
{
    struct node *q=start;
    if(q!=NULL)
    {
        printf("\nDonor's Name: %s", q->info);
        printf("\nDonor's Blood Group: %s", q->group);
        printf("\nDonor's Contact Number: %s\n\n", q->contact);
        getch();
    }
    else
    {
        printf("\n\t------Not Found!!!------\t\n");
    }
}

int getLast()
{
    struct node *q=start;
    if(q==NULL)
    {
        printf("\n\t-------List is empty!!!-------\t\n");
    }
    else
    {
        while(q->link!=NULL)
        {
            q=q->link;
        }
        printf("\nDonor's Name: %s", q->info);
        printf("\nDonor's Blood Group: %s", q->group);
        printf("\nDonor's Contact Number: %s\n\n", q->contact);
        getch();
    }
}

void Delfirst()
{
    struct node *tmp,*q;
        tmp=start;
        start=start->link;
        free(tmp);
        return;
}

void delLast()
{
    struct node *q=start,*tmp;
    if(start->info!=NULL)
    {
        while(q->link->link!=NULL)
        {
            q=q->link;
        }
        tmp=q->link;
        free(tmp);
        q->link=NULL;
    }
}

void delAt(int pos)
{
    struct node *q,*tmp;
    q=start;
    int c=0;
    if(start->info!=NULL)
    {
        if(pos==1)
        {
            Delfirst();
            return;
        }
        while(q->link!=NULL)
        {
            if(c==pos-2)
            {
                tmp=q->link;
                q->link=tmp->link;
                free(tmp);
                return;
            }
            q=q->link;
            c++;
        }
    }
}


int search_list()
{
    struct node *q=start;
    char d[7];
    getchar();
    printf("Enter blood Group: ");
    gets(d);
    int i=1;
    printf("SL.\t            Name\t   Blood group\t\t  Contact");
    printf("\n===================================================================");
    while(q!=NULL)
    {
        if((strcmp(q->group,d))==0)
        {
            printf("\n %d\t\t%s\t\t%s\t\t%s\n", i,q->info,q->group,q->contact);
            i++;
        }
        q=q->link;
    }
    getch();
    if(i==1)
    {
        printf("\n\t-----------Not found!------------\t");
        getch();
    }
}

int change_number()
{
    struct node *q=start;
    char d[15],e[15];
    getchar();
    printf("Enter Previous Contact Number: ");
    gets(d);
    while(q!=NULL)
    {
        if((strcmp(q->contact,d))==0)
        {
            printf("\n\t------Donor Found!-----\t\n");
            getchar();
            printf("\nEnter New Contact Number: ");
            gets(e);
            strcpy(q->contact,e);
            printf("\n-----Contact Updated Successfully-----\n");
            break;
        }
        q=q->link;
    }
        getch();
}


void main()
{
    int choice,n,position,i;
    char m;
    start=NULL;
    while(1)
    {
        printf("============================================\n");
        printf("           Blood Donor Database\n");
        printf("============================================\n");
        printf ("1.Create List\n");
        printf ("2.Add Data of a New Donor\n");
        printf ("3.Display the Complete List\n");
        printf ("4.Find Donor of Specific Blood Group\n");
        printf ("5.Display First Entry\n");
        printf ("6.Display Last Entry\n");
        printf ("7.Delete First Entry\n");
        printf ("8.Delete Last Entry\n");
        printf ("9.Delete Donor From Specific Position\n");
        printf ("10.Update Donor's Contact Info\n");
        printf ("11.Quit\n");
        printf ("\nEnter your choice:");
        scanf ("%d",&choice);
        switch (choice)
        {
        case 1:
            printf ("\n\nHow many donor's data you want to entry:");
            scanf ("%d",&n);
            for(i = 0; i<n; i++)
            {
                Create_List();
            }
            printf("\n");
            break;


        case 2:
            insertLast(n);
            printf("\nData inserted successfully!!!\n");
            break;

        case 3:
            Display();
            break;

        case 4:
            search_list(n);
            break;

        case 5:
            getFirst();
            break;

        case 6:
            getLast();
            break;

        case 7:
            Delfirst();
            printf("\n\t----------deleted successfully!!!----------\t\n\n");
            break;

        case 8:
            delLast();
            printf("\n\t----------deleted successfully!!!----------\t\n\n");
            break;

         case 9:
            printf("\nEnter position: ");
            scanf("%d", &n);
            delAt(n);
            printf("\n\t----------deleted successfully!!!----------\t\n\n");
            break;

         case 10:
            change_number();
            break;

        case 11:
            exit(0);
        default:
            printf ("\n\nWrong choice");
        }
    }
}

