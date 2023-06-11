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
struct People{
    ll a,b,margin,i;
    People(ll a,ll b,ll margin, ll i):a(a), b(b), margin(margin), i(i){};
    People(){}
    void setMargin(){
        margin = 2 * a + b;
    }
};
auto cmp(const People &a, const People &b){
    return a.margin > b.margin;
}
int main(){
    int n;
    cin >> n;
    vector<People> ab(n);
    ll now_aoki = 0;
    ll now_takahashi = 0;
    rep(i,n){
        ab[i].i = i;
        cin >> ab[i].a >> ab[i].b;
        now_aoki += ab[i].a;
        ab[i].setMargin();
    }
    sort(ab.begin(), ab.end(), cmp);
    ll ans = 0;
    rep(i,n){
        now_aoki -= ab[i].a;
        now_takahashi += ab[i].a + ab[i].b;
        ans++;
        if(now_takahashi > now_aoki)break;
    }
    cout << ans << endl;
}
