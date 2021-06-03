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
    int a,b,k;
    cin >> a >> b >> k;
    int n = a + b;
    int dp[n][2] = {};//[i桁目を見て][a or b]
    dp[0][0] = 1;
    dp[0][1] = 1;
    rep(i,n){
        if(i==0)continue;
        dp[i] = 
    }
}