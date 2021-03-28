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
    T(int d,int t,int k):d(d), t(t), k(k){}
    T(){}
};
int main(){
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
    vector<ll> time(n,inf);
    priority_queue<P,vector<P>,greater<P>> q;
    q.emplace(0,x);
    while(q.size()){
        ll t;int v;
        tie(t,v) = q.top();
        q.pop();
        if(time[v] <= t)continue;
        time[v]  = t;
        for(auto d : train[v]){
            ll new_t = ((t + d.k - 1) / d.k) * d.k + d.t;
            q.emplace(new_t, d.d);
        }
    }
    if(time[y] == inf){
        cout << -1 << endl;
    }else{
        cout << time[y] << endl;
    }
}