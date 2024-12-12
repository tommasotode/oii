#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
  int index;
  int left;
  int right;
} Node;

class MaxSegmentTree
{
private:
  Node root;
  vector<int> tree;

  void build(vector<int> &data, Node node)
  {
    if (node.left == node.right)
      tree[node.index] = data[node.left];
    else
    {
      int mid = (node.left + node.right) / 2;
      Node left = {node.index * 2, node.left, mid};
      Node right = {node.index * 2 + 1, mid + 1, node.right};

      build(data, left);
      build(data, right);
      tree[node.index] = max(tree[node.index * 2], tree[node.index * 2 + 1]);
    }
  }

  int get_max(Node node, int l, int r)
  {
    if (l > r)
      return INT_MIN;

    if (node.left == l && node.right == r)
      return tree[node.index];

    int mid = (node.left + node.right) / 2;
    Node left = {node.index * 2, node.left, mid};
    Node right = {node.index * 2 + 1, mid + 1, node.right};

    int end = min(r, mid);
    int start = max(l, mid + 1);

    int tmp_l = get_max(left, l, end);
    int tmp_r = get_max(right, start, r);

    return max(tmp_l, tmp_r);
  }

  void update(Node node, int pos, int val)
  {
    if (node.left == node.right)
      tree[node.index] = val;
    else
    {
      int mid = (node.left + node.right) / 2;
      Node left = {node.index * 2, node.left, mid};
      Node right = {node.index * 2 + 1, mid + 1, node.right};

      if (pos <= mid)
        update(left, pos, val);
      else
        update(right, pos, val);

      tree[node.index] = max(tree[node.index * 2], tree[node.index * 2 + 1]);
    }
  }

public:
  int n;
  vector<int> data;

  MaxSegmentTree(vector<int> &data)
  {
    n = data.size();
    tree.resize(n * 4);
    this->data = data;
    root = {1, 0, n - 1};
    build(data, root);
  }

  void update(int pos, int val)
  {
    update(root, pos, val);
  }

  int get_max(int l, int r)
  {
    return get_max(root, l, r);
  }
};