#include"�����ܿ�.h"
int main()
{
	Linklist L = NULL;
	Initlist(&L);
	bottominsert(L);
	printf("������ĳ���Ϊ��%d\n", Getlength(L));
	printlist(L);
	//bottominsert(L);
	//printf("������ĳ���Ϊ��%d\n", Getlength(L));
	//printlist(L);
	Listinsert(L, 5, 67);
	printf("������ĳ���Ϊ��%d\n", Getlength(L));
	printlist(L);
	ListDelete(L, 5);
	printf("������ĳ���Ϊ��%d\n", Getlength(L));
	printlist(L);
	return 0;
}

