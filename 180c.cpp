#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin >> n;
    vector<ll> factor;
    for(ll i=1;i*i<=n;i++){
        if(n%i == 0){
            factor.push_back(i);
            if(i*i != n){
                factor.push_back(n/i);
            }
        }
    }
    sort(factor.begin(),factor.end());
    for(ll i=0;i<factor.size();i++){
        cout << factor[i] << endl;
    }
    return 0;
}