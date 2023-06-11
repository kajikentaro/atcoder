#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(long long x=0;x<y;x++)
#define rrep(x,y) for(long long x=y-1;x>=0;x--)
#define orep(x,y) for(long long x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<long long,long long>;

struct Road{
    long long dest,c,d;
    Road(long long dest, long long c,long long d):dest(dest), c(c), d(d){}
};
int main(){
    long long n,m;
    cin >> n >> m;
    vector<vector<Road>> path(n);
    rep(i,m){
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;b--;
        path[a].emplace_back(b,c,d);
        path[b].emplace_back(a,c,d);
    }
    priority_queue<P,vector<P>, greater<P>> que;
    que.emplace(0,0);
    vector<long long> res(n,-1);
    while(que.size()){
        long long time, pos;
        tie(time, pos) = que.top();
        que.pop();
        if(res[pos] != -1)continue;
        res[pos] = time;
        ll time_backup = time;
        for(auto i : path[pos]){
            time = time_backup;
            long long tmp = (ll)sqrt(i.d) - 1;
            long long mi = 1e9;
            long long mi_p = -1;
            for(long long j = tmp - 10;j<tmp + 10;j++){
                if(j < 0)continue;
                if(chmin(mi, (long long)j+ i.c + i.d / (j+1))){
                    mi_p = j;
                }
            }
            if(mi_p >= time)time = mi_p;
            que.emplace(time + i.c + i.d / (time+1), i.dest);
        }
    }
    cout << res[n-1] << endl;
}