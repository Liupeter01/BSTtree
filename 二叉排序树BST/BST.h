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


////////////////////////////////////////////////////////////二叉树的初始化操作/////////////////////////////////////////////////////
void InitBSTree(BST * T);        //二叉树的根节点初始化程序
void DestroyBSTree(BST* T);   //二叉树的销毁
static void _DestroyBSTree(BSTNode* p);  //二叉树的销毁子函数

////////////////////////////////////////////////////////////二叉树的结点插入操作/////////////////////////////////////////////////////
BOOL InsertBSTree(BST* T, ElemType arr);            // 二叉排序树的插入构建
static BOOL _InsertBSTree(BSTNode** node, ElemType arr);           //插入构建的子函数,修改指针需要二级指针

BOOL InsertBSTreeIterate(BST* T, ElemType arr);         // 二叉排序树的迭代插入构建
static BOOL _InsertBSTreeIterate(BSTNode** node, ElemType arr);           // 二叉排序树的迭代插入构建

////////////////////////////////////////////////////////////二叉树的极值获取/////////////////////////////////////////////////////
ElemType FindMaximum(BST T);            //求最大
static ElemType _FindMaximum(BSTNode* p);       //求最大子函数

ElemType FindMininum(BST T);               //求最小
static ElemType _FindMininum(BSTNode* p);               //求最小子函数

////////////////////////////////////////////////////////////二叉树的排序/////////////////////////////////////////////////////
void BSTSort(BST T);                    //排序
static void _BSTSort(BSTNode* p);       //排序子函数