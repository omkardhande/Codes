# Codes
Callback function:
If a reference of a function is passed to another function as an argument to call it, then it (the function whose reference was passed) will be called as a Callback function.
Applications: qsort( ) // Quick sort which sorts all datatypes – The compare function is a callback function.

Linked List:Memory efficient doubly linked list (DLL with both addresses xored into one)
Reversing a linked list:
    while (current != NULL)
    {
         next  = current->next;
         current->next = prev;
         prev = current;
        current = next;
     }
     *head_ref = prev;
