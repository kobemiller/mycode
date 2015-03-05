// =====================================================================================
//
//       Filename:  tree_test.cpp
//
//    Description:  树的顺序存储的测试程序 
//
//        Version:  1.0
//        Created:  2015年03月05日 09时30分29秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

//#define CHAR 1
#define CHAR 0

#include "../ds.h"
#if CHAR
    typedef char TElemType;
    TElemType Nil = ' ';
#else
    typedef int TElemType;
    TElemType Nil = 0;
#endif

#include "tree.h"

int main()
{
    Status  i;
    int     j;
    position p;
    TElemType e;
    SqBiTree T, s;
    InitBiTree(T);
    CreateBiTree(T);
    std::cout << "建立二叉树后，树空否? " << BiTreeEmpty(T) << "(1:yes 0:no) 树的深度=" << BiTreeDepth(T);
    std::cout << std::endl;
    i = Root(T, e);
    if ( i )
        std::cout << "二叉树的根为" << e << std::endl;
    else
        std::cout << "数空，无根" << std::endl;
    std::cout << "层序遍历二叉树:" << std::endl;
    LevelOrderTraverse(T, visit);
    std::cout << "中序遍历二叉树:" << std::endl;
    InOrderTraverse(T, visit);
    std::cout << "后序遍历二叉树:" << std::endl;
    PostOrderTraverse(T, visit);
    std::cout << "请输入待修改节点的层号 本层序号：";
    std::cin >> p.level >> p.order;
    e = Value(T, p);
    std::cout << "待修改节点的原值为：" << e << "请输入新值: ";
    std::cin >> e;
    Assign(T, p, e);
    std::cout << "先序遍历二叉树:" << std::endl;
    PreOrderTraverse(T, visit);
    std::cout << "节点" << e << "的双亲为" << Parent(T, e) << std::endl;
    std::cout << "左右孩子分别为";
    std::cout << LeftChild(T, e) << ", " <<  RightChild(T, e) << std::endl;
    std::cout << "左右兄弟为";
    std::cout << LeftSibling(T, e) << ", " << RightSibling(T, e) << std::endl;
    InitBiTree(s);
    std::cout << "建立右子树为空的树s：" << std::endl;
    CreateBiTree(s);
    std::cout << "树s插到树T中，请输入树T中树s的双亲节点s为左（0）或右（1）子树：";
    std::cin >> e >> j;
    InsertChild(T, e, j, s);
    Print(T);
    std::cout << "删除子树，请输入待删除子树根节点的层号 本层序号 左（0）或右（1）子树：";
    std::cin >> p.level >> p.order >> j;
    DeleteChild(T, p, j);
    Print(T);
    ClearBiTree(T);
    std::cout << "清除二叉树后，树空否? " << BiTreeEmpty(T) << "(1:yes 0:no) 树的深度=" << BiTreeDepth(T);
    std::cout << std::endl;
    i = Root(T, e);
    if ( i )
        std::cout << "二叉树的根为" << e << std::endl;
    else
        std::cout << "数空，无根" << std::endl;
    return 0;
}
