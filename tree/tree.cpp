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
		preOrder(root->left);
		cout<<root->data<<endl;
		preOrder(root->right);
	}

}

int main()
{
	Tree tree;
	tree.addNode(6,&(tree.root));
	tree.addNode(5,&(tree.root));
	tree.addNode(4,&(tree.root));
	tree.addNode(3,&(tree.root));
	tree.addNode(2,&(tree.root));
	tree.preOrder(tree.root);

	return 0;
}

