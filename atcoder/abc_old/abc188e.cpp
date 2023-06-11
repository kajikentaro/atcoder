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
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<vector<int>> path(n+1);
    rep(i,n)cin >> a[i+1];
    rep(i,m){
        int x,y;
        cin >> x >> y;
        path[y].push_back(x);
    }
    int max_v = -1e10;
    vector<int> reasonable(n+1,1e10);
    rep(i,n+1){
        if(i==0)continue;
        for(int city : path[i]){
            chmin(reasonable[i],reasonable[city]);
        }
        chmax(max_v, a[i] - reasonable[i]);
        chmin(reasonable[i], a[i]);
    }
    cout << max_v << endl;
}