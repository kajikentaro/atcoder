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
    ll two_jo = 1;
    ll ans = 1e18;
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    orep(i,63){
        two_jo *= 2;
        if(two_jo > n)break;

        ll a1 = n / two_jo;
        //ll a2 = (n + two_jo - 1) / two_jo;

        ll c1 = n - a1 * two_jo;
        //ll c2 = n - a2 * two_jo;
        ll tmp1 = a1 + i + c1;
        //ll tmp2 = a1 + two_jo + c1;
        chmin(ans, tmp1);
    }
    cout << ans << endl;
}
