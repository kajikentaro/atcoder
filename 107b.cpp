#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
ll cal(ll a,ll b,ll c,ll d,ll k){
    return min(b,k-c) - max(a,k-d) + 1;
}
int main(){
    ll n, k;
    cin >> n >> k;
    ll sum = 0;
    rep(i,2*n+1){
        if(i<2)continue;
        ll cd_sum = cal(1,n,1,n,i);
        ll ab_sum = cal(1,n,1,n,k+i);
        sum += max((ll)0,cd_sum * ab_sum);
    }
    cout << sum << endl;
    return 0;
}
