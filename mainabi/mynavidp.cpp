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
    int n,s;
    cin >> n >> s;
    vector<char> name(n);
    rep(i,n)cin >> name[i];
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
    dp[1 << s][s] = 0;
    dp_log[1 << s][s] = name[s];
    rep(i,pow(2,n)){
        rep(now,n){
            if((~i) & (1 << now))continue;
            for(auto tmp: path[now]){
                int fare, next;
                tie(fare, next) = tmp;
                if(chmin(dp[i | (1 << next)][next], dp[i][now] + fare)){
                    dp_log[i | (1 << next)][next] = dp_log[i][now] + name[next];
                }
            }
        }
    }
    cout << dp[pow(2,n) - 1][s] << endl;
    cout << dp_log[pow(2,n) - 1][s] << endl;
}