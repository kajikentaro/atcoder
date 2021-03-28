#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    ll x;
    cin >> n >> x;
    ll coin[55];
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }
    ll x_coin[55];
    ll coin_rel[55];
    for(int i=0;i<n;i++){
        coin_rel[i] = coin[i+1] / coin[i];
    }
    coin_rel[n-1] = -1;
    for(int i=n-1;i>=0;i--){
        x_coin[i] = x / coin[i];
        x%= coin[i];
    }
    ll dp[2] = {1,0};
    for(int i=0;i<n;i++){
        ll dp2[2] = {};

        dp2[0] += dp[0];
        if(x_coin[i]!=0)dp2[1] += dp[0];

        if(1 + x_coin[i] == coin_rel[i]){
            dp2[1] += dp[1];
        }else{
            dp2[0] += dp[1];
            dp2[1] += dp[1];
        }
        swap(dp,dp2);
    }
    cout << dp[0] << endl;

}