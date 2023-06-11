#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
vector<vector<int>> dp(210,vector<int>(20));
ll func(ll length,ll cut){
    if(dp[length][cut] != 0)return dp[length][cut];
    if(cut == 0)return 1;
    if(cut == 1){
        return length - 1;
    }
    if(length <= cut)return -1;
    ll sum = 0;
    for(ll i = 1;i < length;i++){
        rep(j,cut + 1){
            ll a = func(i,cut - j);
            ll b = func(length - i,j);
            if(a <= 0 || b <= 0)continue;
            sum += a * b;
        }
    }
    return sum;
}
int main(){
    ll l;
    cin >> l;
    cout << func(l,11) << endl;
}
