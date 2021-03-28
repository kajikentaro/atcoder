#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
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
    vector<vector<P>> edge(n);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        edge[a].emplace_back(c,b);
    }
    const int inf = 1e9;
    rep(i,n){
        vector<int> dp(n,inf);
        priority_queue<P, vector<P>, greater<P>> q;
        auto add = [&](int now_v, int now_dist){
            for(auto path : edge[now_v]){
                int length, new_v;
                tie(length, new_v) = path;
                int new_dist = length + now_dist;
                q.emplace(new_dist, new_v);
            }
        };
        add(i,0);
        while(q.size()){
            int now_dist,now_v;
            tie(now_dist, now_v) = q.top();
            q.pop();
            if(dp[now_v] != inf)continue;
            dp[now_v] = now_dist;
            add(now_v, now_dist);
        }
        if(dp[i] == inf) cout << -1 << endl;
        else cout << dp[i] << endl;
    }
}
