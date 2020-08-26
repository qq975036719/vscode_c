// 二叉查找树头文件
#ifndef TREE_H_
#define TREE_H_
#include <stdbool.h>

/* 定义二叉树类型 */
#define SLEN 20
#define MAXITEMS 10
// 定义项结构
typedef struct item {
	char petname[SLEN];
	char petkind[SLEN];
} Item;
// 定义结点结构
typedef struct node {
	Item item;
	struct node* left;		// 指向左分支的指针
	struct node* right;		// 指向左分支的指针
} Trnode;

typedef struct tree {
	Trnode* root;			// 指向根结点的指针
	int size;				// 树的项数
} Tree;

// ****************************************************************************

/* 接口函数原型 */

/* 操作：					初始化一颗二叉树为空 */
/* 前提条件：				ptree指向一颗二叉树*/
/* 后置条件：				树被初始化为空 */
void InitializeTree(Tree* ptree);

/* 操作：					确定树是否为空 */
/* 前提条件：				ptree指向一颗二叉树*/
/* 后置条件：				树为空 -- 返回true，否则返回false */
bool TreeIsEmpty(const Tree* ptree);

/* 操作：					确定树是否已满 */
/* 前提条件：				ptree指向一颗二叉树*/
/* 后置条件：				树已满 -- 返回true，否则返回false */
bool TreeIsFull(const Tree* ptree);

/* 操作：					确定树中的项数 */
/* 前提条件：				ptree指向一颗二叉树*/
/* 后置条件：				返回树中的项数 */
int TreeItemCount(const Tree* ptree);

/* 操作：					在树中添加一个项 */
/* 前提条件：				pi是待添加的项的地址，ptree指向一颗已初始化的二叉树*/
/* 后置条件：				添加成功返回true -- 否则返回false */
bool AddItem(const Item* pi, Tree* ptree);

/* 操作：					判断项是否在树中 */
/* 前提条件：				item是待查找项，ptree指向一颗已初始化的二叉树*/
/* 后置条件：				找到pi则返回true -- 否则返回false */
bool InTree(const Item item, const Tree* ptree);

/* 操作：					从树中删除一个项 */
/* 前提条件：				pi是待删除项的地址，ptree指向一颗已初始化的二叉树*/
/* 后置条件：				删除成功返回true -- 失败返回false */
bool DeleteItem(const Item* pi, Tree* ptree);

/* 操作：					把函数应用于树中的每一项 */
/* 前提条件：				ptree指向一颗已初始化的二叉树，pfun指向一个函数*/
/* 后置条件：				树中的每个元素都作为pfun指向的函数被调用一次 */
void Traverse(const Tree* ptree, void(*pfun)(Item item));

/* 操作：					删除树中的所有内容 */
/* 前提条件：				ptree指向一颗已初始化的二叉树*/
/* 后置条件：				树被清空 */
void DeleteAll(Tree* ptree);

#endif