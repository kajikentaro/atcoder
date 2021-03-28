#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll calc(ll n){
    return (ll)((-1 + (ll)sqrt(1+8*n))/2);
}
int main(){
    ll n;
    cin >> n;
    ll ans = calc(n+1);
    ll ans_d0 = (ans-1) * (ans) / 2;
    ll ans_d1 = ans * (ans + 1) / 2;
    ll ans_d2 = (ans+1) * (ans + 2) / 2;
    if(ans_d2 <= n+1){
        ans = ans + 1;
    }else if(ans_d1 <= n+1){
        ans = ans;
    }else{
        ans = ans - 1;
    }
    cout << n - ans + 1<< endl;
}