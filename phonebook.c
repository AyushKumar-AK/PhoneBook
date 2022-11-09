//phone book using doubly linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    struct node *prev;
    char name[20];
    long int phno;
    struct node *next;
};
struct node *h, *temp, *temp1, *temp2, *temp4;
int count = 0;
void create()
{
    char name[20];
    long int phno;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter Name and Phone Number:\n");
    scanf("%s %ld", name, &phno);
    strcpy(temp->name, name);
    temp->phno = phno;
    count++;
}
void insertbeg()
{
    if (h == NULL)
    {
        create();
        h = temp;
    }
    else
    {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}
void insertend()
{
    if (h == NULL)
    {
        create();
        h = temp;
    }
    else
    {
        create();
        temp1 = h;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
    }
}
void insertpos()
{
    int pos, i = 2;
    printf("\n Enter the position to be inserted:");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insertbeg();
    }
    else
    {
        temp1 = h;
        while (i < pos)
        {
            temp1 = temp1->next;
            i++;
        }
        create();
        temp->next = temp1->next;
        temp->prev = temp1;
        temp1->next = temp;
        temp1->next->prev = temp;
    }
}
void deletebeg()
{
    if (h == NULL)
    {
        printf("\n list is empty:");
    }
    else if (h->next == NULL)
    {
        temp = h;
        h = NULL;
        free(temp);
        count--;
    }
    else
    {
        temp = h;
        h = h->next;
        h->prev = NULL;
        free(temp);
        count--;
    }
}
void deleteend()
{
    if (h == NULL)
    {
        printf("\n list is empty:");
    }
    else if (h->next == NULL)
    {
        temp = h;
        h = NULL;
        free(temp);
        count--;
    }
    else
    {
        
        temp1 = h;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->prev->next = NULL;
        free(temp1);
        printf("Element deleted from the end");
    }
}
void deletepos()
{
    int pos, i;
    printf("\n Enter the position to be deleted:");
    scanf("%d", &pos);
    if (pos == 1)
    {
        deletebeg();
    }
    else
        {
            temp1 = h;
            for(i=1; i<pos; i++)
            {
                temp1 = temp1->next;
            }
            printf("%d", temp1->phno);
            temp1->prev->next = temp1->next;
            temp1->next->prev = temp1->prev;
            free(temp1);
        }
}
void display()
{
    if (h == NULL)
    {
        printf("\n List is empty:");
    }
    else
    {
        temp = h;
        int i=1;
        printf("\n Name & Phone Number present in record:\n");
        printf("Position\tName\tPhone Number\n");
        while(temp != NULL)
        {
            printf("%d\t\t%s\t%ld\n",i, temp->name, temp->phno);
            temp = temp->next;
            i++;
        }
    }
}
void search()
{
    char name[20];
    int flag = 0, i = 1;
    printf("\n enter the name to be searched:");
    scanf("%s", name);
    temp = h;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("\n %s %ld is present at position %d", temp->name, temp->phno, i);
            flag = 1;
            break;
        }
        temp = temp->next;
        i++;
    }
    if (flag == 0)
    {
        printf("\n %s is not present in the list", name);
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n 1.insert at beginning");
        printf("\n 2.insert at end");
        printf("\n 3.insert at position");
        printf("\n 4.delete at beginning");
        printf("\n 5.delete at end");
        printf("\n 6.delete at position");
        printf("\n 7.display");
        printf("\n 8.search");
        printf("\n 9.exit");
        printf("\n enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertbeg();
            break;
        case 2:
            insertend();
            break;
        case 3:
            insertpos();
            break;
        case 4:
            deletebeg();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            deletepos();
            break;
        case 7:
            display();
            break;
        case 8:
            search();
            break;
        case 9:
            exit(0);
        default:
            printf("\n invalid choice:");
        }
    }
    return 0;
}
