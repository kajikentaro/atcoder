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
int xor_bit_cnt(bitset<20> a,bitset<20> b){
    bitset<20> c = a ^ b;
    return c.count();
}
int main(){
    int n,m;
    cin >> n >> m;
    map<bitset<20>,int> ma;
    rep(i,n){
        string s;
        cin >> s;
        bitset<20> s2(s);
        ma[s2]++;
    }
    ll ans = 0;
    for(auto i=ma.begin();i!=prev(ma.end());i++){
        for(auto j=next(i);j!=ma.end();j++){
            if(xor_bit_cnt(i->first,j->first) % 2 == 1)ans += i->second * j->second;
        }
    }
    cout << ans << endl;
}