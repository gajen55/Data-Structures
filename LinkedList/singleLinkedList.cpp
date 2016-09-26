#include <iostream>
#include <string>

using namespace std;

typedef struct Node{
	int data;
	Node * next;
} Node;

class List{

	public:
	Node *head;

	List()
	{
		head = NULL;
	}
	void AddNodeFront(int a);
	void AddNodeRear(int a);
	void deleteNode(int a);
	bool findLoop();
	void reverseList();
	void printList();

};

void List :: AddNodeFront(int a)
{
	Node *temp = new Node;
	temp->data = a;
	temp->next = NULL;

	if(head==NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

void List :: AddNodeRear(int a)
{
	Node *temp = new Node;
	temp->data = a;
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp;
	}
	else
	{
		Node *cur = head;
		while(cur->next!=NULL)
		{
			cur =cur->next;
		}
		cur->next = temp;
	}
}

void List :: deleteNode(int a)
{
	Node *prev, *cur;
	if(head==NULL)
	{
		cout<<"Nothing to delete\n";
	}
	else if(head->data==a)
	{
		delete head;
		head = NULL;
	}
	else
	{
		prev = head;
		cur = head->next;

		while(cur!=NULL)
		{
			if(cur->data==a)
			{
				prev->next = prev->next->next;
				delete cur;
			}
			prev = cur;
			cur = cur->next;
		}
	}
}

bool List :: findLoop()
{
	Node *slow, *fast;

	if(head==NULL || head->next==NULL)
	{
		cout<<"No list or only single node is there\n";
	}
	else
	{
		slow = head;
		fast = head;

		while(slow!=NULL || fast->next!=NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			if(slow==fast)
			{
				return true;
			}
		}
	}
	return false;
}

void List :: printList()
{
	Node *temp = head;

	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	List list;
	list.AddNodeFront(1);
	list.AddNodeFront(2);
	list.AddNodeFront(3);
	list.AddNodeFront(4);
	list.AddNodeFront(5);
	list.printList();
	list.deleteNode(3);
	list.printList();
	return 0;
}
