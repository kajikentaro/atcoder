#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define inf 1e9
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
    string s;
    cin >> s;
    s = '0' + s;
    int sn = s.length();
    vector<int> N(sn);
    rep(i,sn){
        N[i] = s[sn - i - 1] - '0';
    }
    vector<vector<int>> dp(sn,vector<int>(2,inf));
    {
        int i = 0;
        rep(j,10){
            if(j >= N[i]){
                chmin(dp[i][0], j + (j - N[i]));
            }else{
                chmin(dp[i][1], j + (j+10 - N[i]));
            }
        }
    }
    rep(i,sn){
        if(i == 0)continue;
        rep(j,10){
            {//dp[][0]
                if(j >= N[i]){
                    chmin(dp[i][0], dp[i-1][0] + j + (j - N[i]));
                }else{
                    chmin(dp[i][1], dp[i-1][0] + j + (j+10 - N[i]));
                }
            }
            {//dp[][1]
                int Ni = N[i] + 1;
                if(j >= Ni){
                    chmin(dp[i][0], dp[i-1][1] + j + (j - Ni));
                }else{
                    chmin(dp[i][1], dp[i-1][1] + j + (j+10 - Ni));
                }
            }
        }
    }
    cout << dp[sn-1][0] << endl;
}