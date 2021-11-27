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
  int n,m;
  cin >> n >> m;
  vector<int> active(n, -1);
  vector<queue<int>> stick(m);
  rep(i,m){
    int k;
    cin >> k;
    rep(_,k){
      int a;
      cin >> a;
      a--;
      stick[i].push(a);
    }
  }
  queue<int> que;
  rep(i,m)que.push(i);
  while(que.size()){
    int i = que.front();
    que.pop();
    if(stick[i].size() == 0)continue;

    int ball = stick[i].front();

    if(active[ball] == -1){
      active[ball] = i;
    }else{
      stick[i].pop();
      stick[active[ball]].pop();
      que.push(i);
      que.push(active[ball]);
    }
  }
  rep(i,m){
    if(stick[i].size()){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}