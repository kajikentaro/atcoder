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
    vector<int> c(3);
    cin >> n;
    rep(i,3)cin >> c[i];

    int mi = 1e18;
    rep(i,10000)rep(j,10000){
        ll remain  = (n - (c[0] * i + c[1] * j));
        if(remain % c[2] == 0){
            ll sum = i + j + remain / c[2];
            chmin(mi, sum);
        }
    }
    cout << mi << endl;
}