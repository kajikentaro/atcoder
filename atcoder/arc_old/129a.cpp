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
string toBinary(ll n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}
int main(){
  ll n,l,r;
  cin >> n >> l >> r;
  string sn = toBinary(n);
  string sl = toBinary(l);
  string sr = toBinary(r);
  int sn_k = sn.size();
  int sl_k = sl.size();
  int sr_k = sr.size();
  ll ans = 0;
  rep(i,sn_k){
    if(sl_k > i + 1)continue;
    if(sr_k < i + 1)continue;
    if(sn[i] == '1'){
      if(sr_k - 1 == i){
        ans += r - powl((ll)2,sr_k - 1) + 1;
      }else{
        ans += powl((ll)2,i);
      }
      if(sl_k - 1 == i){
        ans -= l - powl((ll)2,sl_k - 1);
      }
    }
  }
  printf("%lld\n", ans);
  
}
