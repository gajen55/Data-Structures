#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26
struct Node
{
	bool word;
	Node *children[ALPHABET_SIZE];
};

class Trie
{
	Node *root;
	
	public:
	Trie()
	{
		root = new Node();
		root->word = false;
		for(int i=0; i<ALPHABET_SIZE; i++)
		{
			root->children[i] = NULL;
		}
	}
		
	void insert(string key)
	{
		Node *temp = root;
		int length = key.size();
		for(int i=0; i<length; i++)
		{
			int index = getIndex(key[i]);
			if(!temp->children[index])
			{
				temp->children[index] = getNode();
			}
			temp = temp->children[index];
		}
		temp->word = true;
	}
	
	bool search(string key)
	{
		Node *temp = root;
		int length = key.size();
		for(int i=0; i<length; i++)
		{
			int index = getIndex(key[i]);

			if(!temp->children[index])
			{
				return false;
			}
			temp = temp->children[index];
		}
		return (temp && temp->word);
	}
	
	private:
	Node *getNode()
	{
		Node *temp = new Node();
		root->word = false;
		for(int i=0; i<ALPHABET_SIZE; i++)
		{
			temp->children[i] = NULL;
		}
		return temp;
	}
	
	int getIndex(char c)
	{
		return (c-'a');
	}
};

int main()
{
	Trie t;
	t.insert("these");
	cout<<t.search("the")<<endl;
	cout<<t.search("these")<<endl;
	return 0;
}
	
