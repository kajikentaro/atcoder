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
using mint = modint998244353;
using P = pair<int,int>;
vector<vector<int>> path;
vector<int> used;
vector<int> loop;
map<ll,int> path_used;
int is_path_used(int a, int b){
  if(a < b)swap(a,b);
  if(path_used[a + b * pow(10,6)] >= 1)return 1;
  return 0;
}
void use_path(int a, int b){
  if(a < b)swap(a,b);
  path_used[a + b * pow(10,6)]++;
}
int dfs(int v){
  if(used[v]){
    return 1;
  }
  used[v] = 1;
  int circle = 0;
  for(auto p : path[v]){
    if(is_path_used(v, p) == 1)continue;
    use_path(v, p);
    circle += dfs(p);
  }
  return circle;
}
mint func(){
  int n,m;
  cin >> n >> m;
  path.resize(n);
  used.resize(n);
  loop.resize(n);
  dsu uf(n);
  rep(i,m){
    int u,v;
    cin >> u >> v;
    u--;v--;
    path[u].push_back(v);
    path[v].push_back(u);
    uf.merge(u,v);
  }
  int loop = 0;
  for(auto group : uf.groups()){
    int path_n = 0;
    for(auto v : group){
      path_n += path[v].size();
    }
    path_n /= 2;
    if(group.size() != path_n)return (mint)0;
  }
  for(auto group : uf.groups()){
    loop += dfs(group[0]);
  }
  mint ans = 1;
  rep(i,loop){
    ans *= 2;
  }
  return ans;
}
int main(){
  cout << func().val() << endl;
}
