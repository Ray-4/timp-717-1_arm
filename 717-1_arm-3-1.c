#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int value;
	struct node *next;
} node;

typedef node *list; 



void init (list* l)
{ 
	*l = NULL;
}

void clear (list* l)
{
	list tmp = (list)malloc(sizeof(l));
	while ((*l) != NULL)
	{
		tmp = *l;
		*l = (*l)->next;
		free (tmp);
	}
}

node* find (list* l, int data)
{
	list tmp = (list) malloc(sizeof(l));
	tmp = *l;
	while(tmp->value != data) 
	{
		if(tmp->next == NULL) 
		{
            		return NULL;
		}
        	tmp = tmp->next;
	}
	return tmp;
}

int esEmpty (list *l)
{
	if (*l != NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int push_front (list *l, int data)
{
	list tmp = (list) malloc (sizeof(l));
	tmp->value = data;
	tmp->next = *l;
	*l = tmp;
	return 0;
}

int push_back (list *l, int data)
{
	if (*l == NULL)
	{
		list tmp = (list) malloc (sizeof(l));
		tmp->value = data;
		tmp->next = NULL; 
		*l = tmp;
	}
	else 
	{
		while ((*l)->next) 
		{
			*l = (*l)->next;
		}

		list tmp = (list) malloc (sizeof(l));
		tmp->value = data;
		tmp->next = NULL; 
		(*l)->next = tmp;
	}
   
	return 0;
}

int insertAfter (list *l, int n, int data)
{
	list tmp = (list) malloc(sizeof(l));
	tmp = *l;
	for (int i = 1; i < n; i++)
	{
		tmp = tmp->next;
	}

	list vr = (list) malloc(sizeof(l));
	vr->value = data;
	
	if (tmp->next != NULL)
	{
		vr->next = tmp->next;
	}
	else 
	{
		vr->next = NULL;
	}

	tmp->next = vr;

	return 0;
}

int remov (list *l, int data)
{
	list tmp = (list)malloc(sizeof(l));
	
	while (((*l)->next->value) != data)
	{
		*l = (*l)->next;
	}
	tmp = (*l)->next;
	(*l)->next = tmp->next;
	
	free (tmp);
	return 0;
}

void print (list *l)
{
	list tmp = (list)malloc(sizeof(l));
	tmp = *l;
	while (tmp != NULL)
	{
		printf("%d ", (tmp)->value);
		tmp = (tmp)->next;
	}
	printf("\n");
}


int main ()
{
	int n, a, i;
	list ls, tm;

	scanf ("%d", &n);
	init (&ls);
	scanf("%d", &a);
	push_back (&ls, a);
	tm = ls;

	for (i = 1; i < n; i++)
	{
		scanf ("%d", &a);
		push_back (&tm, a);
		tm = tm->next;
	}

	print (&ls);
	for(int i = 0; i < 3; i++) 
	{
        scanf("%d", &a);
        if(find(&ls, a) != NULL)
		{
            printf("1");
		}
        else
		{
            printf("0");
		}
	}
	printf("\n");

	scanf("%d", &a);
	push_back(&tm, a);
	print(&ls);

	scanf("%d", &a);
	push_front(&ls, a);
	print(&ls);
	
	scanf("%d%d", &n, &a);
	tm = ls;
	insertAfter(&tm, n, a);
	print(&ls);

	tm = ls;
	scanf("%d", &a);
	remov (&tm, a);
	print(&ls);

	clear(&ls);
	
	return 0;
}
