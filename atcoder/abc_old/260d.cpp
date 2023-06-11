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
  int p;
  int log_id;
};
bool operator<(const Block &a, const Block &b) { return a.p < b.p; }
int main() {
  int n, k;
  cin >> n >> k;
  set<Block> se;
  vector<vector<int>> log;
  vector<int> ans(n, -1);
  if (k == 1) {
    orep(i, n) { cout << i << endl; }
    return 0;
  }
  orep(i, n) {
    int p;
    cin >> p;
    p--;
    auto itr = se.lower_bound(Block{p, 0});
    if (itr == se.end()) {
      // 見つからない場合
      se.insert(Block{p, (int)log.size()});
      log.push_back({p});
      continue;
    }
    int log_id = itr->log_id;

    if (log[log_id].size() >= k - 1) {
      // 食べる場合
      for (auto l : log[log_id]) {
        ans[l] = i;
      }
      ans[p] = i;
      se.erase(itr);
      continue;
    }

    // 重ねる場合
    se.erase(itr);
    log[log_id].push_back(p);
    se.insert({p, log_id});
  }

  for (auto a : ans) {
    cout << a << endl;
  }
}