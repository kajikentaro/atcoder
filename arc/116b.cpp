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
using mint = modint998244353;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    sort(a.rbegin(),a.rend());
    mint ans = 0;
    mint tmp = a[0];
    rep(i,n){
        if(i!=0){
            tmp *= 2;
            tmp -= a[i-1];
            tmp += a[i];
        }
        ans += a[i] * tmp;
    }
    cout << ans.val() << endl;
}
