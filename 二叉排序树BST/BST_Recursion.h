/*递归版本*/
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

/*二叉查找树的元素的递归插入*/
int BST_insert_Recursion(BiTree* T, ElemType key);

/*二叉查找树的搜索元素递归版本*/
BSTNode* BST_Search_Recursion(BiTree T, ElemType key);