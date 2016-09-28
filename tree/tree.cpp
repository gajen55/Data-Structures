#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int data;
	Node *left;
	Node *right;
} Node;

class Tree
{
	Node *root;
	void addNode(int a, Node **cur);
	void preOrder(Node *node);
	void inOrder(Node *node);
	void postOrder(Node *node);
	void deleteTree(Node *node);
	Node * deleteNode(int a, Node *node);
	Node * findMinNode(Node *node);
	
	public:
	Tree()
	{
		root = NULL;
	};
	void addNode(int a);
	void preOrder();
	void inOrder();
	void postOrder();
	Node * deleteNode(int a);
	~Tree()
	{
	    deleteTree(root);
	}
};

void Tree :: addNode(int a)
{
    addNode(a,&root);
}

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

void Tree :: preOrder()
{
    preOrder(root);
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

void Tree :: inOrder()
{
    inOrder(root);
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

void Tree :: postOrder()
{
    postOrder(root);
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

void Tree :: deleteTree(Node *node)
{
    if(node!=NULL)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout<<node->data<<" is deleted"<<endl;
        delete node;
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

Node * Tree :: deleteNode(int a)
{
    deleteNode(a, root);
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
	tree.addNode(5);
	tree.addNode(2);
	tree.addNode(-4);
	tree.addNode(3);

	tree.addNode(12);
	tree.addNode(9);
	tree.addNode(21);
	tree.addNode(19);
	tree.addNode(25);
	cout<<"pre Order: ";
	tree.preOrder();
	cout<<endl;
	tree.deleteNode(12);
	cout<<"pre Order: ";
	tree.preOrder();
	cout<<endl;
	cout<<"in order: ";
	tree.inOrder();
	cout<<endl;
	cout<<"post order: ";
	tree.postOrder();
	cout<<endl;

	return 0;
}

