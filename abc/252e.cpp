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
vector<int> ans;
struct Path{
  int to;
  int dist;
  int idx;
  Path(int to, int dist, int idx):to(to), dist(dist), idx(idx){}
};
void dfs(int p, int now_c, vector<int> &used, vector<vector<Path>> &path){
  rep(i, path[p].size()){
    int new_c = now_c + path[p][i].dist;
    int new_p = path[p][i].to;
    int path_idx = path[p][i].idx;
    if(used[new_p] == new_c){
      ans[path[p][i].idx] = 1;
      dfs(new_p, new_c, used, path);
    }
  }
}
int main(){
  int n, m;
  cin >> n >> m;
  ans.resize(m);
  vector<vector<Path>> path(n);
  rep(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    path[a].emplace_back(b, c, i);
    path[b].emplace_back(a, c, i);
  }
  priority_queue<P, vector<P>, greater<P>> que;
  vector<int> used(n, -1);
  que.emplace(0, 0);
  while(que.size()){
    int now_c, now_p;
    tie(now_c, now_p) = que.top();
    que.pop();
    if(used[now_p] != -1)continue;
    used[now_p] = now_c;
    for(auto new_tmp : path[now_p]){
      int new_cost = new_tmp.dist + now_c;
      int new_p = new_tmp.to;
      if(used[new_p] != -1)continue;
      que.emplace(new_cost, new_p);
    }
  }
  dfs(0, 0, used, path);
  rep(i,ans.size()){
    if(ans[i]){
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}