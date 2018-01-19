
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insertBegin(struct Node **head_ref, int data) //** whenever head might have to be changed as pointer to
{                                                  //head is global
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev, int data)
{
    if(prev == NULL)
    {
        printf("Null pointer to previous node");
        return;
    }
    struct Node * new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
}

void insertEnd(struct Node **head_ref, int data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL; //Necessary or else segmentation fault 11
    if(*head_ref == NULL)
    {
        (*head_ref) = new_node;
        return;
    }
    else
    {
        struct Node* last = (*head_ref);
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
    }
}

void deleteNode(struct Node** head_ref, int key)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = (*head_ref);
    struct Node* prev;
    if(temp != NULL && temp->data == key)
    {
        (*head_ref) = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("%d Not found",key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

int getCount(struct Node* head)
{
    if(head == NULL)
        return 0;
    else
        return (1 + getCount(head->next));
}

void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void printNthFromLast(struct Node *head, int n)
{
    struct Node *main_ptr = head;
    struct Node *ref_ptr = head;
    
    int count = 0;
    if(head != NULL)
    {
        while( count < n )
        {
            if(ref_ptr == NULL)
            {
                printf("%d is greater than the no. of "
                       "nodes in list", n);
                return;
            }
            ref_ptr = ref_ptr->next;
            count++;
        } /* End of while*/
        
        while(ref_ptr != NULL)
        {
            main_ptr = main_ptr->next;
            ref_ptr  = ref_ptr->next;
        }
        printf("Node no. %d from last is %d ",
               n, main_ptr->data);
    }
}

void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int detectloop(struct Node *list) // Floyd's method to detect loops in a linked list.
{
    struct Node  *slow_p = list, *fast_p = list;
    int count = 0;
    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            printf("Found Loop \n");
            while(1)
            {
                slow_p = slow_p->next;
                fast_p  = fast_p->next->next;
                count ++;
                if(slow_p == fast_p)
                    return count;
            }
        }
    }
    return 0;
}

/* Recursive Function to delete the entire linked list */
void deleteList(struct Node* head)
{
    if (head == NULL)
        return;
    deleteList(head->next);
    free(head);
}

int main()
{
    struct Node* head = NULL;
    insertEnd(&head,5);
    insertBegin(&head,2);
    insertBegin(&head,1);
    insertAfter(head->next,3);
    printf("List is \n");
    printList(head);
    deleteNode(&head,3);
    printf("List is \n");
    printList(head);
    printf("Number of nodes is %d \n",getCount(head));
    reverse(&head);
    printf("Reversed list is \n");
    printList(head);
    insertBegin(&head,0);
    insertBegin(&head,-1);
    insertBegin(&head,-2);
    insertBegin(&head,-3);
    struct Node* temp = head;
    while(temp->next !=NULL)
        temp = temp->next;
    temp->next = head;
    printf("Length of loop %d \n",detectloop(head));//Length only for Circular LL
    return 0;
}
