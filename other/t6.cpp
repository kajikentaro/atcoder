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
    int n,k;
    string s;
    cin >> n >> k >> s;
    vector<string> dp(k+1);
    dp[0] = "";
    rep(i,n){ //s[i]を採用する
        rrep(j,k){
            if(dp[j].size() != j)continue;
            if(dp[j+1].size() != j+1){
                dp[j+1] = dp[j] + s[i];
                continue;
            }
            chmin(dp[j+1], dp[j] + s[i]);
        }
    }
    cout << dp[k] << endl;
}
