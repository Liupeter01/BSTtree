#include"BST.h"

int main()
{
		  BST T;		  
		  InitBSTree(&T);
		  ElemType arr[] = { 45,12,53,3,37,100,24,61,90,78 };
		  for (int i = 0; i < sizeof(arr) / sizeof(ElemType); ++i)
		  {
					InsertBSTree(&T, arr[i]);
		  }
		  DestroyBSTree(&T);
		  return 0;
}