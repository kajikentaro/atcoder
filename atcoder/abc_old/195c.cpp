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
int main(){
    ll n;
    cin >> n;
    ll magic[5];
    magic[0] = 1e3;
    magic[1] = 1e6;
    magic[2] = 1e9;
    magic[3] = 1e12;
    magic[4] = 1e15;
    ll ans = 0;
    for(ll m : magic){
        if(n >= m){
            ans += n - m + 1;
        }
    }
    cout << ans << endl;
}
