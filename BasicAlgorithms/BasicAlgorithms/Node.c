#include "MyDefine.h"

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*LinkList;

/*Why** double point(here means LinkList* L) is used ? 
Ex: LinkList p = NULL;
	Status  InitList(LinkList L); ##if this is the definition
	Status InitList(LinkList L)
	{
		L = (LinkList)malloc(sizeof(Node));
		if (!*L) return ERR;
		L->next = NULL;
		return OK;
	}
	InitList(p); so, in the fuction, the value of p is assigned as NULL, just a copied value of NULL. In the function, its real that L would be given an address
	             but after all, L is just a local value, its meaningless and just causes memory leak.
				 Now, its necessary to use **, you put address of the point called p into L, and malloc function will allocate space. *L points to the content of p.
				 After the function is finished, p still remains. Thats why ** is necessary.
*/
Status InitLinkListNode(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if (!*L) return ERR;
	(*L)->next = NULL;
	return OK;
}

Status GetElemNode(LinkList L, int i, ElemType* result)
{
	if (!L) return ERR;
	Node* p = L->next;
	int j = 1;
	while (p and j < i)
	{
		j++;
		p = p->next;
	}
	if (!p) return ERR;
}

Node* LocateElemNode(LinkList L, ElemType* e)
{
	Node* p = L->next;
	while (p and p->data != *e)
	{
		p = p->next;
	}
	return p;
}

Status InsertElemNode(LinkList* L, int i, ElemType e)
{
	//If i is longer than the list length, I will just put e to the last.
	Node** p = L;
	Node* iNode = (Node*)malloc(sizeof(Node));
	if (!iNode) return ERR;
	iNode->data = e;
	int j = 0;
	if (*L == NULL)
	{
		if (!InitLinkListNode(L)) return ERR;
		(*L)->next = iNode;
		iNode->next = NULL;
		(*L)->next->data = e;
		return OK;
	}
	while (*p != NULL and j < i - 1)
	{
		if (!(*p)->next)
		{
			iNode->next = NULL;
			(*p)->next = iNode;
			return OK;
		}
		(*p) = (*p)->next;
	}
	iNode->next = (*p)->next;
	(*p)->next = iNode;
	return OK;
}

Status DeletElemNode(LinkList L, int i)
{
	Node* p = L;
	int j = 0;
	while (p and (j < i - 1))
	{
		p = p->next;
		j++;
	}
	if (!p or !p->next) return ERR;
	Node* q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}