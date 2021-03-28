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
ll gcm(ll a, ll b){
    ll r = a % b;
    if(r == 0)return b;
    return gcm(b, r);
}
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    vector<pair<ll,ll>> d(n);
    map<pair<ll,ll>,pair<ll,ll>> m;
    ll zero = 0;
    ll real_zero = 0;
    rep(i,n){
        if(a[i] == 0 && b[i] == 0){
            real_zero++;
            continue;
        }
        if(a[i] == 0 || b[i] == 0){
            if(a[i] == 0){
                m[{0,1}].second++;
            }else{
                m[{0,1}].first++;
            }
            continue;
        }
        ll aba = abs(a[i]);
        ll abb = abs(b[i]);
        ll g = gcm(aba, abb);
        ll a_ = a[i] / g;
        ll b_ = b[i] / g;
        if(a_ < 0){
            a_ = -a_;
            b_ = -b_;
        }
        if(b_ < 0){
            m[{-b_,a_}].second++;
        }else{
            m[{a_,b_}].first++;
        }
    }
    mint ans = 1;
    for(auto l : m){
        auto line = l.second;
        mint fact = 1;
        rep(i,line.first){
            fact *= 2;
        }
        mint fact2 = 1;
        rep(i,line.second){
            fact2 *= 2;
        }
        mint p =(fact - 1) + (fact2 - 1) + 1; 
        ans *= p;
    }
    cout << (ans - 1 + real_zero).val() << endl;
}
