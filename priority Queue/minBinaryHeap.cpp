#include <bits/stdc++.h>
using namespace std;

struct MinBinaryHeap
{
	vector <int> key;
	int n;
	
	void insert(int a)
	{
		key.push_back(a);
		n++;
		swim(n-1);
	}
	
	int remove()
	{
		int max = key[0];
		swap(key[0], key[key.size()-1]);
		key.pop_back;
		n--;
		sink(0);
		return max;
	}
	
	void swim(int N)
	{
		int parent = 2N;
		while(parent>=0)
		{
			if(key[parent]>key[N])
			{
				swap(key[parent], key[N])
			}
			parent = 2N;
		}
	}
	
	void sink(int N)
	{
		
	}
	
	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	
}
