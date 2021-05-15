#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
#define MAX 10000
int main(){
    ll s,p;
    cin >> s >> p;
    vector<ll> factor;
    for(int i=2;(ll)i*i <= p;i++){
        while(p%i==0){
            factor.push_back(i);
            p /= i;
        }
    }
    if(p != 1)factor.push_back(p);
    int k = factor.size();
    for(int i=0;i<pow(2,k);i++){
        ll n = 1,m = 1;
        for(int j=0;j<k;j++){
            if(i & 1<<j){
                n *= factor[j];
            }else{
                m *= factor[j];
            }
        }
        if(n + m == s){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}