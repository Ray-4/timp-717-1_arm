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

void printTree (tree *t) 
{
	node *tmp = (node*) malloc(sizeof(node));
	tmp = t->root;

    int *a,*h;
    int b = 0;
    node *p;
    node *n;
    a = (int *) malloc(4* sizeof(int));
    h = (int *) malloc(3* sizeof(int));
    if(tmp) {
        a[b] = tmp->value;
        p = tmp->left;
        n = tmp->left;
        while(n)
		{
            if(p)
			{
                a[b] = p->value;
                p = p->left;
                b++;
            }
			else
			{
                p = n->right;
                n = p;
            }
        }
        p = tmp->right;
        n = tmp->right;
        b = 0;
        while (n)
		{
            if(p)
			{
                h[b] = p->value;
                p = p->left;
                b++;
            }
			else
			{
                p = n->right;
                n = p;
            }

        }
        printf("%d", tmp->value);
        for(int j = 0; j < 3; j++)
		{
            printf(" %d", a[j]);
        }
        for(int j = 0; j < 3; j++)
		{
            printf(" %d", h[j]);
        }
    }
}

int main ()
{
	int a, i;
	tree tr;

	init (&tr);
	
	for (i = 0; i < 7; i++)
	{
		scanf ("%d", &a);
		insert (&tr, a);
	}

	printTree (&tr);
	printf("\n");

	return 0;
}

