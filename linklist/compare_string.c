/*
Given two linked lists, represented as linked lists (every character is a node in linked list). 
Write a function compare() that works similar to strcmp(), i.e., 
it returns 0 if both strings are same, 
1 if first linked list is lexicographically greater, and 
-1 if second string is lexicographically greater.

*/

/* Program to insert in a sorted list */
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    char data;
    struct node* next;
};

void charInsert(struct node** head_ref, struct node* new_node)
{
    /* special case: first element (null head)*/
    if (*head_ref == NULL)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } 
    else 
    {
        /* SEARCH */
        struct node* ptr = *head_ref;  
        while (ptr->next != NULL) 
        {
            ptr = ptr->next;
        }
        /*  INSERT */
        new_node->next = ptr->next;
        ptr->next = new_node;        
    }

}



/* A utility function to create a new node */
struct node *newNode(char new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    //strcpy((char*)(new_node->data), &new_data); 
    new_node->data = new_data;
    new_node->next =  NULL;
 
    return new_node;
}

/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%c  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int compare(struct node *list1, struct node *list2)
{
    struct node *list1_ptr = list1;
    struct node *list2_ptr = list2;
    while(list1_ptr && list2_ptr && (list1_ptr->data == list2_ptr->data))
    {
        list1_ptr = list1_ptr->next;
        list2_ptr = list2_ptr->next;
    }
#if 0
    /* totaly wrong !!! */
    /* same list */    
    if (list1_ptr && list2_ptr) 
    {   
        if (list1_ptr->data == list2_ptr->data)
            return 0;
        return 
    }
#endif    
    /* different string  */  
    if (list1_ptr && list2_ptr) 
    {   
        return (list1_ptr->data > list2_ptr->data) ? 1 : -1;
    }

    /* length: list1 > list2 */    
    if (list1_ptr) 
    {
        return 1;
    }
    /* length: list2 > list1 */    
    if (list2_ptr) 
    {
        return -1;
    }    

    return 0;
}

int main() 
{
    /* Start with the empty list */
    struct node *head = NULL;
    struct node *new_node;
    struct node *head2 = NULL;
    struct node *new_node2; 
    
    new_node = newNode('g');
    charInsert(&head, new_node);
    new_node = newNode('e');
    charInsert(&head, new_node);
    new_node = newNode('e');
    charInsert(&head, new_node);
    new_node = newNode('k');
    charInsert(&head, new_node);
    new_node = newNode('s');
    charInsert(&head, new_node);
    //new_node = newNode('b');
    //charInsert(&head, new_node);    
    
    new_node2 = newNode('g');
    charInsert(&head2, new_node2);
    new_node2 = newNode('e');
    charInsert(&head2, new_node2);
    new_node2 = newNode('e');
    charInsert(&head2, new_node2);
    new_node2 = newNode('k');
    charInsert(&head2, new_node2);
    new_node2 = newNode('s');
    charInsert(&head2, new_node2);
    new_node2 = newNode('b');
    charInsert(&head2, new_node2);  

    printf("\n Created Linked List\n");
    printList(head);
    printList(head2); 
    printf("compare result: %d\n",compare(head, head2));
    
}


