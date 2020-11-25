#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#define ElemType int

typedef struct BSTNode
{
          ElemType data;
          struct BSTNode* lchild;
          struct BSTNode* rchild;
}BSTNode;

typedef struct BST
{
          BSTNode* root;
}BST;

BSTNode* CreateBSTNode(ElemType x);               //�������Ľ�㴴������


////////////////////////////////////////////////////////////�������ĳ�ʼ������//////////////////////////////////////////////////////////////////////////////////
void InitBSTree(BST * T);        //�������ĸ��ڵ��ʼ������
void DestroyBSTree(BST* T);   //������������
static void _DestroyBSTree(BSTNode* p);  //�������������Ӻ���

BOOL InsertBSTree(BST* T, ElemType arr);            // �����������Ĳ��빹��
static BOOL _InsertBSTree(BSTNode** node, ElemType arr);           //���빹�����Ӻ���,�޸�ָ����Ҫ����ָ��
