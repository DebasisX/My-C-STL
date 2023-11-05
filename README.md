# Linked-List-C-Library
Just #include "ll.h" and you're good to go.

Standard Template for creating a Linked List quicky.  Credit: Debasis Sidkar
Functions include:
    1. Insertion (including Head)
    2. Deletion
    3. Display
    4. Reverse
    5. Sort (Ascending, Descending)
To use this template
       Create a node using node* (variable name) and point it to null.
       node* var = NULL;
       This will be the HEAD node for your list.
    Now you can use the template with the syntax as follows:
    insert(&(head node variable), (integer data));
    insert_head(&(head node variable), (integer data));
    del_node(&(head node variable), (integer data));
    display(&(head node variable));
    reverse(&(head node variable));
    asc_sort(&(head node variable));
    desc_sort(&(head node variable));
*/