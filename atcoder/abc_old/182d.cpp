#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<=b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<=a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> sum_a(n);
    rep(i,n) cin >> a[i];
    sum_a[0] = a[0];
    rep(i,n){
        if(i==0)continue;
        sum_a[i] = a[i] + sum_a[i-1];
    }
    vector<ll> sum_sum_a(n);
    sum_sum_a[0] = sum_a[0];
    rep(i,n){
       if(i==0)continue;
       sum_sum_a[i] = sum_a[i] + sum_sum_a[i-1];
    }
    const ll inf = 1e18;
    ll sum_max = -inf;
    ll sum_max_p = -1;
    ll sum_sum_max = -inf;
    ll sum_sum_max_p = -1;
    rep(i,n){
        if(chmax(sum_sum_max, sum_sum_a[i])){
            sum_sum_max_p = i;
            if(i == n-1)sum_sum_max_p = i-1;
        }
    }
    rep(i,sum_sum_max_p){
        if(chmax(sum_max, sum_a[i]))sum_max_p = i;
    }
    ll ans = sum_sum_a[sum_sum_max_p] + sum_a[sum_max_p];
    cout << ans << endl;
}
