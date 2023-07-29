#include "MyDefine.h"

#pragma region Polynominal Part(Later)
#if 0

typedef struct
{
	float coef;
	int expn;
}Polynominal;

typedef struct
{
	Polynominal* elem;
	int len;
};

#endif

#pragma endregion


typedef struct
{
	ElemType* elem;
	int len;
}List;

Status InitList(List* L)
{
	L->elem = (ElemType*)malloc(MS * sizeof(ElemType));
	if (!L->elem) return ERR;
	L->len = 0;
	return OK;
}

Status GetElemList(List* L, Num num, ElemType* result)
{
	if (num < 1 or num > L->len) return ERR;
	result = L->elem + num - 1;
	return OK;
}

Num LocateElemList(List* L, ElemType* e)
{
	int i;
	for (i = 0; i < L->len; i++)
		if (L->elem[i] == *e)
			return i + 1;
	return NotFound;
}

Status InsertElemList(List* L, Num num, ElemType* e)
{
	int i = L->len;
	if (i == MS) return ERR;
	if (num < 1) return ERR;
	while (i > num - 1)
	{
		L->elem[i] = L->elem[i - 1];
		i--;
	}
	L->elem[i] = *e;
	L->len++;
	return OK;
}

Status DeleteElemList(List* L, Num num)
{
	int i;
	if (num < 1 or num > L->len) return ERR;
	for (i = num - 1; i < L->len - 1; i++)
		L->elem[i] = L->elem[i + 1];
	L->len--;
	return OK;
}




