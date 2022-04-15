#include <iostream>
using namespace std;

typedef struct _node
{
	int value;
	_node* left, * right;
}node;

node* head, * tail;
class Tree
{
public:
	void init_tree()
	{
		head = new node;
		tail = new node;
		head->left = tail;
		head->right = tail;
		head->value = NULL;
		tail->left = tail;
		tail->right = tail;
	}

	int push(node* t, int key)
	{
		if (t == tail)
			return -1;

		if (t->value == NULL)
		{
			t->value = key;
			return 1;
		}
		
		if (t->left == tail)
		{
			node* s = new node;
			t->left = s;
			s->value = key;
			s->left = tail;
			s->right = tail;
			return 1;
		}
		if (t->right == tail)
		{
			node* s = new node;
			t->right = s;
			s->value = key;
			s->left = tail;
			s->right = tail;
			return 1;
		}
		push(t->left, key);
	}

	void preorder(node* t)
	{
		if (t == tail)
			return;

		cout << t->value << ' ';
		preorder(t->left);
		preorder(t->right);
	}

	void inorder(node* t)
	{
		if (t == tail)
			return;

		inorder(t->left);
		cout << t->value << ' ';
		inorder(t->right);
	}

	void postorder(node* t)
	{
		if (t == tail)
			return;

		postorder(t->left);
		postorder(t->right);
		cout << t->value << ' ';
	}
};
int main()
{
	Tree t;
	t.init_tree();
	
	for (int i = 0; i < 6; i++)
		t.push(head, i);
	for (int i = 0; i < 4; i++)
		t.push(head->right, i + 6);

	t.preorder(head);
	cout << endl;
	t.inorder(head);
	cout << endl;
	t.postorder(head);
	cout << endl;
}