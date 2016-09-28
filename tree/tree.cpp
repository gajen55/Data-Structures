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
	Node * deleteNode(int a, Node *node);
	Node * findMinNode(Node *node);
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

Node * Tree :: findMinNode(Node *node)
{
	if(node->left==NULL)
	{
		return node;
	}
	else
	{
		return findMinNode(node->left);
	}
}

Node * Tree :: deleteNode(int a, Node *node)
{
	if(node==NULL)
	{
		return node;
	}
	if(a<node->data)
	{
		node->left = deleteNode(a, node->left);
	}
	else if(a>node->data)
	{
		node->right = deleteNode(a, node->right);
	}
	else
	{
		if(node->left==NULL)
		{
			Node * temp = node->right;
			delete node;
			return temp;
		}
		else if(node->right==NULL)
		{
			Node *temp = node->left;
			delete node;
			return temp;
		}
		else
		{
			Node *temp = findMinNode(node->right);
			node->data = temp->data;
			node->right = deleteNode(temp->data, node->right);
		}
	}
	return node;
}

int main()
{
	Tree tree;
	tree.addNode(5,&(tree.root));
	tree.addNode(2,&(tree.root));
	tree.addNode(-4,&(tree.root));
	tree.addNode(3,&(tree.root));

	tree.addNode(12,&(tree.root));
	tree.addNode(9,&(tree.root));
	tree.addNode(21,&(tree.root));
	tree.addNode(19,&(tree.root));
	tree.addNode(25,&(tree.root));
	cout<<"pre Order: ";
	tree.preOrder(tree.root);
	tree.deleteNode(12,tree.root);
	cout<<"pre Order: ";
	tree.preOrder(tree.root);
	cout<<endl<<"in order: ";
	tree.inOrder(tree.root);
	cout<<endl<<"post order: ";
	tree.postOrder(tree.root);

	return 0;
}

