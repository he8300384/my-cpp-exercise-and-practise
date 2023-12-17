#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//接口思想 制作链表 存储数据
//综合训练 序列化 函数指针 

#define NAMESIZE 128

//基本数据内容
struct pepole
{
    char name[NAMESIZE];
    int age;
};

typedef struct pepole Item;

//链表节点
typedef struct node
{
    Item item;
    struct node*  next;
} Node ;

//最简易的链表开始端头
typedef Node* List; 


bool InitList(List* plist);
bool ListIsFull(List* plist);
bool ListIsEmpty(List* plist);
unsigned int ListItemCount(const List * plist);
bool AddItem(Item Item, List * plist);
static void CopyToNode(Item item, Node* pnode);
void Traverse(const List * plist, void(* pfun)(Item item));
void EmptyTheList(List * plist);

//以上内容可以放入 。h 作为 API

void printList(Item item)//输出项目内容
{
    printf("name: %s \tage: %d\n", item.name, item.age);
}

void save(Item item)//不完备的写文件操作 首先文件是追加模式 其次打开文件次数过多
{
    FILE * file;
    file = fopen("out/chain.txt", "a+");
    fprintf(file,"name:%s age:%d\n", item.name , item.age);
    fclose(file);
}

void load(const char* filename , List * list)//读取文件中的数据 填充链表
{
    FILE * file;
    file = fopen(filename, "r");
    Item p1 ;
    while( (fscanf(file,"name:%s age:%d\n", &p1.name , &p1.age)) != -1)
        AddItem(p1, list);//复用函数功能
    fclose(file);
}

int main()
{
    List pepoles;

    InitList(&pepoles);
    if(ListIsFull(&pepoles)) printf("no space\n");

    //批量加一些对象
    // for(int i = 0; i<20; i++)
    // {
        // Item p1 = {"heqin", i};
        // AddItem(p1, &pepoles); 
    // }
    load("out/chain.txt", &pepoles); //通过载入的方式填充链表

    //操作函数利用函数指针实现可拓展的功能
    Traverse(&pepoles, printList);
    //Traverse(&pepoles, save);

    EmptyTheList(&pepoles);

    return 0;
}

bool InitList(List* plist)
{
    * plist = NULL;
}

bool ListIsEmpty(List* plist)
{
    if(*plist == NULL) 
        return true;
    else 
        return false;
}

bool ListIsFull(List* plist)
{
    Node* pt = (Node *)malloc (sizeof(Node));

    if(pt != NULL)
    {
        return false;
        free(pt);
    }
    else
        return true;
}

unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = *plist;
    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

bool AddItem(Item Item, List * plist)
{
    Node* pnew;
    Node* scan  = *plist;

    pnew = (Node*)malloc(sizeof( Node));//分配一块堆内存

    if(pnew==NULL) return false;
    
    CopyToNode(Item, pnew);//栈内容拷贝到堆对象中
    pnew->next=NULL;

    if(scan ==NULL)
    *plist = pnew;

    else
    {
        while (scan->next != NULL)
             scan = scan->next;
        scan->next = pnew;
    } 
    return true;
}

void Traverse(const List * plist, void(* pfun)(Item item))
{
    Node * pnode = *plist;
    while (pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }        
}

void EmptyTheList(List * plist)
{
    Node* psave;
    while(*plist != NULL)
    {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

static void CopyToNode(Item item, Node* pnode)
{
    pnode->item = item;
}
