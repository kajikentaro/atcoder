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
    //tdpc e
    string n;
    int mod;
    cin >> mod >> n;
    int ns = n.size();
    mint dp[ns+1][mod][2] = {};
    dp[0][0][1] = 1;

    rep(keta,ns){
        rep(now,mod){
            rep(entry,10){
                int next = (now + entry) % mod;
                dp[keta+1][next][0] += dp[keta][now][0];
                if(entry == n[keta] - '0'){
                    dp[keta+1][next][1] += dp[keta][now][1];
                }
                if(entry < n[keta] - '0'){
                    dp[keta+1][next][0] += dp[keta][now][1];
                }
                if(entry > n[keta] -'0')continue;
            }
        }
    }
    ll ans = (dp[ns][0][1] + dp[ns][0][0] - 1).val();
    cout << ans << endl;
}