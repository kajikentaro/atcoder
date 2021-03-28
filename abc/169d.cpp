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
ll func(ll x){
    return x * (x+1) / 2;
}
int main(){
    ll n;
    cin >> n;
    map<ll,ll> Prime;
    ll n_bu = n;
    for(ll i = 2;i*i<=n_bu;i++){
        while(1){
            if(n % i == 0){
                Prime[i]++;
                n/=i;
            } 
            else break;
        }
    }
    if(n != 1)Prime[n]++;
    ll ans = 0;
    for(auto P : Prime){
        ll up = 1e9;
        ll down = 0;
        while(1){
            ll c = (up + down) / 2;
            if(P.second < func(c)){
                up = c;
            }else{
                down = c;
            }
            if(up - down == 1)break;
        }
        ans += down;
    }
    cout << ans << endl;
    return 0;
}
