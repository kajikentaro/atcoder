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
  int n, k;
  cin >> n >> k;
  vector<string> s(n);
  rep(i,n)cin >> s[i];

  int ans = 0;
  rep(i,1<<n){
    map<char, int> ma;
    rep(j,n){
      if(i >> j & 1){
        string str = s[j];
        for(auto c : str){
          ma[c]++;
        }
      }
    }
    int tmp_ans = 0;
    for(auto m : ma){
      if(m.second == k)tmp_ans++;
    }
    chmax(ans, tmp_ans);
  }
  cout << ans << endl;
}