#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
#define ll long long
#define rep(x,y) for(int x=0;x<y;x++)
mint dp[10010][2][101];
mint solve(string n, int d, int k, bool tight, int sum){
    mint ans(0);
    for(int i=0;i<=(tight ? (n[k] - '0') : 9);i++){
        int now_sum = (sum + i)%d;
        if(k == n.size()-1 && now_sum == 0)ans++;
        bool now_tight = tight && ((n[k] - '0') == i);
        mint* cache = &dp[k+1][now_tight][now_sum];
        if(*cache == -1) (*cache) = solve(n,d,k+1,now_tight,now_sum);
        ans += (*cache);
    }
    return ans;
}
int main(void){
    int d;
    string n;
    cin >> d >> n;
    rep(i,10010){
        rep(j,2){
            rep(k,101){
                dp[i][j][k] = -1;
            }
        }
    }
    cout << solve(n,d,0,true,0).val()-1 << endl;
}