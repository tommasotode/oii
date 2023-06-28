#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{
	private:
		int n;
		vector<int> t;
		function<int(int, int)> func;

		void build(vector<int>& data, int node, int tl, int tr)
		{
			if (tl == tr)
				t[node] = data[tl];
			else
			{
				int tm = (tl + tr) / 2;
				build(data, node*2, tl, tm);
				build(data, node*2+1, tm+1, tr);
				t[node] = func(t[node*2], t[node*2+1]);
			}
		}

		int query(int node, int tl, int tr, int l, int r)
		{
			if (l > r) 
				return INT_MIN;
			
			if (l == tl && r == tr)
				return t[node];

			int tm = (tl + tr) / 2;

			return func(query(node*2, tl, tm, l, min(r, tm)), query(node*2+1, tm+1, tr, max(l, tm+1), r));
		}

		void update(int node, int tl, int tr, int pos, int new_val)
		{
			if (tl == tr)
				t[node] = new_val;
				
			else 
			{
				int tm = (tl + tr) / 2;
				
				if (pos <= tm)
					update(node*2, tl, tm, pos, new_val);
				else
					update(node*2+1, tm+1, tr, pos, new_val);
				
				t[node] = func(t[node*2], t[node*2+1]);
			}
		}

		int get_first(int node, int lv, int rv, int l, int r, int x)
		{
			if(lv > r || rv < l)
				return -1;
			
			if(l <= lv && rv <= r)
			{
				if(t[node] <= x)
					return -1;
				
				while(lv != rv)
				{
					int mid = lv + (rv-lv)/2;
					if(t[2*node] > x)
					{
						node = 2*node;
						rv = mid;
					}
					else
					{
						node = 2*node+1;
						lv = mid+1;
					}
				}
				return lv;
			}

			int mid = lv + (rv-lv)/2;
			int rs = get_first(2*node, lv, mid, l, r, x);
			if(rs != -1)
				return rs;

			return get_first(2*node+1, mid+1, rv, l ,r, x);
		}

	public:
		SegmentTree(vector<int>& data, function<int(int, int)> query)
		{
			n = data.size();
			t.resize(4*n);
			func = query;
			build(data, 1, 0, n-1);
		}

		int query(int l, int r)
		{
			return query(1, 0, n-1, l, r);
		}

		void update(int pos, int new_val)
		{
			update(1, 0, n-1, pos, new_val);
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