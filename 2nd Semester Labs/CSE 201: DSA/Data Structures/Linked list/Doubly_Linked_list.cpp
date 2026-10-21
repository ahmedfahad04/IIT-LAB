#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * head = NULL;

// inserting value at Begining
void insertatFirst(int item){
    struct node * ptr = (node *) malloc (sizeof(node));

    //asserting these two condition is a must
    if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  

    printf("Inserted Element(Front): %d\n", item);
}

// inserting value after Specific Node
void insertAfterNode(int node_location,int value){
    struct node * ptr = head;
    struct node * temp = (node *) malloc (sizeof(node));
    struct node * extra;

    for(int i = 0 ; i < node_location-1; i++) ptr = ptr->next;

    extra = ptr -> next; //3rd node

    temp -> data = value; //new node to be added between 2 and 3 node
    temp -> prev = ptr;
    temp -> next = extra;

    extra -> prev = temp;
    ptr -> next = temp; //2nd node

    printf("Inserted Value after %d Node is: %d\n", node_location, value);
}

// inserting value at the END
void insertatLast(int value){
    struct node * temp = (node *) malloc (sizeof(node));
    struct node * ptr = head;

    while(ptr->next != NULL) ptr = ptr->next;

    temp -> data = value;
    temp -> prev = ptr;
    ptr -> next = temp;
    temp -> next = NULL;

    printf("Inserted Element(Last): %d\n", value);

}   

// deleting the First Element
void deletionFirst(){
    struct node * ptr = head;
    
    if(head == NULL) printf("NO elements in list.\n");
    else{
        head = head -> next;
        printf("Deleted Element: %d\n", ptr->data);
        head -> prev = NULL;
        free(ptr);
    }
    
}

// deleting element after a node(problematic)
void deletionInBetween(int node_location){
    struct node * ptr = head, *ptr_next;
    if(head == NULL) {
        printf("List is empty\n");
        return ;
    }
    
    if(ptr -> next != NULL) ptr_next = head -> next;
    else{
        printf("Overflow\n");
        return;
    }

    for(int i = 0 ; i < node_location-1; i++){
        if(ptr->next != NULL && ptr_next -> next != NULL){
            ptr = ptr -> next;
            ptr_next = ptr_next -> next;
        }
        else{
            printf("Overflow\n");
            return;
        }
    }
    
    ptr -> next = ptr_next -> next;

    if(ptr -> next != NULL) ptr_next = ptr_next -> next;
    else{
        ptr -> next = ptr_next;
        printf("Overflow. Cant Delete Element\n");
        return;
    }
   
    printf("Deleted value: %d\n", ptr_next -> data);
    
    ptr_next -> prev = ptr;

}

// delete the last element
void deletionLast(){
    struct node * ptr = head;

    if(head ==  NULL){
        printf("List is empty.\n");
        return;
    } 

    struct node * ptr_prev = head -> next;
    while(ptr_prev->next != NULL) {
        ptr_prev = ptr_prev -> next;
        ptr = ptr -> next;
    }

    ptr -> next = NULL;
    printf("Deleted Value: %d\n", ptr_prev->data);
    free(ptr_prev);
}

// search a specific value
struct node * searchNode(struct node * head, int value){
    struct node * ptr = head;

    if( head == NULL){
        printf("List is empty.\n");
        return NULL;
    }

    if(ptr->next == NULL){
        printf("%d is NOT Found.\n", value);
        return NULL;
    }

    if(ptr -> data == value){
        printf("%d FOUND!!\n", value);
        return ptr -> next;
    }

    searchNode(head->next, value);

}

//replace a specific value
void replaceNodeValue(int value , int change_to){
    struct node * add = searchNode(head, value);
    add -> data = change_to;
}

// display the list both in forward and backward
void printlist(){
    struct node * ptr = head;

    if(ptr == NULL){
        printf("List is Empty.\n");
        return;
    }

    puts(" >> PRINING FORWARD << \n");
    while(ptr -> next != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr -> next;
    }
   
    printf("Element: %d\n", ptr->data);

    puts(" >> PRINTING BACKWARD << \n");
    while(ptr->prev != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr -> prev;
    }
    printf("Element: %d\n", ptr -> data);
}

int main(){
    
    puts("## Before Operation ##");
    printlist();

    insertatFirst(15);
    insertatFirst(66);
    insertatFirst(1);
    insertatLast(47);
    insertatLast(89);
    insertAfterNode(2, 555);
    insertAfterNode(4, 999);

    puts("## After Insetion ##\n");
    printlist();

    deletionFirst();
    deletionFirst();
    deletionLast();
    deletionInBetween(3);
    searchNode(head, 555);
    replaceNodeValue(555,35);

    puts("## After Deletion ##\n");
    printlist();

}
