#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define LEN 64

struct Info
{
    char name[LEN];
    int number;
};

typedef struct Info Item;

typedef struct node
{
    Item item;
    struct node* next;
}Node;

void Init();

int main()
{
//数据结构体
    Item i1 = {"ads", 12};
    Item i2 = {"wdd", 11};
    Item i3 = {"vce", 10};
    Item i4 = {"gef", 9};

//链表节点 分配堆空间
    Node *n2 = (Node *)malloc(sizeof(Node));
    Node *n1 = (Node *)malloc(sizeof(Node));
    Node *n3 = (Node *)malloc(sizeof(Node));
    Node *n4 = (Node *)malloc(sizeof(Node));


    n1->item = i1;
    n1->next = n2;

    n2->item = i2;
    n2->next = n3;

    n3->item = i3;
    n3->next = n4;

    n4->item = i4;
    n4->next = NULL; 


    Node *  ptr = n1;

    while(ptr != NULL)
    {
        printf("%s\n", ptr->item);
        ptr = ptr->next;
    }

//释放堆空间
    ptr = n1;
    while(ptr != NULL)
    {
        Node * temp = ptr;
        ptr = ptr->next;
        free(temp);
    }   
    
}
