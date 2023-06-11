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
    vector<int> a(m);
    vector<int> b(m);
    rep(i,m)cin >> a[i] >> b[i];

    int k;
    cin >> k;
    vector<int> c(k);
    vector<int> d(k);
    rep(i,k)cin >> c[i] >> d[i];
    int max_sum = 0;
    for(int i=0;i<pow(2,k);i++){
        vector<int> dish(n+1,0);
        rep(j,k){
            if(1 << j & i){
                dish[c[j]]++;
            }else{
                dish[d[j]]++;
            }
        }
        int sum = 0;
        rep(j,m){
            if(dish[a[j]] && dish[b[j]])sum++;
        }
        chmax(max_sum, sum);
    }
    cout << max_sum << endl;
}
