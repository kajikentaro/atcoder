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
struct SameIdxs {
  int extends = -1;
  vector<int> idx_list;
};
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  vector<SameIdxs> res(n);
  vector<int> same_b_idx;
  int bi = 0;
  set<int> only_b;
  set<int> all_b;
  rep(ai, n) {
    same_b_idx.resize(0);
    while (bi <= n - 1) {
      all_b.insert(b[bi]);
      if (a[ai] == b[bi]) {
        while (bi + 1 <= n - 1 && all_b.count(b[bi + 1])) {
          same_b_idx.push_back(bi);
          bi++;
        }
        break;
      } else {
        only_b.insert(b[bi]);
        bi++;
        continue;
      }
    }
    while (ai <= n - 1 && bi <= n - 1) {
      if (all_b.count(a[ai]) == 0) {
        ai--;
        break;
      }
      only_b.erase(a[ai]);
      if (only_b.size() == 0) {
        for (auto sbi : same_b_idx) {
          res[ai].idx_list.push_back(sbi);
        }
        res[ai].idx_list.push_back(bi);

        int backup_ai = ai;
        while (ai + 1 <= n - 1 && all_b.count(a[ai + 1])) {
          ai++;
          res[ai].extends = backup_ai;
        }
        bi++;
        break;
      } else {
        ai++;
        continue;
      }
    }
  }
  int q;
  cin >> q;
  rep(i, q) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    if (res[x].extends != -1) x = res[x].extends;
    auto exists =
        binary_search(res[x].idx_list.begin(), res[x].idx_list.end(), y);
    if (exists) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}