#include"BST.h"

BSTNode* CreateBSTNode(ElemType x)            //二叉树的结点创建函数
{
		  BSTNode* s = (BSTNode*)malloc(sizeof(BSTNode));
		  assert(s != NULL);
		  s->lchild = s->rchild = NULL;
		  s->data = x;
		  return s;
}

void InitBSTree(BST* T)        //二叉树的根节点初始化程序
{
		  T->root = NULL;	  //初始化为空树
}

void DestroyBSTree(BST* T)   //二叉树的销毁
{
		  _DestroyBSTree(T->root);
}

static void _DestroyBSTree(BSTNode* p)  //二叉树的销毁子函数
{
		  if (p != NULL)
		  {
					BSTNode* temp = p;
					_DestroyBSTree(temp->lchild);
					_DestroyBSTree(temp->rchild);
					free(p);
		  }
}

BOOL InsertBSTree(BST* T, ElemType arr)           // 二叉排序树的递归插入构建
{
		  return _InsertBSTree(&(T->root), arr);
}

static BOOL _InsertBSTree(BSTNode** node, ElemType arr)           //插入构建的子函数,修改指针需要二级指针
{
		  if (*node == NULL)  //二叉树是一个空树
		  {
					*node = CreateBSTNode(arr);
					return TRUE;
		  }
		  else
		  {
					if ((*node)->data > arr)
					{
							  _InsertBSTree(&((*node)->rchild), arr);			//大于根节点，去右子树
					}
					else if ((*node)->data < arr)
					{
							  _InsertBSTree(&((*node)->lchild), arr);			//小于根节点，去左子树
					}
					else if ((*node)->data == arr)					  //不允许出现重复的元素
					{
							  return FALSE;
					}
		  }
		  return FALSE;
}

BOOL InsertBSTreeIterate(BST* T, ElemType arr)           // 二叉排序树的迭代插入构建
{
		  return _InsertBSTreeIterate(&(T->root), arr);
}

static BOOL _InsertBSTreeIterate(BSTNode** node, ElemType arr)           // 二叉排序树的迭代插入构建
{
		  if (*node == NULL)  //没有根节点
		  {
					*node = CreateBSTNode(arr);
					return TRUE;
		  }
		  else
		  {
					BSTNode* ptemp = *node;		
					BSTNode* parent = NULL;		  //记录前驱
					while (ptemp != NULL && ptemp->data != arr)	//不可以重复
					{
							  parent = ptemp;
							  if (ptemp->data > arr)
							  {
										ptemp = ptemp->rchild;					//大于根节点，去右子树
							  }
							  else if (ptemp->data < arr)
							  {
										ptemp = ptemp->lchild;					//小于根节点，去左子树
							  }
					}
					ptemp = CreateBSTNode(arr);	  //创建结点
					if (parent->data > arr)					//结点应该插入到其父节点的右子树
					{
							  parent->rchild = ptemp;
					}
					else if (parent->data < arr)			//结点应该插入到其父节点的左子树
					{
							  parent->lchild = ptemp;
					}
					return TRUE;
		  }
		  return FALSE;
}

BOOL RemoveBSTree(BST T, ElemType key)         //指定结点删除
{
		  assert(T.root != NULL);
		  return _RemoveBSTree(T.root, key);
}

static BOOL _RemoveBSTree(BSTNode* p, ElemType key) //删除结点子函数
{

}

BSTNode* BSTreeSearch(BST T, ElemType key)        //指定结点搜索
{
		  assert(T.root != NULL);
		  return _BSTreeSearch(T.root, key);
}

static BSTNode* _BSTreeSearch(BSTNode* p, ElemType key)  //搜索结点子函数
{
		  BOOL flag = 0;				//是否找到标识
		  BSTNode* temp = p;
		  while (temp != NULL)
		  {
					if (temp->data == key)
					{
							  flag = 1;
							  break;
					}
					else if (temp->data > key)         //搜索的数值大于根节点
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

ElemType FindMaximum(BST T)           //求最大
{
		  assert(T.root != NULL);
		  return _FindMaximum(T.root);
}

static ElemType _FindMaximum(BSTNode* p)       //求最大子函数
{
		  BSTNode* ptemp = p;
		  while (ptemp->rchild != NULL)
		  {
					ptemp = ptemp->rchild;
		  }
		  return ptemp->data;
}

ElemType FindMininum(BST T)               //求最小
{
		  assert(T.root != NULL);
		  return _FindMininum(T.root);
}

static ElemType _FindMininum(BSTNode* p)               //求最小子函数
{
		  BSTNode* ptemp = p;
		  while (ptemp->lchild != NULL)
		  {
					ptemp = ptemp->lchild;
		  }
		  return ptemp->data;
}

void BSTSort(BST T)                 //排序
{
		  assert(T.root != NULL);
		  _BSTSort(T.root);
		  printf("\n");
}
static void _BSTSort(BSTNode* p)      //排序子函数
{
		  if (p != NULL)
		  {
					_BSTSort(p->lchild);
					printf("%d ", p->data);
					_BSTSort(p->rchild);
		  }
}