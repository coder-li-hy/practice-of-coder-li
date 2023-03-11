#include"链表功能库.h"
int main()
{
	Linklist L = NULL;
	Initlist(&L);
	bottominsert(L);
	printf("该链表的长度为：%d\n", Getlength(L));
	printlist(L);
	//bottominsert(L);
	//printf("该链表的长度为：%d\n", Getlength(L));
	//printlist(L);
	Listinsert(L, 5, 67);
	printf("该链表的长度为：%d\n", Getlength(L));
	printlist(L);
	ListDelete(L, 5);
	printf("该链表的长度为：%d\n", Getlength(L));
	printlist(L);
	return 0;
}

