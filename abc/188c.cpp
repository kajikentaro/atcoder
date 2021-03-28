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
    int n;
    cin >> n;
    int nn = pow(2,n);
    vector<ll> a(nn/2);
    vector<ll> b(nn/2);
    rep(i,nn/2)cin >> a[i];
    rep(i,nn/2)cin >> b[i];
    auto a_max = max_element(a.begin(),a.end());
    auto b_max = max_element(b.begin(),b.end());
    ll a_maxp = distance(a.begin(),a_max);
    ll b_maxp = distance(b.begin(),b_max);
    if(*a_max > *b_max){
        swap(a_maxp, b_maxp);
        a_maxp += nn / 2;
    }
    cout << a_maxp + 1 << endl;
}
