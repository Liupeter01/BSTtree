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

BOOL InsertBSTree(BST* T, ElemType arr)           // �����������ĵݹ���빹��
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

BOOL InsertBSTreeIterate(BST* T, ElemType arr)           // �����������ĵ������빹��
{
		  return _InsertBSTreeIterate(&(T->root), arr);
}

static BOOL _InsertBSTreeIterate(BSTNode** node, ElemType arr)           // �����������ĵ������빹��
{
		  if (*node == NULL)  //û�и��ڵ�
		  {
					*node = CreateBSTNode(arr);
					return TRUE;
		  }
		  else
		  {
					BSTNode* ptemp = *node;		
					BSTNode* parent = NULL;		  //��¼ǰ��
					while (ptemp != NULL && ptemp->data != arr)	//�������ظ�
					{
							  parent = ptemp;
							  if (ptemp->data > arr)
							  {
										ptemp = ptemp->rchild;					//���ڸ��ڵ㣬ȥ������
							  }
							  else if (ptemp->data < arr)
							  {
										ptemp = ptemp->lchild;					//С�ڸ��ڵ㣬ȥ������
							  }
					}
					ptemp = CreateBSTNode(arr);	  //�������
					if (parent->data > arr)					//���Ӧ�ò��뵽�丸�ڵ��������
					{
							  parent->rchild = ptemp;
					}
					else if (parent->data < arr)			//���Ӧ�ò��뵽�丸�ڵ��������
					{
							  parent->lchild = ptemp;
					}
					return TRUE;
		  }
		  return FALSE;
}

BOOL RemoveBSTree(BST T, ElemType key)         //ָ�����ɾ��
{
		  assert(T.root != NULL);
		  return _RemoveBSTree(T.root, key);
}

static BOOL _RemoveBSTree(BSTNode* p, ElemType key) //ɾ������Ӻ���
{

}

BSTNode* BSTreeSearch(BST T, ElemType key)        //ָ���������
{
		  assert(T.root != NULL);
		  return _BSTreeSearch(T.root, key);
}

static BSTNode* _BSTreeSearch(BSTNode* p, ElemType key)  //��������Ӻ���
{
		  BOOL flag = 0;				//�Ƿ��ҵ���ʶ
		  BSTNode* temp = p;
		  while (temp != NULL)
		  {
					if (temp->data == key)
					{
							  flag = 1;
							  break;
					}
					else if (temp->data > key)         //��������ֵ���ڸ��ڵ�
					{
							  temp = temp->rchild;
					}
					else
					{
							  temp = temp->lchild;
					}
		  }
		  return (flag ? temp : NULL);

}

ElemType FindMaximum(BST T)           //�����
{
		  assert(T.root != NULL);
		  return _FindMaximum(T.root);
}

static ElemType _FindMaximum(BSTNode* p)       //������Ӻ���
{
		  BSTNode* ptemp = p;
		  while (ptemp->rchild != NULL)
		  {
					ptemp = ptemp->rchild;
		  }
		  return ptemp->data;
}

ElemType FindMininum(BST T)               //����С
{
		  assert(T.root != NULL);
		  return _FindMininum(T.root);
}

static ElemType _FindMininum(BSTNode* p)               //����С�Ӻ���
{
		  BSTNode* ptemp = p;
		  while (ptemp->lchild != NULL)
		  {
					ptemp = ptemp->lchild;
		  }
		  return ptemp->data;
}

void BSTSort(BST T)                 //����
{
		  assert(T.root != NULL);
		  _BSTSort(T.root);
		  printf("\n");
}
static void _BSTSort(BSTNode* p)      //�����Ӻ���
{
		  if (p != NULL)
		  {
					_BSTSort(p->lchild);
					printf("%d ", p->data);
					_BSTSort(p->rchild);
		  }
}