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
  priority_queue<int,vector<int>,greater<int>> que;
  dsu uf(n);
  vector<vector<int>> path_out(n);
  vector<int> path_in(n);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    path_out[a].push_back(b);
    path_in[b]++;
    uf.merge(a,b);
  }
  rep(i,n){
    if(path_in[i] == 0)que.push(i);
  }
  /*
  for(auto vec : uf.groups()){
    bool clear = false;
    for(auto v : vec){
      if(path_in[v] == 0){
        que.push(v);
        clear = true;
      }
    }
    if(clear == false){
      cout << -1 << endl;
      return 0;
    }
  }
  */
  vector<int> ans;
  while(que.size()){
    int v = que.top();
    que.pop();
    ans.push_back(v);
    for(auto v_next: path_out[v]){
      path_in[v_next]--;
      if(path_in[v_next] == 0){
        que.push(v_next);
      }
    }
  }
  rep(i,n){
    if(path_in[i] != 0){
      cout << -1 << endl;
      return 0;
    }
  }
  /*
  rep(i,n){
    for(auto pn : path_in){
      if(pn != 0){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  */
  for(auto a : ans){
    cout << a + 1 << " ";
  }
  cout << endl;
}