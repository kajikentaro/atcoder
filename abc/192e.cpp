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
struct T{
    int d;
    int t;
    int ta;
    int tb;
    T(int d_,int t_,int ta_, int tb_):d(d_),t(t_),ta(ta_),tb(tb_){}
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
        
        int ta = k * ((t + k - 1) / k);
        train[a].push_back(T(b,t, ta,0));
        train[b].push_back(T(a,t, ta,0));
    }
    vector<int> time(n, -1);
    time[x] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,x});
    while(1){
        if(pq.size() == 0)break;
        int c = pq.top().second;
        pq.pop();
        if(c == y){
            cout << time[c] << endl;
            return 0;
        }
        for(auto d : train[c]){
            if(time[d.d] != -1)continue;
            int new_time = d.t + d.ta * ((time[c]  + d.ta - 1) / d.ta);
            pq.push({new_time,d.d});
        }
        while(1){
            if(pq.size() == 0)break;
            int min_p = pq.top().second;
            int min_time = pq.top().first;
            if(time[min_p] == -1){
                time[min_p] = min_time;
                break;
            }else{
                pq.pop();
            }
        }
    }
    cout << -1 << endl;
}
