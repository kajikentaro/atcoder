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
    #define int ll
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    int ma = a[0];
    ll wa = 0;
    ll wawa = 0;
    rep(i,n){
        chmax(ma, a[i]);

        wa += a[i];

        ll ans = wa + ma * (i + 1) + wawa;

        wawa += wa;

        cout << ans << endl;
    }
}
