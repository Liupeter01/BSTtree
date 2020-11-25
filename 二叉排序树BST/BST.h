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

BSTNode* CreateBSTNode(ElemType x);               //二叉树的结点创建函数


////////////////////////////////////////////////////////////二叉树的初始化操作//////////////////////////////////////////////////////////////////////////////////
void InitBSTree(BST * T);        //二叉树的根节点初始化程序
void DestroyBSTree(BST* T);   //二叉树的销毁
static void _DestroyBSTree(BSTNode* p);  //二叉树的销毁子函数

BOOL InsertBSTree(BST* T, ElemType arr);            // 二叉排序树的插入构建
static BOOL _InsertBSTree(BSTNode** node, ElemType arr);           //插入构建的子函数,修改指针需要二级指针
