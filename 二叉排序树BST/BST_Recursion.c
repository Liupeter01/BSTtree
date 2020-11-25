#include"BST_Recursion.h"

/*�����������Ԫ�صĵݹ����*/
int BST_insert_Recursion(BiTree* T, ElemType key)
{
          if (*T == NULL)      //�����������ڸ��ڵ�ն�����
          {
                    *T = InitBSTree(T, key);      //��ʼ�����ڵ�
                    return 1;           //�ɹ�
          }
          else      //�ǿն�����
          {
                    if ((*T)->data == key)        //�����������������������ͬ
                    {
                              return 0; //ʧ��
                    }
                    else if ((*T)->data > key)     //�����������ݴ��ڲ�������
                    {
                              return BST_insert_Recursion(&((*T)->lchild), key);
                    }
                    else                //������������С�ڲ���������ͬ
                    {
                              return BST_insert_Recursion(&((*T)->rchild), key);
                    }
          }
}

/*���������������Ԫ�صݹ�汾*/
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