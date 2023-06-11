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
    ll n;
    cin >> n;
    vector<ll> a(1e6);
    ll ans = 0;
    rep(i,n){
        ll in;
        cin >> in;
        a[in]++;
        ans += in;
    }
    ll q;
    cin >> q;
    rep(i,q){
        ll b,c;
        cin >> b >> c;
        ans -= b * a[b];
        ans += c * a[b];
        a[c] += a[b];
        a[b] = 0;
        cout << ans << endl;
    }
}
