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
void dfs(int p, vector<bool> &used, vector<int> &chain){
    if(used[p])return;
    used[p] = true;
    chain.push_back(p);
    for(int next : path[p]){
        dfs(next, used, chain);
    }
}
ll dfs2(int chain_p, vector<int> &chain, vector<int> &colors){
    if(chain_p == chain.size())return 1;
    int p = chain[chain_p];
    ll ans = 0;
    rep(i,3){
        bool ng = false;
        for(int next : path[p]){
            if(colors[next] == i){
                ng = true;
                break;
            }
        }
        if(ng)continue;
        colors[p] = i;
        ans += dfs2(chain_p + 1, chain, colors);
        colors[p] = -1;
    }
    return ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    path.resize(n);
    dsu d(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        path[a].push_back(b);
        path[b].push_back(a);
        d.merge(a,b);
    }
    vector<vector<int>> gs = d.groups();
    ll ans = 1;
    for(vector<int> g : gs){
        vector<bool> used(n, false);
        vector<int> chain;
        dfs(g[0],used,chain);
        vector<int> colors(n,-1);
        ans *= dfs2(0, chain,colors);
    }
    cout << ans << endl;
}
