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
struct UF{
    vector<int> uf;
    int root_n;
    UF(int n):uf(n, -1), root_n(n){}
    int find(int a){
        if(uf[a] < 0)return a;
        return uf[a] = find(uf[a]);
    }
    int size(int a){
        return -uf[find(a)];
    }
    int merge(int a,int b){
        int ra = find(a);
        int rb = find(b);
        if(ra == rb)return 0;
        if(size(ra) < size(rb))swap(ra,rb);//sb is smaller
        uf[ra] += uf[rb];
        uf[rb] = ra;
        root_n--;
        return 1;
    }
    int get_root_n(){
      return root_n;
    }
    int same(int a,int b){
        if(find(a) == find(b))return 1;
        return 0;
    }
};
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> path(n);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    if(a > b)swap(a,b);
    path[a].push_back(b);
  }

  UF uf(n);
  vector<int> ans;
  ans.push_back(0);
  rrep(i,n){
    for(auto p : path[i]){
      uf.merge(i,p);
    }
    if(i == 0)break;
    ans.push_back(uf.get_root_n() - i);
  }
  rrep(i,n){
    cout << ans[i] << endl;
  }
}