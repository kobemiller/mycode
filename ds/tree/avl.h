// =====================================================================================
//
//       Filename:  avl.h
//
//    Description:  平衡二叉树的c实现 
//
//        Version:  1.0
//        Created:  2015年03月06日 13时21分32秒
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

typedef struct AVLTreeNode
{
    Type    key;
    int     height;
    struct AVLTreeNode  *left;
    struct AVLTreeNode  *right;
}Node, *AVLTree;

static Node* avltree_create_node(Type key, Node* left, Node* right)
{
    Node* p;
    if ( (p = (Node*)malloc(sizeof(Node))) == NULL )
        return NULL;
    p->key = key;
    p->height = 0;
    p->left = left;
    p->right = right;

    return p;
}

/*
 * 树的高度采用维基百科的定义：树的高度为最大层数。即空的二叉平衡树的高度是0，
 * 非空树的高度等于它的最大层数
 */
#define HEIGHT(p)   ((p == NULL) ? 0 : (((Node*)(p))->height))
int avltree_height(AVLTree tree)
{
    return HEIGHT(tree);
}

void preorder_avltree(AVLTree tree)
{
    if ( tree != NULL )
    {
        printf("%d ", tree->key);
        preorder_avltree(tree->left);
        preorder_avltree(tree->right);
    }
}

void inorder_avltree(AVLTree tree)
{
    if ( tree != NULL )
    {
        inorder_avltree(tree->left);
        printf("%d ", tree->key);
        inorder_avltree(tree->right);
    }
}

void postorder_avltree(AVLTree tree)
{
    if ( tree != NULL )
    {
        postorder_avltree(tree->left);
        postorder_avltree(tree->right);
        printf("%d ", tree->key);
    }
}


Node* avltree_search(AVLTree x, Type key)
{
    if ( x == NULL || x->key == key )
        return x;
    if ( key < x->key )
        return avltree_search(x->left, key);
    else
        return avltree_search(x->right, key);
}

Node* iterative_avltree_search(AVLTree x, Type key)
{
    while ( (x != NULL) && (x->key != key) )
    {
        if ( key < x->key )
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

Node* avltree_minimum(AVLTree tree)
{
    if ( tree == NULL )
        return NULL;
    while ( tree->left != NULL )
        tree = tree->left;
    return tree;
}

Node* avltree_maximum(AVLTree tree)
{
    if ( tree == NULL )
        return NULL;
    while ( tree->right != NULL )
        tree = tree->right;
    return tree;
}

#define MAX(a, b)   ((a) > (b) ? (a) : (b))

/*
 * 每次调整的对象都是最小不平衡子树，即在插入路径上离插入节点最近的平衡因子绝对值大于1的节点作为根的子树
 */
static Node* left_left_rotation(AVLTree k2)
{
    AVLTree k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = MAX(HEIGHT(k2->left), HEIGHT(k2->right)) + 1;
    k1->height = MAX(HEIGHT(k1->left), k2->height) + 1;

    return k1;
}

static Node* right_right_rotation(AVLTree k2)
{
    AVLTree k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    k2->height = MAX(HEIGHT(k2->left), HEIGHT(k2->right)) + 1;
    k1->height = MAX(HEIGHT(k1->right), k2->height) + 1;

    return k1;
}

static Node* left_right_rotation(AVLTree k3)
{
    k3->left = right_right_rotation(k3->left);

    return left_left_rotation(k3);
}

static Node* right_left_rotation(AVLTree k1)
{
    k1->right = left_left_rotation(k1->right);

    return right_right_rotation(k1);
}

Node* avltree_insert(AVLTree tree, Type key)
{
    if ( tree == NULL )
    {
        tree = avltree_create_node(key, NULL, NULL);
        if ( tree == NULL )
        {
            printf("ERROR: create avltree node failed!\n");
            return NULL;
        }
    }
    else if ( key < tree->key )
    {
        tree->left = avltree_insert(tree->left, key);
        if ( HEIGHT(tree->left) - HEIGHT(tree->right) == 2 )
        {
            if ( key < tree->left->key )
                tree = left_left_rotation(tree);
            else
                tree = left_right_rotation(tree);
        }
    }
    else if ( key > tree->key )
    {
        tree->right = avltree_insert(tree->right, key);
        if ( HEIGHT(tree->right) - HEIGHT(tree->left) == 2 )
        {
            if ( key > tree->right->key )
                tree = right_right_rotation(tree);
            else
                tree = right_left_rotation(tree);
        }
    }
    else
    {
        printf("添加失败：不允许添加相同的节点！\n");
    }

    tree->height = MAX(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;

    return tree;
}

static Node* delete_node(AVLTree tree, Node *z)
{
    if ( tree == NULL || z == NULL )
        return NULL;
    if ( z->key < tree->key )
    {
        tree->left = delete_node(tree->left, z);
        if ( HEIGHT(tree->right) - HEIGHT(tree->left) == 2 )
        {
            Node *r = tree->right;
            if ( HEIGHT(r->left) > HEIGHT(r->right) )
                tree = right_left_rotation(tree);
            else
                tree = right_right_rotation(tree);
        }
    }
    else if ( z->key > tree->key )
    {
        tree->right = delete_node(tree->right, z);
        if ( HEIGHT(tree->left) - HEIGHT(tree->right) == 2 )
        {
            Node *l = tree->left;
            if ( HEIGHT(l->right) > HEIGHT(l->left) )
                tree = left_right_rotation(tree);
            else
                tree = left_left_rotation(tree);
        }
    }
    else
    {
        if ( (tree->left) && (tree->right) )
        {
            if ( HEIGHT(tree->left) > HEIGHT(tree->right) )
            {
                //如果tree的左子树比右子树高，则：
                //1、找出tree的左子树中的最大节点
                //2、将该最大节点的值赋值给tree
                //3、删除该最大节点
                Node *max = avltree_maximum(tree->left);
                tree->key = max->key;
                tree->left = delete_node(tree->left, max);
            }
            else
            {
                //如果tree的左子树不比右子树高，则：
                //1、找出tree的右子树中的最小节点
                //2、将该最小节点的值赋给tree
                //3、删除该最小节点
                Node *min = avltree_minimum(tree->right);
                tree->key = min->key;
                tree->right = delete_node(tree->right, min);
            }
        }
        else
        {
            Node* tmp = tree;
            tree = tree->left ? tree->left : tree->right;
            free(tmp);
        }
    }
    return tree;
}

Node* avltree_delete(AVLTree tree, Type key)
{
    Node *z;
    if ( (z = avltree_search(tree, key)) != NULL )
        tree = delete_node(tree, z);
    return tree;
}

void destroy_avltree(AVLTree tree)
{
    if ( tree == NULL )
        return;
    if ( tree->left != NULL )
        destroy_avltree(tree->left);
    if ( tree->right != NULL )
        destroy_avltree(tree->right);
    free(tree);
}

void print_avltree(AVLTree tree, Type key, int direction)
{
    if ( tree != NULL )
    {
        if ( direction == 0 )
            printf("%2d is root\n", tree->key);
        else
            printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");
        print_avltree(tree->left, tree->key, -1);
        print_avltree(tree->right, tree->key, 1);
    }
}

