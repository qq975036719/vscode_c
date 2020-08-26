// 二叉树接口函数
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "17.10_tree.h"

/* 局部函数定义 */
typedef struct pair {		// SeekItem()的返回类型
	Trnode* parent;			// 目标项的父节点
	Trnode* child;			// 目标项
} Pair;
static Pair SeekItem(const Item* pi, const Tree* ptree);		 // 在树中查找pi指向的项
static Trnode* MakeNode(const Item* pi);						 // 创建一个新结点
static void AddNode(Trnode* new_node, Trnode* root);			 // 添加新结点 -- 从根结点出发寻找新结点的存放位置
static void DeleteNode(Trnode** pnode);							 // 在树中删除pnode指向的结点
static void InOrder(const Trnode* root, void(*pfun)(Item item)); // 按左子树--项--右子树的顺序调用函数
static void DeleteAllNodes(Trnode* root);						 // 删除所有结点
static bool ToLeft(const Item* i1, const Item* i2);				 // 判断目标结点是否在根结点的左边
static bool ToRight(const Item* i1, const Item* i2);		     // 判断目标结点是否在根结点的右边

// ********************************************************

/* 接口函数定义 */

// 初始化二叉树
void InitializeTree(Tree* ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

// 确定树是否为空
bool TreeIsEmpty(const Tree* ptree)
{
	return (ptree->root == NULL ? true : false);
}

// 确定树是否已满
bool TreeIsFull(const Tree* ptree)
{
	if (ptree->size == MAXITEMS)
		return true;
	else
		return false;
}

// 确定树中的项数
int TreeItemCount(const Tree* ptree)
{
	return ptree->size;
}

// 在树中添加一个项
bool AddItem(const Item* pi, Tree* ptree)
{
	Trnode* new_node;

	// 判断树是否已满和待添加项是否在树中存在
	if (TreeIsFull(ptree)) {			// 树满了 -- 无法添加新的项
		fprintf(stderr, "树已满！\n");
		return false;
	}
	if (SeekItem(pi, ptree).child != NULL) {	// 在树中该项已存在
		fprintf(stderr, "树中已有该项，请勿重复添加\n");
		return false;
	}
	// 创建新结点
	new_node = MakeNode(pi);
	// 树的项数加1
	ptree->size++;

	// 找出树中新结点该存放的位置并将新结点添加到树中
	if (ptree->root == NULL)			// 树为空则新结点作为根结点
		ptree->root = new_node;
	else
		AddNode(new_node, ptree->root);

	return true;
}

// 判断项是否在树中
bool InTree(const Item item, const Tree* ptree)
{
	return (SeekItem(&item, ptree).child == NULL ? false : true);
}

// 从树中删除一个项
bool DeleteItem(const Item* pi, Tree* ptree)
{
	Pair look;

	// 在树中查找项的位置
	look = SeekItem(pi, ptree);
	
	// 判断树结点的情况
	if (look.child == NULL) {
		fprintf(stderr, "树中不存在该结点，无法删除！\n");
		return false;
	}
	if (look.parent == NULL)					// 被删除的项是根结点的项
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)	// 被删除项是其父结点的左子结点
		DeleteNode(&look.parent->left);
	else if (look.parent->left == look.child)	// 被删除项是其父结点的右子结点
		DeleteNode(&look.parent->right);
	// 树的项数减1
	ptree->size--;

	return true;
}

// 把函数应用于树中的每一项
void Traverse(const Tree* ptree, void(*pfun)(Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

// 清空树
void DeleteAll(Tree* ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	//ptree->root = NULL;
	ptree->size = 0;
}

/* 局部函数定义 */

// 在树中查找pi指向的项
static Pair SeekItem(const Item* pi, const Tree* ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	if (look.child == NULL)
		return look;

	while (look.child != NULL) {
		if (ToLeft(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->right;
		}
		// 既不在左边也不在右边 -- 即相等，此时代表已经找到目标项的位置，退出循环
		else
			break;
	}

	return look;
}

// 创建一个新结点
static Trnode* MakeNode(const Item* pi)
{
	Trnode* new_node;
	
	new_node = (Trnode*)malloc(sizeof(Trnode));
	if (new_node != NULL) {
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->item = *pi;
	}

	return new_node;
}

// 添加一个结点
static void AddNode(Trnode* new_node, Trnode* root)
{
	if (ToLeft(&new_node->item, &root->item)) {		// 添加结点在根结点的左子结点
		if (root->left == NULL)						// 根结点的左子结点为空时 -- 直接将新结点加到该处
			root->left = new_node;
		else										// 根结点的左子结点不为空则递归继续寻找，直到为空
			AddNode(new_node, root->left);
	}
	if (ToRight(&new_node->item, &root->item)) {
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else {
		fprintf(stderr, "树中已有该项，请勿重复添加！");
		exit(EXIT_FAILURE);
	}
}

// 按左子树--项--右子树的顺序调用函数
static void InOrder(const Trnode* root, void(*pfun)(Item item))
{
	if (root != NULL) {
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

// 删除所有结点
static void DeleteAllNodes(Trnode* root)
{
	Trnode* pright;

	if (root != NULL) {
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

// 判断目标结点是否在根结点的左边
static bool ToLeft(const Item* i1, const Item* i2)
{
	int temp;

	if ((temp = strcmp(i1->petname, i2->petname)) < 0)
		return true;
	else if (temp == 0 &&
		strcmp(i1->petkind, i2->petkind) < 0)
		return true;
	else
		return false;
}

// 判断目标结点是否在根结点的右边
static bool ToRight(const Item* i1, const Item* i2)
{
	int temp;

	if ((temp = strcmp(i1->petname, i2->petname)) > 0)
		return true;
	else if (temp == 0 &&
		strcmp(i1->petkind, i2->petkind) > 0)
		return true;
	else
		return false;
}

// 删除一个结点
static void DeleteNode(Trnode** pnode)	/* pnode是指向待删除结点的父结点成员的地址 */
{
	Trnode* temp;

	// 被删除结点的子结点只有一个的情况和没有子结点的情况
	if ((*pnode)->left == NULL) {		// *pnode是被删除的结点，被删除结点左子结点为空，则让父节点
										// 指向被删除结点的右结点
		temp = *pnode;
		*pnode = (*pnode)->right;
		free(temp);
	}
	else if ((*pnode)->right == NULL) {
		temp = *pnode;
		*pnode = (*pnode)->left;
		free(temp);
	}
	/* 若被删除结点无子结点 -- 程序先到左结点判断 --> 父节点指向被删除结点的右结点
	   因为右结点也为空，相当于被删除结点的父结点指向了NULL */

	   // 被删除结点的子结点有两个的情况
	else {
		// 寻找被删除结点的右子结点连接到左子结点的位置 -- 直到找到左子结点的右子树上的空位
		for (temp = (*pnode)->left; temp->right != NULL; temp = temp->right)
			continue;
		/* 找到之后现在的temp是被删除结点的左子结点的右子树上的末尾 -- 把被删除结点的右子树
		   连接到temp的右子结点 */
		temp->right = (*pnode)->right;
		temp = (*pnode);
		*pnode = (*pnode)->left;
		free(temp);
	}
}