#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
int main(){
  int n,k;
  string s;
  cin >> n >> k >> s;
  int ans = 0;
  rep(i,n)if(s[i] == '.')ans++;
  auto calc = [&](int t){
    int c = 0;
    rep(i,n){
      if(k == 0)return;
      if(s[i] == 'S')c++;
      else c = 0;
      if(c == t){
        k--;
        ans += t;
        rep(j,t){
          s[i - j] = '.';
        }
        c = 0;
      }
    }
  };
  calc(3);
  calc(2);
  calc(1);
  cout << ans << endl;
}