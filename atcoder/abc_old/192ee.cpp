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
using P = pair<ll,int>;
struct T{
    int d,t,k;
    T(int d, int t, int k):d(d), t(t), k(k){};
};
ll func(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    x--;y--;
    vector<vector<T>> train(n);
    rep(i,m){
        int a,b,t,k;
        cin >> a >> b >> t >> k;
        a--;b--;
        train[a].emplace_back(b,t,k);
        train[b].emplace_back(a,t,k);
    }
    const ll inf = 1e18;
    vector<ll> dp(n,inf);
    priority_queue<P,vector<P>,greater<P>> q;
    q.emplace(0,x);
    while(q.size()){
        ll dist;int v;
        tie(dist,v) = q.top();
        q.pop();
        //if(dp[v] != inf)continue;
        if(dp[v] < dist)continue;
        dp[v] = dist;
        for(auto t : train[v]){
            ll new_time = t.t + t.k * ((dp[v] - 1 + t.k)/t.k);
            q.emplace(new_time, t.d);
        }
    }
    if(dp[y] == inf)return -1;
    return dp[y];
}
int main(){
    cout << func() << endl;
}