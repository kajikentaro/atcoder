#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b) {
  return a < b ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  return b < a ? (a = b, 1) : 0;
}
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int, int>;

struct Block {
  int w;
  set<int> neighbor;
};

void calc_neighbor(vector<Block> &a) {
  int n = a.size();
  rep(i, n) {
    rep(j, n) {
      if (abs(a[i].w - a[j].w) <= 1) {
        a[i].neighbor.insert(j);
      }
    }
  }
}

vector<Block> remove_2_connection(vector<Block> &a) {
  int n = a.size();
  calc_neighbor(a);
  vector<bool> is_alive(n, true);
  rep(i, n) {
    if (i <= 0) continue;
    int A = i;
    int B = i - 1;
    if (a[A].neighbor.count(B)) {
      i += 1;
      is_alive[A] = false;
      is_alive[B] = false;
    }
  }
  vector<Block> new_a;
  rep(i, n) {
    if (is_alive[i]) new_a.push_back(a[i]);
  }
  return new_a;
}

vector<Block> remove_4_connection(vector<Block> &a) {
  int n = a.size();
  calc_neighbor(a);
  vector<bool> is_alive(n, true);
  rep(i, n) {
    if (i <= 2) continue;
    if (is_alive[i] == false) continue;
    int A = i;
    int B = i - 1;
    int C = i - 2;
    int D = i - 3;
    if (a[B].neighbor.count(C) && a[A].neighbor.count(D)) {
      i += 3;
      is_alive[A] = false;
      is_alive[B] = false;
      is_alive[C] = false;
      is_alive[D] = false;
    }
  }
  vector<Block> new_a;
  rep(i, n) {
    if (is_alive[i]) new_a.push_back(a[i]);
  }
  return new_a;
}

bool func() {
  int n;
  cin >> n;
  if (n == 0) return false;

  vector<Block> a(n);
  rep(i, n) cin >> a[i].w;

  int start_n;
  while (1) {
    start_n = a.size();
    while (1) {
      vector<Block> new_a = remove_4_connection(a);
      swap(new_a, a);
      if (new_a.size() == a.size()) break;
    }
    vector<Block> new_a = remove_2_connection(a);
    swap(new_a, a);
    if (a.size() == start_n) break;
  }

  cout << (n - a.size()) << endl;

  return true;
}
int main() {
  while (func()) {
    ;
  }
}