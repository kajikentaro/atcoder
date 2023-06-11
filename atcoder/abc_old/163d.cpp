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
ll sum(ll n){
    return n * (n + 1) / 2;
}
int main(){
    ll n,k;
    cin >> n >> k;
    mint ans;
    for(ll i=k;i<=n+1;i++){
        ll min = sum(i-1);
        ll max = sum(n) - sum(n-i);
        ans += max - min + 1;
    }
    cout << ans.val() << endl;
}
