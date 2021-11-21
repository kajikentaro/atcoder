#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
int main(){
    int n, s;
    cin >> n >> s;
    vector<string> name(n);
    rep(i,n) cin >> name[i];
    int t;
    cin >> t;
    vector<vector<P>> path(n);
    rep(i,t){
        int a,b,w;
        cin >> a >> b >> w;
        path[a].emplace_back(w,b);
    }
    const int inf = 1e9;
    vector<vector<int>> dp(pow(2,n), vector<int>(n,inf));
    vector<vector<string>> dp_log(pow(2,n), vector<string>(n,""));
    for(auto i : path[s]){
        int w, next;
        tie(w,next) = i;
        dp[1 << next][next] = w;
        dp_log[1 << next][next] = name[s] + name[next];
    }
    rep(i,pow(2,n)){
        rep(j,n){
            if((1 << j & i) == 0)continue;
            for(auto tmp : path[j]){
                int w, next;
                tie(w,next) = tmp;

                int next_status = i | 1 << next;
                if(next_status == i)continue;
                if(chmin(dp[next_status][next], w + dp[i][j])){
                    dp_log[next_status][next] = dp_log[i][j] + name[next];
                }
                //dp[1 << next][next] = w;
            }
        }
    }
    cout << dp[pow(2,n) - 1][s] << endl;
    cout << dp_log[pow(2,n) - 1][s] << endl;
}