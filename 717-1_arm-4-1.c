#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *left; //descendant - потомки
	struct node *right;
	struct node *par; // предок

} node;

typedef struct tree
{
	struct node *root;
	int sum;
} tree;

void init (tree *t)
{	
	t->root = NULL;
	t->sum = 0;
}

int find (tree *t, int data, node **n)
{
	node *tmp = (node*) malloc(sizeof(node));
	tmp = t->root;

	while (tmp != NULL)
	{
		if (data > (tmp->value))
		{
			tmp = tmp->right;
			continue;
		}
		else if (data < (tmp->value))
		{
			tmp = tmp->left;
			continue;
		}
		else 
		{
			*n = tmp;
			return 0;
		}
	}
	return 1;

}

int insert (tree *t, int data)
{
	node *tmp = (node*) malloc(sizeof(node));
		
	if (t->root == NULL)
	{
		tmp->par = NULL;
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->value = data;
		t->root = tmp;
		t->sum += 1;
		return 0;
	}

	tmp = t->root;
	node *vr = (node*) malloc(sizeof(node));
	vr->left = NULL;
	vr->right = NULL;
	vr->value = data;

	while (tmp)
	{
		if (data > (tmp->value))
		{
			if (tmp->right != NULL)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				vr->par = tmp;
				tmp->right = vr;
				t->sum += 1;
				return 0;
			}
		}
		else if (data < (tmp->value))
		{
			if (tmp->left != NULL)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				vr->par = tmp;
				tmp->left = vr;
				t->sum += 1;
				return 0;
			}
		}
		else
		{
			return 1;
		}
	}
}

int remov (tree *t, int value)
{
	node *tmp = t->root; 

	while (tmp->value != value) 
	{ 
		if (value < tmp->value) 
			tmp = tmp->left; 
		else if (value > tmp->value) 
			tmp = tmp->right; 
	} 

	if (tmp == NULL) 
		return 1; 
	if (tmp->left == NULL && tmp->right == NULL) 
	{ 
		if (tmp->par->value > value) 
			tmp->par->left = NULL; 
		else 
			tmp->par->right = NULL; 
		free(tmp); 
	} 
	else if (tmp->left != NULL && tmp->right == NULL) 
	{ 
		tmp->left->par = tmp->par; 

		if (tmp->par->value > value) 
			tmp->par->left = tmp->left; 
		else 
			tmp->par->right = tmp->left; 
		free(tmp); 
	} 

	else if (tmp->left == NULL && tmp->right != NULL) 
	{ 
		tmp->right->par = tmp->par; 
		if (tmp->par->value > value) 
			tmp->par->left = tmp->right; 
		else 
			tmp->par->right = tmp->right; 
		free(tmp); 
	} 
	else if (tmp->left != NULL && tmp->right != NULL) 
	{ 
		node *p = tmp->right; 
		if (p->left == NULL) 
		{ 
			tmp->value = p->value; 
			if (p->right == NULL) 
			{ 
				tmp->right = NULL; 
				free(tmp->right); 
			} 
			else 
			{ 
				tmp->right = tmp->right->right; 
				p->right->par = tmp; 
				free(p); 
			} 
		} 
		else 
		{ 
			while(p->left) 
				p = p->left; 
			
			tmp->value = p->value; 
			if (p->right) 
			{ 
				tmp->value = p->value; 
				p->value = p->right->value; 
				tmp->right = NULL; 
				free(p->right); 
			} 
			else 
			{ 
				tmp->value = p->value; 
				p->par->left = NULL; 
				free(p); 
			} 
		} 
	} 
	t->sum--; 
	return 0; 
}

int removeMin (node *n, tree *t)
{
	if (t->sum == 1) 
	{ 
		t->root = NULL; 
		t->sum = 0; 
		free(t->root); 
		return 0; 
	} 

	while(n->left) 
		n = n->left; 
	if (n->right) 
	{
		n->right->par = n->par; 
		if (n == t->root) 
			t->root = n->right; 
		else 
			n->par->left = n->right; 
	} 
	else 
	{ 
		n->par->left = NULL; 
	} 
	int m = n->value; 
	free(n); 
	t->sum--; 
	return m; 
}

void clear (tree *t)
{
	while (t->root)
		removeMin (t->root, t);
}

int rotateRight (node **n)
{
	node *tmp = (*n)->left; 
	if (tmp == NULL) 
		return 1; 
	(*n)->left = tmp->right; 
	tmp->right = (*n); 
	tmp->par = (*n)->par; 
	(*n)->par = tmp; 
	(*n) = tmp;
	return 0;
}

int rotateLeft (node **n)
{
	node *tmp = (*n)->right; 
	if (tmp == NULL) 
		return 1; 
	(*n)->right = tmp->left; 
	tmp->left = (*n); 
	tmp->par = (*n)->par; 
	(*n)->par = tmp; 
	(*n) = tmp; 
	return 0; 

}

// использование очередей для вывода дерева

typedef struct Nod
{
        int value;
        struct Nod *next;
} Nod;

typedef struct list
{
	struct Nod *head;
	struct Nod *tail;
} list;

void init_list (list* l)
{
        l->head = NULL;
		l->tail = NULL;
}

void clear_list (list* l)
{
        Nod* tmp = (Nod*)malloc(sizeof(Nod));
		while ((l->head) != NULL)
        {
				tmp = l->head;
				l->head = l->head->next;
                free (tmp);
        }
}

