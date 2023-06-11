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
  int n;
  cin >> n;
  vector<P> input(n);
  rep(i,n)cin >> input[i].first >> input[i].second;
  int ans = 0;
  rep(i,n)rep(j,i)rep(k,j){
    P a(input[j].first - input[i].first, input[j].second - input[i].second);
    P b(input[k].first - input[i].first, input[k].second - input[i].second);
    if(a.first == 0){
      if(b.first == 0)continue;
      ans++;
      continue;
    }
    if(b.first == 0){
      if(a.first == 0)continue;
      ans++;
      continue;
    }
    if(a.second * b.first != b.second * a.first)ans++;
  }
  cout << ans << endl;
}
