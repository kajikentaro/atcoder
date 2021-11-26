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
  string a[3];
  rep(i,3)cin >> a[i];
  string b[] = {"ABC","ARC","AGC","AHC"};
  rep(i,4){
    bool ok = false;
    rep(j,3){
      if(b[i] == a[j])ok = true;
    }
    if(ok == false){
      cout << b[i] << endl;
    }
  }
}
