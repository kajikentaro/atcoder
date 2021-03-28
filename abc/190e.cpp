#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
#define inf 1e9
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> all_path(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        all_path[a].push_back(b);
        all_path[b].push_back(a);
    }
    int k;
    cin >> k;
    vector<int> c(k);
    rep(i,k){
        cin >> c[i];
        c[i]--;
    }
    vector<vector<int>> main_path(k,vector<int>(k,-1));
    rep(i,k){
        int start = c[i];
        vector<int> dist(n,inf);
        dist[start] = 0;
        queue<int> que;
        que.push(start);
        while(que.size()){
            int cursor = que.front();
            que.pop();
            int now_dist = dist[cursor] + 1;
            for(int next : all_path[cursor]){
                if(dist[next] != inf)continue;
                dist[next] = now_dist;
                que.push(next);
                //if(chmin(dist[next], now_dist))que.push(next);
            }
        }
        rep(j,k) main_path[i][j] = main_path[j][i] = dist[c[j]];
    }
    vector<vector<int>> dp(pow(2,k),vector<int>(k,inf));
    rep(i,k){
        dp[1<<i][i] = 0;
    }
    rep(i,pow(2,k))rep(j,k){
        if(~i&1<<j)continue;
        rep(t,k){
            if(i&1<<t)continue;
            if(main_path[j][k] == -1)continue;
            chmin(dp[i | 1<<t][t], main_path[j][t] + dp[i][j]);
        }
    }
    int ans = inf;
    rep(i,k){
        chmin(ans,dp[pow(2,k)-1][i]);
    }
    if(ans == inf)ans = -2;
    cout << ans +1 << endl;
    return 0;
}
