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
    int n,x,y;
    cin >> n >> x >> y;
    x--;y--;
    vector<vector<int>> path(n);
    rep(i,n-1){
        path[i].push_back(i+1);
        path[i+1].push_back(i);
    }
    path[x].push_back(y);
    path[y].push_back(x);
    vector<int> ans(n);
    rep(i,n){
        priority_queue<P,vector<P>,greater<P>> q;
        const int inf = 1e9;
        vector<int> time(n,inf);
        q.emplace(0,i);
        while(q.size()){
            int t,v;
            tie(t,v) = q.top();
            q.pop();
            if(t >= time[v])continue;
            time[v] = t;
            ans[t]++;
            for(auto d : path[v]){
                int new_t = time[v] + 1;
                q.emplace(new_t, d);
            }
        }
    }
    rep(i,n){
        if(i==0)continue;
        cout << ans[i]/2 << endl;
    }
}
