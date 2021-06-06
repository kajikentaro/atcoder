#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
vector<vector<ll>> dp;
int main(){
    int n,s;
    cin >> n >> s;
    vector<string> name(n);
    rep(i,n)cin >> name[i];
    dp.resize(pow(2,n),vector<ll>(n,1e18));
    dp[1][0] = 0;

    int t;
    cin >> t;
    vector<vector<P>> path(n);
    rep(i,t){
        int a,b,w;
        cin >> a >> b >> w;
        path[a].emplace_back(w,b);
    }
    rep(i, pow(2, n))rep(j, n) {
        if (i == 0)continue;
        if (~i & 1 << j)continue;
        ll now = dp[i][j];
        rep(l, path[j].size()) {
            int cos, k;
            tie(cos, k) = path[j][l];

            ll *old = &dp[i | 1 << k][k];
            ll next = now + cos;
            if(*old > next)*old = next;
        }
    }
    vector<ll> result;
    rep(i,n){
        result.push_back(dp[pow(2,n)-1][i] + cost(i,0));
    }
    cout << *min_element(result.begin(),result.end()) << endl;
    return 0;
}