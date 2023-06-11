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
    ll sum = 0;
    for(ll i=1;i*i<=2*n;i++){
        if(2*n % i == 0){
            ll a = i, b = 2 * n / i;
            if((a + b - 1) % 2 == 0 && (b - a - 1) % 2 == 0)sum++;
        }
    }
    cout << sum * 2 << endl;
}
