#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
	int index;
	int left;
	int right;
} Node;

class SegmentTree
{
	private:
		int n;
		vector<int> tree;
		function<int(int, int)> func;

		void build(vector<int>& data, int node, int l_tr, int r_tr)
		{
			if (l_tr == r_tr)
				tree[node] = data[l_tr]; // caso base
			else
			{
				int mid_seg = (l_tr + r_tr) / 2;
				build(data, node*2, l_tr, mid_seg);
				build(data, node*2 + 1, mid_seg + 1, r_tr);
				
				tree[node] = func(tree[node*2], tree[node*2 + 1]);
			}
		}

		int query(int node, int l_tr, int r_tr, int l, int r)
		{
			if (l > r) 
				return INT_MIN;
			
			if (l_tr == l && r_tr == r)
				return tree[node];

			int mid_tr = (l_tr + r_tr) / 2;

			int left = query(node*2, l_tr, mid_tr, l, min(r, mid_tr));
			int right = query(node*2 + 1, mid_tr + 1, r_tr, max(l, mid_tr + 1), r);

			return func(left, right);
		}

		void update(int node, int l_tr, int r_tr, int pos, int val)
		{
			if (l_tr == r_tr)
				tree[node] = val; // caso base
				
			else 
			{
				int mid_tr = (l_tr + r_tr) / 2;
				
				if (pos <= mid_tr)
					update(node*2, l_tr, mid_tr, pos, val);
				else
					update(node*2 + 1, mid_tr + 1, r_tr, pos, val);
				
				tree[node] = func(tree[node*2], tree[node*2 + 1]);
			}
		}

		int first_greater(int node, int l_node, int r_node, int l, int r, int val)
		{
			if(l_node > r || r_node < l)
				return -1;
			
			if(l_node >= l && r_node <= r)
			{
				if(tree[node] <= val)
					return -1;
				
				while(l_node != r_node)
				{
					int mid = l_node + (( r_node - l_node ) / 2);
					
					node = (tree[node*2] > val) ? node*2 : node*2 + 1;
					r_node = (tree[node*2] > val) ? mid : r_node;
					l_node = (tree[node*2] > val) ? l_node : mid + 1;
				}

				return l_node;
			}

			int mid = l_node + (r_node-l_node) / 2;
			
			int result = first_greater(node*2, l_node, mid, l, r, val);
			if(result != -1)
				return result;

			return first_greater(node*2 + 1, mid + 1, r_node, l ,r, val);
		}

	public:
		SegmentTree(vector<int>& data, function<int(int, int)> query)
		{
			n = data.size();
			tree.resize(n*4);
			func = query;
			build(data, 1, 0, n-1);
		}

		int query(int l, int r)
		{
			return query(1, 0, n-1, l, r);
		}

		void update(int pos, int val)
		{
			update(1, 0, n-1, pos, val);
		}
};

int main()
{
	int length = 5;
	vector<int> tmp = {6, 2, 94, 4, 17};

	int l = 0, r = length - 1;

	SegmentTree s = SegmentTree(tmp, [](int x, int y) -> int { return max(x, y); });

	int m = s.query(l, r);
	cout << m << endl;

	return 0;
}