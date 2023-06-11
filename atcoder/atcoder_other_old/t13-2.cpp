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
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<P>> path(n);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        path[a].emplace_back(c,b);
        path[b].emplace_back(c,a);
    }
    priority_queue<P,vector<P>, greater<P>> que;
    que.emplace(0, 0);
    const int inf = 1001001001;
    vector<int> dist_0(n,inf);
    while(que.size()){
        int now,now_dist;
        tie(now_dist, now) = que.top();
        que.pop();
        if(dist_0[now] != inf)continue;
        dist_0[now] = now_dist;
        for(auto i : path[now]){
            int next, path_dist;
            tie(path_dist, next) = i;
            que.emplace(path_dist + now_dist, next);
        }
    }
    que.emplace(0,n-1);
    vector<int> dist_n(n,inf);
    while(que.size()){
        int now,now_dist;
        tie(now_dist, now) = que.top();
        que.pop();
        if(dist_n[now] != inf)continue;
        dist_n[now] = now_dist;
        for(auto i : path[now]){
            int next, path_dist;
            tie(path_dist, next) = i;
            que.emplace(path_dist + now_dist, next);
        }
    }
    rep(i,n){
        cout << dist_n[i] + dist_0[i] << endl;
    }
}
