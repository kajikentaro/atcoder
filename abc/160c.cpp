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
using P = pair<int,int>;
int main(){
    int k,n;
    cin >> k >> n;
    vector<int> a(n);
    vector<int> dist(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        if(i ==0){
            dist[i] = min(abs(a[n-1] - a[i]),k - abs(a[n-1] - a[i]));
        }else{
            dist[i] = min(abs(a[i-1] - a[i]),k - abs(a[i-1] - a[i]));
        }
    }
    int max_dist = *max_element(dist.begin(),dist.end());
    cout << k - max_dist << endl;
}
