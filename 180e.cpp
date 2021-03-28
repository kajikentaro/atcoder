#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
vector<vector<ll>> dp;
int n;
int x[17];
int y[17];
int z[17];
ll cost(int a,int b){
    return abs(x[a] - x[b]) + abs(y[a] - y[b]) + max(0,z[b]-z[a]);
}
int main(){
    cin >> n;
    rep(i,n){
        cin >> x[i];
        cin >> y[i];
        cin >> z[i];
    }
    dp.resize(pow(2,n),vector<ll>(n,1e18));
    dp[1][0] = 0;
    rep(i, pow(2, n))rep(j, n) {
        if (i == 0)continue;
        if (~i & 1 << j)continue;
        ll now = dp[i][j];
        rep(k, n) {
            if(i & 1 << k)continue;
            ll *old = &dp[i | 1 << k][k];
            ll next = now + cost(j,k);
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