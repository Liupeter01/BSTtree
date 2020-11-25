#include"BST.h"

BSTNode* CreateBSTNode(ElemType x)            //�������Ľ�㴴������
{
		  BSTNode* s = (BSTNode*)malloc(sizeof(BSTNode));
		  assert(s != NULL);
		  s->lchild = s->rchild = NULL;
		  s->data = x;
		  return s;
}

void InitBSTree(BST* T)        //�������ĸ��ڵ��ʼ������
{
		  T->root = NULL;	  //��ʼ��Ϊ����
}

void DestroyBSTree(BST* T)   //������������
{
		  _DestroyBSTree(T->root);
}

static void _DestroyBSTree(BSTNode* p)  //�������������Ӻ���
{
		  if (p != NULL)
		  {
					BSTNode* temp = p;
					_DestroyBSTree(temp->lchild);
					_DestroyBSTree(temp->rchild);
					free(p);
		  }
}

BOOL InsertBSTree(BST* T, ElemType arr)           // �����������Ĳ��빹��
{
		  return _InsertBSTree(&(T->root), arr);
}

static BOOL _InsertBSTree(BSTNode** node, ElemType arr)           //���빹�����Ӻ���,�޸�ָ����Ҫ����ָ��
{
		  if (*node == NULL)  //��������һ������
		  {
					*node = CreateBSTNode(arr);
					return TRUE;
		  }
		  else
		  {
					if ((*node)->data > arr)
					{
							  _InsertBSTree(&((*node)->rchild), arr);			//���ڸ��ڵ㣬ȥ������
					}
					else if ((*node)->data < arr)
					{
							  _InsertBSTree(&((*node)->lchild), arr);			//С�ڸ��ڵ㣬ȥ������
					}
					else if ((*node)->data == arr)					  //����������ظ���Ԫ��
					{
							  return FALSE;
					}
		  }
		  return FALSE;
}