#include <stdio.h>
#include <stdlib.h>
typedef struct list_item 
{
    int x;
    struct list_item* next;
} list_item;

void free_nodes(list_item* node)//该函数用于释放链表节点 
{
    while (node!=NULL) 
    {
        list_item* temp=node;
        node = node->next;
        free(temp);
    }
}

void erase_list(list_item* head)//无法改变头指针，所以要在主函数中手动改变 
{
    if (head!=NULL) 
    {
        free_nodes(head);
    }
}

int main() 
{
    list_item* head=NULL;
    erase_list(head);
    head=NULL;//手动改变
    return 0;
}