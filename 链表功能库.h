#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}Node;//������Node
typedef struct node* Linklist;//��������
void Initlist(Linklist*);//��ʼ������
int Getlength(Linklist);//��ȡ�����ȣ�������ͷ��㣩
void headinsert(Linklist);//ͷ�巨
void bottominsert(Linklist);//β�巨
void printlist(Linklist);//��ӡ�������г�Ա
int get_int(void);//���һ������
int Listinsert(Linklist L, int i, int e);//�������в���һ��Ԫ��
int ListDelete(Linklist L, int i);//ɾ�������е�һ��Ԫ��