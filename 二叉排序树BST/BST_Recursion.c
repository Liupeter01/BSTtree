#include"BST_Recursion.h"

/*二叉查找树的元素的递归插入*/
int BST_insert_Recursion(BiTree* T, ElemType key)
{
          if (*T == NULL)      //二叉树不存在根节点空二叉树
          {
                    *T = InitBSTree(T, key);      //初始化根节点
                    return 1;           //成功
          }
          else      //非空二叉树
          {
                    if ((*T)->data == key)        //二叉树的数据与插入数据相同
                    {
                              return 0; //失败
                    }
                    else if ((*T)->data > key)     //二叉树的数据大于插入数据
                    {
                              return BST_insert_Recursion(&((*T)->lchild), key);
                    }
                    else                //二叉树的数据小于插入数据相同
                    {
                              return BST_insert_Recursion(&((*T)->rchild), key);
                    }
          }
}

/*二叉查找树的搜索元素递归版本*/
BSTNode* BST_Search_Recursion(BiTree T, ElemType key)
{
          if (T->data > key)
          {
                    BST_Search_Recursion(T->lchild, key);
          }
          else if (T->data == key)
          {
                    return T;
          }
          else
          {
                    BST_Search_Recursion(T->rchild, key);
          }
}