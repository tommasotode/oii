#include <utility>
#include <vector>
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
		vector<int> tree;
		Node root;
		function<int(int, int)> func;

		void build(vector<int>& data, Node node)
		{
			if (node.left == node.right)
				tree[node.index] = data[node.left];
			else
			{
				int mid = (node.left + node.right) / 2;
				Node left = {node.index*2, node.left, mid};
				Node right = {node.index*2 + 1, mid + 1, node.right};
				
				build(data, left);
				build(data, right);
				tree[node.index] = func(tree[node.index*2], tree[node.index*2 + 1]);
			}
		}

		int query(Node node, int l, int r)
		{
			if (l > r)
				return INT_MIN;	// da cambiare in base alla query
			
			if (node.left == l && node.right == r)
				return tree[node.index];

			int mid = (node.left + node.right) / 2;
			Node left = {node.index*2, node.left, mid};
			Node right = {node.index*2 + 1, mid + 1, node.right};

			int end = min(r, mid), start = max(l, mid + 1);
			int tmp_l = query(left, l, end);
			int tmp_r = query(right, start, r);

			return func(tmp_l, tmp_r);
		}

		void update(Node node, int pos, int val)
		{
			if (node.left == node.right)
				tree[node.index] = val;
			else 
			{
				int mid = (node.left + node.right) / 2;
				Node left = {node.index*2, node.left, mid};
				Node right = {node.index*2 + 1, mid + 1, node.right};

				if (pos <= mid)
					update(left, pos, val);
				else
					update(right, pos, val);
				
				tree[node.index] = func(tree[node.index*2], tree[node.index*2 + 1]);
			}
		}

		int first_greater(Node node, int l, int r, int val)
		{
			if(node.left > r || node.right < l)
				return -1;
			
			if(node.left >= l && node.right <= r)
			{
				if(tree[node.index] <= val)
					return -1;
				
				while(node.left != node.right)
				{
					int mid = node.left + (( node.right - node.left ) / 2);
					if(tree[node.index*2] > val)
					{
						node.index = node.index*2;
						node.right = mid;
					}
					else
					{
						node.index = node.index*2 + 1;
						node.left = mid + 1;
					}
				}
				return node.left;
			}
			
			int mid = node.left + (node.right - node.left) / 2;
			Node left = {node.index*2, node.left, mid};
			Node right = {node.index*2 + 1, mid + 1, node.right};
			
			int result = first_greater(left, l, r, val);
			if(result != -1)
				return result;
			return first_greater(right, l , r, val);
		}
		
		int last_greater(Node node, int l, int r, int val)
		{
			if(node.left > r || node.right < l)
				return -1;
			
			if(node.left >= l && node.right <= r)
			{
				if(tree[node.index] <= val)
					return -1;
				
				while(node.left != node.right)
				{
					int mid = node.left + (( node.right - node.left ) / 2);
					if(tree[node.index*2 + 1] > val)
					{
						node.index = node.index*2 + 1;
						node.left = mid + 1;
					}
					else
					{
						node.index = node.index*2;
						node.right = mid;
					}
				}
				return node.left;
			}
			
			int mid = node.left + (node.right - node.left) / 2;
			Node left = {node.index*2, node.left, mid};
			Node right = {node.index*2 + 1, mid + 1, node.right};
			
			int result = last_greater(right, l, r, val);
			if(result != -1)
				return result;
			return last_greater(left, l , r, val);
		}
		
	public:
		vector<int> d;
		int n;

		SegmentTree()
		{
		}

		SegmentTree(vector<int>& data, function<int(int, int)> query)
		{
			n = data.size();
			tree.resize(n*4);
			d = data;
			func = query;
			root = {1, 0, n-1};
			build(data, root);
		}

		void update(int pos, int val)
		{
			update(root, pos, val);
		}

		int first_greater(int l, int r, int val)
		{
			return first_greater(root, l, r, val);
		}

		int last_greater(int l, int r, int val)
		{
			return last_greater(root, l, r, val);
		}
};

SegmentTree st;
void inizializza(int N, vector<int> H)
{
	st = SegmentTree(H, [](int x, int y) -> int { return max(x, y); });
	return;
}

pair<int, int> chiedi(int x)
{
	int l = st.last_greater(0, x, st.d[x]);
	if (l == -1)
		l = 0;
	
	int r = st.first_greater(x, st.n-1, st.d[x]);
	if (r == -1)
		r = st.n-1;

	return {l, r};
}

void cambia(int x, int h)
{
	st.update(x, h);
	st.d[x] = h;
	return;
}