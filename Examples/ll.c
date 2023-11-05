#include "ll.h"
int main()
{
    node *newlist = NULL; // Initialize a Linked List
    int size, data;
    printf("Enter the List: \n");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data);
        insert(&newlist, data);
    }
    display(&newlist);
    int del;
    printf("Something to delete. \n");
    scanf("%d", &del);
    del_node(&newlist, del);
    printf("Final List after Reverse: \n");
    reverse(&newlist);
    display(&newlist);
    printf("Sorting Now: \n");
    asc_sort(&newlist);
    display(&newlist);
    int pos;
    scanf("%d", &pos);
    int x = element(&newlist, pos);
    printf("The Element: %d", x);
}