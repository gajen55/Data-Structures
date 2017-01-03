#include <bits/stdc++.h>
using namespace std;

struct MinBinaryHeap
{
	vector <int> key;
	int n;
	
	MinBinaryHeap()
	{
		n=0;
	}
	
	void printer()
	{
	    for(int i=0; i<key.size(); i++)
	    {
	        cout<<key[i]<<endl;
	    }
	}
	void insert(int a)
	{
		key.push_back(a);
		n++;
		swim(n);
	}
	
	int remove()
	{
		int max = key[0];
		swap(key[0], key[n-1]);
		key.pop_back();
		n--;
		sink(1);
		return max;
	}
	
	void swim(int k)
	{
		int parent = k/2;
		while(parent>=1)
		{
			if(key[parent-1]>key[k-1])
			{
				swap(key[parent-1], key[k-1]);
			}
			k = parent;
			parent = k/2;
		}
	}
	
	void sink(int k)
	{
		int child;
		while(2*k<=n-1)
		{
			if(2*k == n-1)
			{
				child = 2*k;
			}
			else
			{
				if(key[2*k-1] < key[2*k])
					child = 2*k;
				else
					child = 2*k+1;
			}
			if(key[k-1]>key[child-1])
			    swap(key[k-1],key[child-1]);
			k = child;
		}
	}
	
	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	
};

int main()
{
	MinBinaryHeap mbh;
	mbh.insert(1);
	mbh.insert(2);
	mbh.insert(3);

	mbh.insert(7);
	mbh.insert(4);
	mbh.insert(5);
	
	//mbh.printer();
	cout<<mbh.remove();
}
