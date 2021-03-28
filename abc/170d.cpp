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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    int max = 1e6+10;
    vector<int> dp(max);
    int ans = 0;
    rep(i,n){
        if(dp[a[i]] > 0){
            dp[a[i]]++;
            continue;
        }
        for(int j=a[i];j<max;j+=a[i]){
            dp[j]++;
        }
    }
    rep(i,n){
        if(dp[a[i]] == 1)ans++;
    }
    cout << ans << endl;
}