int push_back (list *l, int data)
{

		Nod *tmp = (Nod*)malloc(sizeof(Nod));
		tmp->value = data;
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

// копирование из одной очереди в другую
void copylist (list *arr, list *arr_2)
{
	while (arr_2->head)
	{
		push_back (arr, arr_2->head->value);
		arr_2->head = arr_2->head->next;
	}
}

// запись потомков узла
void zapis (node* n, list *arr)
{
	if (n->left != NULL)
	{
		Nod *vr = (Nod*)malloc(sizeof(node));
		(vr->value) = (n->left->value);
		vr->next = NULL;

		if (arr->tail != NULL)
		{
			arr->tail->next = vr;
		}

		arr->tail = vr;
	
		if (arr->head == NULL)
		{
 			arr->head = vr;
		}
	}
	else 
	{
		Nod *tmp = (Nod*)malloc(sizeof(Nod));
		tmp->value = 777;
		tmp->next = NULL;

		if (arr->tail != NULL)
		{
			arr->tail->next = tmp;
		}

		arr->tail = tmp;
	
		if (arr->head == NULL)
		{
			arr->head = tmp;
		}
	}

	if (n->right != NULL)
	{
		Nod *tmp = (Nod*)malloc(sizeof(Nod));
		tmp->value = n->right->value;
		tmp->next = NULL;

		if (arr->tail != NULL)
		{
			arr->tail->next = tmp;
		}

		arr->tail = tmp;
	
		if (arr->head == NULL)
		{
			arr->head = tmp;
		}
	}
	else 
	{
		Nod *tmp = (Nod*)malloc(sizeof(Nod));
		tmp->value = 777;
		tmp->next = NULL;

		if (arr->tail != NULL)
		{
			arr->tail->next = tmp;
		}

		arr->tail = tmp;
	
		if (arr->head == NULL)
		{
			arr->head = tmp;
		}
	}
}



void print (node *n)
{
	node *temp = (node*) malloc(sizeof(node));
	node *vr = (node*) malloc(sizeof(node));
	node *fig = (node*) malloc(sizeof(node));
	fig->value = 777;
	fig->left = NULL;
	fig->right = NULL;

	tree *der = (tree*) malloc(sizeof(tree));
	der->root = n;
	temp = n;

	list arr, arr_2; 
	
	list ls, ls_2;
	
	init_list (&arr);
	init_list (&arr_2);

	int k = 1, step = 1, j = 0, i;

	if (temp == NULL)
	{
		printf ("-");
	}
	else
	{
		printf ("%d \n", temp->value);
		//printf ("%d ", temp->left->value);
		zapis (temp, &arr);
		//printf ("%d", arr.head->value);

		while (k != 0)
		{	
			ls = arr;
			ls_2 = arr_2;
			//vr = NULL;

			//проверка на отсутствие потомков
			for (i = 0; i < step * 2; i++)
			{
				if (ls.head->value == 777)
				{
					j++;
				}
				ls.head = ls.head->next;
			}

			if (j == step * 2)
			{
				k = 0;
				break;
			}

			ls = arr;
			for (i = 0; i < step * 2; i++)
			{	
				if (ls.head->value != 777)
				{
					printf("%d ", ls.head->value);
				}
				else
				{

					printf ("_ ");
				}

				if (find (der, ls.head->value, &vr) == 0)
				{
					//printf("%d \n", vr->value);
					zapis (vr, &arr_2);
				}
				else
				{
					//vr = NULL;
					zapis (fig, &arr_2);
				}

				ls.head = ls.head->next;
			}
			printf ("\n");

			clear_list (&arr);
			copylist (&arr, &arr_2);
			clear_list (&arr_2);
			
			step *= 2;
			j = 0;
		}
	}
}

void printTree (tree *t)
{
	node *tmp = (node*) malloc(sizeof(node));
	tmp = t->root;
	print (tmp);
}

int main ()
{
	int a, i;
	tree tr;

	init (&tr);
	
	for (i = 0; i < 4; i++)
	{
		scanf ("%d", &a);
		insert (&tr, a);
	}

	printTree (&tr);

	for (i = 0; i < 3; i++)
	{
		scanf ("%d", &a);
		insert (&tr, a);
	}

	printTree (&tr);

	node *vr = (node*) malloc(sizeof(node));

	for (i = 0; i < 2; i++)
	{
		scanf ("%d", &a);
		find (&tr, a, &vr);

		if (find (&tr, a, &vr) != 0)
		{
			printf("-");
		}
		else
		{
			if (vr->par)
			{
				printf("%d ", vr->par->value);
			}
			else
			{
				printf("_ ");
			}
			if (vr->left)
			{
				printf("%d ", vr->left->value);
			}
			else
			{
				printf("_ ");
			}
			if (vr->right)
			{
				printf("%d ", vr->right->value);
			}
			else
			{
				printf("_ ");
			}
		}
		printf ("\n");
	}

	scanf ("%d", &a);
	remov (&tr, a);
	printTree (&tr);

	
	//rotateLeft (vr);
	while (rotateLeft (&tr.root) == 0)
	{;}
	printTree (&tr);

	while (rotateRight (&tr.root) == 0)
	{;}
	//rotateRight (vr);
	printTree (&tr);

	printf("%d \n", tr.sum);
	clear (&tr);
	printTree (&tr);
	printf ("\n");
	
	return 0;
}
