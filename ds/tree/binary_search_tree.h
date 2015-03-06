// =====================================================================================
//
//       Filename:  binary_search_tree.h
//
//    Description: 二叉查找树的实现 
//
//        Version:  1.0
//        Created:  2015年03月06日 00时03分27秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================
#include <stdio.h>
#include <stdlib.h>

typedef int Type;

typedef struct BSTreeNode
{
    Type    key;
    struct  BSTreeNode *left;
    struct  BSTreeNode *right;
    struct  BSTreeNode *parent;
}Node, *BSTree;

static Node* create_bstree_node(Type key, Node* parent, Node* left, Node* right)
{
    Node* p;

    if ( (p = (Node*)malloc(sizeof(Node))) == NULL )
        return NULL;
    p->key = key;
    p->left = left;
    p->right = right;
    p->parent = parent;

    return p;
}

void preorder_bstree(BSTree tree)
{
    if ( tree != NULL )
    {
        printf("%d ", tree->key);
        preorder_bstree(tree->left);
        preorder_bstree(tree->right);
    }
}

void inorder_bstree(BSTree tree)
{
    if ( tree != NULL )
    {
        inorder_bstree(tree->left);
        printf("%d ", tree->key);
        inorder_bstree(tree->right);
    }
}

void postorder_bstree(BSTree tree)
{
    if ( tree != NULL )
    {
        postorder_bstree(tree->left);
        postorder_bstree(tree->right);
        printf("%d ", tree->key);
    }
}

Node* bstree_search(BSTree x, Type key)
{
    if ( x == NULL || x->key == key )
        return x;
    if ( key < x->key )
        return bstree_search(x->left, key);
    else
        return bstree_search(x->right, key);
}
Node* iterative_bstree_search(BSTree x, Type key)
{
    while ( (x != NULL) && (x->key == key) )
    {
        if ( key < x->key )
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

Node* bstree_maximum(BSTree tree)
{
    if ( tree == NULL )
        return NULL;
    while ( tree->right != NULL )
        tree = tree->right;
    return tree;
}

Node* bstree_minimum(BSTree tree)
{
    if ( tree == NULL )
        return NULL;
    while ( tree->left != NULL )
        tree = tree->left;
    return tree;
}

//节点的前驱：是该节点的左子树中的最大节点
//节点的后继：是该节点的右子树中的最小节点
Node* bstree_predecessor(Node* x)
{
    //如果x存在左孩子，则x的前驱节点为以其左孩子为根的子树的最大节点
    if ( x->left != NULL )
        return bstree_predecessor(x->left);

    //如果x没有左孩子，则x有以下两种可能：
    //1、x是一个右孩子，则x的前驱节点为它的父节点
    //2、x是一个左孩子，则查找x的最低的父节点，并且该父节点要有右孩子，x的前驱节点就是这个最低的父节点
    Node* y = x->parent;
    while ( (y != NULL) && (x == y->left) )
    {
        x = y;
        y = y->parent;
    }
}

Node* bstree_successor(Node* x)
{
    //如果x存在右孩子，则x的后继节点为以其右孩子为根的子树的最小节点
    if ( x->right != NULL )
        return bstree_minimum(x->right);
    //如果没有右孩子，则x有以下两种可能：
    //1、x是一个左孩子，则x的后继节点为他的父节点
    //2、x是一个右孩子，则查找x的最低父节点，并且该父节点要有左孩子，x的后继节点就是这个最低的父节点
    Node* y = x->parent;
    while ( (y != NULL) && (x == y->right) )
    {
        x = y;
        y = y->parent;
    }
    return y;
}

/*
 * 二叉排序树的插入操作，插入的新节点一定是某个叶节点
 */
static Node* bstree_insert(BSTree tree, Node* z)
{
    Node* y = NULL;
    Node* x = tree;

    while ( x != NULL )
    {
        y = x;
        if ( z->key < x->key )
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if ( y == NULL )
        tree = z;
    else if ( z->key < y->key )
        y->left = z;
    else
        y->right = z;
    return tree;
}
Node* insert_bstree(BSTree tree, Type key)
{
    Node* z;
    if ( (z = create_bstree_node(key, NULL, NULL, NULL)) == NULL )
        return tree;
    return bstree_insert(tree, z);
}

int BSTinsert(BSTree Tree, Type key)
{
    if ( Tree == NULL )
    {
        Tree = (BSTree)malloc(sizeof(Node));
        Tree->key = key;
        Tree->left = Tree->right = NULL;
        return 1;
    }
    else if ( key == Tree->key )
        return 0;
    else if ( key < Tree->key )
        return BSTinsert(Tree->left, key);
    else
        return BSTinsert(Tree->right, key);
}

/*
 *
 * 二叉排序树的删除操作
 * 删除一个节点时，不能把以该节点为根的子树上的节点都删除，必须先把被删除节点从
 * 存储二叉排序树的链表上摘下，将因删除节点而断开的二叉链表重新链接起来，同时保
 * 证二叉排序树的性质不会丢失
 *
 * 删除操作按3种情况来处理：
 * 1、如果被删除节点z是叶节点，则直接删除，不会破坏二叉排序树的性质
 * 2、若z只有一颗左子树或右子树，则让z的子树成为z父节点的子树，替代z的位置
 * 3、若z有左右两颗子树，则令z的直接后继（或直接前驱）替代z，然后从二叉排序树中
 * 删除这个直接后继（或直接前驱），这样就转换为第一或第二种情况
 */
static Node* bstree_delete(BSTree tree, Node* z)
{
    Node* x = NULL;
    Node* y = NULL;

    if ( (z->left == NULL) || (z->right == NULL) )
        y = z;
    else
        y = bstree_successor(z);
    if ( y->left != NULL )
        x = y->left;
    else
        x = y->right;
    if ( x != NULL )
        x->parent = y->parent;
    if ( y->parent == NULL )
        tree = x;
    else if ( y == y->parent->left )
        y->parent->left = x;
    else
        y->parent->right = x;
    if ( y != z )
        z->key = y->key;
    if ( y != NULL )
        free(y);

    return tree;
}
Node* delete_bstree(BSTree tree, Type key)
{
    Node *z, *node;

    if ( (z = bstree_search(tree, key)) != NULL )
        tree = bstree_delete(tree, z);
    
    return tree;
}

/*
 * direction:
 * 0--表示该节点是根节点
 * -1--表示该节点是它的父节点的左孩子
 * 1--表示该节点是它的父节点的右孩子
 */
void print_bstree(BSTree tree, Type key, int direction)
{
    if ( tree != NULL )
    {
        if ( direction == 0 )
            printf("%2d is root\n", tree->key);
        else
            printf("%2d is %2d's %6s child\n", 
                    tree->key, key, direction == 1 ? "right" : "left");
        print_bstree(tree->left, tree->key, -1);
        print_bstree(tree->right, tree->key, 1);
    }
}

void destroy_bstree(BSTree tree)
{
    if ( tree == NULL )
        return;
    if ( tree->left != NULL )
        destroy_bstree(tree->left);
    if ( tree->right != NULL )
        destroy_bstree(tree->right);

    free(tree);
}
