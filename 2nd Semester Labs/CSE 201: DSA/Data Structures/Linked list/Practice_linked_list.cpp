#include <bits/stdc++.h>
using namespace std;
#define N 100
#define emt puts("List is Empty")

struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;

void InsertFront(int x)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));

    temp->value = x;
    temp->next = head;
    head = temp;
}

void InsertBack(int x)
{
    node *last, *new_element;

    new_element = (node *)malloc(sizeof(node));
    new_element->value = x;

    if (head == NULL)
    {
        new_element->next = head;
        head = new_element;
    }
    else
    {

        last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = new_element; // new_element -> next is wrong here.
        new_element->next = NULL;
    }
}

node *search_list(struct node *point, int x)
{

    if (head == NULL)
    {
        emt;
        return NULL;
    }
    if (point->next == NULL)
    {
        printf("%d NOT FOUND!!\n", x);
        return NULL;
    }
    if (point->value == x)
    {
        printf("%d FOUND!!\n", point->value);
        return point;
    }

    else
        return search_list(point->next, x);
}

void replace_list(int from, int to)
{
    struct node *temp = search_list(head, from);

    if (temp != NULL)
        temp->value = to;
    printf("%d was replaced with %d\n",from ,to);
}

void printlist()
{
    node *temp;
    temp = head;

    if (temp == NULL)
        emt;
    else
    {

        printf("Values: ");
        while (temp->next != NULL)
        {

            printf("%d ", temp->value); //%d wasn't given
            temp = temp->next;
        }

        printf("%d\n", temp->value); //temp->next was given
    }
}

int main()
{
   

    InsertFront(10);

    InsertFront(22);

    InsertFront(50);

    InsertBack(80);

    printlist();

    replace_list(22, 155);

    InsertBack(1478);

    InsertFront(987);

    printlist();
}
