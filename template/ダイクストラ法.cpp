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
//頂点1からnまでの最短経路を求めるプログラム
int main(){
    int n,m;
    cin >> n >> m;
    //firstが時間、secondが位置
    vector<vector<P>> path(n);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        path[a].emplace_back(c,b);
        path[b].emplace_back(c,a);
    }
    priority_queue<P,vector<P>, greater<P>> que;
    que.emplace(0,0);
    vector<int> res(n,-1);
    while(que.size()){
        int time, pos;
        tie(time, pos) = que.top();
        que.pop();
        if(res[pos] != -1)continue;
        res[pos] = time;
        for(auto i : path[pos])que.emplace(time + i.first, i.second);
    }
    cout << res[n-1] << endl;
}