#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// insert at BEGIN
void insertbegin(int value)
{
    struct node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {

        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = head;
        head = newnode;
        temp->next = head;
    }

    printf("%d inserted(head)\n", value);
}

// insert at the END
void insertEnd(int value)
{
    struct node *ptr = (node *)malloc(sizeof(node));
    ptr->data = value;

    if (head == NULL)
    {

        head = ptr;
        ptr->next = head;
    }

    else
    {
        struct node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = ptr;
        ptr->next = head;
    }

    printf("%d inserted(End)\n", value);
}

// insert after specific NODE
void insertAfter(int index, int value)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
    }
    else
    {
        struct node *temp = head;
        struct node *ptr = (node *)malloc(sizeof(node));

        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            insertEnd(value);
        }

        else
        {
            ptr->data = value;
            ptr->next = temp->next;
            temp->next = ptr;
        }

        printf("%d inserted(between)\n", value);
    }
}

// delete the HEAD element
void deletionbegin()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    else
    {
        struct node *temp = head;
        struct node *temp2 = head;

        if (temp->next == head)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }

            head = head->next;
            temp->next = head;
            free(temp2);
        }
        printf("%d is deleted(begin)\n", temp2->data);
    }
}

// delete a specific ELEMENT
void deletionBetween(int index)
{ // 1 2 3 4 5
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }
    else if (index > 1)
    {
        struct node *beforetarget = head;
        struct node *target = head->next;

        for (int i = 0; i < index - 2; i++)
        {
            beforetarget = beforetarget->next;
            target = target->next;
            //printf("%d: Before, %d: Target\n", beforetarget->data, target->data);
        }

        if (beforetarget->next == head || target->next == head)
        {
            cout << "Not enough element to be deleted\n";
            return;
        }

        beforetarget->next = target->next;
        printf("%d has been deleted(between)\n", target->data);
        free(target);
    }
    else
    {
        cout << "Not enough element to be deleted\n";
        return;
    }
}

// delete the LAST element
void deletionEnd()
{

    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    else
    {

        struct node *ptr = head;
        struct node *ptr2 = head->next;

        if (ptr->next == head) // used for deleting only head element(when node = 1)
        {
            head = NULL;
            printf("%d is deleted(end)\n", ptr->data);
            free(ptr);
            return;
        }

        while (ptr2->next != head)
        {
            ptr2 = ptr2->next;
            ptr = ptr->next;
        }

        ptr->next = head;

        printf("%d is deleted(end)\n", ptr2->data);
        free(ptr2);
    }
}

// display the list
void displaylist()
{
    if (head == NULL)
    {
        printf("List is Empty.");
    }

    else
    {
        struct node *temp = head;

        while (temp->next != head)
        {
            printf("Element: %d\n", temp->data);
            temp = temp->next;
        }

        printf("Element: %d\n", temp->data);
    }
}

//searching & replacing mention in singly and doubly linked list file

int main()
{
    insertbegin(5);
    insertbegin(4);
    insertbegin(3);
    insertbegin(2);
    insertbegin(1);
    insertEnd(54);
    insertEnd(99);
    insertAfter(5, 20);

    cout << "\nBefore #### Circular Linkedlist\n";
    displaylist();

    deletionBetween(2);
    deletionbegin();
    deletionbegin();
    deletionEnd();

    cout << "\nAFTER #### Circular Linkedlist\n";
    displaylist();
}