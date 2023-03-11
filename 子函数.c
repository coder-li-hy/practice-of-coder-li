#define _CRT_SECURE_NO_WARNINGS 1 
#include"�����ܿ�.h"
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
void Initlist(Linklist* L)//��ʼ������
{
	*L = (Linklist)malloc(sizeof(Node));
	if (*L == NULL)
	{
		printf("�����ڴ�ʧ��");
		exit(1);
	}
	(*L)->next = NULL;//ͷ����ָ��������
	(*L)->data = 0;
}

int Getlength(Linklist L)//��ȡ�����ȣ�������ͷ��㣩
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
	Linklist p = L->next;//ʹ�ṹ��ָ��ָ���һ�����
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
		Linklist newnode = (Linklist)malloc(sizeof(Node));//�����µĽ��
		if (newnode == NULL)
		{
			printf("�����ڴ�ʧ��");
			exit(1);
		}
		newnode->data = t;
		newnode->next = L->next;
		L->next = newnode;//ͨ��->���ı�next��ֵ��ͨ��ָ�����޸���������Ȼ��Ч
		i++;
	} while (t != 0);
}

void bottominsert(Linklist L)
{
	int t;
	Node* p = L;//��ʼ������ָ��ָ��ͷ�ڵ�
	//�ռ任ʱ����Զ���ָ��p��¼β����λ��
	Node* r = L;//r���ڼ�¼β��
	//if (p->next == NULL)printf("p����ָ��NULL\n");
	do
	{
		t = get_int();
		if (t == 0) return ;
		//while (p->next != NULL)//ʹָ���������������һ�����
		//{
		//	p = p->next;
		//}
		//�ռ任ʱ����Զ���ָ��p��¼β����λ��
		Node* newnode = (Node*)malloc(sizeof(Node));//�����ڴ�ռ�
		if (newnode == NULL)
		{
			printf("�����ڴ�ʧ��");
			exit(1);
		}
		newnode->data = t;
		newnode->next = NULL;//�ÿ���β����ָ����
		//�����½��
		r->next = newnode;
		r = newnode;//ʹr�����Ƶ�β��
		
	} while (t != 0);
}

int Listinsert(Linklist L, int i, int e)
{
	Node* p = L; int j = 0;
	while (p && j < i - 1)//�ҵ���i-1����㣨Ҫ���䲻Ϊ�գ�
	{
		p = p->next;
		j++;
	}

	if (p == NULL || j > i - 1)
	{
		printf("δ�ҵ���λ�á�\n"); return 1;
	}
	Node* newnode = (Node*)malloc(sizeof(Node));//�����µĽ��
	newnode->data = e;//Ϊ�µĽ�㸳ֵ
	if (newnode == NULL)
	{
		printf("�����ڴ�ʧ�ܡ�\n");
		return 1;
	}
	newnode->next = p->next;//�ؼ�����
	p->next = newnode;
}

int ListDelete(Linklist L, int i)
{
	Node* p = L;//ʹ����ָ��ָ����Ԫ���
	int j = 0;//��ʼ��������
	Node* q;//������ָ���Ա��¼����ɾ���Ľڵ�
	while (p->next && j < i - 1)//ʹ����ָ���������i-1��Ԫ����Ҫ���i��Ԫ�ز���Ϊ��
	{
		p = p->next;
		j++;
	}
	if (p->next == NULL || j > i - 1)//����i������Ƿ�Ϊ�գ������λ���Ƿ�Ϸ�
	{
		printf("λ�÷Ƿ���\n");
		return 1;
	}
	q = p->next;//��¼��i�����ĵ�ַ
	p->next = q->next;//������
	free(q);//�ͷ��ڴ�ɾ�����
}