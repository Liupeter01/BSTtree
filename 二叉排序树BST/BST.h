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


////////////////////////////////////////////////////////////�������ĳ�ʼ������/////////////////////////////////////////////////////
void InitBSTree(BST * T);        //�������ĸ��ڵ��ʼ������
void DestroyBSTree(BST* T);   //������������
static void _DestroyBSTree(BSTNode* p);  //�������������Ӻ���

////////////////////////////////////////////////////////////�������Ľ��������/////////////////////////////////////////////////////
BOOL InsertBSTree(BST* T, ElemType arr);            // �����������Ĳ��빹��
static BOOL _InsertBSTree(BSTNode** node, ElemType arr);           //���빹�����Ӻ���,�޸�ָ����Ҫ����ָ��

BOOL InsertBSTreeIterate(BST* T, ElemType arr);         // �����������ĵ������빹��
static BOOL _InsertBSTreeIterate(BSTNode** node, ElemType arr);           // �����������ĵ������빹��

////////////////////////////////////////////////////////////�������ļ�ֵ��ȡ/////////////////////////////////////////////////////
ElemType FindMaximum(BST T);            //�����
static ElemType _FindMaximum(BSTNode* p);       //������Ӻ���

ElemType FindMininum(BST T);               //����С
static ElemType _FindMininum(BSTNode* p);               //����С�Ӻ���

////////////////////////////////////////////////////////////������������/////////////////////////////////////////////////////
void BSTSort(BST T);                    //����
static void _BSTSort(BSTNode* p);       //�����Ӻ���