#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *Linknode;


int length(Linknode *L)
{
	if ((*L)->next == *L)
	{
		return 0;
	}
	Linknode p;
	p = *L;
	int j = 0;
	while (p->next != NULL)
	{
		j++;
		p = p->next;
	}
	return j;
}


void INSERT(LNode **L, int pos, int data)
{

	Linknode p, q;
	p = *L;
	int i = -1;
	while (p&&i < pos - 1)
	{
		p = p->next;
		i++;
	}
	if (!p || i>pos - 1) return;
	q = malloc(sizeof(LNode));
	q->data = data;
	q->next = p->next;
	p->next = q;
}

void DELETE(LNode **L, int pos)
{

	if (pos<0 || pos>length(L) - 1)
	{
		return;
	}
	LNode *p, *q;
	//p = malloc(sizeof(LNode));
	p = *L;
	int i = -1;
	while (p&&i < pos - 1)
	{
		p = p->next;
		i++;
	}
	if (!p || i>pos - 1) return;
	q = malloc(sizeof(LNode));
	q = p->next;
	p->next = q->next;
	free(q);
}

void GET(LNode **L, int pos)
{

	int c;
	if (pos<0 || pos>length(L) - 1)
	{
		int r = -1;
		printf("%d\n", r);
		getchar();
		return;
	}
	LNode *p;
	p = *L;
	for (int i = 0; i <= pos; i++)
	{
		p = p->next;
	}
	c = p->data;
	printf("%d\n", c);
	getchar();
	return;
}

void APPEND(LNode **L, int data)
{
	LNode *p, *q;
	p = *L;
	q = malloc(sizeof(LNode));
	//p = malloc(sizeof(LNode));
	q->data = data;
	q->next = NULL;
	if (p->next == NULL)
	{
		p->next = q;
		return;
	}
	else
	{
		while (p->next)
		{
			p = p->next;
		}
		p->next = q;
		return;
	}
}

void CLEAR(LNode **L)
{
	Linknode p, q;
	//q = malloc(sizeof(LNode));
	//p = malloc(sizeof(LNode));
	p = q = (*L)->next;
	if ((*L)->next == NULL)
	{
		return;
	}
	while ((p->next) != NULL)
	{
		p = p->next;
		free(q);
		q = p;
	}
	(*L)->next = NULL;
}

void Creat(LNode **L)
{
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L)
	{
		(*L)->next = NULL;
	}
}

int main()
{

	int num;
	scanf("%d", &num);
	getchar();
	char cmd[8];
	LNode *p;
	Creat(&p);
	while (num--)
	{
		scanf("%s", &cmd);
		if (cmd[0] == 'A')
		{
			int x;
			scanf("%d", &x);
			APPEND(&p, x);
			memset(cmd, 0, sizeof(cmd));
		}
		if (cmd[0] == 'I')
		{
			int x, pos;
			scanf("%d %d", &pos, &x);
			INSERT(&p, pos, x);

			memset(cmd, 0, sizeof(cmd));
		}
		if (cmd[0] == 'D')
		{
			int pos;
			scanf("%d", &pos);
			DELETE(&p, pos);

			memset(cmd, 0, sizeof(cmd));
		}
		if (cmd[0] == 'G')
		{
			int pos;
			scanf("%d", &pos);
			GET(&p, pos);

			memset(cmd, 0, sizeof(cmd));
		}
		if (cmd[0] == 'C')
		{
			CLEAR(&p);
			memset(cmd, 0, sizeof(cmd));
		}

	}
}