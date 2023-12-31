#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//实现链表存储 人员信息
//实验链表各类操作

#define LEN 64

struct Info
{
    char name[LEN] ;
    int number ;
};

typedef struct Info Item;

typedef struct node
{
    Item item;
    struct node* next;
}Node;

typedef struct  list
{
    Node * head;
    Node * end;
    int num;
}List;

void initList(List* list)
{
     list->head = NULL;//链表头
     list->end = NULL;//链表尾
     list->num = 0;//链表元素数量
}

//遍历到链表尾部
Node* listEnd(List * list)
{
    Node * ptr = list->head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr;
}

//追加元素
bool append(List* list, Item item)
{
    if(list->head == NULL)
    {
        list->head = (Node*)malloc(sizeof(Node));
        list->end = list->head;
        list->head->item = item;
        list->head->next = NULL;
        list->num = 1;
        return true;
    }

    Node * ptr =  list->end;
    
    ptr->next = (Node*)malloc(sizeof(Node));
    ptr->next->item = item;
    ptr->next->next = NULL;

    list->end = ptr->next;
    list->num ++;
    return true;
}

//打印内容
void printList(List* list)
{
    Node* ptr = list->head;

    while(ptr != NULL)
    {   
        printf("name = %s  age = %d\n", ptr->item.name, ptr->item.number);
        ptr = ptr->next;
    }
}

//显示链表长度
void listLength(List* list)
{
    printf("list length = %d\n", list->num);
}

//删去尾节点
void pop(List* list)
{
    if(list->head == NULL)
        return;

    Node* ptr = list->head;

    while(ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }

    free(ptr->next);
    ptr->next =NULL;

    list->end = ptr;
    list->num -= 1;
}

//根据item编号搜索内容
int findItem(List* list, Item item)
{
    Node* ptr = list->head;
    int location = 0;
    while(ptr != NULL)
    {
        if(ptr->item.number == item.number)
            return location;
        location ++;
        ptr = ptr->next;
    }
    return -1;
}

//释放堆空间
void clearList(List* list)
{
    Node* ptr = list->head;
    while(ptr != NULL)
    {
        Node * temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    initList(list);
}

//反转链表
void reverse(List* list)
{
    Node* ptr = list->head;
    if(ptr == NULL)
        return;
    Node* temp = NULL; 
    while (ptr != NULL)
    {
        Node* temp2 = ptr->next;
        ptr->next = temp; 
        temp = ptr;
        ptr = temp2;
    }
    list->end = list->head;
    list->head = temp;
}

//存储内容
void saveList(List* list, const char* position)
{
    FILE* file = fopen(position, "w+");
    Node* ptr = list->head;

    while(ptr != NULL)
    {
        fprintf(file, "name:%s age:%d\n",ptr->item.name, ptr->item.number);
        ptr = ptr->next;
    }

    fclose(file);
}

// 读取文件内容
void loadFile(List* list, const char* position)
{
    FILE* file = fopen(position, "r");
    Item i;

    while((fscanf(file, "name:%s age:%d\n", &i.name, &i.number)) != -1)
    {
        append(list, i);
    }
}

//读取输入内容
void inputItem(List* list)
{
    Item i;
    printf("input new item:\n");
    scanf("%s %d",&i.name, &i.number);
    if(i.name == NULL || i.number <= 0)
        printf("error input\n");
    append(list, i);
}

void testList();

int main()
{
    List list;
    initList(&list);

    loadFile(&list, "out/chainList.txt");
    printList(&list);
    printf("\n");
    //Item i = {"sfs", 98};
    //append(&list, i);
    //inputItem(&list);
    reverse(&list);
    printList(&list);

    saveList(&list, "out/chainList.txt");
    clearList(&list);
}




//一些测试函数
void testList()
{
    List pepoleList;
    initList(&pepoleList);
    
    Item i={"aff",12} ;
    Item i1={"ccc",22} ;
    Item i2={"www",32} ;
    Item i3={"eee",42} ;
    Item i4={"xxe",52} ;
    Item i5={"weu",62} ;

    append(&pepoleList,i);
    listLength(&pepoleList);

    append(&pepoleList,i1);
    append(&pepoleList,i2);
    append(&pepoleList,i3);
    append(&pepoleList,i4);
    append(&pepoleList,i5);

    listLength(&pepoleList);

    printList(&pepoleList);
    listLength(&pepoleList);
    pop(&pepoleList);
    listLength(&pepoleList);
    printList(&pepoleList);

    printf("%s item at: %d\n",i4.name, findItem(&pepoleList, i4));
    saveList(&pepoleList, "out/chainList.txt");

    clearList(&pepoleList);
}