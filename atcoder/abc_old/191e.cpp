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
const int inf = 1e9;
struct P{
    int to,cost;
    P(int t, int c):to(t), cost(c){}
};
struct N{
    bool done = false;
    int cost = inf;
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<P>> path(n);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        path[a].emplace_back(b,c);
    }
    rep(i,n){
        vector<N> cost(n);
        for(auto start : path[i]){
            chmin(cost[start.to].cost,start.cost);
        }
        while(1){
            int tmp_min_cost = inf;
            int start = -1;
            rep(j,cost.size()){
                if(cost[j].done)continue;
                if(chmin(tmp_min_cost, cost[j].cost))start = j;
            }
            if(start == -1)break;
            cost[start].done = true;
            for(auto destination : path[start]){
                int new_cost = cost[start].cost + destination.cost;
                chmin(cost[destination.to].cost, new_cost);
            }
        }
        if(cost[i].done == false)cost[i].cost = -1;
        cout << cost[i].cost << endl;
    }
}
