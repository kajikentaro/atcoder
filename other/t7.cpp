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
int main(){
    #define int long long
    int n;
    cin >> n;
    vector<int> a(n+1);
    const int inf = 2e9;
    a[0] = -inf;
    orep(i,n)cin >> a[i];
    a.push_back(inf);
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    rep(i,q){
        int b;
        cin >> b;
        auto up_itr = lower_bound(a.begin(), a.end(), b);
        auto bottom_itr = up_itr-1;
        cout << min(abs(*bottom_itr - b), abs(*up_itr - b)) << endl;
    }
}
