#define _CRT_SECURE_NO_WARNINGS 1 
#include"链表功能库.h"
int get_int(void)
{
	int t;

	printf("enter 0 to quit.\n");
	while (scanf("%d", &t) != 1)
	{
		if (t == 0) return t;
		char ch;
		while ((ch = getchar()) != '\n')
			putchar(ch); 
		printf(" is not an integer. please enter an integer like 25,34,88\n");
	}
	printf("successful input:%d\n", t);
	return t;
}
void Initlist(Linklist* L)//初始化链表
{
	*L = (Linklist)malloc(sizeof(Node));
	if (*L == NULL)
	{
		printf("分配内存失败");
		exit(1);
	}
	(*L)->next = NULL;//头结点的指针域悬空
	(*L)->data = 0;
}

int Getlength(Linklist L)//获取链表长度（不包括头结点）
{
	int count = 0;
	Linklist p = L->next;
	while (p != NULL) {
		p = p->next;
		count++;
	}
	return count;
}

void printlist(Linklist L)
{
	Linklist p = L->next;//使结构体指针指向第一个结点
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
}

void headinsert(Linklist L)
{
	int t = 0, i = 0;
	do
	{
		t = get_int();
		if (t == 0) return ;
		Linklist newnode = (Linklist)malloc(sizeof(Node));//创建新的结点
		if (newnode == NULL)
		{
			printf("分配内存失败");
			exit(1);
		}
		newnode->data = t;
		newnode->next = L->next;
		L->next = newnode;//通过->来改变next的值，通过指针来修改在外面依然有效
		i++;
	} while (t != 0);
}

void bottominsert(Linklist L)
{
	int t;
	Node* p = L;//初始化工作指针指向头节点
	//空间换时间可以定义指针p记录尾结点的位置
	Node* r = L;//r用于记录尾部
	//if (p->next == NULL)printf("p现在指向NULL\n");
	do
	{
		t = get_int();
		if (t == 0) return ;
		//while (p->next != NULL)//使指针遍历到链表的最后一个结点
		//{
		//	p = p->next;
		//}
		//空间换时间可以定义指针p记录尾结点的位置
		Node* newnode = (Node*)malloc(sizeof(Node));//开辟内存空间
		if (newnode == NULL)
		{
			printf("分配内存失败");
			exit(1);
		}
		newnode->data = t;
		newnode->next = NULL;//置空新尾结点的指针域
		//插入新结点
		r->next = newnode;
		r = newnode;//使r重新移到尾部
		
	} while (t != 0);
}

int Listinsert(Linklist L, int i, int e)
{
	Node* p = L; int j = 0;
	while (p && j < i - 1)//找到第i-1个结点（要求其不为空）
	{
		p = p->next;
		j++;
	}

	if (p == NULL || j > i - 1)
	{
		printf("未找到该位置。\n"); return 1;
	}
	Node* newnode = (Node*)malloc(sizeof(Node));//建立新的结点
	newnode->data = e;//为新的结点赋值
	if (newnode == NULL)
	{
		printf("分配内存失败。\n");
		return 1;
	}
	newnode->next = p->next;//关键操作
	p->next = newnode;
}

int ListDelete(Linklist L, int i)
{
	Node* p = L;//使工作指针指向首元结点
	int j = 0;//初始化计数器
	Node* q;//再来个指针以便记录将被删除的节点
	while (p->next && j < i - 1)//使工作指针遍历到第i-1个元素且要求第i个元素不能为空
	{
		p = p->next;
		j++;
	}
	if (p->next == NULL || j > i - 1)//检查第i个结点是否为空，输入的位置是否合法
	{
		printf("位置非法！\n");
		return 1;
	}
	q = p->next;//记录第i个结点的地址
	p->next = q->next;//重新连
	free(q);//释放内存删除结点
}