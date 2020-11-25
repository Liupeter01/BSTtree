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

BOOL InsertBSTree(BST* T, ElemType arr)           // 二叉排序树的插入构建
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