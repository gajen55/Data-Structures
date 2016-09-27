#include <iostream>
#include <string>

using namespace std;

typedef struct Node{
	int data;
	Node *left;
	Node *right;
} Node;

class Tree{

	public:

	Node *root;

	Tree()
	{
		root = NULL;
	};

	void addNode(int a, Node **cur);
	void preOrder(Node *node);
	void inOrder(Node *node);
	void postOrder(Node *node);
	void deleteNode(Node *node);
};

void Tree :: addNode(int a, Node **cur)
{
	if(*cur==NULL)
	{
		Node *temp = new Node;
		temp->data = a;
		temp->left = NULL;
		temp->right = NULL;
		*cur = temp;
	}
	else
	{
		if(a<(*cur)->data)
		{
			addNode(a, &(*cur)->left);
		}
		else
		{
			addNode(a, &(*cur)->right);
		}
	}
}

void Tree :: preOrder(Node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}

}
void Tree :: inOrder(Node *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}

}

void Tree :: postOrder(Node *root)
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}

}

int main()
{
	Tree tree;
	tree.addNode(3,&(tree.root));
	tree.addNode(2,&(tree.root));
	tree.addNode(1,&(tree.root));
	tree.addNode(4,&(tree.root));
	tree.addNode(5,&(tree.root));
	cout<<"pre Order: ";
	tree.preOrder(tree.root);
	cout<<endl<<"in order: ";
	tree.inOrder(tree.root);
	cout<<endl<<"post order: ";
	tree.postOrder(tree.root);

	return 0;
}
