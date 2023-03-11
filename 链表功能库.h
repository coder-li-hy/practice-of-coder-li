#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}Node;//定义结点Node
typedef struct node* Linklist;//定义链表
void Initlist(Linklist*);//初始化链表
int Getlength(Linklist);//获取链表长度（不包括头结点）
void headinsert(Linklist);//头插法
void bottominsert(Linklist);//尾插法
void printlist(Linklist);//打印链表所有成员
int get_int(void);//获得一个整数
int Listinsert(Linklist L, int i, int e);//向链表中插入一个元素
int ListDelete(Linklist L, int i);//删除链表中的一个元素