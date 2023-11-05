#include <ll.h>
int main()
{
    node *ll;
    int n = 0;

    int data;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &data);
        insert(&ll, data);
    }
    int x;
    printf("Position of Node to Insert & DATA to Insert: ");

    scanf("%d", &x);
    scanf("%d", &data);
    insert_pos(&ll, x, data);

    display(&ll);
}
