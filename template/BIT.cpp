#include <bits/stdc++.h>
using namespace std;
// Binary Index Tree
template <typename T>
struct BIT {
  int n;
  vector<T> bit;
  BIT(int n) : n(n + 1), bit(n + 1, 0) {}
  void add(int p, T x) {
    // (i&-1)で末尾の1を求める
    for (int i = p; i < n; i += (i & -i)) {
      bit[i] += x;
    }
  }
  T sum(int p) {
    T s(0);
    for (int i = p; i > 0; i -= (i & -i)) {
      s += bit[i];
    }
    return s;
  }
};
