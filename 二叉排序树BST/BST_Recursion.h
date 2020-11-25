/*�ݹ�汾*/
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define ElemType int

typedef struct BSTNode
{
          ElemType data;
          struct BSTNode* lchild;
          struct BSTNode* rchild;
}BSTNode, * BiTree;

/*�����������Ԫ�صĵݹ����*/
int BST_insert_Recursion(BiTree* T, ElemType key);

/*���������������Ԫ�صݹ�汾*/
BSTNode* BST_Search_Recursion(BiTree T, ElemType key);