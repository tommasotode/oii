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
		Node root;

		void build(vector<int>& data, Node node)
		{
			if (node.left == node.right)	// caso base
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
			if (l > r)	// caso base (minimo in questo caso)
				return INT_MIN;	// da cambiare in base alla query
			
			if (node.left == l && node.right == r)	// caso base definitivo
				return tree[node.index];	// quando rientra completamente nel range

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
			if (node.left == node.right)	// caso base
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
						node.index = 2*node.index + 1;
						node.left = mid + 1;
					}
				}
				return node.left;
			}
			int mid = node.left + (node.right - node.left) / 2;
			Node left = {node.index*2, node.left, mid};
			Node right = {node.index*2, mid + 1, node.right};
			
			int result = first_greater(left, l, r, val);
			if(result != -1)
				return result;
			return first_greater(right, l , r, val);
		}

	public:
		SegmentTree(vector<int>& data, function<int(int, int)> query)
		{
			n = data.size();
			tree.resize(n*4);
			func = query;
			root = {1, 0, n-1};
			build(data, root);
		}

		int query(int l, int r)
		{
			return query(root, l, r);
		}

		void update(int pos, int val)
		{
			update(root, pos, val);
		}

		int first_greater(int l, int r, int val)
		{
			return first_greater(root, l, r, val);
		}
};

int main()
{
	int length = 5;
	vector<int> tmp = {6, 2, 94, 4, 17};

	int l = 0, r = length - 1;
	SegmentTree s = SegmentTree(tmp, [](int x, int y) -> int { return max(x, y); });

	cout << s.first_greater(l, r, 94) << endl;
	s.update(3, 8953);
	cout << s.first_greater(l, r, 94) << endl;

	return 0;
}