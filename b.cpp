#include<atcoder/all>
#include<bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define ll long long
int main(void){
    ll n,k;
    cin >> n >> k;
    ll sum = 0;
    for(ll i=k+1;i<=2*n-1;i++){
        int right=i,left=i-k;
        if(left>=n){
            left = 2*(n-1) - left +1;
        }
        if(right>=n){
            right = 2*(n-1) - right +1;
        }
        sum += right * left;
    }
    cout << sum << endl;
    return 0;
}