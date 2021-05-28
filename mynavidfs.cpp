#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
vector<vector<int>> dp;
vector<vector<string>> dp_log;
vector<vector<P>> path;
vector<char> name;
const int inf = 1e9;
int s;
int dfs(int state, int now){
    //if((1 << now & state) == 0)return inf;
    if(dp[state][now] != inf)return dp[state][now];
    if((1 << now) & (~state))return inf;
    for(auto i : path[now]){
        int fare, before;
        tie(fare, before) = i;

        int before_state = (1 << now) ^ state;
        if(chmin(dp[state][now], dfs(before_state, before) + fare)){
            dp_log[state][now] = dp_log[before_state][before] + name[now];
        }
    }
    return dp[state][now];
}
int main(){
    int n,t;
    cin >> n >> s;
    name.resize(n);
    path.resize(n);
    dp.resize(1 << n, vector<int>(n,inf));
    dp_log.resize(1 << n, vector<string>(n,""));

    rep(i,n)cin >> name[i];
    cin >> t;
    dp[0][s] = 0;
    dp_log[0][s] = name[s];

    rep(i,t){
        int a,b,w;
        cin >> a >> b >> w;
        path[b].emplace_back(w,a);
    }

    dp[1 << s][s] = 0;
    dp_log[1 << s][s] = name[s];

    cout << dfs((1 << n) - 1, s) << endl;
    cout << dp_log[(1 << n) - 1][s] << endl;
}