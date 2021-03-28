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
ll gcd(ll x, ll y) {
    if(x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y); 
    }
}
ll func(){
    ll sosu[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    vector<ll> can;
    for(ll i=0;i<pow(2,15);i++){
        ll now = 1;
        rep(j,15){
            if(1<<j & i){
                now *= sosu[j];
            }
        }
        if(now == 1)continue;
        can.push_back(now);
    }
    sort(can.begin(), can.end());
    ll n;
    cin >> n;
    vector<ll> x(n);
    rep(i,n)cin >> x[i];
    for(auto c : can){
        bool flag = true;
        rep(j,n){
            ll g = gcd((ll)x[j],c);
            if(g == 1){
                flag = false;
                break;
            }
        }
        if(flag){
            return c;
        }
    }
}
int main(){
    cout << func() << endl;
}
