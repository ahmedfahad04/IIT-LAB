#include <bits/stdc++.h>
#define N 100
using namespace std;

struct Node{
    int data;
    struct Node * next;
};
struct Node * head = NULL;

//all type of insertion operations.......................................................

// insert at first
void InsertAtFirst(int value){
    struct Node * temp = (struct Node *) malloc (sizeof(struct Node));

    temp -> data = value;
    temp -> next = head;
    // head -> next = NULL; // we need this line when we declare Node * head = (struct Node *) malloc (sizeof(struct Node));
    head = temp;
    printf("%d Added(head)\n", value);

}

// insert in between(index)
void InsertAtIndex(int value, int index){
    struct Node * ptr = head;
    struct Node * temp = (struct Node *) malloc (sizeof(struct Node));
    temp -> data = value;

    for(int i = 0; i<index-1; i++){
        ptr = ptr -> next;
    }

    temp -> next = ptr -> next;
    ptr -> next = temp;
    printf("%d Added(index)\n", value);
}

// insert at specfic node is given in LL_code_with_harry

// insert at end
void InsertAtEnd(int value){
    Node * temp = (struct Node *) malloc (sizeof(struct Node));
    Node * ptr;

    ptr = head;
    while(ptr->next != NULL) ptr = ptr->next;

    temp -> data = value;
    ptr-> next = temp;
    temp->next = NULL;
    printf("%d Added(end)\n", value);
}


//all type of deletion operations.......................................................

// delete the first node
void deleteFirst()
{
    struct Node *ptr = head;
    head = head->next;
    printf("%d has been removed(head)\n", ptr->data);
    free(ptr);

}

// delete element after given index
void deletoinInBetween(int index)
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
void deleteWithValue(int value)
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
void deleteLastNode()
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


// search an element
void SearchElement(struct Node * head,int value){
   
    struct Node * ptr = (struct Node *) malloc (sizeof(struct Node));
    ptr = head;
    
    if(ptr->data == value){
        printf("%d FOUND!!\n", value);
        return;
    }

    if(ptr->next == NULL){
        printf("NOT FOUND!\n");
        return;
    } 
    
    SearchElement(head->next, value);

}

// replace certain value
void ReplaceValue(int from_value, int to_value){
    struct Node * ptr = head;

    while(ptr -> data != from_value) ptr = ptr -> next;
    ptr -> data = to_value;

    printf("%d is replaced with %d\n", from_value, to_value);
}

// display linked list
void PrintList(){
    struct Node * ptr;
    ptr = head;
    while(ptr->next != NULL){
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
    printf("Element: %d\n", ptr->data);
}


int main(){   

    puts("\nINSERTING Elements\n");
    InsertAtFirst(9); // insert at head
    InsertAtFirst(8);
    InsertAtFirst(4);
    InsertAtFirst(2);
    InsertAtFirst(12);
    InsertAtEnd(1478);             // insert at the end
    InsertAtIndex(1111,3);        // insert at index
    InsertAtIndex(5555,4);        // insert at index

    puts("\nAFTER Insertion\n");
    PrintList();

    puts("\nDELETING Elements\n");
    deletoinInBetween( 5); // delete node using index
    deleteFirst();   // delete the head node
    deleteFirst();
    deleteWithValue(9); // delete node using value
    deleteLastNode();     // delete the last node
    ReplaceValue(1111,9999);
    puts("\nAfter Deletion\n");
    PrintList();

    SearchElement(head, 5555);
    
}
