#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int,int>;
int main(){
  string s;
  int k,n;
  cin >> s >> k;
  n = s.size();
  vector<int> sum(n);
  rep(i,n){
    int ok = (s[i] == 'X' ? 1 : 0);
    if(i==0){
      sum[i] = ok;
      continue;
    }
    sum[i] = sum[i-1] + ok;
  }
  auto calc_sum = [&](int from, int cnt){
    if(cnt == 0)return 0;
    int to = from + cnt - 1;
    if(from - 1 < 0)return sum[to];
    return sum[to] - sum[from-1];
  };

  ll wa = n + 1;
  ll ac = 0;
  while(wa - ac != 1){
    ll wj = (wa + ac) / 2;
    bool ok = false;
    rep(i,n){
      if(i + wj - 1 > n - 1)break;
      int s = calc_sum(i, wj);
      if(s + k >= wj){
        ok = true;
        break;
      }
    }
    if(ok)ac = wj;
    else wa = wj;
  }
  cout << ac << endl;
}