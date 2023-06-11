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
    string x;
    ll m;
    cin >> x >> m;
    map<ll,ll> c;
    ll d = (*max_element(x.begin(),x.end())) - '0';
    reverse(x.begin(),x.end());
    if(x.size() == 1){
        cout << 1 << endl;
        return 0;
    }
    while(1){
        d++;
        ll ans = 0;
        ll now = 1;
        rep(i,x.size()){
            ans += now * (x[i] - '0');
            now *= d;
            if(now < 0 || ans < 0){
                ans = (ll)1e18 + 1;
                break;
            }
        }
        if(ans > m)break;
        c[ans]++;
    }
    cout << c.size() << endl;
}
