#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define orep(x,y) for(int x=1;x<=y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define mint modint1000000007
#define ll long long
using namespace std;
using namespace atcoder;   
vector<int> dp;
vector<vector<int>> path;
int func(int a){
    if(dp[a] != -1)return dp[a];
    int ans = 0;
    rep(i,path[a].size()){
        ans = max(func(path[a][i]),ans);
    }
    return dp[a] = ans + 1;
}
int main(){
    int n,m;
    cin >> n >> m;
    path.resize(n);
    dp.resize(n,-1);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        path[a].push_back(b);
    }
    int ans = 0;
    rep(i,n){
        ans = max(ans,func(i));
    }
    cout << ans-1 << endl;
}