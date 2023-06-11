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
vector<vector<int>> path;
vector<int> lengths;
vector<map<int,int>> dp;
template<class MAP, class VALUE>
static bool contains_key(MAP m, VALUE v)
{
    return m.find(v) != m.end(); // findを使ったいつものやつ
}
int child_dfs(int p, int depth){
    if(contains_key(dp[p], depth)) return dp[p][depth];
    if(depth == 0){
        return dp[p][depth] = 1;
    }
    int ans = 0;
    for(auto next : path[p]){
        ans += child_dfs(next, depth - 1);
    }
    return dp[p][depth] = ans;
}
void dfs(int p,int length){
    lengths[p] = length;
    for(auto next : path[p]){
        dfs(next, length + 1);
    }
}
int main(){
    int n;
    cin >> n;
    path.resize(n);
    lengths.resize(n);
    dp.resize(n);
    rep(i,n){
        if(i==0)continue;
        int p; cin >> p; p--;
        path[p].push_back(i);
    }
    dfs(0,0);

    int q;
    cin >> q;
    rep(i,q){
        int u,d;
        cin >> u >> d;
        u--;
        int remain_length = d - lengths[u];
        int ans = child_dfs(u, remain_length);
        cout << ans << endl;
    }
}
