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
    ll n,m,k;
    cin >> n >> m >> k;
    n++;m++;
    vector<ll> a(n);
    vector<ll> b(m);
    rep(i,n){
        if(i==0)continue;
        ll in;
        cin >> in;
        a[i] = a[i-1] + in;
    }
    rep(i,m){
        if(i==0)continue;
        ll in;
        cin >> in;
        b[i] = b[i-1] + in;
    }
    ll ac = 0, bc = 0;
    while(1){
        if((a[ac+1] > b[bc+1] && bc != m-1) || ac == n-1){
            bc++;
        }else{
            ac++;
        }
        ll now_t = a[ac] + b[bc];
        if(now_t > k){
            bc--;
            break;
        }
        if(ac == n-1 && bc == m-1){
            break;
        }
    }
    cout << ac + bc << endl;
}
