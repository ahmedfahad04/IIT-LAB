#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// all type of insertion operations.................................................

// insert at begining
struct Node *InsertAtFirst(struct Node *head, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = value;
    temp->next = head;

    printf("%d Added(head)\n", value);
    return temp;
}

// insert at the end/back
void InsertAtEnd(struct Node *head, int value)
{
    Node *temp = (struct Node *)malloc(sizeof(struct Node));
    Node *ptr;

    ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    temp->data = value;
    ptr->next = temp;
    temp->next = NULL;

    printf("%d added(end)\n", value);
}

// insert in between(index)
void InsertAtIndex(struct Node *head, int value, int index)
{
    struct Node *ptr = head;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;

    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;

    printf("%d added(index)\n", value);
}

// inset after a node
void InsertAfterNode(struct Node *head, struct Node *prevnode, int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;

    ptr->next = prevnode->next;
    prevnode->next = ptr;

    printf("%d added(node)\n", value);
}

//all type of deletion operations.......................................................

// delete the first node
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    printf("%d has been removed(head)\n", ptr->data);
    free(ptr);

    return head;
}

// delete element after given index
void deletoinInBetween(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    printf("%d has been deleted(index)\n", q->data);
    free(q);
}

// delete a node with given value
void deleteWithValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value)
    {
        q = q->next;
        p = p->next;
    }

    printf("%d has been removed(value)\n", q->data);
    p->next = q->next;
    free(q);
}

// delete the last node
void deleteLastNode(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    printf("%d has been removed(last)\n", q->data);
    free(q);
}

// display linked list
void PrintList(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("Element: %d\n", ptr->data);
}

int main()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));

    head->data = 154;
    head->next = second;

    second->data = 999;
    second->next = NULL;

    puts("\nBEFORE\n");
    PrintList(head);

    puts("\nINSERTING Elements\n");
    head = InsertAtFirst(head, 9); // insert at head
    head = InsertAtFirst(head, 8);
    head = InsertAtFirst(head, 4);
    head = InsertAtFirst(head, 2);
    InsertAtEnd(head, 1478);             // insert at the end
    InsertAtIndex(head, 1111, 3);        // insert at index
    InsertAfterNode(head, second, 2222); // insert after Node

    puts("\nAFTER Insertion\n");
    PrintList(head);

    puts("\nDELETING Elements\n");
    deletoinInBetween(head, 5); // delete node using index
    head = deleteFirst(head);   // delete the head node
    head = deleteFirst(head);
    deleteWithValue(head, 9); // delete node using value
    deleteLastNode(head);     // delete the last node
    puts("\nAfter Deletion\n");
    PrintList(head);
}