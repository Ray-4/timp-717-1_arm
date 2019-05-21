#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
	struct node *prev; // previous 
	
} node;

typedef struct list
{
	node *head;
	node *tail;
} lis;

void init (lis *l)
{
	l->head = NULL;
	l->tail = NULL;
}

void clear (lis *l)
{
	node* tmp = (node*)malloc(sizeof(node));
	while ((l->head) != NULL)
	{
		tmp = l->head;
		l->head = l->head->next;
		free(tmp);
	}

}

int isEmpty (lis *l)
{
	if (l->head != NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

node* find (lis *l, int data)
{
	node* tmp = (node*) malloc(sizeof(l));
	tmp = l->head;	
	while (tmp->value != data)
	{
		if (tmp->next == NULL)
		{
			return 0;
		}
		tmp = tmp->next;
	}
	return tmp;
}

int push_back (lis *l, int data)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->value = data;
	tmp->prev = l->tail;
	tmp->next = NULL;

	if (l->tail != NULL)
	{
		l->tail->next = tmp;
	}

	l->tail = tmp;
	
	if (l->head == NULL)
	{
		l->head = tmp;
	}
	
	return 0;
}

int push_front (lis *l, int data)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->value = data;
	tmp->next = l->head;
	tmp->prev = NULL;

	if (l->head != NULL)
	{
		l->head->prev = tmp;
	}

	l->head = tmp;

	if (l->tail == NULL)
	{
		l->tail = tmp;
	}

	return 0;
}

int insertAfter (lis *l, int n, int data)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp = l->head;

	for (int i = 1; i < n; i++)
	{	
		tmp = tmp->next;
	}
	node *vr = (node*)malloc(sizeof(node));
	vr->value = data;
	
	if (tmp->next != NULL)
	{
		vr->next = tmp->next;
		tmp->next->prev = vr;
		vr->prev = tmp;
	}
	else 
	{
		vr->next = NULL;
		vr->prev = tmp;
	}
	
	tmp->next = vr;
	return 0;
}

int insertBefore (lis *l, int n, int data)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp = l->head;

	for (int i = 1; i < n; i++)
	{
		tmp = tmp->next;
	}
	node *vr = (node*)malloc(sizeof(node));
	vr->value = data;
	
	if (tmp->prev != NULL)
	{
		vr->next = tmp;
		vr->prev = tmp->prev;
		tmp->prev->next = vr;
	}
	else 
	{
		vr->next = tmp;
		vr->prev = NULL;
	}
	
	tmp->prev = vr;
	return 0;
}

int removeFirst (lis *l, int data)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp = l->head;
	
	while (tmp->value != data)
	{
		tmp = tmp->next;
		if (tmp == NULL)
		{
			break;
		}
	}

	node *vr = (node*)malloc(sizeof(node));
	vr = tmp;
	tmp = vr->next;
	vr->prev->next = tmp;
	tmp->prev = vr->prev;
	
	if (vr == l->head)
	{
		l->head = vr->next;
	}

	free(vr);
	return 0;
}

int removeLast (lis *l, int data)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp = l->tail;
	
	while (tmp->value != data)
	{
		tmp = tmp->prev;
		if (tmp == NULL)
		{
			break;
		}
	}

	node *vr = (node*)malloc(sizeof(node));
	vr = tmp;
	tmp = vr->prev;
	if (vr->next == NULL)
	{
		tmp->next = NULL;
	}
	else
	{
		tmp->next = vr->next;
	}
	if (vr == l->tail)
	{
		l->tail = vr->prev;
	}
	
	free(vr);
	return 0;
}

void print (lis *l)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp = l->head;

	while (tmp != NULL)
	{
		printf ("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

void print_invers (lis *l)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp = l->tail;

	while (tmp != NULL)
	{
		printf ("%d ", tmp->value);
		tmp = tmp->prev;
	}
	printf("\n");
}

int main ()
{
	int n, a, i;
	lis ls, temp;

	scanf ("%d", &n);
	init (&ls);
	scanf("%d", &a);
	push_back (&ls, a);

	for (i = 1; i < n; i++)
	{
		scanf("%d", &a);
		push_back (&ls, a);
	}
	print (&ls);
	
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &a);
		if (find(&ls, a) != NULL)
		{
			printf ("1");
		}
		else
		{
			printf ("0");
		}
	}
	printf("\n");
	
	scanf("%d", &a);
	push_back (&ls, a);
	print_invers (&ls);

	scanf("%d", &a);
	push_front (&ls, a);
	print (&ls);

	scanf ("%d%d", &n, &a);
	insertAfter (&ls, n, a);
	print_invers(&ls);
	
	scanf ("%d%d", &n, &a);
	temp = ls;
	insertBefore (&ls, n, a);
	print (&ls);

	scanf ("%d", &a);
	removeFirst (&ls, a);
	print_invers (&ls);

	scanf ("%d", &a);
	removeLast (&ls, a);
	print (&ls);

	clear (&ls);
	return 0;
}
