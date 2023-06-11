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
//頂点1からnまでの最短経路を求めるプログラム
struct Path {
  ll time, pos;
  Path(ll time, ll pos) : time(time), pos(pos) {}
};
struct Poll {
  ll time, pos;
  Poll(ll time, ll pos) : time(time), pos(pos) {}
};
bool operator>(const Poll &a, const Poll &b) { return a.time > b.time; }
int main() {
  ll n;
  cin >> n;
  vector<vector<Path>> path(n);
  rep(i, n - 1) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    path[a].emplace_back(c, b);
    path[b].emplace_back(c, a);
  }

  ll q, k;
  cin >> q >> k;
  k--;
  priority_queue<Poll, vector<Poll>, greater<Poll>> que;
  que.emplace(0, k);
  vector<ll> res(n, -1);
  while (que.size()) {
    Poll p = que.top();
    que.pop();
    if (res[p.pos] != -1) continue;
    res[p.pos] = p.time;
    for (auto i : path[p.pos]) {
      que.emplace(p.time + i.time, i.pos);
    }
  }

  vector<ll> ans_list;
  rep(i, q) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    ll ans = res[x] + res[y];
    ans_list.push_back(ans);
  }
  for (auto a : ans_list) {
    cout << a << endl;
  }
}