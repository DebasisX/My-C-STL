#include <ll.h>
int main ()
{
    node* list;
    int data;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &data);
        insert_head(&list, data);
    }
    int x = 0;
    for (int j = 0; j < 5; j++)
    {
        x += element(&list, j);
    }
    printf("%d", x);
    display (&list);
    reverse(&list);
    display(&list);
}