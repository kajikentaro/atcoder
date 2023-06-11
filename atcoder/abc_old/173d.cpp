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
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    sort(a.begin(),a.end());
    ll ans = a[n-1];
    queue<int> que;
    que.push(a[n-2]);
    que.push(a[n-2]);
    rrep(i,n){
        if(i >=n-2)continue;
        ans += que.front();
        que.pop();
        que.push(a[i]);
        que.push(a[i]);
    }
    cout << ans << endl;
}
