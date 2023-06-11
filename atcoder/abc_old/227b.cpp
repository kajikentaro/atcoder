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
bool func(int s){
  orep(a,300)orep(b,300){
    int ans = 4 * a * b + 3 * a + 3 * b;
    if(ans == s){
      return true;
    }
  }
  return false;
}
int main(){
  int n;
  cin >> n;
  int ans = 0;
  rep(i,n){
    int s;
    cin >> s;
    if(func(s) == false)ans++;
  }
  cout << ans << endl;
}