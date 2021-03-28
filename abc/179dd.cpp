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
    cin >> n >> k;
    vector<int> l(k);
    vector<int> r(k);
    rep(i,k){
        cin >> l[i] >> r[i];
    }
    vector<ll> dp(n+1);
    dp[1] = 1;
    orep(i,n){
        rep(j,k){
            int start = i + l[j];
            int end = i + r[j];
            if(start <= n)dp[start] += dp[i];
            if(end <= n)dp[end] += -dp[i];
        }
    }
    mint ans = 0;
    mint now = 0;
    orep(i,n){
        now += dp[i];
        ans += now;
    }
    cout << ans.val() << endl;
}
