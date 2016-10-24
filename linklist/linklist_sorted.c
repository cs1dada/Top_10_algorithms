/*
Initial Linked List
2 -> 5 -> 7 -> 10 -> 15 

Linked List after insertion of 9
2 -> 5 -> 7 -> "9" -> 10 -> 15 

*/


/* Program to insert in a sorted list */
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
void sortedInsert(struct node** head_ref, struct node* new_node)
{
    /* special case: first element (null head) / small than head */
    if (*head_ref == NULL || new_node->data <= (*head_ref)->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } 
    else 
    {
        /* SEARCH */
        struct node* ptr = *head_ref;
        //bug: SEARCH from second element 
        //while ((ptr != NULL)&&(ptr->data < new_node->data))         
        while ((ptr->next != NULL)&&(ptr->next->data < new_node->data)) 
        {
            ptr = ptr->next;
        }
        /*  INSERT */
        new_node->next = ptr->next;
        ptr->next = new_node;
        
    }

}

/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST sortedInsert */
 
/* A utility function to create a new node */
struct node *newNode(int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
    new_node->next =  NULL;
 
    return new_node;
}
 
/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    /* Start with the empty list */
    struct node *head = NULL;
    struct node *new_node = newNode(2);
    sortedInsert(&head, new_node);
    new_node = newNode(5);
    sortedInsert(&head, new_node);    
    new_node = newNode(7);
    sortedInsert(&head, new_node);
    new_node = newNode(10);
    sortedInsert(&head, new_node);
    new_node = newNode(15);
    sortedInsert(&head, new_node);   
    /* new */
    new_node = newNode(9);
    sortedInsert(&head, new_node);     
    new_node = newNode(0);
    sortedInsert(&head, new_node);      
    new_node = newNode(16);
    sortedInsert(&head, new_node);    
    new_node = newNode(-1);
    sortedInsert(&head, new_node);        
 
    printf("\n Created Linked List\n");
    printList(head);

}
