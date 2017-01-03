#include <bits/stdc++.h>
using namespace std;

template <class item>
class MinBinaryHeap
{
	vector <item> key;
	int n;
	
	public:
	MinBinaryHeap()
	{
		n=0;
	}
	
	void push(item a)
	{
		key.push_back(a);
		n++;
		swim(n);
	}
	
	item pop()
	{
		item max = key[0];
		swap(key[0], key[n-1]);
		key.pop_back();
		n--;
		sink(1);
		return max;
	}
	int size()
	{
	    return n;
	}
	
	bool empty()
	{
	    return (n?false:true);
	}
	private:
	void swim(item k)
	{
		item parent = k/2;
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
	
	void sink(item k)
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
	
	void swap(item &a, item &b)
	{
		item temp = a;
		a = b;
		b = temp;
	}
	
};

int main()
{
	MinBinaryHeap <long> mbh;
	mbh.push(1);
	mbh.push(2);
	mbh.push(3);
	mbh.push(7);
	mbh.push(4);
	mbh.push(5);

	cout<<mbh.pop();
}
