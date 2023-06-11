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
#define VV vector<vector<int>>
mint dfs(int a, int n){
    
}
mint func(int a, int b){
    mint res = 1;
    rep(i,b){
        res *= (a-i);
    }
    rep(i,b){
        res /= (b-i);
    }
    return res;
}
int main(){
    int n,m;
    cin >> n >> m;
    const int inf = 1e9;
    vector<int> grid(m+1,-1);
    for(int i=2;i*i<=m;i++){
        for(int j=i;j<=m;j+=i){
            if(grid[j] == -1)grid[j] = i;
        }
    }
    vector<int> dp(m+1);
    rrep(i,m+1){
        if(i==0)continue;
        int t = i;
        set<int> div;
        div.insert(1);
        while(1){
            div.insert(t);
            if(grid[t] == -1)break;
            div.insert(grid[t]);
            t /= grid[t];
        }
        for(auto d : div){
            dp[d]++;
        }
    }
    mint ans = 0;
    orep(i,m){
        mint t = dp[i] * (dp[i] + 1) / 2;
    }
    cout << ans.val() << endl;
}
