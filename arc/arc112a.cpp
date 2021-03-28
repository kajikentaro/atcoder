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
ll func(int pp){
    return (1+pp) * (ll)pp / 2;
}
int main(){
    int t;
    cin >> t;
    rep(i,t){
        int l,r;
        cin >> l >> r;
        int p = (2 * l);
        int pp = r - p + 1;
        if(pp < 0){
            cout << 0 << endl;
            continue;
        }
        cout << func(pp) << endl;
    }
    return 0;
}
