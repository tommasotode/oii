#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
int L[375001], R[375001];

void merge(vector<int>& v, int l, int m, int r) {
  int n1 = m-l+1, n2 = r-m, i, j=0, k=l;
  for(i = 0; i < n1; ++i) L[i] = v[l+i];
  for(i = 0; i < n2; ++i) R[i] = v[m+i+1];

  i = 0;
  while(i < n1 && j < n2) {
    if(L[i] < R[j]) {
      v[k] = L[i];
      ++i;
    } else {
      v[k] = R[j];
      ++j;
      ans += j + m - k; // aumento numero di scambi
    }
    ++k;
  }

  while(i < n1) {
    v[k] = L[i];
    ++i;
    ++k;
  }

  while(j < n2) {
    v[k] = R[j];
    ++j;
    ++k;
  }
}

void mergesort(vector<int>& v, int l, int r) {
  if(l >= r) return;

  int mid = l + (r-l) / 2;
  mergesort(v, l, mid);
  mergesort(v, mid+1, r);
  merge(v, l, mid, r);
}

long long paletta_sort(int N, int V[]) {
  vector<int> a, b;
  for(int i = 0; i < N; ++i) {
    if(i % 2 == 0)
      a.push_back(V[i]);
    else 
      b.push_back(V[i]);
  }
  mergesort(a, 0, a.size() - 1);
  mergesort(b, 0, b.size() - 1);

  for(int i = 0; i < b.size(); ++i) {
    if(b[i] < a[i]) return -1;
  }
  return ans;
}
