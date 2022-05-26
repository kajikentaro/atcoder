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
ll comb(ll n,ll r)
{
    ll i = 1;
    ll k = r > n - r ? n - r : r, count;
    if(k < 0) return 0;
    std::list<ll> list;
    std::list<ll>::iterator it;
    for(count = 2; count <= k; ++count) list.push_back(count);
    for(count = n; count > n - k; --count)
    {
        i *= count;
        for(it = list.begin(); it != list.end(); )
        {
            if(!(i % *it))
            {
                i /= *it;
                it = list.erase(it);
            }
            else ++it;
        }
    }
    return i;
}
int main(){
  ll n;
  cin >> n;
  ll MAX_NUM = 2e5 + 10;
  vector<ll> a(MAX_NUM);
  rep(i,n){
    ll b;
    cin >> b;
    a[b]++;
  }
  ll sum = comb(n, 3);
  rep(i, MAX_NUM){
    if(a[i] <= 2)continue;
    ll b = comb(a[i], 3);
    sum -= b;
  }
  rep(i, MAX_NUM){
    if(a[i] <= 1)continue;
    ll b = comb(a[i], 2);
    sum -= b * (n - a[i]);
  }
  cout << sum << endl;
}