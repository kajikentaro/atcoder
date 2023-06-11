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
  vector<string> s(n);
  vector<string> t(n);
  rep(i,n)cin >> s[i];
  rep(i,n)cin >> t[i];

  auto rotate = [&](vector<string>& a){
    vector<string> b(n,a[0]);
    rep(i,n){
      rep(j,n){
        b[i][j] = a[j][n-i-1];
      }
    }
    swap(a,b);
  };

  auto get_base = [&](vector<string> &a, int &ai, int&aj){
    ai = 1e9;
    aj = 1e9;
    rep(i,n)rep(j,n){
      if(a[i][j] == '#'){
        chmin(ai, i);
        chmin(aj, j);
      }
    }
  };

  rep(_,4){
    int si_b,sj_b,ti_b,tj_b;
    get_base(s,si_b,sj_b);
    get_base(t,ti_b,tj_b);
    bool ok = true;
    rep(i,n)rep(j,n){
      int si = si_b + i;
      int sj = sj_b + j;

      int ti = ti_b + i;
      int tj = tj_b + j;

      if((si >= n||sj >=n)&&(ti >=n||tj >=n))continue;
      if(si >= n||sj >=n){
        if(t[ti][tj] == '#')ok = false;
        continue;
      }
      if(ti >= n||tj >=n){
        if(s[si][sj] == '#')ok = false;
        continue;
      }
      if(s[si][sj] != t[ti][tj])ok = false;
    }
    if(ok){
      cout << "Yes" << endl;
      return 0;
    }
    rotate(s);
  }
  cout << "No" << endl;
}
