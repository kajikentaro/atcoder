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
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i,n)cin >> t[i];
    int def = 100010;
    vector<vector<int>> dp(n+1,vector<int>(def));
    dp[0][0] = 1;
    orep(i,n){
        rep(j,def){
            if(j - t[i-1] >= 0 && dp[i-1][j - t[i-1]])dp[i][j] = 1;
            if(dp[i-1][j])dp[i][j] = 1;
        }
    }
    int sum_len = 0;
    rep(i,n)sum_len += t[i];
    int score = 1e9;
    rep(j,def){
        if(dp[n][j] == 1){
            chmin(score, max(sum_len - j, j));
        }
    }
    cout << score << endl;
}