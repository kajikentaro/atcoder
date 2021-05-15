#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
using mint = modint998244353;
int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<mint>> table(k,vector<mint>(n));
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    table[0][n-1] = a[n-1];
    for(int i=n-2;i>=0;i++){
        table[0][i] = table[0][i+1] + a[i];
    }
    rep(i,k){
        if(i==0)continue;
        rep(j,n){
            table[i][j] = table[i-1][j] * table[0][j];
        }
    }
    

}