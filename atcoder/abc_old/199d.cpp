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
ll dfs(int p, vector<int> colors){
    int col_now = colors[p];
    int col_new[2] = {(col_now + 1) % 3, (col_now + 2) % 3};
    vector<int> non_search_v;
    for(int next : path[p]){
        if(colors[next] == col_now)return 0;
        if(colors[next] == -1)non_search_v.push_back(next);
    }
    if(non_search_v.size() == 0)return 1;
    ll ans = 0;
    rep(i,pow(2,non_search_v.size())){
        vector<int> new_colors;
        copy(colors.begin(), colors.end(), back_inserter(new_colors));
        rep(j,non_search_v.size()){
            int new_col_n = (int)(bool)(1 << j & i);
            new_colors[non_search_v[j]] = col_new[new_col_n];
        }
        ll res = 1;
        for(int next : path[p]){
            res *= dfs(next, new_colors);
        }
        ans += res;
    }
    return ans;
};
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
        int start = g[0];
        ll res = 0;
        rep(i,3){
            vector<int> color(n,-1);
            color[start] = i;
            res += dfs(start, color);
        }
        ans *= res;
    }
    cout << ans << endl;
}
