// =====================================================================================
//
//       Filename:  avl_test.c
//
//    Description:  平衡二叉树的测试程序 
//
//        Version:  1.0
//        Created:  2015年03月06日 15时28分37秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================
#include "avl.h"

static int arr[] = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
#define TBL_SIZE(a)     ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i, ilen;
    AVLTree root = NULL;

    printf("==高度：%d\n", avltree_height(root));
    printf("==依次添加：");
    ilen = TBL_SIZE(arr);

    for ( i = 0; i < ilen; i++ )
    {
        printf("%d ", arr[i]);
        root = avltree_insert(root, arr[i]);
        printf("\n==前序遍历：");
        preorder_avltree(root);
        printf("\n");
    }

    printf("\n==前序遍历：");
    preorder_avltree(root);

    printf("\n==中序遍历：");
    inorder_avltree(root);
    printf("\n==后序遍历：");
    postorder_avltree(root);
    printf("\n");

    printf("==高度：%d\n", avltree_height(root));
    printf("==最小值：%d\n", (avltree_minimum(root))->key);
    printf("==最大值：%d\n", (avltree_maximum(root))->key);
    printf("==树的详细信息：\n");
    print_avltree(root, root->key, 0);

    i = 8;
    printf("\n==删除根节点：%d", i);
    root = avltree_delete(root, i);

    printf("\n==高度：%d", avltree_height(root));
    printf("\n==中序遍历：");
    inorder_avltree(root);
    printf("\n==树的详细信息：\n");
    print_avltree(root, root->key, 0);

    destroy_avltree(root);

    return 0;
}