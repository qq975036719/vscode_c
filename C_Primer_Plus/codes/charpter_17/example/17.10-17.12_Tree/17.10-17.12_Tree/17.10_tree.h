// ���������ͷ�ļ�
#ifndef TREE_H_
#define TREE_H_
#include <stdbool.h>

/* ������������� */
#define SLEN 20
#define MAXITEMS 10
// ������ṹ
typedef struct item {
	char petname[SLEN];
	char petkind[SLEN];
} Item;
// ������ṹ
typedef struct node {
	Item item;
	struct node* left;		// ָ�����֧��ָ��
	struct node* right;		// ָ�����֧��ָ��
} Trnode;

typedef struct tree {
	Trnode* root;			// ָ�������ָ��
	int size;				// ��������
} Tree;

// ****************************************************************************

/* �ӿں���ԭ�� */

/* ������					��ʼ��һ�Ŷ�����Ϊ�� */
/* ǰ��������				ptreeָ��һ�Ŷ�����*/
/* ����������				������ʼ��Ϊ�� */
void InitializeTree(Tree* ptree);

/* ������					ȷ�����Ƿ�Ϊ�� */
/* ǰ��������				ptreeָ��һ�Ŷ�����*/
/* ����������				��Ϊ�� -- ����true�����򷵻�false */
bool TreeIsEmpty(const Tree* ptree);

/* ������					ȷ�����Ƿ����� */
/* ǰ��������				ptreeָ��һ�Ŷ�����*/
/* ����������				������ -- ����true�����򷵻�false */
bool TreeIsFull(const Tree* ptree);

/* ������					ȷ�����е����� */
/* ǰ��������				ptreeָ��һ�Ŷ�����*/
/* ����������				�������е����� */
int TreeItemCount(const Tree* ptree);

/* ������					���������һ���� */
/* ǰ��������				pi�Ǵ���ӵ���ĵ�ַ��ptreeָ��һ���ѳ�ʼ���Ķ�����*/
/* ����������				��ӳɹ�����true -- ���򷵻�false */
bool AddItem(const Item* pi, Tree* ptree);

/* ������					�ж����Ƿ������� */
/* ǰ��������				item�Ǵ������ptreeָ��һ���ѳ�ʼ���Ķ�����*/
/* ����������				�ҵ�pi�򷵻�true -- ���򷵻�false */
bool InTree(const Item item, const Tree* ptree);

/* ������					������ɾ��һ���� */
/* ǰ��������				pi�Ǵ�ɾ����ĵ�ַ��ptreeָ��һ���ѳ�ʼ���Ķ�����*/
/* ����������				ɾ���ɹ�����true -- ʧ�ܷ���false */
bool DeleteItem(const Item* pi, Tree* ptree);

/* ������					�Ѻ���Ӧ�������е�ÿһ�� */
/* ǰ��������				ptreeָ��һ���ѳ�ʼ���Ķ�������pfunָ��һ������*/
/* ����������				���е�ÿ��Ԫ�ض���Ϊpfunָ��ĺ���������һ�� */
void Traverse(const Tree* ptree, void(*pfun)(Item item));

/* ������					ɾ�����е��������� */
/* ǰ��������				ptreeָ��һ���ѳ�ʼ���Ķ�����*/
/* ����������				������� */
void DeleteAll(Tree* ptree);

#endif