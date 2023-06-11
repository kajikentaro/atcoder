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
  int n,k;
  cin >> n >> k;
  vector<int> p(n);
  vector<int> p_backup(n);
  rep(i,n){
    int a,b,c;
    cin >> a >> b >> c;
    p[i] = a + b + c;
    p_backup[i] = a + b + c;
  }
  sort(p.rbegin(), p.rend());
  rep(i,n){
    int wa = -1;
    int ac = n-1;
    while(ac - wa != 1){
      int wj = (wa + ac + 1) / 2;
      if(p[wj] <= p_backup[i] + 300){
        ac = wj;
      }else{
        wa = wj;
      }
    }
    int possible_rank = ac + 1;
    if(possible_rank <= k){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}