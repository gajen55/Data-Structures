#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;
    friend class List;
};

class List
{
    Node *head;
    public:
    List()
    {
        head=NULL;
    }
    
    void insertNodeFront(int a)
    {
        Node *temp = new Node();
        temp->data=a;
        temp->prev=NULL;
        if(head==NULL)
        {
            head = temp;
            head->next = NULL;
        }
        else
        {
            temp->next=head;
        
            head->prev=temp;
            head = temp;
        }
    }
    
    void addLoop()
    {
        Node *temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
    
    bool detectLoop()
    {
        Node *slow = head;
        Node *fast = head->next;
        while((slow!=NULL && fast!=NULL && fast->next!=NULL) )
        {
            if(slow==fast) return true;
            slow = slow->next;
            fast=fast->next->next;
        }
        return false;
    }
    
    void reverseList()
    {
        if(head==NULL || head->next==NULL)
        {
            cout<<"no need to revrese\n";
            
        }
        else
        {
            Node *temp;
            Node *cur = head;
            while(cur->next!=NULL)
            {
                temp = cur->next;
                cur->next = cur->prev;
                cur->prev = temp;
                cur = temp;
            }
            cur->next = cur->prev;
            cur->prev = NULL;
            head = cur;
        }
    }
    void printList()
    {
        Node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data;
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
	List list;

	list.insertNodeFront(1);
	list.insertNodeFront(2);
	list.insertNodeFront(3);
	list.insertNodeFront(4);
	list.insertNodeFront(5);
	list.insertNodeFront(6);
	//list.addLoop();
	list.printList();
	list.reverseList();
	list.printList();

	return 0;
}
