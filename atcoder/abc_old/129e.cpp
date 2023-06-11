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
int main(){
    string s;
    cin >> s;
    s = '0' + s;
    int sn = s.length();
    vector<int> L(sn);
    rep(i,sn){
        L[i] = s[i] - '0';
    }
    vector<vector<mint>> dp(sn,vector<mint>(2,0));
    dp[0][1] = 1;
    rep(i,sn){
        if(i == 0)continue;
        pair<int,int> candidate[] = {{1,0},{0,1},{0,0}};
        for(pair<int,int> c : candidate){
            dp[i][0] += dp[i-1][0];
            if(c.first + c.second){
                if(L[i]){
                    dp[i][1] += dp[i-1][1];
                }else{

                }
            }else{
                if(L[i]){
                    dp[i][0] += dp[i-1][1];
                }else{
                    dp[i][1] += dp[i-1][1];
                }
            }
        }
    }
    cout << dp[sn-1][0].val() + dp[sn-1][1].val() << endl;
}
