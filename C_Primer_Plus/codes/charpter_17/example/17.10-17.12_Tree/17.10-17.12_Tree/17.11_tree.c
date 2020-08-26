// �������ӿں���
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "17.10_tree.h"

/* �ֲ��������� */
typedef struct pair {		// SeekItem()�ķ�������
	Trnode* parent;			// Ŀ����ĸ��ڵ�
	Trnode* child;			// Ŀ����
} Pair;
static Pair SeekItem(const Item* pi, const Tree* ptree);		 // �����в���piָ�����
static Trnode* MakeNode(const Item* pi);						 // ����һ���½��
static void AddNode(Trnode* new_node, Trnode* root);			 // ����½�� -- �Ӹ�������Ѱ���½��Ĵ��λ��
static void DeleteNode(Trnode** pnode);							 // ������ɾ��pnodeָ��Ľ��
static void InOrder(const Trnode* root, void(*pfun)(Item item)); // ��������--��--��������˳����ú���
static void DeleteAllNodes(Trnode* root);						 // ɾ�����н��
static bool ToLeft(const Item* i1, const Item* i2);				 // �ж�Ŀ�����Ƿ��ڸ��������
static bool ToRight(const Item* i1, const Item* i2);		     // �ж�Ŀ�����Ƿ��ڸ������ұ�

// ********************************************************

/* �ӿں������� */

// ��ʼ��������
void InitializeTree(Tree* ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

// ȷ�����Ƿ�Ϊ��
bool TreeIsEmpty(const Tree* ptree)
{
	return (ptree->root == NULL ? true : false);
}

// ȷ�����Ƿ�����
bool TreeIsFull(const Tree* ptree)
{
	if (ptree->size == MAXITEMS)
		return true;
	else
		return false;
}

// ȷ�����е�����
int TreeItemCount(const Tree* ptree)
{
	return ptree->size;
}

// ���������һ����
bool AddItem(const Item* pi, Tree* ptree)
{
	Trnode* new_node;

	// �ж����Ƿ������ʹ�������Ƿ������д���
	if (TreeIsFull(ptree)) {			// ������ -- �޷�����µ���
		fprintf(stderr, "��������\n");
		return false;
	}
	if (SeekItem(pi, ptree).child != NULL) {	// �����и����Ѵ���
		fprintf(stderr, "�������и�������ظ����\n");
		return false;
	}
	// �����½��
	new_node = MakeNode(pi);
	// ����������1
	ptree->size++;

	// �ҳ������½��ô�ŵ�λ�ò����½����ӵ�����
	if (ptree->root == NULL)			// ��Ϊ�����½����Ϊ�����
		ptree->root = new_node;
	else
		AddNode(new_node, ptree->root);

	return true;
}

// �ж����Ƿ�������
bool InTree(const Item item, const Tree* ptree)
{
	return (SeekItem(&item, ptree).child == NULL ? false : true);
}

// ������ɾ��һ����
bool DeleteItem(const Item* pi, Tree* ptree)
{
	Pair look;

	// �����в������λ��
	look = SeekItem(pi, ptree);
	
	// �ж����������
	if (look.child == NULL) {
		fprintf(stderr, "���в����ڸý�㣬�޷�ɾ����\n");
		return false;
	}
	if (look.parent == NULL)					// ��ɾ�������Ǹ�������
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)	// ��ɾ�������丸�������ӽ��
		DeleteNode(&look.parent->left);
	else if (look.parent->left == look.child)	// ��ɾ�������丸�������ӽ��
		DeleteNode(&look.parent->right);
	// ����������1
	ptree->size--;

	return true;
}

// �Ѻ���Ӧ�������е�ÿһ��
void Traverse(const Tree* ptree, void(*pfun)(Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

// �����
void DeleteAll(Tree* ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	//ptree->root = NULL;
	ptree->size = 0;
}

/* �ֲ��������� */

// �����в���piָ�����
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
		// �Ȳ������Ҳ�����ұ� -- ����ȣ���ʱ�����Ѿ��ҵ�Ŀ�����λ�ã��˳�ѭ��
		else
			break;
	}

	return look;
}

// ����һ���½��
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

// ���һ�����
static void AddNode(Trnode* new_node, Trnode* root)
{
	if (ToLeft(&new_node->item, &root->item)) {		// ��ӽ���ڸ��������ӽ��
		if (root->left == NULL)						// ���������ӽ��Ϊ��ʱ -- ֱ�ӽ��½��ӵ��ô�
			root->left = new_node;
		else										// ���������ӽ�㲻Ϊ����ݹ����Ѱ�ң�ֱ��Ϊ��
			AddNode(new_node, root->left);
	}
	if (ToRight(&new_node->item, &root->item)) {
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else {
		fprintf(stderr, "�������и�������ظ���ӣ�");
		exit(EXIT_FAILURE);
	}
}

// ��������--��--��������˳����ú���
static void InOrder(const Trnode* root, void(*pfun)(Item item))
{
	if (root != NULL) {
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

// ɾ�����н��
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

// �ж�Ŀ�����Ƿ��ڸ��������
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

// �ж�Ŀ�����Ƿ��ڸ������ұ�
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

// ɾ��һ�����
static void DeleteNode(Trnode** pnode)	/* pnode��ָ���ɾ�����ĸ�����Ա�ĵ�ַ */
{
	Trnode* temp;

	// ��ɾ�������ӽ��ֻ��һ���������û���ӽ������
	if ((*pnode)->left == NULL) {		// *pnode�Ǳ�ɾ���Ľ�㣬��ɾ��������ӽ��Ϊ�գ����ø��ڵ�
										// ָ��ɾ�������ҽ��
		temp = *pnode;
		*pnode = (*pnode)->right;
		free(temp);
	}
	else if ((*pnode)->right == NULL) {
		temp = *pnode;
		*pnode = (*pnode)->left;
		free(temp);
	}
	/* ����ɾ��������ӽ�� -- �����ȵ������ж� --> ���ڵ�ָ��ɾ�������ҽ��
	   ��Ϊ�ҽ��ҲΪ�գ��൱�ڱ�ɾ�����ĸ����ָ����NULL */

	   // ��ɾ�������ӽ�������������
	else {
		// Ѱ�ұ�ɾ���������ӽ�����ӵ����ӽ���λ�� -- ֱ���ҵ����ӽ����������ϵĿ�λ
		for (temp = (*pnode)->left; temp->right != NULL; temp = temp->right)
			continue;
		/* �ҵ�֮�����ڵ�temp�Ǳ�ɾ���������ӽ����������ϵ�ĩβ -- �ѱ�ɾ������������
		   ���ӵ�temp�����ӽ�� */
		temp->right = (*pnode)->right;
		temp = (*pnode);
		*pnode = (*pnode)->left;
		free(temp);
	}
}