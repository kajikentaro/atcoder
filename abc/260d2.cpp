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
int main() {
  int n, k;
  cin >> n >> k;
  set<int> se;
  vector<vector<int>> log;
  vector<int> ans(n, -1);
  unordered_map<int, int> log_id_map;
  if (k == 1) {
    orep(i, n) { cout << i << endl; }
    return 0;
  }
  orep(i, n) {
    int p;
    cin >> p;
    p--;
    auto itr = se.lower_bound(p);
    if (itr == se.end()) {
      // 見つからない場合
      log_id_map[p] = log.size();
      se.insert(p);
      log.push_back({p});
      continue;
    }

    // 重ねる場合
    int log_id = log_id_map[*itr];
    se.erase(itr);
    log_id_map[p] = log_id;
    log[log_id].push_back(p);
    se.insert(p);

    if (log[log_id].size() == k) {
      // 食べる場合
      for (auto l : log[log_id]) {
        ans[l] = i;
      }
      se.erase(p);
    }
  }

  for (auto a : ans) {
    cout << a << endl;
  }
}