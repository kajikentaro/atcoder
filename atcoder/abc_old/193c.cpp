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
    ll n;
    cin >> n;
    ll ans = n;
    map<ll,int> z;
    for(ll i=2;i*i<=n;i++){
        ll now = pow(i,2);
        if(z[now] >= 1)continue;
        while(now <= n){
            z[now]++;
            ans--;
            now *= i;
        }
    }
    cout << ans << endl;
}
