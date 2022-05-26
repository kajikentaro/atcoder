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
  int a,b,c,d,e,f,x;
  cin >> a >> b >> c >> d >> e >> f >> x;
  int T = 0;
  int A = 0;
  orep(i,x){
    if(((i - 1) % (a + c) + 1) <= a)T += b;
    if(((i - 1) % (d + f) + 1) <= d)A += e;
  }
  if(T > A){
    cout << "Takahashi" << endl;
  }else if(A > T){
    cout << "Aoki" << endl;
  }else{
    cout << "Draw" << endl;
  }
}
