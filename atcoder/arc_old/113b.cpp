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
using P = pair<int,int>;
vector<ll> func(ll a, ll k){
    vector<ll> ab;
    ll now_v = a % k;
    ab.push_back(now_v);
    while(1){
        ll new_v = (now_v * ab[0]) % k;
        if(ab[0] != new_v){
            now_v = new_v;
            ab.push_back(new_v);
            if(ab.size() > k){
                1/0;
            }
        }else{
            break;
        }
    }
    return ab;
}
int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    vector<ll>  k1_ring = func(a,10);
    ll k1 = k1_ring.size();

    vector<ll> k2_ring = func(b,k1);
    ll k2 = k2_ring.size();

    ll p = k2_ring[(c + k2 - 1) % k2];
    ll ans = k1_ring[(p + k1 - 1) % k1];
    cout << ans << endl;
}
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
using P = pair<int,int>;
int main(){
}
